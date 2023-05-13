#include <iostream>
using namespace std;

void minHeapify(int arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
  
    if (left < n && arr[left] < arr[smallest])
        smallest = left;
  
    if (right < n && arr[right] < arr[smallest])
        smallest = right;
  
    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

void deleteMin(int arr[], int& n) {
    if (n == 0) {
        cout << "Heap is empty." << endl;
        return;
    }
    
    int minElement = arr[0];
    arr[0] = arr[n - 1];
    n--;
    minHeapify(arr, n, 0);
    
    cout << "Deleted element: " << minElement << endl;
}

void displayHeap(int arr[], int n) {
    if (n == 0) {
        cout << "Heap is empty." << endl;
        return;
    }
    
    cout << "Current heap elements: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    
    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    for (int i = n / 2 - 1; i >= 0; i--)
        minHeapify(arr, n, i);
    
    displayHeap(arr, n);
    
    deleteMin(arr, n);
    
    displayHeap(arr, n);
    
    return 0;
}

