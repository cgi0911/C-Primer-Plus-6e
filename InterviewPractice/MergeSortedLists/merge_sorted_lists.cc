#include <iostream>
#include <random>

typedef struct Node {
    int data;
    Node *next;
} Node;


Node *mergeSortedLists (Node *l1, Node *l2) {
    Node *n1 = l1;
    Node *n2 = l2;
    Node *dummy = new Node;
    Node *tail = dummy;

    while (n1 && n2) {
        if (n1->data < n2->data) {
            tail->next = n1;
            n1 = n1->next;
        }
        else {
            tail->next = n2;
            n2 = n2->next;
        }
        tail = tail->next;
    }

    if (n1) {
        tail->next = n1;
    }
    else if (n2) {
        tail->next = n2;
    }

    return dummy->next;
}




int main () {
}
