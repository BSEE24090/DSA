#include <iostream>
using namespace std;

class Stack {//Stack class
private:
    int top;         //top index of stack
    int size;        //Max stack size
    int* arr;

public:
        Stack(int s) {
        size = s;
        top = -1;
        arr = new int[size];
    }
    bool isEmpty() {//Checkig if stack is empty
        return (top == -1);
    }
    bool isFull() {//Checking if stack is full
        return (top == size - 1);
    }
    void push(int value) {//Pushing/adding value on stack
        if (isFull()) {
            cout << "Stack Overflow! Already full.\n";
        }
        else {
            arr[++top] = value;
            cout << "Pushed: " << value << endl;
        }
    }
    int pop() {// Popping/deleting value from stack
        if (isEmpty()) {
            cout << "Stack Underflow! Already empty.\n";
            return -1;
        }
        else {
            cout << "Popped: " << arr[top] << endl;
            return arr[top--];
        }
    }
    int peek() {//Viewing top element
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return -1;
        }
        else {
            return arr[top];
        }
    }
};

int main() {//main function
    int capacity;
    cout << "Enter the stack size: ";
    cin >> capacity;

    Stack s(capacity);

    int choice, value;

    while (true) {
        cout << "\n---- Stack Menu ----\n";
        cout << "1. Push Element\n";
        cout << "2. Pop Element\n";
        cout << "3. View Top Element (Peek)\n";
        cout << "4. Check if Empty\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter the value to push: ";
            cin >> value;
            s.push(value);
            break;

        case 2:
            s.pop();
            break;

        case 3:
            value = s.peek();
            if (value != -1)
                cout << "The Top Element is: " << value << endl;
            break;

        case 4:
            if (s.isEmpty())
                cout << "Stack is already Empty.\n";
            else
                cout << "Stack is not Empty.\n";
            break;

        case 5:
            cout << "Exiting the Program.\n";
            return 0;

        default:
            cout << "Invalid Choice! Try again.\n";
        }
    }
    return 0;
}
