#include "modules.h"

// Функция считывания записи заданного типа из файла по его серийному номеру.
struct module read_record_from_file(FILE *pfile, int index) {
    // Вычисление смещения, на котором должна располагаться желаемая запись, от начала файла.
    int offset = index * sizeof(struct module);
    // Переместите указатель положения на вычисленное смещение от начала файла.
    fseek(pfile, offset, SEEK_SET);

    // Чтение записи указанного типа из файла.
    struct module record;
    fread(&record, sizeof(struct module), 1, pfile);

    // По соображениям безопасности мы возвращаем указатель положения файла в начало файла.
    rewind(pfile);

    // Возврат записи чтения
    return record;
}

// Функция записи записи указанного типа в файл с указанным серийным номером.
void write_record_in_file(FILE *pfile, const struct module *record_to_write, int index) {
    // Вычисление смещения, на котором должна располагаться требуемая запись от начала файла.
    int offset = index * sizeof(struct module);
    // Переместите указатель положения на вычисленное смещение от начала файла.
    fseek(pfile, offset, SEEK_SET);

    // Записать запись указанного типа в файл.
    fwrite(record_to_write, sizeof(struct module), 1, pfile);

    // На всякий случай заставьте подсистему ввода-вывода записать содержимое своего буфера в файл прямо
    // сейчас.
    fflush(pfile);

    // В целях безопасности верните указатель положения файла в начало файла.
    rewind(pfile);
}

// Функция для получения размера файла в байтах.
int get_file_size_in_bytes(FILE *pfile) {
    int size = 0;
    fseek(pfile, 0, SEEK_END);  // Переместите указатель позиции в конец файла.
    size = ftell(pfile);  // Считывает количество байтов от начала файла до указателя текущей позиции.
    rewind(pfile);  // В целях безопасности верните указатель положения файла в начало файла..
    return size;
}

// Функция для получения количества записей в файле
int get_records_count_in_file(FILE *pfile) { return get_file_size_in_bytes(pfile) / sizeof(struct module); }

void select_mod(int id) {
    FILE *pfile = fopen("../materials/master_modules.db", "rb");
    int count = get_records_count_in_file(pfile);

    if (id == 0) {
        id = count;
    } else if (id > count) {
        id = count;
    }
    printf("\n");
    for (int i = 0; i < id; i++) {
        struct module b;
        b = read_record_from_file(pfile, i);
        if (b.flag_remove != 1) {
            printf("%d %s %d %d %d\n", b.id, b.name_module, b.level, b.cell, b.flag_remove);
        }
    }
    printf("\n");
    fclose(pfile);
}

void insert_mod() {
    FILE *pfile = fopen("../materials/master_modules.db", "r+b");
    int count = get_records_count_in_file(pfile), flag = 1;
    struct module b;
    printf("\n");
    if (scanf("%d %30s %d %d %d\n", &b.id, b.name_module, &b.level, &b.cell, &b.flag_remove) != 5) {
        printf("n/a\n");
        flag = 0;
    }
    if (flag) {
        write_record_in_file(pfile, &b, count);
    }
    fclose(pfile);
    printf("\n");
}

void update_mod(int str, int elem, int replace) {
    FILE *pfile = fopen("../materials/master_modules.db", "r+b");
    int count = get_records_count_in_file(pfile), flag = 1;
    struct module b;

    if (str > count || str < 0) flag = 0;

    if (flag) {
        b = read_record_from_file(pfile, str);
        switch (elem) {
            case 1:
                b.id = replace;
                break;
            case 2:
                b.level = replace;
                break;
            case 3:
                b.cell = replace;
                break;
            case 4:
                b.flag_remove = replace;
                break;
        }
        write_record_in_file(pfile, &b, str);
    }

    fclose(pfile);
    printf("\n");
}

void delete_mod(int str) {
    FILE *pfile = fopen("../materials/master_modules.db", "r+b");
    int count = get_records_count_in_file(pfile), flag = 1;
    struct module b;

    fclose(pfile);

    if (str > count || str < 0) {
        printf("n/a\n");
        flag = 0;
    }

    if (flag) {
        struct module b2;
        FILE *temp = fopen("temp", "wb");
        fclose(temp);
        pfile = fopen("../materials/master_modules.db", "rb");
        temp = fopen("temp", "ab");

        int count2 = 0;
        for (int i = 0; i < count; i++) {
            if (i != str) {
                b = read_record_from_file(pfile, i);
                write_record_in_file(temp, &b, count2);
                count2++;
            }
        }
        fclose(pfile);
        fclose(temp);

        pfile = fopen("../materials/master_modules.db", "wb");
        fclose(pfile);

        pfile = fopen("../materials/master_modules.db", "ab");
        temp = fopen("temp", "rb");

        for (int i = 0; i < count2; i++) {
            b2 = read_record_from_file(temp, i);
            write_record_in_file(pfile, &b2, i);
        }

        fclose(pfile);
        fclose(temp);
    }
}

void del_by_ids(int el1, int el2, int el3) {
    delete_mod(el1);
    delete_mod(el2);
    delete_mod(el3);
}

void get_on_lvl1() {
    FILE *pfile = fopen("../materials/master_modules.db", "r+b");
    int count = get_records_count_in_file(pfile);

    printf("\n");
    for (int i = 0; i < count; i++) {
        struct module b;
        b = read_record_from_file(pfile, i);
        if (b.level == 1 && b.flag_remove != 1) {
            printf("%-2d ON LVL_1\n", b.id);
        }
    }
    printf("\n");
    fclose(pfile);
}

void get_on_lvl_and_cell1() {
    FILE *pfile = fopen("../materials/master_modules.db", "r+b");
    int count = get_records_count_in_file(pfile);

    printf("\n");
    for (int i = 0; i < count; i++) {
        struct module b;
        b = read_record_from_file(pfile, i);
        if (b.level == 1 && b.cell == 1 && b.flag_remove != 1) {
            printf("ID:%-2d ON LVL_1 AND CELL_1\n", b.id);
        }
    }
    printf("\n");
    fclose(pfile);
}
