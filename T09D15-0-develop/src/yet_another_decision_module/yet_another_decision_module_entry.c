#include <stdio.h>
#include <stdlib.h>

#include "../data_libs/data_io.h"
#include "decision.h"

int main() {
    double *data;
    int n, flag = 1;

    if (scanf("%d", &n) == 1 && n > 0) {
        data = (double *)malloc(n * sizeof(double));
    } else {
        flag = 0;
        printf("n/a");
    }

    if (flag == 1) {
        input(data, n, &flag);
        if (flag == 0) free(data);
    }

    if (flag == 1) {
        if (make_decision(data, n)) {
            printf("YES");
        } else {
            printf("NO");
        }
    }

    if (flag == 1) free(data);
    return 0;

    if (make_decision(data, n))
        printf("YES");
    else
        printf("NO");
}
