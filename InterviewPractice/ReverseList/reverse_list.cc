#include <iostream>
#include <random>

using namespace std;

typedef struct Node {
    int data;
    Node *next;
} Node;


Node *reverseList (Node *head) {
    Node *newhead;

    if (!head) {
        return NULL;
    }

    if (!head->next) {
        return head;    // End of list
    }

    else {
        newhead = reverseList (head->next);
        // Now we've got newhead, but we need to append the tail to the end of list
        head->next->next = head;
        head->next = NULL;
    }

    return newhead;
}


int main () {
    int n;
    random_device rd;
    uniform_int_distribution<int> dist (0, 100);

    cout << "# of integers: ";
    cin >> n;

    Node *head = new Node;
    Node *tail = head;
    tail->data = dist (rd);
    tail->next = NULL;

    for (int i = 1 ; i < n ; i++) {
        Node *newnode = new Node;
        newnode->data = dist (rd);
        newnode->next = NULL;
        tail->next = newnode;
        tail = newnode;
    }

    cout << "Original list:" << endl;
    tail = head;
    while (tail) {
        cout << tail->data << " ";
        tail = tail->next;
    }
    cout << endl << endl;

    head = reverseList (head);   

    cout << "Reversed list:" << endl;
    tail = head;
    while (tail) {
        cout << tail->data << " ";
        tail = tail->next;
    }
    cout << endl << endl;

    reverseList (head);   


}
