#include "data_stat.h"

double max(double *data, int n) {
    double max = *data;
    for (int i = 0; i < n; i++) {
        if (data[i] > max) {
            max = data[i];
        }
    }
    return max;
}

double min(double *data, int n) {
    double min = *data;
    for (int i = 0; i < n; i++) {
        if (data[i] < min) {
            min = data[i];
        }
    }
    return min;
}

double mean(double *data, int n) {
    double mean = 0;
    for (int i = 0; i < n; i++) {
        mean += data[i];
    }
    return mean / (double)n;
}

double variance(double *data, int n, double mean) {
    double var = 0;
    for (int i = 0; i < n; i++) {
        var += ((data[i] - mean) * (data[i] - mean));
    }
    return var / (double)n;
}

void bubble(double *a, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (double j = 0, *p = a; j < n - 1 - i; j++, p++) {
            if (*p > *(p + 1)) {
                swap(p, p + 1);
            }
        }
    }
}

void swap(double *p1, double *p2) {
    double temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

