// Coryright 2022 chineser
#include <stdio.h>
#define NMAX 10

long long int input(long long int *a, long long int *n);
void output(long long int *a, long long int n);
void squaring(long long int *a, long long int n);

int main() {
    long long int n, data[NMAX];
    int flag = 1;
    if (!input(data, &n)) {
        flag = 0;
    } else {
        squaring(data, n);
        output(data, n);
    }
    flag++;
    return 0;
}

long long int input(long long int *a, long long int *n) {
    int flag = 1;
    if (scanf("%lld", n) != 1 || *n > NMAX || *n < 1) {
        printf("n/a");
        flag = 0;
    } else {
        for (long long int *p = a; p - a < *n; p++) {
            if (scanf("%lld", p) != 1 && flag != 0) {
                printf("n/a");
                flag = 0;
            }
        }
    }
    return flag;
}

void output(long long int *a, long long int n) {
    for (int i = 0; i < n; i++) {
        printf("%lld", a[i]);
        if (i != n - 1) {
            printf(" ");
        }
    }
}

void squaring(long long int *a, long long int n) {
    for (long long int *p = a; p - a < n; p++) {
        *p *= *p;
    }
}
