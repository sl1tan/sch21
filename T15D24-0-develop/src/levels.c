#include "levels.h"

// Функция считывания записи заданного типа из файла по его серийному номеру.
struct level lvl_read_record_from_file(FILE *pfile, int index) {
    // Вычисление смещения, на котором должна располагаться желаемая запись, от начала файла.
    int offset = index * sizeof(struct level);
    // Переместите указатель положения на вычисленное смещение от начала файла.
    fseek(pfile, offset, SEEK_SET);

    // Чтение записи указанного типа из файла.
    struct level record;
    fread(&record, sizeof(struct level), 1, pfile);

    // По соображениям безопасности мы возвращаем указатель положения файла в начало файла.
    rewind(pfile);

    // Возврат записи чтения
    return record;
}

// Функция записи записи указанного типа в файл с указанным серийным номером.
void lvl_write_record_in_file(FILE *pfile, const struct level *record_to_write, int index) {
    // Вычисление смещения, на котором должна располагаться требуемая запись от начала файла.
    int offset = index * sizeof(struct level);
    // Переместите указатель положения на вычисленное смещение от начала файла.
    fseek(pfile, offset, SEEK_SET);

    // Записать запись указанного типа в файл.
    fwrite(record_to_write, sizeof(struct level), 1, pfile);

    // На всякий случай заставьте подсистему ввода-вывода записать содержимое своего буфера в файл прямо
    // сейчас.
    fflush(pfile);

    // В целях безопасности верните указатель положения файла в начало файла.
    rewind(pfile);
}

// Функция для получения размера файла в байтах.
int lvl_get_file_size_in_bytes(FILE *pfile) {
    int size = 0;
    fseek(pfile, 0, SEEK_END);  // Переместите указатель позиции в конец файла.
    size = ftell(pfile);  // Считывает количество байтов от начала файла до указателя текущей позиции.
    rewind(pfile);  // В целях безопасности верните указатель положения файла в начало файла..
    return size;
}

// Функция для получения количества записей в файле
int lvl_get_records_count_in_file(FILE *pfile) {
    return lvl_get_file_size_in_bytes(pfile) / sizeof(struct level);
}

void select_lvl(int id) {
    FILE *pfile = fopen("../materials/master_levels.db", "rb");
    int count = lvl_get_records_count_in_file(pfile);

    if (id == 0) {
        id = count;
    } else if (id > count) {
        id = count;
    }
    printf("\n");
    for (int i = 0; i < id; i++) {
        struct level b;
        b = lvl_read_record_from_file(pfile, i);
        printf("%d %d %d\n", b.number, b.count, b.flag_save);
    }
    printf("\n");
    fclose(pfile);
}

void insert_lvl() {
    FILE *pfile = fopen("../materials/master_levels.db", "r+b");
    int count = lvl_get_records_count_in_file(pfile), flag = 1;
    struct level b;
    printf("\n");
    if (scanf("%d%d%d\n", &b.number, &b.count, &b.flag_save) != 3) {
        printf("n/a\n");
        flag = 0;
    }
    if (flag) {
        lvl_write_record_in_file(pfile, &b, count);
    }
    fclose(pfile);
    printf("\n");
}

void update_lvl(int str, int elem, int replace) {
    FILE *pfile = fopen("../materials/master_levels.db", "r+b");
    int count = lvl_get_records_count_in_file(pfile), flag = 1;
    struct level b;

    if (str > count || str < 0) flag = 0;
    if (flag) {
        b = lvl_read_record_from_file(pfile, str);
        switch (elem) {
            case 1:
                b.number = replace;
                break;
            case 2:
                b.count = replace;
                break;
            case 3:
                b.flag_save = replace;
                break;
        }
        lvl_write_record_in_file(pfile, &b, str);
    }

    fclose(pfile);
    printf("\n");
}

void delete_lvl(int str) {
    FILE *pfile = fopen("../materials/master_levels.db", "r+b");
    int count = lvl_get_records_count_in_file(pfile), flag = 1;
    struct level b;

    fclose(pfile);

    if (str > count || str < 0) {
        printf("n/a\n");
        flag = 0;
    }

    if (flag) {
        struct level b2;
        FILE *temp = fopen("temp", "wb");
        fclose(temp);
        pfile = fopen("../materials/master_levels.db", "rb");
        temp = fopen("temp", "ab");

        int count2 = 0;
        for (int i = 0; i < count; i++) {
            if (i != str) {
                b = lvl_read_record_from_file(pfile, i);
                lvl_write_record_in_file(temp, &b, count2);
                count2++;
            }
        }
        fclose(pfile);
        fclose(temp);

        pfile = fopen("../materials/master_levels.db", "wb");
        fclose(pfile);

        pfile = fopen("../materials/master_levels.db", "ab");
        temp = fopen("temp", "rb");

        for (int i = 0; i < count2; i++) {
            b2 = lvl_read_record_from_file(temp, i);
            lvl_write_record_in_file(pfile, &b2, i);
        }

        fclose(pfile);
        fclose(temp);
    }
}
