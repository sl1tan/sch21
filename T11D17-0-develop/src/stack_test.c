#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

int main() {
    stack *stk = init();
    printf("Testing push:\n");
    for (int i = 0; i < 6; i++) {
        push(&stk, i);
    }
    stack_out(stk);
    if (stk->next != NULL) {
        printf("\nSUCCESS");
    } else {
        printf("\nFAIL");
    }
    printf("\nTesting pop:\n");
    int t = stk->door;
    for (int i = 0; i < 5; i++) {
        pop(&stk);
    }
    stack_out(stk);
    if (t != stk->door) {
        printf("\nSUCCESS\n");
    } else {
        printf("\nFAIL\n");
    }
    destroy(&stk);
}
