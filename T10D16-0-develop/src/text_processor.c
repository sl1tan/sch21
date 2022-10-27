#include <stdio.h>

#include "s21_string.h"

void processor(char* str, int n);

int main(int argc, char** argv) {
    int flag, n;
    char str[100];

    flag = 1;

    if (argc != 2 || (argv[1][0] != '-' || argv[1][1] != 'w')) {
        flag = 0;
    }
    if (flag == 1) {
        if (scanf("%d", &n) != 1 || n < 2) flag = 0;
        if (flag == 1) {
            scanf("%c", &str[0]);
            for (int i = 0; i < 100; i++) {
                scanf("%c", &str[i]);
                if (str[i] == '\n') {
                    str[i] = '\0';
                    break;
                }
            }
            if (flag == 1) {
                processor(str, n);
            }
        }
    }
    if (flag == 0) {
        printf("n/a");
    }
    return flag;
}

void processor(char* str, int n) {
    char *p = s21_strtok(str, " ,."), buffer[100] = "";
    int current = 0, word = 0, len, flag = 1;
    while (p != NULL) {
        len = s21_strlen(p);
        if (current + len < n) {
            if (flag == 1) {
                if (current != 0) {
                    buffer[current++] = ' ';
                    buffer[current] = '\0';
                }
                s21_strcat(buffer, p);
            } else {
                s21_strcpy(buffer, p);
                flag = 1;
            }
            current += len;
            flag = 1;
        } else {
            if (len < n) {
                if (flag == 1) printf("%s\n", buffer);
                s21_strcpy(buffer, p);
                current = len;
                flag = 1;
            } else {
                if (flag == 1 && current != 0) buffer[current++] = ' ';
                for (int i = current; i < n - 1; i++) {
                    buffer[i] = p[word++];
                }
                buffer[n - 1] = '-';
                buffer[n] = '\0';
                current = 0;
                printf("%s\n", buffer);
                flag = 0;
                for (int i = word, j = 0; i < len; i++) {
                    p[j++] = p[i];
                }
                p[len - word] = '\0';
                word = 0;
                current = 0;
            }
        }
        if (flag == 1) {
            p = s21_strtok(NULL, " ,.");
        }
    }
    printf("%s", buffer);
}
