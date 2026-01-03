#include <iostream>
using namespace std;
class Node {// creating a AVL tree
public:
    int data;
    Node* left;
    Node* right;
    int height;

    Node(int d) {
        data = d;
        left = NULL;
        right = NULL;
        height = 1;
    }
};

class AVLTree {//initilization and balancing of AVLTree
private:
    Node* root;
    int getHeight(Node* n) {
        if (n == NULL)
            return 0;
        return n->height;
    }
    int getBalance(Node* n) {
        if (n == NULL)
            return 0;
        return getHeight(n->left) - getHeight(n->right);
    }
    int max(int a, int b) {
        return (a > b) ? a : b;
    }
    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;
        x->right = y;
        y->left = T2;

        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

        return x;
    }
    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;
        y->left = x;
        x->right = T2;

        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

        return y;
    }
    Node* insertNode(Node* node, int value) {
        if (node == NULL)
            return new Node(value);
        if (value < node->data)
            node->left = insertNode(node->left, value);
        else if (value > node->data)
            node->right = insertNode(node->right, value);
        else
            return node; //to stop duplication

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        int balance = getBalance(node);

        if (balance > 1 && value < node->left->data)//for left of left case 
            return rightRotate(node);

        if (balance < -1 && value > node->right->data)//for right of right case 
            return leftRotate(node);

        if (balance > 1 && value > node->left->data) {//for right of left case 
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && value < node->right->data) {//for left of right case 
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    void inorder(Node* node) {//arranging in given order
        if (node == NULL)
            return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

public:
    AVLTree() {
        root = NULL;
    }

    void insert(int value) {
        root = insertNode(root, value);
        cout << "Node has been inserted successfully.\n";
    }

    void display() {
        if (root == NULL) {
            cout << "This tree is already empty.\n";
            return;
        }
        cout << "Performing Inorder Traversal: ";
        inorder(root);
        cout << endl;
    }
};

int main() {
    AVLTree tree;
    int choice, value;

    do {//main menu
        cout << "\n         AVL Tree Menu       \n";
        cout << "1. Inserting Node\n";
        cout << "2. Displaying Inorder Traversal\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value value: ";
            cin >> value;
            tree.insert(value);
            break;

        case 2:
            tree.display();
            break;

        case 3:
            cout << "Exiting the program...\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 3);
    return 0;
}