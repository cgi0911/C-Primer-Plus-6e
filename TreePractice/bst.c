#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

Node *new_node (int in_data) {
    Node *ret = (Node *) malloc (sizeof (Node));
    ret->data = in_data;
    ret->left = NULL;
    ret->right = NULL;
    return ret;
}


Node *insert_to_bst (Node *root, int in_data) {
    Node *nnode = new_node (in_data);
    
    if (root == NULL) {
        root = nnode;
        return root;
    }
    
    else {
        Node *curr_node = root;
        
        while (1) {
            if (nnode->data <= curr_node->data) {
                if (curr_node->left == NULL) {
                    curr_node->left = nnode;
                    break;
                }
                else {
                    curr_node = curr_node->left;
                }
            }
            else if (nnode->data > curr_node->data) {
                if (curr_node->right == NULL) {
                    curr_node->right = nnode;
                    break;
                }
                else {
                    curr_node = curr_node->right;
                }
            }
        }
    }
    
    return root;
}


void print_nodes_inorder (Node *parent) {
    if (parent->left != NULL) {
        print_nodes_inorder (parent->left);
    }
    
    printf ("%p -> %d\n", parent, parent->data);
    
    if (parent->right != NULL) {
        print_nodes_inorder (parent->right);
    }
    
    return;
}


void print_nodes_preorder (Node *parent) {
    printf ("%p -> %d\n", parent, parent->data);
    
    if (parent->left != NULL) {
        print_nodes_inorder (parent->left);
    }
    
    if (parent->right != NULL) {
        print_nodes_inorder (parent->right);
    }
    
    return;
}


void print_nodes_postorder (Node *parent) {
    if (parent->left != NULL) {
        print_nodes_inorder (parent->left);
    }
    
    if (parent->right != NULL) {
        print_nodes_inorder (parent->right);
    }
    
    printf ("%p -> %d\n", parent, parent->data);
    
    return;
}


void print_bst (Node *root, TravOrder order) {
    if (root == NULL) {
        printf ("Empty tree!\n");
        return;
    }
    
    printf ("Traversing the tree, order is ");
    switch (order) {
        case IN_ORDER:
            printf ("IN_ORDER\n");
            break;
            
        case PRE_ORDER:
            printf ("PRE_ORDER\n");
            break;
            
        case POST_ORDER:
            printf ("POST_ORDER\n");
            break;
            
        default:
            printf ("Invalid input, set to IN_ORDER\n");
            break;
    }
    
    printf ("Root node address: %p\n", root);
    
    printf ("----------------------------------------\n");
    
    switch (order) {
        case IN_ORDER:
            print_nodes_inorder (root);
            break;
            
        case PRE_ORDER:
            print_nodes_preorder (root);
            break;
            
        case POST_ORDER:
            print_nodes_postorder (root);
            break;
            
        default:
            print_nodes_inorder (root);
            break;
    }

    printf ("----------------------------------------\n\n");
    
    return;
}


Node *gen_rand_bst (int n, int r) {
    // A tree with n nodes, each node's data is in the range of [0..r-1]
    
    if (n <= 0) {
        return NULL;    // Empty tree
    }
    
    Node *root = NULL;
    
    for (int i = 0 ; i < n ; i++) {
        root = insert_to_bst (root, rand () % r);
    }
    
    return root;
}