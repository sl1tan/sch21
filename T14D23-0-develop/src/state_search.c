#include <stdio.h>

void read(char *name);
void search(char *name, int day, int month, int year);

int main() {
    char name[200];
    int day, month, year, flag = 1;
    scanf("%199s", name);
    if (scanf("%d.%d.%d", &day, &month, &year) != 3 || day < 1 || day > 31 || month < 1 || month > 12 ||
        year < 0) {
        printf("n/a");
        flag = 0;
    } else {
        FILE *fp;
        fp = fopen(name, "rb");
        fseek(fp, 0, SEEK_END);
        long pos = ftell(fp);
        if (pos == 0) {
            printf("n/a");
            flag = 0;
        }
        fclose(fp);
    }

    if (flag) {
        search(name, day, month, year);
    }
}

void search(char *name, int day, int month, int year) {
    int flag = 1;
    FILE *fp;
    if ((fp = fopen(name, "rb")) == NULL) {
        printf("n/a");
        flag = 0;
    }
    if (flag) {
        int end, count = 0;

        fseek(fp, 0, SEEK_END);
        end = ftell(fp);
        end = end / 32;
        fseek(fp, 0, SEEK_SET);

        for (int j = 0; j < end; j++) {
            int buffer[8];
            fread(buffer, sizeof(int), 8, fp);
            if (buffer[0] == year && buffer[1] == month && buffer[2] == day) {
                printf("%d", buffer[7]);
                count = 1;
                break;
            }
        }
        fseek(fp, 0, SEEK_SET);
        fclose(fp);
        if (count == 0) {
            printf("n/a");
        }
    }
}
