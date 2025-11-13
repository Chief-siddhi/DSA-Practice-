#include <iostream>
using namespace std;

void insertionSort(int arr[], int n) {
    for(int i = 1; i < n; i++) {
        int curr = arr[i];
        int prev = i - 1;

        // Shift larger elements to the right
        while(prev >= 0 && arr[prev] > curr) {
            arr[prev + 1] = arr[prev];
            prev--;
        }

        // Place current element in correct position
        arr[prev + 1] = curr;
    }
}

int main() {
    int arr[5] = {5, 4, 1, 3, 2};
    int n = 5;

    insertionSort(arr, n);

    cout << "Sorted array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
