#include <stdio.h>
#include <stdlib.h>

#define RAW_MAX 100
#define COLUMN_MAX 100

void choose_mode(int* flag, int static_arr[100][100]);
void input_raw_and_col(int* raw, int* column, int* flag);
void input_arr_static(int raw, int column, int arr[100][100], int* flag);
void output_arr_static(int raw, int column, int arr[100][100]);
void output_arr_dynamic(int raw, int column, int** arr);
void input_arr_dynamic(int raw, int column, int** arr, int* flag);

int** dynamic_1(int raw, int column);
int** dynamic_2(int raw, int column);
int** dynamic_3(int raw, int column);

int main() {
    int static_arr[RAW_MAX][COLUMN_MAX];
    int flag = 1;
    choose_mode(&flag, static_arr);
    flag++;
    return 0;
}

void choose_mode(int* flag, int static_arr[100][100]) {
    int mode, raw, column;
    int** dynamic;
    if (scanf("%d", &mode) != 1 || mode > 4 || mode < 1) {
        printf("n/a");
        *flag = 0;
    } else {
        switch (mode) {
            case 1:
                input_raw_and_col(&raw, &column, flag);
                if (*flag == 1) {
                    input_arr_static(raw, column, static_arr, flag);
                }
                if (*flag == 1) {
                    output_arr_static(raw, column, static_arr);
                }
                break;
            case 2:
                input_raw_and_col(&raw, &column, flag);
                if (*flag == 1) {
                    dynamic = dynamic_1(raw, column);
                }
                if (*flag == 1) {
                    input_arr_dynamic(raw, column, dynamic, flag);
                    if (*flag == 0) {
                        for (int i = 0; i < raw; i++) {
                            free(dynamic[i]);
                        }
                        free(dynamic);
                    }
                }
                if (*flag == 1) {
                    output_arr_dynamic(raw, column, dynamic);
                    for (int i = 0; i < raw; i++) {
                        free(dynamic[i]);
                    }
                    free(dynamic);
                }
                break;
            case 3:
                input_raw_and_col(&raw, &column, flag);
                if (*flag == 1) {
                    dynamic = dynamic_2(raw, column);
                }
                if (*flag == 1) {
                    input_arr_dynamic(raw, column, dynamic, flag);
                    if (*flag == 0) free(dynamic);
                }
                if (*flag == 1) {
                    output_arr_dynamic(raw, column, dynamic);
                    free(dynamic);
                }
                break;
            case 4:
                input_raw_and_col(&raw, &column, flag);
                if (*flag == 1) {
                    dynamic = dynamic_3(raw, column);
                }
                if (*flag == 1) {
                    input_arr_dynamic(raw, column, dynamic, flag);
                    if (*flag == 0) free(dynamic);
                }
                if (*flag == 1) {
                    output_arr_dynamic(raw, column, dynamic);
                    free(dynamic);
                }
                break;
        }
    }
}

void input_raw_and_col(int* raw, int* column, int* flag) {
    if (scanf("%d%d", raw, column) != 2 || *raw < 1 || *raw > RAW_MAX || *column < 1 ||
        *column > COLUMN_MAX) {
        printf("n/a");
        *flag = 0;
    }
}

void input_arr_static(int raw, int column, int arr[100][100], int* flag) {
    for (int i = 0; i < raw; i++) {
        for (int j = 0; j < column; j++) {
            if (scanf("%d", &arr[i][j]) != 1) {
                *flag = 0;
            }
        }
        if (*flag == 0) {
            printf("n/a");
            break;
        }
    }
}

void output_arr_static(int raw, int column, int arr[100][100]) {
    for (int i = 0; i < raw; i++) {
        for (int j = 0; j < column; j++) {
            printf("%d", arr[i][j]);
            if (j != column - 1) printf(" ");
        }
        if (i != raw - 1) printf("\n");
    }
}

void output_arr_dynamic(int raw, int column, int** arr) {
    for (int i = 0; i < raw; i++) {
        for (int j = 0; j < column; j++) {
            printf("%d", arr[i][j]);
            if (j != column - 1) printf(" ");
        }
        if (i != raw - 1) printf("\n");
    }
}

void input_arr_dynamic(int raw, int column, int** arr, int* flag) {
    for (int i = 0; i < raw; i++) {
        for (int j = 0; j < column; j++) {
            if (scanf("%d", &arr[i][j]) != 1) {
                *flag = 0;
            }
        }
        if (*flag == 0) {
            printf("n/a");
            break;
        }
    }
}

int** dynamic_1(int raw, int column) {
    int** arr = malloc(raw * sizeof(int*));
    for (int i = 0; i < raw; i++) {
        arr[i] = (int*)malloc(column * sizeof(int));
    }
    return arr;
}

int** dynamic_2(int raw, int column) {
    int** arr = (int**)malloc(raw * sizeof(int*));
    int* arr2 = (int*)malloc(raw * column * sizeof(int));
    for (int i = 0; i < raw; i++) {
        arr[i] = &arr2[i * column];
    }
    free(arr2);
    return arr;
}

int** dynamic_3(int raw, int column) {
    int** arr = (int**)malloc(raw * sizeof(int*) + raw * column * sizeof(int));
    int* pointer = (int*)(arr + raw);
    for (int i = 0; i < raw; i++) {
        arr[i] = (pointer + column * i);
    }
    return arr;
}
