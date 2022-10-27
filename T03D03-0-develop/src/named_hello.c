#include <stdio.h>

int main() {
    int name;
    if (scanf("%d", &name) == 1) {
        printf("Hello, %d!", name);
    }
    else printf("n/a");
    return 0;
}