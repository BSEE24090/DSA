#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i)
{
    int largest = i;        //assuming the root is largest
    int left = 2 * i + 1;   //left child given
    int right = 2 * i + 2;  //right child given

    if (left < n && arr[left] > arr[largest])//checking if left child is larger than root
        largest = left;

    if (right < n && arr[right] > arr[largest])//checking if right child is larger than it is  largest so far
        largest = right;

    if (largest != i)//if root is not the largest
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest); //recursive heapify
    }
}

void heapSort(int arr[], int n)
{

    for (int i = n / 2 - 1; i >= 0; i--)//for Max Heap
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--)//extracting heap elements
    {
        swap(arr[0], arr[i]);   //moveing root to rhe end
        heapify(arr, i, 0);
    }
}

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int n;
    int arr[100];

    cout << "enter the number of elements: ";
    cin >> n;
    cout << "enter the elements: \n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "\nOriginal Array: \n";
    display(arr, n);

    heapSort(arr, n);

    cout << "\nSorted Array: \n";
    display(arr, n);
    return 0;
}
