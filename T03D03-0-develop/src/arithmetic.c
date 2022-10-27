#include <stdio.h>

int main() {
    int sum, diff, mult, quot, flag, num1, num2;
    char c;
    if (scanf("%d", &num1) == 1 && scanf("%d", &num2) == 1) {
        scanf("%c", &c);
        if (c == '\n' || c == '\0' || c == ' ') {
            sum = num1 + num2;
            diff = num1 - num2;
            mult = num1 * num2;
            if (num2 == 0)
                flag = 1;
            else
                quot = num1 / num2;
            if (flag == 1)
                printf("%d %d %d n/a", sum, diff, mult);
            else
                printf("%d %d %d %d", sum, diff, mult, quot);
        } else
            printf("n/a");
    } else
        printf("n/a");
    return 0;
}