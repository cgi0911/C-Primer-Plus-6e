#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "bst.h"

int main () {
    srand (time (NULL));
    
    int n, r;
    TravOrder order;
    
    printf ("Input number of nodes: ");
    scanf ("%d", &n);
    printf ("Input range of node data [0..r-1]: ");
    scanf ("%d", &r);
    
    Node *root = gen_rand_bst (n, r);
    
    order = PRE_ORDER;
    print_bst (root, order);
}