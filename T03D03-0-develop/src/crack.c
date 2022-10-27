#include <stdio.h>

int main() {
    float x, y;
    char c;

    if (scanf("%f", &x) == 1 && scanf("%f", &y) == 1) {
        scanf("%c", &c);
        if (c == '\n' || c == '\0' || c == ' ') {
            if (x * x + y * y < 25)
                printf("GOTCHA");
            else
                printf("MISS");
        } else
            printf("n/a");
    } else
        printf("n/a");
    return 0;
}