#include "status_events.h"

// Функция считывания записи заданного типа из файла по его серийному номеру.
struct event st_read_record_from_file(FILE *pfile, int index) {
    // Вычисление смещения, на котором должна располагаться желаемая запись, от начала файла.
    int offset = index * sizeof(struct event);
    // Переместите указатель положения на вычисленное смещение от начала файла.
    fseek(pfile, offset, SEEK_SET);

    // Чтение записи указанного типа из файла.
    struct event record;
    fread(&record, sizeof(struct event), 1, pfile);

    // По соображениям безопасности мы возвращаем указатель положения файла в начало файла.
    rewind(pfile);

    // Возврат записи чтения
    return record;
}

// Функция записи записи указанного типа в файл с указанным серийным номером.
void st_write_record_in_file(FILE *pfile, const struct event *record_to_write, int index) {
    // Вычисление смещения, на котором должна располагаться требуемая запись от начала файла.
    int offset = index * sizeof(struct event);
    // Переместите указатель положения на вычисленное смещение от начала файла.
    fseek(pfile, offset, SEEK_SET);

    // Записать запись указанного типа в файл.
    fwrite(record_to_write, sizeof(struct event), 1, pfile);

    // На всякий случай заставьте подсистему ввода-вывода записать содержимое своего буфера в файл прямо
    // сейчас.
    fflush(pfile);

    // В целях безопасности верните указатель положения файла в начало файла.
    rewind(pfile);
}

// Функция для получения размера файла в байтах.
int st_get_file_size_in_bytes(FILE *pfile) {
    int size = 0;
    fseek(pfile, 0, SEEK_END);  // Переместите указатель позиции в конец файла.
    size = ftell(pfile);  // Считывает количество байтов от начала файла до указателя текущей позиции.
    rewind(pfile);  // В целях безопасности верните указатель положения файла в начало файла..
    return size;
}

// Функция для получения количества записей в файле
int st_get_records_count_in_file(FILE *pfile) {
    return st_get_file_size_in_bytes(pfile) / sizeof(struct event);
}

void select_st(int id) {
    FILE *pfile = fopen("../materials/master_status_events.db", "rb");
    int count = st_get_records_count_in_file(pfile);

    if (id == 0) {
        id = count;
    } else if (id > count) {
        id = count;
    }
    printf("\n");
    for (int i = 0; i < id; i++) {
        struct event b;
        b = st_read_record_from_file(pfile, i);
        printf("%d %d %d %s %s\n", b.id_event, b.module_id, b.new_status, b.data_upd, b.time_upd);
    }
    printf("\n");
    fclose(pfile);
}

void insert_st() {
    FILE *pfile = fopen("../materials/master_status_events.db", "r+b");
    int count = st_get_records_count_in_file(pfile), flag = 1;
    struct event b;
    printf("\n");
    if (scanf("%d %d %d %11s %9s\n", &b.id_event, &b.module_id, &b.new_status, b.data_upd, b.time_upd) != 5) {
        printf("n/a\n");
        flag = 0;
    }
    if (flag) {
        st_write_record_in_file(pfile, &b, count);
    }
    fclose(pfile);
    printf("\n");
}

void update_st(int str, int elem, int replace) {
    FILE *pfile = fopen("../materials/master_status_events.db", "r+b");
    int count = st_get_records_count_in_file(pfile), flag = 1;
    struct event b;

    if (str > count || str < 0) flag = 0;

    if (flag) {
        b = st_read_record_from_file(pfile, str);
        switch (elem) {
            case 1:
                b.id_event = replace;
                break;
            case 2:
                b.module_id = replace;
                break;
            case 3:
                b.new_status = replace;
                break;
        }
        st_write_record_in_file(pfile, &b, str);
    }

    fclose(pfile);
    printf("\n");
}

void delete_st(int str) {
    FILE *pfile = fopen("../materials/master_status_events.db", "r+b");
    int count = st_get_records_count_in_file(pfile), flag = 1;
    struct event b;

    fclose(pfile);

    if (str > count || str < 0) {
        printf("n/a\n");
        flag = 0;
    }

    if (flag) {
        struct event b2;
        FILE *temp = fopen("temp", "wb");
        fclose(temp);
        pfile = fopen("../materials/master_status_events.db", "rb");
        temp = fopen("temp", "ab");

        int count2 = 0;
        for (int i = 0; i < count; i++) {
            if (i != str) {
                b = st_read_record_from_file(pfile, i);
                st_write_record_in_file(temp, &b, count2);
                count2++;
            }
        }
        fclose(pfile);
        fclose(temp);

        pfile = fopen("../materials/master_status_events.db", "wb");
        fclose(pfile);

        pfile = fopen("../materials/master_status_events.db", "ab");
        temp = fopen("temp", "rb");

        for (int i = 0; i < count2; i++) {
            b2 = st_read_record_from_file(temp, i);
            st_write_record_in_file(pfile, &b2, i);
        }

        fclose(pfile);
        fclose(temp);
    }
}

void get_active() {
    FILE *pfile = fopen("../materials/master_status_events.db", "r+b");
    int count = st_get_records_count_in_file(pfile);

    printf("\n");
    for (int i = 0; i < count; i++) {
        struct event b;
        b = st_read_record_from_file(pfile, i);
        if (b.new_status == 1) {
            printf("%-2d IS ACTIVE\n", b.module_id);
        }
    }
    printf("\n");
    fclose(pfile);
}
