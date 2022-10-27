// Coryright 2022 chineser
#include <stdio.h>

#define NMAX 10

int input(int *a);
void output(int *a);
void bubble(int *a);
void swap(int *p1, int *p2);

int main() {
    int a[NMAX];
    int flag = 1;
    if (!input(a)) {
        flag = 0;
    } else {
        bubble(a);
        output(a);
    }
    flag++;
    return 0;
}

int input(int *a) {
    int flag = 1;
    for (int *p = a; p - a < NMAX; p++) {
        if (p - a + 1 == NMAX) {
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
    return flag;
}

void output(int *a) {
    for (int i = 0; i < NMAX - 1; i++) {
        printf("%d ", a[i]);
    }
    printf("%d", a[NMAX - 1]);
}

void bubble(int *a) {
    for (int i = 0; i < NMAX - 1; i++) {
        for (int j = 0, *p = a; j < NMAX - 1 - i; j++, p++) {
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
