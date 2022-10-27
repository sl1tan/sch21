#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

stack *init() {
    stack *temp = NULL;
    return temp;
}

void push(stack **head, int val) {
    stack *tmp = (stack *)malloc(sizeof(stack));
    tmp->door = val;
    if (*head == NULL) {
        *head = tmp;
    } else {
        tmp->next = *head;
        *head = tmp;
    }
}

void pop(stack **head) {
    stack *del = (*head)->next;
    free(*head);
    *head = del;
}
void destroy(stack **head) {
    while (*head != NULL) {
        stack *temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

void stack_out(stack *head) {
    printf("OUT: ");
    stack *p = head;
    while (p) {
        printf("%d", p->door);
        if (p->next != NULL) printf(" ");
        p = p->next;
    }
}
