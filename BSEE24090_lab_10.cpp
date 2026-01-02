#include <iostream>
using namespace std;

class Node {//node for tree creation
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
class BST {// creating class for Binary Search tree
private:
    Node* root;
    Node* insertNode(Node* temp, int val) {
        if (temp == NULL) {
            return new Node(val);
        }

        if (val < temp->data) {
            temp->left = insertNode(temp->left, val);
        }
        else if (val > temp->data) {
            temp->right = insertNode(temp->right, val);
        }
        else {
            cout << "Duplicate value is not allowed.\n";
        }
        return temp;
    }

    void inorder(Node* temp) {
        if (temp == NULL)
            return;

        inorder(temp->left);
        cout << temp->data << " ";
        inorder(temp->right);
    }

    void preorder(Node* temp) {
        if (temp == NULL)
            return;

        cout << temp->data << " ";
        preorder(temp->left);
        preorder(temp->right);
    }

    void postorder(Node* temp) {
        if (temp == NULL)
            return;

        postorder(temp->left);
        postorder(temp->right);
        cout << temp->data << " ";
    }

public:
    BST() {
        root = NULL;
    }

    void insert(int val) {
        root = insertNode(root, val);
    }

    void displayInorder() {
        if (root == NULL) {
            cout << "This tree is empty.\n";
            return;
        }
        inorder(root);
        cout << endl;
    }

    void displayPreorder() {//displays pre order tree
        if (root == NULL) {
            cout << "This tree is empty.\n";
            return;
        }
        preorder(root);
        cout << endl;
    }

    void displayPostorder() {//displays poat order tree
        if (root == NULL) {
            cout << "This tree is empty.\n";
            return;
        }
        postorder(root);
        cout << endl;
    }
};

int main() {
    BST tree;
    int choice, value;

    do {
        cout << "\n      Binary Search Tree Menu\n";
        cout << "1. Insert Node\n";
        cout << "2. Inorder Traversal\n";
        cout << "3. Preorder Traversal\n";
        cout << "4. Postorder Traversal\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            tree.insert(value);
            break;

        case 2:
            cout << "Inorder Traversal: ";
            tree.displayInorder();
            break;

        case 3:
            cout << "Preorder Traversal: ";
            tree.displayPreorder();
            break;

        case 4:
            cout << "Postorder Traversal: ";
            tree.displayPostorder();
            break;

        case 5:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 5);
    return 0;
}