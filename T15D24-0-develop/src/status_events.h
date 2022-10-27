#ifndef SRC_STATUS_EVENTS_H_
#define SRC_STATUS_EVENTS_H_
#include <stdio.h>

struct event {
    int id_event;
    int module_id;
    int new_status;
    char data_upd[11];
    char time_upd[9];
};


void select_st(int id);
int delet(FILE *db, int id);
// int insert(FILE *db, event *entity);
// int update(FILE *db, int id, event *entity);

struct event st_read_record_from_file(FILE *pfile, int index);

void st_write_record_in_file(FILE *pfile, const struct event *record_to_write, int index);

void st_swap_records_in_file(FILE *pfile, int record_index1, int record_index2);

int st_get_file_size_in_bytes(FILE *pfile);

int st_get_records_count_in_file(FILE *pfile);

void insert_st();
void update_st(int str, int elem, int replace);
void delete_st(int str);
void get_active();


#endif  //  SRC_STATUS_EVENTS_H_
