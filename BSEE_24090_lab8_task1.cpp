#include <iostream>
using namespace std;

class QueueArray {
private:
    int arr[100];//max size
    int front;//front element
    int back;//back element
    int size;//current size

public:
    QueueArray() {//initial values
        front = 0;
        back = -1;
        size = 0;
    }

    void enqueue(int value) {//adding at rear or back
        if (size == 100) {
            cout << "Queue is already full! Cannot add anymore.\n";
            return;
        }
        back++;
        arr[back] = value;
        size++;
        cout << "Inserted: " << value << endl;
    }

    void dequeue() {//remving front element
        if (isEmpty()) {
            cout << "Queue is already empty! Nothing to remove.\n";
            return;
        }
        cout << "Removed: " << arr[front] << endl;
        front++;
        size--;
    }

    bool isEmpty() {
        return (size == 0);
    }

    void showFront() {
        if (isEmpty()) {
            cout << "Queue is already empty.\n";
            return;
        }
        cout << "The Front Element is: " << arr[front] << endl;
    }

    void display() {//displaying all elements
        if (isEmpty()) {
            cout << "Queue is already empty.\n";
            return;
        }
        cout << "Queue: ";
        for (int i = front; i <= back; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    QueueArray q;
    int choice, value;
    while (true) {
        cout << "\n     Queue Using Array   \n";
        cout << "1. Enqueue the Queue\n";
        cout << "2. Dequeue the Queue\n";
        cout << "3. Showing the Front elemeny\n";
        cout << "4. Checking if the Queue is Empty\n";
        cout << "5. Displaying the Queue\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
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
            cout << (q.isEmpty() ? "Queue is empty\n" : "Queue is mot empty\n");
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