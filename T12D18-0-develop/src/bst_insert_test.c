#include <stdio.h>
#include "bst.h"

int main() {
    t_btree *root = NULL;
    root = bstree_create_node(21);
    printf("current: 21 == %d\n", root->item);
    bstree_insert(&root, 42, st);
    printf("right  : 42 == %d\n", root->right->item);
    bstree_insert(&root, 13, st);
    printf("left   : 13 == %d\n", root->left->item);
    freemem(root);
    return 0;
}
