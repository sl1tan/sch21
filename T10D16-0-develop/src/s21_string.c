#include "s21_string.h"

#include <stdio.h>

static char* bef;

int s21_strlen(const char* string) {
    int len = 0;
    while (string[len] != '\0') {
        len++;
    }
    return len;
}

int s21_strcmp(char* string1, char* string2) {
    int flag = 0;
    while (1) {
        if (*string1 > *string2) {
            flag = *string1;
            break;
        }
        if (*string1 < *string2) {
            flag = -(*string2);
            break;
        }
        if ((*string2 == '\0') && (*string1 == *string2)) break;
        string1++;
        string2++;
    }
    return flag;
}

char* s21_strcpy(char* dest, char* src) {
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return dest;
}

char* s21_strcat(char* dest, char* src) {
    while (*dest != '\0') dest++;
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return dest;
}

char* s21_strchr(char* string, char symbol) {
    char* sym = 0;
    while (*string != '\0') {
        if (*string == symbol) sym = string;
        string++;
    }
    return sym;
}

char* s21_strstr(char* string1, char* string2) {
    char* ptr = 0;
    while (*string1 != '\0') {
        char* tmp = string1;
        char* tmp2 = string2;
        while (*tmp == *tmp2) {
            tmp++;
            tmp2++;
            if (*tmp2 == '\0') ptr = string1;
        }
        string1++;
    }
    return ptr;
}

char* s21_strtok(char* string, char* delim) {
    char* token;
    if (string == 0) {
        string = bef;
    }
    if (string == 0) return 0;
    token = string;
    int flag = 1;
    while ((*string != '\0') && (flag)) {
        char* tmp = delim;
        while (*tmp != '\0') {
            if (*string == *tmp) {
                *string = '\0';
                flag = 0;
                break;
            }
            tmp++;
        }
        string++;
    }
    if (flag == 0)
        bef = string;
    else
        bef = 0;
    return token;
}
