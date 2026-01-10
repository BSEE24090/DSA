#include <iostream>
using namespace std;

class HashTable {
private:
    int* table;
    int size;
    int prime;   //used for secondary hash
    const int EMPTY = -1;
    const int DELETED = -2;
    int hash1(int key) {//first hash function
        return key % size;
    }
    int hash2(int key) {//second hash function
        return prime - (key % prime);
    }

public:
    HashTable(int s) {//constructor
        size = s;
        prime = s - 1;   //prime less than the table size
        table = new int[size];
        for (int i = 0; i < size; i++)
            table[i] = EMPTY;
    }

    void insert(int key) {//inserting rhe key using double Hashing
        int index = hash1(key);

        if (table[index] == key) {
            cout << "No dublicated key is allowed!\n";
            return;
        }
        if (table[index] == EMPTY || table[index] == DELETED) {
            table[index] = key;
            cout << "Key is inserted at index " << index << endl;
            return;
        }

        int step = hash2(key);//collision occurred
        for (int i = 1; i < size; i++) {
            int newIndex = (index + i * step) % size;
            if (table[newIndex] == key) {
                cout << "Duplicate key not allowed!\n";
                return;
            }
            if (table[newIndex] == EMPTY || table[newIndex] == DELETED) {
                table[newIndex] = key;
                cout << "Key inserted at index " << newIndex << endl;
                return;
            }
        }
        cout << "Hash table is full!\n";
    }

    void search(int key) {//search key
        int index = hash1(key);
        int step = hash2(key);

        for (int i = 0; i < size; i++) {
            int newIndex = (index + i * step) % size;

            if (table[newIndex] == EMPTY) {
                cout << "key was not found.\n";
                return;
            }

            if (table[newIndex] == key) {
                cout << "key was founded at index " << newIndex << endl;
                return;
            }
        }
        cout << "key was not found!\n";
    }

    void remove(int key) {//deleting key
        int index = hash1(key);
        int step = hash2(key);

        for (int i = 0; i < size; i++) {
            int newIndex = (index + i * step) % size;

            if (table[newIndex] == EMPTY) {
                cout << "key was not found!\n";
                return;
            }

            if (table[newIndex] == key) {
                table[newIndex] = DELETED;
                cout << "key was deleted successfully!\n";
                return;
            }
        }

        cout << "key was not found!\n";
    }

    void display() {//displaying the hash table

        cout << "\nHash-Table:\n";
        for (int i = 0; i < size; i++) {
            cout << i << " : ";
            if (table[i] == EMPTY)
                cout << "Is Empty";
            else if (table[i] == DELETED)
                cout << "Deleting...";
            else
                cout << table[i];
            cout << endl;
        }
    }

    ~HashTable() {//destructor
        delete[] table;
    }
};
int main() {
    int size;
    cout << "enter hash table size: ";
    cin >> size;

    HashTable ht(size);
    int choice, key;

    do {
        cout << "\n         HASH TABLE MENU     \n";
        cout << "1. Inserting the Key\n";
        cout << "2. Searching for the Key\n";
        cout << "3. Deleteing the Key\n";
        cout << "4. Displaying Hash Table\n";
        cout << "0. Exiting\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "enter the key to be inserted: ";
            cin >> key;
            ht.insert(key);
            break;

        case 2:
            cout << "enter the key to be searched: ";
            cin >> key;
            ht.search(key);
            break;

        case 3:
            cout << "enter the key to be deleteted: ";
            cin >> key;
            ht.remove(key);
            break;

        case 4:
            ht.display();
            break;

        case 0:
            cout << "exiting the program...\n";
            break;

        default:
            cout << "invalid choice.\n";
        }
    } while (choice != 0);
    return 0;
}