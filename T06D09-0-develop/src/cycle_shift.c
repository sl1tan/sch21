#include <stdio.h>

#define NMAX 10

int input(int *buffer, int *length, int *shift);
void output(int *buffer, int length);
void cycle_shift(int *a, int n, int shift);

int main() {
    int length, data[NMAX], flag = 1, shift;
    if (!input(data, &length, &shift)) {
        flag = 0;
    } else {
        cycle_shift(data, length, shift);
        output(data, length);
    }
    flag++;
    return 0;
}

int input(int *buffer, int *length, int *shift) {
    int flag = 1;
    if (scanf("%d", length) != 1 || *length > NMAX || *length < 1) {
        printf("n/a");
        flag = 0;
    } else {
        for (int *p = buffer; p - buffer < *length; p++) {
            if (p - buffer + 1 == *length) {
                if (scanf("%d", p) != 1) {
                    printf("n/a");
                    flag = 0;
                    break;
                }
            } else {
                if (scanf("%d", p) != 1 && flag != 0) {
                    printf("n/a");
                    flag = 0;
                    break;
                }
            }
        }
        if (scanf("%d", shift) != 1 && flag != 0) {
            printf("n/a");
            flag = 0;
        }
    }
    return flag;
}

void output(int *buffer, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d", buffer[i]);
        if (i != length - 1) {
            printf(" ");
        }
    }
}

void cycle_shift(int *a, int n, int shift) {
    shift = shift % n;
    if (shift > 0) {
        for (int i = shift - 1; i > -1; i--) {
            for (int j = 0; j < n - shift; j++) {
                int temp = a[i + j];
                a[i + j] = a[i + j + 1];
                a[i + j + 1] = temp;
            }
        }
    } else {
        shift = -shift;
        for (int i = -1; i < shift - 1; i++) {
            for (int j = n - shift; j > 0; j--) {
                int temp = a[j + i];
                a[j + i] = a[j + i + 1];
                a[j + i + 1] = temp;
            }
        }
    }
}
