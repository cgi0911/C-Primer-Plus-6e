#ifndef BST_H
#define BST_H

#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

typedef enum {IN_ORDER, PRE_ORDER, POST_ORDER} TravOrder;

extern Node *new_node (int in_data);

extern Node *insert_to_bst (Node* root, int in_data);

extern void print_bst (Node *root, TravOrder order);

extern Node *gen_rand_bst (int n, int r);

#endif /* BST_H */