#ifndef SRC_MODULES_H_
#define SRC_MODULES_H_
#include <stdio.h>

struct module {
    int id;
    char name_module[30];
    int level;
    int cell;
    int flag_remove;
};

void select_mod(int id);
int delet(FILE *db, int id);
// int insert(FILE *db, module *entity);
// int update(FILE *db, int id, module *entity);

struct module read_record_from_file(FILE *pfile, int index);

void write_record_in_file(FILE *pfile, const struct module *record_to_write, int index);

void swap_records_in_file(FILE *pfile, int record_index1, int record_index2);

int get_file_size_in_bytes(FILE *pfile);

int get_records_count_in_file(FILE *pfile);

void insert_mod();

void update_mod(int str, int elem, int replace);

void delete_mod(int str);

void del_by_ids(int el1, int el2, int el3);

void get_on_lvl1();

void get_on_lvl_and_cell1();

#endif  //  SRC_MODULES_H_
