#include "binary.h"

int read(char *name);
int sort(char *name);
int insert(char *name);

int main() {
    FILE *fp;
    char name[200];
    int mod = 3, flag = 1;
    scanf("%199s", name);
    if (scanf("%d", &mod) != 1 || mod > 2 || mod < 0) {
        printf("n/a");
        flag = 0;
    }
    if ((fp = fopen(name, "rb")) == NULL && flag) {
        flag = 0;
        printf("n/a");
    } else {
        fclose(fp);
    }

    if (flag) {
        switch (mod) {
            case 0:
                read(name);
                break;
            case 1:
                if (sort(name)) {
                    read(name);
                }
                break;
            case 2:
                if (insert(name)) {
                    sort(name);
                    read(name);
                }
                break;
        }
    }
}

int read(char *name) {
    int flag = 1;
    FILE *fp;
    if ((fp = fopen(name, "rb")) == NULL) {
        printf("n/a");
        flag = 0;
    } else {
        fseek(fp, 0, SEEK_END);
        long pos = ftell(fp);
        if (pos == 0) {
            printf("n/a");
            flag = 0;
        }
    }

    if (flag) {
        int count = get_records_count_in_file(fp);
        for (int i = 0; i < count; i++) {
            struct my_struct b;
            b = read_record_from_file(fp, i);
            printf("%d %d %d %d %d %d %d %d", b.year, b.month, b.day, b.hour, b.minute, b.second, b.status,
                   b.code);
            if (i < count - 1) printf("\n");
        }
        fclose(fp);
    }
    return flag;
}

int sort(char *name) {
    int flag = 1;
    FILE *fp;
    if ((fp = fopen(name, "r+b")) == NULL) {
        printf("n/a");
        flag = 0;
    }

    if (flag) {
        int count = get_records_count_in_file(fp);
        struct my_struct b1;
        struct my_struct b2;
        for (int i = 0; i < count - 1; i++) {
            for (int k = 0; k < count - 1 - i; k++) {
                b1 = read_record_from_file(fp, k);
                b2 = read_record_from_file(fp, k + 1);
                if (b2.year < b1.year) {
                    swap_records_in_file(fp, k, k + 1);
                } else if (b2.year == b1.year && b2.month < b1.month) {
                    swap_records_in_file(fp, k, k + 1);
                } else if (b2.month == b1.month && b2.day < b1.day) {
                    swap_records_in_file(fp, k, k + 1);
                } else if (b2.day == b1.day && b2.hour < b1.hour) {
                    swap_records_in_file(fp, k, k + 1);
                } else if (b2.hour == b1.hour && b2.minute < b1.minute) {
                    swap_records_in_file(fp, k, k + 1);
                } else if (b2.minute == b1.minute && b2.second < b1.second) {
                    swap_records_in_file(fp, k, k + 1);
                }
            }
        }
        fclose(fp);
    }
    return flag;
}

int insert(char *name) {
    int flag = 1;
    FILE *fp;
    struct my_struct b;
    if (scanf("%d%d%d%d%d%d%d%d", &b.year, &b.month, &b.day, &b.hour, &b.minute, &b.second, &b.status,
              &b.code) != 8 ||
        b.day < 1 || b.day > 31 || b.month < 1 || b.month > 12 || b.year < 0 || b.hour > 23 || b.hour < 0 ||
        b.minute < 0 || b.minute > 59 || b.second > 59 || b.second < 0) {
        printf("n/a");
        flag = 0;
    }

    if (flag) {
        if ((fp = fopen(name, "r+b")) == NULL) {
            printf("n/a");
            flag = 0;
        }
    }

    if (flag) {
        int count = get_records_count_in_file(fp);
        write_record_in_file(fp, &b, count);
        fclose(fp);
    }
    return flag;
}
