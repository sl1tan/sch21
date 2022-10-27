#include "s21_string.h"

#include <stdio.h>

void s21_strlen_test() {
    printf("Tests s21_strlen: \n");
    int len = 0;
    printf("INPUT: 12345\n");
    len = s21_strlen("12345");
    printf("OUTPUT: %d\n", len);
    len == 5 ? printf("SUCCESS\n") : printf("FAIL\n");
    printf("INPUT: \\0\n");
    len = s21_strlen("\0");
    printf("OUTPUT: %d\n", len);
    len == 0 ? printf("SUCCESS\n") : printf("FAIL\n");
    printf("INPUT: \n");
    len = s21_strlen("");
    printf("OUTPUT: %d\n", len);
    len == 0 ? printf("SUCCESS\n") : printf("FAIL\n");
}

void s21_strcmp_test() {
    printf("Tests s21_strcmp: \n");
    int status = 0;
    printf("INPUT: School School\n");
    status = s21_strcmp("School", "School");
    printf("OUTPUT: %d\n", status);
    status == 0 ? printf("SUCCESS\n") : printf("FAIL\n");
    printf("INPUT:  hello\n");
    status = s21_strcmp("", "hello");
    printf("OUTPUT: %d\n", status);
    status < 0 ? printf("SUCCESS\n") : printf("FAIL\n");
    printf("INPUT: 123 1\n");
    status = s21_strcmp("123", "1");
    printf("OUTPUT: %d\n", status);
    status > 0 ? printf("SUCCESS\n") : printf("FAIL\n");
}

void s21_strcpy_test() {
    printf("Tests s21_strcpy: \n");
    char str1[] = "12345";
    char str2[] = "msk";
    char str3[] = "abob\0a";
    printf("INPUT: %s %s\n", str1, str2);
    s21_strcpy(str1, str2);
    printf("OUTPUT: %s %s\n", str1, str2);
    s21_strcmp(str1, str2) == 0 ? printf("SUCCESS\n") : printf("FAIL\n");
    printf("INPUT:%s %s\n", str3, str1);
    s21_strcpy(str3, str1);
    printf("OUTPUT: %s %s\n", str3, str1);
    s21_strcmp(str3, str1) == 0 ? printf("SUCCESS\n") : printf("FAIL\n");
    printf("INPUT:%s %s\n", str2, str3);
    s21_strcpy(str2, str3);
    printf("OUTPUT: %s %s\n", str2, str3);
    s21_strcmp(str2, str3) == 0 ? printf("SUCCESS\n") : printf("FAIL\n");
}

void s21_strcat_test() {
    printf("Tests s21_strcat: \n");
    char str1[] = "School";
    char str2[] = "21";
    char str3[] = "aboba\0q";
    char str4[50];
    s21_strcpy(str4, str1);
    printf("INPUT: %s %s\n", str1, str2);
    s21_strcat(str4, str2);
    printf("OUTPUT:%s\n", str4);
    s21_strcmp(str4, "School21") == 0 ? printf("SUCCESS\n") : printf("FAIL\n");

    printf("INPUT:%s %s\n", str4, str1);
    s21_strcat(str4, str1);
    printf("OUTPUT:%s\n", str4);
    s21_strcmp(str4, "School21School") == 0 ? printf("SUCCESS\n") : printf("FAIL\n");

    printf("INPUT:%s %s\n", str4, str3);
    s21_strcat(str4, str3);
    printf("OUTPUT:%s\n", str4);
    s21_strcmp(str4, "School21Schoolaboba") == 0 ? printf("SUCCESS\n") : printf("FAIL\n");
}

void s21_strchr_test() {
    printf("Tests s21_strchr: \n");
    char str1[] = "School";
    char str2[] = "21";
    char str3[] = "aboba\0q";
    char t = 'o', *result;
    printf("INPUT: %s %c\n", str1, t);
    if (s21_strchr(str1, t) != NULL) {
        result = s21_strchr(str1, t);
        printf("OUTPUT:%d\n", (int)(result - str1));
        printf("SUCCESS\n");
    } else {
        printf("NULL\n");
        printf("FAIL\n");
    }
    printf("INPUT: %s %c\n", str2, t);
    if (s21_strchr(str2, t) != NULL) {
        result = s21_strchr(str2, t);
        printf("OUTPUT:%d\n", (int)(result - str2));
        printf("SUCCESS\n");
    } else {
        printf("NULL\n");
        printf("FAIL\n");
    }
    printf("INPUT: %s %c\n", str3, t);
    if (s21_strchr(str3, t) != NULL) {
        result = s21_strchr(str3, t);
        printf("OUTPUT:%d\n", (int)(result - str3));
        printf("SUCCESS\n");
    } else {
        printf("NULL\n");
        printf("FAIL\n");
    }
}

void s21_strstr_test() {
    printf("Tests s21_strstr: \n");
    char str1[] = "School";
    char str2[] = "21";
    char str3[] = "Aboba";
    char str4[] = "that me hello";
    char str5[] = "me";
    char *result;
    printf("INPUT: %s %s\n", str1, str2);
    if (s21_strstr(str1, str2) != NULL) {
        result = s21_strstr(str1, str2);
        printf("OUTPUT:%d\n", (int)(result - str1));
        printf("SUCCESS\n");
    } else {
        printf("NULL\n");
        printf("FAIL\n");
    }
    printf("INPUT: %s %s\n", str3, str1);
    if (s21_strstr(str3, str1) != NULL) {
        result = s21_strstr(str3, str1);
        printf("OUTPUT:%d\n", (int)(result - str3));
        printf("SUCCESS\n");
    } else {
        printf("NULL\n");
        printf("FAIL\n");
    }
    printf("INPUT: %s %s\n", str1, str3);
    if (s21_strstr(str1, str3) != NULL) {
        result = s21_strstr(str1, str3);
        printf("OUTPUT:%d\n", (int)(result - str1));
        printf("SUCCESS\n");
    } else {
        printf("NULL\n");
        printf("FAIL\n");
    }
    printf("INPUT: %s %s\n", str4, str5);
    if (s21_strstr(str4, str5) != NULL) {
        result = s21_strstr(str4, str5);
        printf("OUTPUT:%s\n", result);
        printf("SUCCESS\n");
    } else {
        printf("NULL\n");
        printf("FAIL\n");
    }
}

void s21_strtok_test() {
    printf("Tests  s21_strtok: \n");
    char str1[] = "PEACE, FRIEND. GUM";
    char str2[] = ",.";
    char str3[] = "PEACE, FRIEND. GUM";
    char str4[] = "I";
    char str5[] = "PEACE, FRIEND. GUM";
    char str6[] = "\0";
    printf("INPUT: %s %s\n", str1, str2);
    char *result = s21_strtok(str1, str2);
    if (result != NULL) {
        printf("OUTPUT:\n");
        while (result != NULL) {
            printf("%s\n", result);
            result = s21_strtok(NULL, str2);
        }
        printf("SUCCESS\n");
    } else {
        printf("NULL\n");
        printf("FAIL\n");
    }
    printf("INPUT: %s %s\n", str3, str4);
    result = s21_strtok(str3, str4);
    if (result != NULL) {
        printf("OUTPUT:\n");
        while (result != NULL) {
            printf("%s\n", result);
            result = s21_strtok(NULL, str4);
        }
        printf("SUCCESS\n");
    } else {
        printf("NULL\n");
        printf("FAIL\n");
    }
    printf("INPUT: %s %s\n", str5, str6);
    result = s21_strtok(str5, str6);
    if (result != NULL) {
        printf("OUTPUT:\n");
        while (result != NULL) {
            printf("%s\n", result);
            result = s21_strtok(NULL, str6);
        }
        printf("SUCCESS\n");
    } else {
        printf("NULL\n");
        printf("FAIL\n");
    }
}
