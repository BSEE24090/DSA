#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next;

    Node(int v) {
        value = v;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    bool isEmpty() {
        return head == nullptr;
    }

    // Insert new node at the beginning
    void insertAtFront(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Insert new node at the end
    void insertAtTail(int value) {
        Node* newNode = new Node(value);

        if (isEmpty()) {
            head = newNode;
            return;
        }

        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }

    // Insert node at a specific index
    void insertAtIndex(int value, int index) {
        if (index < 0) {
            cout << "Invalid index.\n";
            return;
        }

        if (index == 0) {
            insertAtFront(value);
            return;
        }

        Node* newNode = new Node(value);
        Node* current = head;
        int currentIndex = 0;

        while (current != nullptr && currentIndex < index - 1) {
            current = current->next;
            currentIndex++;
        }

        if (current == nullptr) {
            cout << "Index is out of range.\n";
            delete newNode;
            return;
        }

        newNode->next = current->next;
        current->next = newNode;
    }

    // Delete the first node
    void deleteFromStart() {
        if (isEmpty()) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Delete the last node
    void deleteFromEnd() {
        if (isEmpty()) {
            cout << "List is empty.\n";
            return;
        }

        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }

        Node* current = head;
        while (current->next->next != nullptr) {
            current = current->next;
        }

        delete current->next;
        current->next = nullptr;
    }

    // Delete a node at a given index
    void deleteNodeFromAnyIndex(int index) {
        if (isEmpty()) {
            cout << "List is empty.\n";
            return;
        }

        if (index < 0) {
            cout << "Invalid index.\n";
            return;
        }

        if (index == 0) {
            deleteFromStart();
            return;
        }

        Node* current = head;
        int currentIndex = 0;

        while (current != nullptr && currentIndex < index - 1) {
            current = current->next;
            currentIndex++;
        }

        if (current == nullptr || current->next == nullptr) {
            cout << "Index is out of range.\n";
            return;
        }

        Node* toDelete = current->next;
        current->next = current->next->next;
        delete toDelete;
    }

    // Display nodes of the list
    void printList() {
        if (isEmpty()) {
            cout << "List is empty.\n";
            return;
        }

        Node* current = head;
        cout << "Linked List: ";

        while (current != nullptr) {
            cout << current->value << " -> ";
            current = current->next;
        }

        cout << "NULL\n";
    }
};

int main() {
    LinkedList list;
    int choice, value, index;

    do {
        cout << "\n   LINKED LIST MENU\n";
        cout << "1. Insert At Front\n";
        cout << "2. Insert At Tail\n";
        cout << "3. Insert At Index\n";
        cout << "4. Delete From Start\n";
        cout << "5. Delete From End\n";
        cout << "6. Delete From Index\n";
        cout << "7. Check If Empty\n";
        cout << "8. Print List\n";
        cout << "9. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            list.insertAtFront(value);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> value;
            list.insertAtTail(value);
            break;

        case 3:
            cout << "Enter value: ";
            cin >> value;
            cout << "Enter index: ";
            cin >> index;
            list.insertAtIndex(value, index);
            break;

        case 4:
            list.deleteFromStart();
            break;

        case 5:
            list.deleteFromEnd();
            break;

        case 6:
            cout << "Enter index: ";
            cin >> index;
            list.deleteNodeFromAnyIndex(index);
            break;

        case 7:
            cout << (list.isEmpty() ? "List is empty.\n" : "List is not empty.\n");
            break;

        case 8:
            list.printList();
            break;

        case 9:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 9);

    return 0;
}
