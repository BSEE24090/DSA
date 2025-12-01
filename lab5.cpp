#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int n) {
        data = n;
        next = nullptr;
        prev = nullptr;
    }
};

class LinkedList {//creating list
private:
    Node* head;

public:
    LinkedList() { head = nullptr; }

    bool isEmpty() {
        return head == nullptr;
    }

    void insertAtFront(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        }
        head = newNode;
    }

    void insertAtTail(int val) {
        Node* newNode = new Node(val);

        if (isEmpty()) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->prev = temp;
    }

    void insertAtIndex(int val, int index) {
        if (index < 0) {
            cout << " Index is Invalid.\n";
            return;
        }

        if (index == 0) {
            insertAtFront(val);
            return;
        }

        Node* newNode = new Node(val);
        Node* temp = head;
        int currentIndex = 0;

        while (temp != nullptr && currentIndex < index - 1) {
            temp = temp->next;
            currentIndex++;
        }

        if (temp == nullptr) {
            cout << " Index is out of range.\n";
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next != nullptr) {
            temp->next->prev = newNode;
        }

        temp->next = newNode;
    }

    void deleteFromStart() {
        if (isEmpty()) {
            cout << " List is already empty.\n";
            return;
        }

        Node* temp = head;
        head = head->next;

        if (head != nullptr) {
            head->prev = nullptr;
        }

        delete temp;
    }

    void deleteFromEnd() {//deleting last node
        if (isEmpty()) {
            cout << " List is already empty.\n";
            return;
        }

        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }

        temp->prev->next = nullptr;
        delete temp;
    }

    void deleteNodeFromAnyIndex(int index) {
        if (isEmpty()) {
            cout << " List is already empty.\n";
            return;
        }
        if (index < 0) {
            cout << " Invalid index.\n";
            return;
        }
        if (index == 0) {
            deleteFromStart();
            return;
        }

        Node* temp = head;
        int currentIndex = 0;

        while (temp != nullptr && currentIndex < index) {
            temp = temp->next;
            currentIndex++;
        }

        if (temp == nullptr) {
            cout << " Index is out of current range.\n";
            return;
        }

        if (temp->next != nullptr) {
            temp->next->prev = temp->prev;
        }

        temp->prev->next = temp->next;

        delete temp;
    }

    void printList() {
        if (isEmpty()) {
            cout << " List is already empty.\n";
            return;
        }

        Node* temp = head;
        cout << " Linked List: ";
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << " NULL\n";
    }
};

int main() {
    LinkedList list;
    int choice, val, index;

    do {
        cout << "\n    DOUBLE LINKED LIST MENU \n";
        cout << " 1. Inserting Node At Front\n";
        cout << " 2. Inserting Node At Tail\n";
        cout << " 3. Inserting Node At Index\n";
        cout << " 4. Deleteing Node From Start\n";
        cout << " 5. Deleteing Node From End\n";
        cout << " 6. Deleteing Node From Index (0-n)\n";
        cout << " 7. Checking if List is Empty\n";
        cout << " 8. Printing Linked List\n";
        cout << " 9. Exit\n";

        cout << " Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << " Enter the value: ";
            cin >> val;
            list.insertAtFront(val);
            break;

        case 2:
            cout << " Enter the value: ";
            cin >> val;
            list.insertAtTail(val);
            break;

        case 3:
            cout << " Enter the value: ";
            cin >> val;
            cout << " Enter the index: ";
            cin >> index;
            list.insertAtIndex(val, index);
            break;

        case 4:
            list.deleteFromStart();
            break;

        case 5:
            list.deleteFromEnd();
            break;

        case 6:
            cout << " Enter the index: ";
            cin >> index;
            list.deleteNodeFromAnyIndex(index);
            break;

        case 7:
            cout << (list.isEmpty() ? " List is already empty." : " List is NOT empty.") << endl;
            break;

        case 8:
            list.printList();
            break;

        case 9:
            cout << " Exiting Program\n";
            break;

        default:
            cout << " Invalid choice.\n";
        }

    } while (choice != 9);

    return 0;
}
