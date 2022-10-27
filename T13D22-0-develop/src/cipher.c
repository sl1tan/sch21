#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "logger.h"

int read(char *name, FILE *log);
void write_plus(char *name, FILE *log);
void cezar(char *name, int shift, FILE *log);
void shifr(FILE *log);

int main() {
    char name[200];
    int count;
    int sw = 0;
    FILE *log;
    log = log_init("logs.txt");
    while (1) {
        if (scanf("%d%*c", &sw) == 1 && sw > 0 && sw < 4) {
            switch (sw) {
                case 1:
                    scanf("%s", name);
                    if (!read(name, log)) {
                        count++;
                        break;
                    }
                    break;
                case 2:
                    write_plus(name, log);
                    break;
                case 3:
                    shifr(log);
                    break;
            }
        } else if (sw == -1) {
#ifdef LOGS
            logcat(log, "выход из программы", info);
#endif
            log_close(log);
            break;
        } else {
            printf("n/a\n");
            scanf("%*s");
#ifdef LOGS
            logcat(log, "Некорректный режим работы", warning);
#endif
        }
    }
    return 0;
}

int read(char *name, FILE *log) {
#ifdef LOGS
    char save[200];
#endif
    FILE *fp;
    int flag = 1;
    if ((fp = fopen(name, "r")) == NULL) {
        printf("n/a\n");
#ifdef LOGS
        strcpy(save, name);
        strcat(save, " не существует или пустой");
        logcat(log, save, error);
        strcpy(save, "");
#endif
        flag = 0;
    }

    if (flag) {
        char c;
        int count = 0;
        while ((c = fgetc(fp)) != EOF) {
            printf("%c", c);
            count++;
        }
        if (count == 0) {
            printf("n/a\n");
            flag = 0;
        }
        if (flag) printf("\n");
        fclose(fp);
#ifdef LOGS
        strcpy(save, name);
        strcat(save, " открыт для чтения");
        logcat(log, save, info);
        strcpy(save, "");
#endif
    }

    return flag;
}

void write_plus(char *name, FILE *log) {
#ifdef LOGS
    char save[200];
#endif
    FILE *fp;
    int flag = 1;
    char str[100];
    scanf("%[^\n]s", str);
    if (!fopen(name, "r")) {
        printf("n/a\n");
#ifdef LOGS
        logcat(log, "вызов функции записи, без успешного чтения файла ранее", error);
        strcpy(save, "");
#endif
        flag = 0;
    }
    if (flag) {
        if (((fp = fopen(name, "a")) == NULL)) {
            printf("n/a\n");
            scanf("%*s");
            flag = 0;
#ifdef LOGS
            strcpy(save, name);
            strcat(save, "Невозможно записать строку в файл");
            logcat(log, save, error);
            strcpy(save, "");

#endif
        }
    }

    if (flag) {
        fputs(str, fp);
        fclose(fp);
#ifdef LOGS
        strcpy(save, name);
        strcat(save, " был изменён, добавили строку");
        logcat(log, save, info);
        strcpy(save, "");
#endif
        read(name, log);
    }
}

void cezar(char *name, int shift, FILE *log) {
#ifdef LOGS
    char save[200];
    char buffer[12];
#endif
    int flag = 1;
    FILE *fp;

    if (flag) {
        if ((fp = fopen(name, "r+")) == NULL) {
            printf("n/a\n");
            scanf("%*s");
            flag = 0;
        }
    }

    if (flag) {
        char c = fgetc(fp);
        while (!feof(fp)) {
            fseek(fp, -1, SEEK_CUR);
            c = c + shift;
            fputc(c, fp);
            fseek(fp, 0, SEEK_CUR);
            c = fgetc(fp);
        }
        fclose(fp);
#ifdef LOGS
        strcpy(save, name);
        strcat(save, " был зашифрован с кодом: ");
        sprintf(buffer, "%u", shift);
        strcat(save, buffer);
        logcat(log, save, info);
        strcpy(save, "");
        strcpy(buffer, "");
#endif
    }
}

void clear(char *name, FILE *log) {
#ifdef LOGS
    char save[200];
#endif
    FILE *fp;
    fp = fopen(name, "w");
    fclose(fp);
#ifdef LOGS
    strcpy(save, name);
    strcat(save, " был очищен");
    logcat(log, save, info);
    strcpy(save, "");
#endif
}

void shifr(FILE *log) {
    struct dirent **namelist;
    int len;
    char dir[100];
    char dir2[100];
    char save[100];
    scanf("%s", dir);
    strcpy(dir2, dir);
    strcpy(save, dir);
    len = scandir(dir, &namelist, NULL, alphasort);
    if (len < 0) {
#ifdef LOGS
        logcat(log, "директории не существует", info);
#endif
        printf("n/a\n");
    } else {
        int flag = 1, shift;
        if (flag) {
            if (scanf("%d", &shift) != 1) {
                printf("n/a\n");
                scanf("%*s");
                flag = 0;
#ifdef LOGS
        logcat(log, "некорректный ключ шифрования", info);
#endif
            }
        }

        if (flag) {
            shift = shift % 256;
            if (shift < 0) {
                shift = 256 + shift;
            }
            if (shift == 0) flag = 0;
        }

        if (flag) {
            while (len--) {
                char *str;
                int n;
                strcat(dir, "/");
                strcat(dir2, "/");
                str = namelist[len]->d_name;
                n = strlen(str);
                if (str[n - 1] == 'c') {
                    strcat(dir, str);
                    cezar(dir, shift, log);
                }
                if (str[n - 1] == 'h') {
                    strcat(dir2, str);
                    clear(dir2, log);
                }
                free(namelist[len]);
                strcpy(dir, save);
                strcpy(dir2, save);
            }
            free(namelist);
            strcpy(dir, "");
            strcpy(dir2, "");
        }
    }
}
