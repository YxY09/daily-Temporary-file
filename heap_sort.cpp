#include<iostream>
#include<vector>
using namespace std;

void Max_heapify(int * A, int i, int size) {
    int l = 2 * i + 1, r = 2 * i + 2;
    int largest = i;
    if (l < size && A[l] > A[largest]) {
        largest = l;
    }
    if (r < size && A[r] > A[largest]) {
        largest = r;
    }
    if (largest != i) {
        swap(A[i], A[largest]);
        Max_heapify(A, largest, size);
    }
}

void Build_heapify(int * A, int size) {
    for (int i = size / 2 - 1; i >= 0; --i) {
        Max_heapify(A, i, size);
    } 
}

void heap_sort(int *A, int size) {
    Build_heapify(A, size);
    for (int i = size - 1; i > 0; --i) {
        swap(A[0], A[i]);
        Max_heapify(A, 0, i);
    }
}

int main() {
    int arr[] = {1, 4, 5, 2, 1, 4, 5, 6, 7, 2, 4, 5, 6, 3, 0, 19, 18, 201};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Original array: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    heap_sort(arr, size);
    cout << "After sorting array: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
