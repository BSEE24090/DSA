#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};
class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }
    bool isEmpty() {
        return (top == nullptr);
    }

    void push(int value) {//Push function
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        cout << value << " pushed to stack.\n";
    }

    void pop() {//Pop function
        if (isEmpty()) {
            cout << "Stack is empty! Nothing to pop.\n";
            return;
        }

        Node* temp = top;
        cout << temp->data << " popped from stack.\n";
        top = top->next;
        delete temp;
    }
    void peek() {//peek function
        if (isEmpty()) {
            cout << "Stack is empty! No top element.\n";
            return;
        }
        cout << "Top element: " << top->data << "\n";
    }
};

int main() {//main menu
    Stack s;
    int choice, value;

    while (true) {
        cout << "\n===== STACK MENU =====\n";
        cout << "1. Push element\n";
        cout << "2. Pop element\n";
        cout << "3. View top element\n";
        cout << "4. Check if stack is empty\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            s.push(value);
            break;
        case 2:
            s.pop();
            break;
        case 3:
            s.peek();
            break;
        case 4:
            if (s.isEmpty())
                cout << "Stack is empty.\n";
            else
                cout << "Stack is NOT empty.\n";
            break;
        case 5:
            cout << "Exiting program...\n";
            return 0;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    }
    return 0;
}