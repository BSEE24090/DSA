#include <iostream>
using namespace std;

class Node {//node creation
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};
class QueueLL {//queue creation
private:
    Node* front;
    Node* back;

public:
    QueueLL() {//initial value
        front = NULL;
        back = NULL;
    }

    void enqueue(int value) {//entering element at back
        Node* newNode = new Node(value);

        if (isEmpty()) {
            front = back = newNode;
        }
        else {
            back->next = newNode;
            back = newNode;
        }

        cout << "Inserted: " << value << endl;
    }

    void dequeue() {//removing element from front
        if (isEmpty()) {
            cout << "Queue is already empty.\n";
            return;
        }

        Node* temp = front;
        cout << "Removed: " << temp->data << endl;

        front = front->next;

        if (front == NULL)
            back = NULL;

        delete temp;
    }

    bool isEmpty() {
        return (front == NULL);
    }

    void showFront() {//displaying front element
        if (isEmpty()) {
            cout << "Queue is already empty.\n";
            return;
        }
        cout << "The Front element is: " << front->data << endl;
    }

    void display() {//displaying full queue
        if (isEmpty()) {
            cout << "Queue is already empty.\n";
            return;
        }
        cout << "Queue: ";
        Node* temp = front;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    QueueLL q;
    int choice, value;
    while (true) {//main menu
        cout << "\n     Queue Using Linked List     \n";
        cout << "1. Enqueue the queue\n";
        cout << "2. Dequeue the queue\n";
        cout << "3. Show Front the queue\n";
        cout << "4. Check if the queue is Empty\n";
        cout << "5. Displaying the Queue\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter the value: ";
            cin >> value;
            q.enqueue(value);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.showFront();
            break;
        case 4:
            cout << (q.isEmpty() ? "Queue is already empty empty\n" : "Queue is not empty\n");
            break;
        case 5:
            q.display();
            break;
        case 6:
            return 0;
        default:
            cout << "Invalid choice!\n";
        }
    }
}