#include <iostream>
#include <random>

using namespace std;

typedef struct Node {
    int data;
    Node *left;
    Node *right;
} Node;


Node *new_node (int num) {
    Node *nd = new Node;
    nd->data = num;
    nd->left = NULL;
    nd->right = NULL;
    return nd;
}

class BST {
    public:
        BST ();
        ~BST ();
        Node *insert (int num);
        void print_inorder ();
        int get_size ();
    private:
        Node *root;
        void _print_inorder (Node *nd);
        int tree_size;
};


BST::BST () {
    root = NULL;
    tree_size = 0;
}


void del_node (Node *nd) {
    if (nd == NULL) {
        return;
    }

    // Do a post-order traversal to recursively delete children nodes
    if (nd->left != NULL) {
        del_node (nd->left);
    }

    if (nd->right != NULL) {
        del_node (nd->right);
    }

    delete (nd);
}

BST::~BST () {
    del_node (root);
}


Node* BST::insert (int num) {
    if (root == NULL) {
        root = new_node (num);
        tree_size ++;
        return root;
    }

    Node *pos = root;

    while (1) {
        if (num <= pos->data) {
            if (pos->left == NULL) {
                pos->left = new_node (num);
                tree_size ++;
                return pos->left;
            }
            else {
                pos = pos->left;
            }
        }
        else {
            if (pos->right == NULL) {
                pos->right = new_node (num);
                tree_size ++;
                return pos->right;
            }
            else {
                pos = pos->right;
            }
        }
    }
}


void BST::_print_inorder (Node *nd) {
    if (nd == NULL) { return; }
    _print_inorder (nd->left);
    cout << nd->data << " ";
    _print_inorder (nd->right);
}

void BST::print_inorder () {
    if (root == NULL) {
        cout << "Empty BST!" << endl;
        return;
    }

    _print_inorder (root); 
    cout << endl;
}


int BST::get_size () {
    return tree_size;
}

int main () {
    int n;
    int lo, hi;
    cout << "# of integers: ";
    cin >> n;
    cout << "Range [lo, hi]: ";
    cin >> lo >> hi;

    random_device rd;
    uniform_int_distribution<int> dist (lo, hi);

    BST myBST;
    for (int i = 0 ; i < n ; i++) {
        myBST.insert (dist (rd));
    }

    cout << "Tree size = " << myBST.get_size () << endl;

    myBST.print_inorder ();
}
