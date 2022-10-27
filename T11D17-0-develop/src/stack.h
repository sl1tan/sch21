#ifndef SRC_STACK_H_
#define SRC_STACK_H_

typedef struct dynamic_struct {
    int door;
    struct dynamic_struct *next;
} stack;

stack *init();

void push(stack **head, int val);
void pop(stack **head);
void destroy(stack **head);
void stack_out(stack *head);

#endif  // SRC_STACK_H_
