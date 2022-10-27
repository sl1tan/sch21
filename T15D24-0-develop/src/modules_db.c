#include <stdio.h>

#include "shared.h"

int main() {
    int mod, select_data, select_len, str_update, elem_update, replace_update, str_delete, el1, el2, el3;
    char ui[400] =
        "\nPlease choose one operation:\n1. SELECT\n2. INSERT\n3. UPDATE\n4. DELETE\n5. Get all active "
        "additional modules (last module status is 1)\n6. Delete modules by ids\n7. Set protected mode for "
        "main module\n8. Set delete_flag fo all modules\n9. Get all modules on lvl one\n10. Get all modules "
        "on lvl one and cell one\n-1. EXIT\n";
    char select_ui[400] = "Please choose a table:\n1. Modules\n2. Levels\n3. Status events\n";
    char select_mod[400] = "Insert the number of records or send 0 to output all of them: ";
    char insert_ui[400] = "Insert element of table\n";
    char update_ui[400] = "Write a row in the table to change ";
    char delete_ui[400] = "Write a row in the table to delete ";
    char update_ui2_mod[400] =
        "\nWhich element are we changing?\n1. Module ID\n2. Number of the memory level where "
        "the module is located\n3. Number of the cell where the module is located on this level\n4. Deletion "
        "flag\n";
    char update_ui2_lvl[400] =
        "\nWhich element are we changing?\n1. Number of memory level\n2. The number of cells on the "
        "level\n3. Protection flag\n";
    char update_ui2_st[400] =
        "\nWhich element are we changing?\n1. Event ID\n2. Module ID\n3. New module status\n";
    char update_ui3[400] = "\nEnter a new value ";
    while (1) {
        int flag = 1;
        printf("%s", ui);
        if (scanf("%d%*c", &mod) != 1 || (mod < 1 && mod != -1) || mod > 10) {
            printf("n/a\n");
            scanf("%*s");
            flag = 0;
        } else if (mod == -1) {
            break;
        }
        if (flag) {
            switch (mod) {
                case 1:
                    printf("%s", select_ui);
                    if (scanf("%d%*c", &select_data) != 1 || select_data < 1 || select_data > 3) {
                        printf("n/a\n");
                        scanf("%*s");
                        flag = 0;
                    }
                    if (flag) {
                        printf("%s", select_mod);
                        if (scanf("%d%*c", &select_len) != 1 || select_len < 0) {
                            printf("n/a\n");
                            scanf("%*s");
                            flag = 0;
                        }
                    }

                    if (flag) {
                        SELECT(select_data, select_len);
                    }
                    break;
                case 2:
                    printf("%s", select_ui);
                    if (scanf("%d%*c", &select_data) != 1 || select_data < 1 || select_data > 3) {
                        printf("n/a\n");
                        scanf("%*s");
                        flag = 0;
                    }

                    if (flag) {
                        printf("%s", insert_ui);
                        INSERT(select_data);
                    }
                    break;
                case 3:
                    printf("%s", select_ui);
                    if (scanf("%d%*c", &select_data) != 1 || select_data < 1 || select_data > 3) {
                        printf("n/a\n");
                        scanf("%*s");
                        flag = 0;
                    }

                    if (flag) {
                        printf("%s", update_ui);
                        if (scanf("%d%*c", &str_update) != 1) {
                            printf("n/a\n");
                            scanf("%*s");
                            flag = 0;
                        }

                        if (flag) {
                            switch (select_data) {
                                case 1:
                                    printf("%s", update_ui2_mod);
                                    break;
                                case 2:
                                    printf("%s", update_ui2_lvl);
                                    break;
                                case 3:
                                    printf("%s", update_ui2_st);
                                    break;
                            }
                            if (scanf("%d%*c", &elem_update) != 1 || elem_update < 1 || elem_update > 4) {
                                printf("n/a\n");
                                scanf("%*s");
                                flag = 0;
                            }
                        }

                        if (flag) {
                            printf("%s", update_ui3);
                            if (scanf("%d%*c", &replace_update) != 1) {
                                printf("n/a\n");
                                scanf("%*s");
                                flag = 0;
                            }
                        }

                        if (flag) UPDATE(select_data, str_update, elem_update, replace_update);
                    }
                    break;
                case 4:
                    printf("%s", select_ui);
                    if (scanf("%d%*c", &select_data) != 1 || select_data < 1 || select_data > 3) {
                        printf("n/a\n");
                        scanf("%*s");
                        flag = 0;
                    }

                    if (flag) {
                        printf("%s", delete_ui);
                        if (scanf("%d%*c", &str_delete) != 1) {
                            printf("n/a\n");
                            scanf("%*s");
                            flag = 0;
                        }
                    }
                    if (flag) DELETE(select_data, str_delete);
                    break;
                case 5:
                    CASE5(select_data, str_delete);
                    break;
                case 6:
                    printf("Send 3 id to delete ");
                    if (scanf("%d%d%d", &el1, &el2, &el3) != 3) {
                        printf("n/a");
                        flag = 0;
                    }

                    if (flag) CASE6(el1, el2 - 1, el3 - 2);
                    break;
                case 7:
                    CASE7();
                    break;
                case 8:
                    CASE8();
                    break;
                case 9:
                    CASE9();
                    break;
                case 10:
                    CASE10();
                    break;
            }
        }
    }
    return 0;
}
