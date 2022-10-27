// Coryright 2022 chineser
#include <stdio.h>

#define NMAX 10

int input(int *a);
void output(int *a);
void swap(int *p1, int *p2);
void quicksort(int *l, int *r);
void sift_down(int *numbers, int root, int bottom);
void heap_sort(int *numbers, int array_size);

int main() {
    int a[NMAX];
    int flag = 1;
    if (!input(a)) {
        flag = 0;
    } else {
        heap_sort(a, NMAX);
        output(a);
        printf("\n");
        quicksort(a, a + NMAX);
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

void swap(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void quicksort(int *l, int *r) {
    if (r - l <= 1) return;
    int z = *(l + (r - l) / 2);
    int *ll = l, *rr = r - 1;
    while (ll <= rr) {
        while (*ll < z) ll++;
        while (*rr > z) rr--;
        if (ll <= rr) {
            swap(ll, rr);
            ll++;
            rr--;
        }
    }
    if (l < rr) quicksort(l, rr + 1);
    if (ll < r) quicksort(ll, r);
}

void sift_down(int *numbers, int root, int bottom) {
    int maxChild;
    int done = 0;

    while ((root * 2 <= bottom) && (!done)) {
        if (root * 2 == bottom)
            maxChild = root * 2;

        else if (numbers[root * 2] > numbers[root * 2 + 1])
            maxChild = root * 2;
        else
            maxChild = root * 2 + 1;

        if (numbers[root] < numbers[maxChild]) {
            int temp = numbers[root];
            numbers[root] = numbers[maxChild];
            numbers[maxChild] = temp;
            root = maxChild;
        } else {
            done = 1;
        }
    }
}

void heap_sort(int *numbers, int array_size) {
    for (int i = (array_size / 2); i >= 0; i--) sift_down(numbers, i, array_size - 1);

    for (int i = array_size - 1; i >= 1; i--) {
        int temp = numbers[0];
        numbers[0] = numbers[i];
        numbers[i] = temp;
        sift_down(numbers, 0, i - 1);
    }
}
