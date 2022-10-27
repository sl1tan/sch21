#include <stdio.h>
#include <stdlib.h>

#include "../data_libs/data_io.h"
#include "../data_libs/data_stat.h"
#include "../data_module/data_process.h"
#include "../yet_another_decision_module/decision.h"

int main() {
    double *data, *data2;
    int n, flag = 1;

    printf("LOAD DATA...\n");
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
        data2 = (double *)malloc(n * sizeof(double));
        for (int i = 0; i < n; i++) {
            data2[i] = data[i];
        }
        printf("RAW DATA:\n\t");
        output(data, n);

        printf("\nNORMALIZED DATA:\n\t");
        normalization(data, n);
        output(data, n);

        printf("\nSORTED NORMALIZED DATA:\n\t");
        bubble(data, n);
        output(data, n);

        printf("\nFINAL DECISION:\n\t");
        make_decision(data2, n);
        output(data2, n);
    }

    if (flag == 1) {
        free(data);
        free(data2);
    }
    return 0;
}
