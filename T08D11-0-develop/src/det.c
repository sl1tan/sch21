// Copyright 2022 chineser
#include <stdio.h>
#include <stdlib.h>

double **matr(double **a, int n, int x);
double det(double **a, int n);

int main() {
    int n = 0, raw, column, flag = 1;
    double **a = NULL;
    if (scanf("%d %d", &raw, &column) != 2) {
        printf("n/a");
        flag = 0;
    } else {
        if (raw != column) {
            printf("n/a");
            flag = 0;
        } else {
            n = raw;
        }
    }

    if (flag == 1) {
        a = (double **)malloc(n * sizeof(double *));
        for (int i = 0; i < n; ++i) a[i] = (double *)malloc(n * sizeof(double));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (scanf("%le", &a[i][j]) != 1) {
                    flag = 0;
                }
            }
            if (flag == 0) {
                printf("n/a");
                break;
            }
        }

        if (flag == 0) {
            for (int i = 0; i < n; i++) {
                free(a[i]);
            }
            free(a);
        }
    }

    if (flag == 1) {
        printf("%.6lf\n", det(a, n));
        for (int i = 0; i < n; i++) {
            free(a[i]);
        }
        free(a);
    }
    flag++;
}

double **matr(double **a, int n, int x) {
    double **res = (double **)malloc((n - 1) * sizeof(int *));
    for (int i = 0; i < n - 1; ++i) res[i] = (double *)malloc((n - 1) * sizeof(double));
    for (int i = 1; i < n; ++i)
        for (int j = 0, k = 0; j < n; ++j, ++k) {
            if (j == x) {
                --k;
                continue;
            }
            res[i - 1][k] = a[i][j];
        }
    return res;
}

double det(double **a, int n) {
    if (n == 1) return a[0][0];
    if (n == 2) return (a[1][1] * a[0][0]) - (a[0][1] * a[1][0]);
    double ans = 0;
    int sig = 1;
    double **su;
    for (int i = 0; i < n; ++i) {
        su = matr(a, n, i);
        ans += (sig * a[0][i] * det(su, n - 1));
        sig *= -1;
        for (int i = 0; i < n - 1; i++) {
            free(su[i]);
        }
        free(su);
    }
    return ans;
}
