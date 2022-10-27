// Coryright 2022 chineser
#include <math.h>
#include <stdio.h>
#define NMAX 30

int input(int *a, int *n);
double mean(int *a, int n);
double variance(int *a, int n);
int search(int *a, int n);

int main() {
    int n, data[NMAX];
    int flag = 1;
    if (!input(data, &n)) {
        flag = 0;
    } else {
        printf("%d", search(data, n));
    }
    flag++;
    return 0;
}

int input(int *a, int *n) {
    int flag = 1;
    if (scanf("%d", n) != 1 || *n > NMAX || *n < 1) {
        printf("n/a");
        flag = 0;
    } else {
        for (int *p = a; p - a < *n; p++) {
            if (scanf("%d", p) != 1 && flag != 0) {
                printf("n/a");
                flag = 0;
            }
        }
    }
    return flag;
}

double mean(int *a, int n) {
    double mean = 0;
    double probability = 1 / (double)n;
    for (int *p = a; p - a < n; p++) mean += (double)*p * probability;
    return mean;
}

double variance(int *a, int n) {
    double mean = 0, square_mean = 0, variance = 0;
    double probability = 1 / (double)n;
    for (int *p = a; p - a < n; p++) {
        mean += (double)*p * probability;
        square_mean += (double)(*p * *p) * probability;
    }
    variance = square_mean - mean * mean;
    return variance;
}

int search(int *a, int n) {
    double mean_v = mean(a, n);
    double variance_v = variance(a, n);
    for (int *p = a; p - a < n; p++) {
        if ((*p % 2 != 0) || (*p == 0) || ((double)*p < mean_v) ||
            ((double)*p > mean_v + 3 * sqrt(variance_v))) {
            continue;
        }
        return *p;
    }
    return 0;
}
