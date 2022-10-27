#include "list.h"

#include <stdio.h>
#include <stdlib.h>

struct node* init(struct door* door);
struct node* add_door(struct node* elem, struct door* door);
struct node* find_door(int door_id, struct node* root);
struct node* remove_door(struct node* elem, struct node* root);
void destroy(struct node* root);
void output(struct node* root);

struct node* init(struct door* door) {
    struct node* tmp = (struct node*)malloc(sizeof(struct node));
    tmp->data = door;
    tmp->next = NULL;
    return tmp;
}

struct node* add_door(struct node* elem, struct door* door) {
    struct node* p = init(door);
    p->next = elem->next;
    elem->next = p;
    return elem;
}

struct node* find_door(int door_id, struct node* root) {
    struct node* p = root;
    int flag = 0;
    while (p != NULL) {
        if (p->data->id == door_id) {
            flag = 1;
            break;
        }
        p++;
    }
    if (flag == 0) p = root;
    return p;
}

struct node* remove_door(struct node* elem, struct node* root) {
    struct node* p = elem;
    struct node* head = root;
    if (elem != NULL) {
        if (elem == root) {
            free(elem);
            return p->next;
        }
        struct node* next = p->next;
        while (head->next != elem) {
            head++;
        }
        struct node* prev = head;
        prev->next = next;
        free(elem);
    }
    return root;
}

void destroy(struct node* root) {
    struct node* _Head = root;
    while (_Head != 0) {
        struct node* tmp = _Head;
        _Head = _Head->next;
        free(tmp);
    }
}
void output(struct node* root) {
    struct node* tmp = root;
    while (tmp != NULL) {
        printf("%d %d\n", tmp->data->id, tmp->data->status);
        tmp = tmp->next;
    }
}
