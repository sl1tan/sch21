#include <stdio.h>

int maximum(int a, int b);

int maximum(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}

int main() {
    int inp1, inp2;
    char c;
    if (scanf("%d", &inp1) == 1 && scanf("%d", &inp2) == 1) {
        scanf("%c", &c);
        if (c == '\0' || c == '\n' || c == ' ') {
            int max = maximum(inp1, inp2);
            printf("%d", max);
        } else
            printf("n/a");
    } else
        printf("n/a");
    return 0;
}