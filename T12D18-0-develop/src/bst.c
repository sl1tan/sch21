#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

t_btree *bstree_create_node(int item) {
    t_btree *tmp = (t_btree*)malloc(sizeof(t_btree));
    tmp->left = tmp->right = NULL;
    tmp->item = item;
    return tmp;
}

void freemem(t_btree *tree) {
  if (tree != NULL) {
    freemem(tree->left);
    freemem(tree->right);
    free(tree);
  }
}

void bstree_insert(t_btree** root, int item, int (*cmpf)(int, int)) {
    if ((*root) == NULL) *root = bstree_create_node(item);
    if (cmpf((*root)->item, item) == 1) {
        bstree_insert(&(*root)->left, item, cmpf);
    }
    if (cmpf((*root)->item, item) == -1) {
        bstree_insert(&(*root)->right, item, cmpf);
    }
}

int st(int a, int b) {
    int st;
    if (a > b) {
        st = 1;
    } else if (a < b) {
        st = -1;
    } else {
        st = 0;
    }
    return st;
}
