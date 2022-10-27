#include "shared.h"
#include "modules.h"
#include "levels.h"
#include "status_events.h"

void SELECT(int mod, int len) {
    switch (mod) {
        case 1:
            select_mod(len);
            break;
        case 2:
            select_lvl(len);
            break;
        case 3:
            select_st(len);
            break;
    }
}

void INSERT(int mod) {
    switch (mod) {
        case 1:
            insert_mod();
            break;
        case 2:
            insert_lvl();
            break;
        case 3:
            insert_st();
            break;
    }
}

void UPDATE(int mod, int str, int elem, int replace) {
    switch (mod) {
        case 1:
            update_mod(str, elem, replace);
            break;
        case 2:
            update_lvl(str, elem, replace);
            break;
        case 3:
            update_st(str, elem, replace);
            break;
    }
}

void DELETE(int mod, int str) {
    switch (mod) {
        case 1:
            delete_mod(str);
            break;
        case 2:
            delete_lvl(str);
            break;
        case 3:
            delete_st(str);
            break;
    }
}

void CASE5() {
    get_active();
}

void CASE6(int el1, int el2, int el3) {
    del_by_ids(el1, el2, el3);
}

void CASE7() {
    update_st(0, 3, 0);
    select_st(1);
    update_st(0, 3, 1);
    select_st(1);
    update_st(0, 3, 20);
    select_st(1);

    update_mod(0, 2, 1);
    update_mod(0, 3, 1);
    update_lvl(0, 3, 1);

    select_mod(1);
    select_lvl(1);
}

void CASE8() {
    FILE *pfile = fopen("../materials/master_modules.db", "rb");
    int count = get_records_count_in_file(pfile);
    fclose(pfile);
    for (int i = 1; i < count; i++) {
        update_mod(i, 4, 1);
    }
    select_mod(0);
}

void CASE9() {
    get_on_lvl1();
}

void CASE10() {
    get_on_lvl_and_cell1();
}
