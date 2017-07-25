/* Longest prefix matching trie */
#include <stdint.h>

typedef struct Prefix {
    uint32_t ip;
    int prelen;
} Prefix;

typedef struct Node {
    Prefix pfx;
    Node *zero;
    Node *one;
} Node;

Node *new_trie (void);

void insert_new_rule (Prefix pfx);

Prefix lookup (uint32_t ip);