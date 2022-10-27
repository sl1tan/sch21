#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_

int s21_strlen(const char* string);
int s21_strcmp(char* string1, char* string2);
char* s21_strcpy(char* dest, char* src);
char* s21_strcat(char* dest, char* src);
char* s21_strchr(char* string, char symbol);
char* s21_strstr(char* string1, char* string2);
char* s21_strtok(char* string, char* delim);

void s21_strlen_test();
void s21_strcmp_test();
void s21_strcpy_test();
void s21_strcat_test();
void s21_strchr_test();
void s21_strstr_test();
void s21_strtok_test();

#endif  //  SRC_S21_STRING_H_
