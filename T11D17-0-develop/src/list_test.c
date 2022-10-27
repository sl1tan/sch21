#include "list.h"

#include <stdio.h>
#include <stdlib.h>
void add_door_tests();
void remove_door_tests();

int main() {
    add_door_tests();
    printf("\n-----------------\n\n");
    remove_door_tests();
    return 0;
}

void add_door_tests() {
    struct door door[2];
    door[0].id = 1;
    door[0].status = 0;
    struct node *test = init(&door[0]);
    door[1].id = 2;
    door[1].status = 1;
    printf("Testing add:\n");
    printf("СПИСОК ДО:\n");
    output(test);
    add_door(test, &door[1]);
    printf("СПИСОК ПОСЛЕ:\n");
    output(test);
    find_door(2, test);
    destroy(test);
}

void remove_door_tests() {
    struct door door[2];
    door[0].id = 3;
    door[0].status = 1;
    struct node *test = init(&door[0]);
    door[1].id = 4;
    door[1].status = 0;
    add_door(test, &door[1]);
    printf("Testing remove:\n");
    printf("СПИСОК ДО:\n");
    output(test);
    remove_door(test->next, test);
    printf("СПИСОК ПОСЛЕ:\n");
    output(test);
    destroy(test);
}
