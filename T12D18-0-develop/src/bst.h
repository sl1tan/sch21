#ifndef SRC_BST_H_
#define SRC_BST_H_

typedef struct s_btree {
    struct s_btree *left;
    struct s_btree *right;
    int item;
} t_btree;

t_btree *bstree_create_node(int item);
void freemem(t_btree *tree);
void bstree_insert(t_btree** root, int item, int (*cmpf)(int, int));
int st(int a, int b);

#endif  // SRC_BST_H_
