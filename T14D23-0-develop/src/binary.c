#include "binary.h"

// Функция считывания записи заданного типа из файла по его серийному номеру.
struct my_struct read_record_from_file(FILE *pfile, int index) {
    // Вычисление смещения, на котором должна располагаться желаемая запись, от начала файла.
    int offset = index * sizeof(struct my_struct);
    // Переместите указатель положения на вычисленное смещение от начала файла.
    fseek(pfile, offset, SEEK_SET);

    // Чтение записи указанного типа из файла.
    struct my_struct record;
    fread(&record, sizeof(struct my_struct), 1, pfile);

    // По соображениям безопасности мы возвращаем указатель положения файла в начало файла.
    rewind(pfile);

    // Возврат записи чтения
    return record;
}

// Функция записи записи указанного типа в файл с указанным серийным номером.
void write_record_in_file(FILE *pfile, const struct my_struct *record_to_write, int index) {
    // Вычисление смещения, на котором должна располагаться требуемая запись от начала файла.
    int offset = index * sizeof(struct my_struct);
    // Переместите указатель положения на вычисленное смещение от начала файла.
    fseek(pfile, offset, SEEK_SET);

    // Записать запись указанного типа в файл.
    fwrite(record_to_write, sizeof(struct my_struct), 1, pfile);

    // На всякий случай заставьте подсистему ввода-вывода записать содержимое своего буфера в файл прямо
    // сейчас.
    fflush(pfile);

    // В целях безопасности верните указатель положения файла в начало файла.
    rewind(pfile);
}

// Функция взаимного переноса двух записей в файле по их индексам.
void swap_records_in_file(FILE *pfile, int record_index1, int record_index2) {
    // Считывает обе записи из файла в переменные
    struct my_struct record1 = read_record_from_file(pfile, record_index1);
    struct my_struct record2 = read_record_from_file(pfile, record_index2);

    // Перезаписать записи в файле
    write_record_in_file(pfile, &record1, record_index2);
    write_record_in_file(pfile, &record2, record_index1);
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
int get_records_count_in_file(FILE *pfile) {
    return get_file_size_in_bytes(pfile) / sizeof(struct my_struct);
}
