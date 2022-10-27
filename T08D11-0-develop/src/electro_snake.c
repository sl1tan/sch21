// Coryright 2022 chineser
#include <stdio.h>
#include <stdlib.h>
/*
    1 6 7
    2 5 8
    3 4 9
*/
void sort_vertical(int *matrix, int n, int m, int **result_matrix);

/*
    1 2 3
    6 5 4
    7 8 9
*/
void sort_horizontal(int *matrix, int n, int m, int **result_matrix);

void output_arr_dynamic(int raw, int column, int **arr);
int **dynamic_1(int raw, int column);
void input_arr_dynamic(int raw, int column, int **arr, int *flag);
void newArr(int n, int m, int **matrix, int **arr);

int main() {
    int **matrix, **result, *sorted;
    int n, m;
    int flag = 1;

    if (scanf("%d%d", &n, &m) != 2 || n < 1 || m < 1) {
        printf("n/a");
        flag = 0;
    }
    if (flag == 1) {
        matrix = dynamic_1(n, m);
        input_arr_dynamic(n, m, matrix, &flag);
        if (flag == 0) {
            for (int i = 0; i < n; i++) {
                free(matrix[i]);
            }
            free(matrix);
        }
    }

    if (flag == 1) {
        result = dynamic_1(n, m);
        newArr(n, m, matrix, &sorted);
        sort_vertical(sorted, n, m, result);
        output_arr_dynamic(n, m, result);
        printf("\n\n");
        sort_horizontal(sorted, n, m, result);
        output_arr_dynamic(n, m, result);
        for (int i = 0; i < n; i++) {
            free(matrix[i]);
        }
        free(matrix);

        for (int i = 0; i < n; i++) {
            free(result[i]);
        }
        free(result);
        free(sorted);
    }
    return 0;
}

void sort(int *array, int len) {
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
            }
        }
    }
}

void sort_vertical(int *matrix, int n, int m, int **result_matrix) {
    int k = 0;
    for (int i = 0; i < m; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < n; j++) {
                result_matrix[j][i] = matrix[k++];
            }
        } else {
            for (int j = n - 1; j >= 0; j--) {
                result_matrix[j][i] = matrix[k++];
            }
        }
    }
}

void sort_horizontal(int *matrix, int n, int m, int **result_matrix) {
    int k = -1;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < m; j++) {
                result_matrix[i][j] = matrix[++k];
            }
        } else {
            for (int j = m - 1; j >= 0; j--) {
                result_matrix[i][j] = matrix[++k];
            }
        }
    }
}

void output_arr_dynamic(int raw, int column, int **arr) {
    for (int i = 0; i < raw; i++) {
        for (int j = 0; j < column; j++) {
            printf("%d", arr[i][j]);
            if (j != column - 1) printf(" ");
        }
        if (i != raw - 1) printf("\n");
    }
}

void input_arr_dynamic(int raw, int column, int **arr, int *flag) {
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

void newArr(int n, int m, int **matrix, int **arr) {
    int *arr_2 = (int *)malloc(n * m * sizeof(int));
    int k = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            arr_2[++k] = matrix[i][j];
        }
    }
    sort(arr_2, n * m);
    *arr = arr_2;
}

int **dynamic_1(int raw, int column) {
    int **arr = malloc(raw * sizeof(int *));
    for (int i = 0; i < raw; i++) {
        arr[i] = (int *)malloc(column * sizeof(int));
    }
    return arr;
}
