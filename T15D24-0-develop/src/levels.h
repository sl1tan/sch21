#ifndef SRC_LEVELS_H_
#define SRC_LEVELS_H_
#include <stdio.h>

struct level {
    int number;
    int count;
    int flag_save;
};


void select_lvl(int id);
int delet(FILE *db, int id);
// int insert(FILE *db, level *entity);
// int update(FILE *db, int id, level *entity);

struct level lvl_read_record_from_file(FILE *pfile, int index);

void lvl_write_record_in_file(FILE *pfile, const struct level *record_to_write, int index);

void lvl_swap_records_in_file(FILE *pfile, int record_index1, int record_index2);

int lvl_get_file_size_in_bytes(FILE *pfile);

int lvl_get_records_count_in_file(FILE *pfile);

void insert_lvl();
void update_lvl(int str, int elem, int replace);
void delete_lvl(int str);


#endif  //  SRC_LEVELS_H_
