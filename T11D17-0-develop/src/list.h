#ifndef SRC_LIST_H_
#define SRC_LIST_H_
struct door {
    int id;
    int status;
};
typedef struct node {
    struct door* data;
    struct node* next;
} node;
struct node* init(struct door* door);
struct node* add_door(struct node* elem, struct door* door);
struct node* find_door(int door_id, struct node* root);
struct node* remove_door(struct node* elem, struct node* root);
void destroy(struct node* root);
void output(struct node* root);
#endif  // SRC_LIST_H_
