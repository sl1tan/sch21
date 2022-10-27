#include "binary.h"

int read(char *name);
int sort(char *name);
void clear(char *name, struct my_struct b1, struct my_struct b2);

int main() {
    FILE *fp;
    char name[200];
    int flag = 1;
    scanf("%199s", name);
    struct my_struct b1;
    b1.hour = 0;
    b1.minute = 0;
    b1.second = 0;
    b1.status = 0;
    b1.code = 0;
    if (scanf("%d.%d.%d", &b1.day, &b1.month, &b1.year) != 3 || b1.day < 1 || b1.day > 31 || b1.month < 1 ||
        b1.month > 12 || b1.year < 0) {
        printf("n/a");
        flag = 0;
    }

    struct my_struct b2;
    b2.hour = 0;
    b2.minute = 0;
    b2.second = 0;
    b2.status = 0;
    b2.code = 0;
    if (flag) {
        if (scanf("%d.%d.%d", &b2.day, &b2.month, &b2.year) != 3 || b2.day < 1 || b2.day > 31 ||
            b2.month < 1 || b2.month > 12 || b2.year < 0) {
            printf("n/a");
            flag = 0;
        }
    }

    if (flag) {
        if ((fp = fopen(name, "r+b")) == NULL) {
            printf("n/a");
            flag = 0;
        }
    }

    if (flag) {
        fclose(fp);
        clear(name, b1, b2);
        read(name);
    }
    return 0;
}

int read(char *name) {
    int flag = 1;
    FILE *fp;
    if ((fp = fopen(name, "rb")) == NULL) {
        printf("n/a");
        flag = 0;
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

void clear(char *name, struct my_struct b1, struct my_struct b2) {
    FILE *fp, *temp;
    sort(name);

    fp = fopen(name, "rb");

    temp = fopen("temp", "wb");
    fclose(temp);

    int count = get_records_count_in_file(fp);

    temp = fopen("temp", "ab");
    int pos = 0;
    for (int i = 0; i < count; i++) {
        int flag = 1;
        struct my_struct buf;
        buf = read_record_from_file(fp, i);
        if (buf.year >= b1.year && buf.year <= b2.year) {
            flag = 0;
        }

        if (flag) {
            write_record_in_file(temp, &buf, pos);
            pos++;
        }
    }
    fclose(temp);
    fclose(fp);

    fp = fopen(name, "wb");
    fclose(fp);

    temp = fopen("temp", "rb");
    fp = fopen(name, "a+b");
    for (int i = 0; i < pos - 1; i++) {
        struct my_struct buf;
        buf = read_record_from_file(temp, i);
        write_record_in_file(fp, &buf, i);
    }
    fclose(temp);
    fclose(fp);
}
