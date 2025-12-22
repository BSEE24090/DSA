#include <iostream>
using namespace std;

class Sorting {
private:
    int arr[50];
    int n;

public:
    Sorting() {
        n = 0;
    }

    void inputArray() {// array input by user
        cout << "Enter the number of elements: ";
        cin >> n;

        if (n <= 0) {
            cout << "Array is empty!\n";
            return;
        }

        cout << "Enter array elements:\n";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        displayArray();
    }

    void displayArray() {//display array
        if (n == 0) {
            cout << "Array is empty!\n";
            return;
        }

        cout << "Array elements: ";
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void bubbleSort() {//bubble sort
        if (n <= 1) {
            cout << "Array does not need sorting!\n";
            return;
        }

        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }

        cout << "Bubble Sort applied successfully!\n";
        displayArray();
    }

    void selectionSort() {//selection sort
        if (n <= 1) {
            cout << "Array does not need sorting!\n";
            return;
        }

        for (int i = 0; i < n - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }

        cout << "Selection Sort applied successfully!\n";
        displayArray();
    }

    void insertionSort() {//insertion sort
        if (n <= 1) {
            cout << "Array does not need sorting!\n";
            return;
        }

        for (int i = 1; i < n; i++) {
            int key = arr[i];
            int j = i - 1;

            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }

        cout << "Insertion Sort applied successfully!\n";
        displayArray(); 
    }
};

int main() {
    Sorting s;
    int choice;
    s.inputArray();

    do {
        cout << "\n     SORTING MENU        \n";
        cout << "1. Bubble Sort\n";
        cout << "2. Selection Sort\n";
        cout << "3. Insertion Sort\n";
        cout << "4. Display Array\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            s.bubbleSort();
            break;
        case 2:
            s.selectionSort();
            break;
        case 3:
            s.insertionSort();
            break;
        case 4:
            s.displayArray();
            break;
        case 5:
            cout << "Exiting the  program...\n";
            break;
        default:
            cout << "Invalid choice! please Try again.\n";
        }

    } while (choice != 5);

    return 0;
}