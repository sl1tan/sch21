// Coryright 2022 chineser
#include <stdio.h>
#include <stdlib.h>

int input(int **a, int *n, int *flag2);
void output(int *a, int n);
void bubble(int *a, int n);
void swap(int *p1, int *p2);

int main() {
    int *a;
    int flag = 1, n, flag2 = 1;
    if (!input(&a, &n, &flag2)) {
        flag = 0;
        if (flag2 == 1) free(a);
    } else {
        bubble(a, n);
        output(a, n);
        free(a);
    }
    flag++;
    return 0;
}

int input(int **a, int *n, int *flag2) {
    int flag = 1;
    if (scanf("%d", n) != 1 || *n < 1) {
        *flag2 = 0;
        flag = 0;
        printf("n/a");
    } else {
        *a = (int *)malloc(*n * sizeof(int));
        for (int *p = *a; p - *a < *n; p++) {
            if (scanf("%d", p) != 1 && flag != 0) {
                printf("n/a");
                flag = 0;

                break;
            }
        }
    }
    return flag;
}

void output(int *a, int n) {
    for (int i = 0; i < n - 1; i++) {
        printf("%d ", a[i]);
    }
    printf("%d", a[n - 1]);
}

void bubble(int *a, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0, *p = a; j < n - 1 - i; j++, p++) {
            if (*p > *(p + 1)) {
                swap(p, p + 1);
            }
        }
    }
}

void swap(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}
