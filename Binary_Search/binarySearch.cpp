#include<iostream>
using namespace std;

// Binary search function to find the index of a key in an array
int binarySearch(int arr[], int size, int key) {
    int start = 0;
    int end = size - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == key) {
            return mid;
        }

        // If key is greater, search in the right half
        if (key > arr[mid]) {
            start = mid + 1;
        } else { // key < arr[mid], search in the left half
            end = mid - 1;
        }
    }

    return -1; // Key not found
}

int main() {
    int even[6] = {2, 4, 6, 8, 12, 18};
    int odd[5] = {3, 8, 11, 14, 16};

    int evenIndex = binarySearch(even, 6, 6);
    cout << "Index of 6 is " << evenIndex << endl;

    int oddIndex = binarySearch(odd, 5, 14);
    cout << "Index of 14 is " << oddIndex << endl;

    return 0;
}

// Function to find the peak element in an array using binary search
int findPeak(int arr[], int n) {
    int start = 0;
    int end = n - 1;

    while (start < end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] < arr[mid + 1]) {
            start = mid + 1; // Search in the right half
        } else {
            end = mid; // Search in the left half
        }
    }
    return start; // Peak element found at index 'start'
}
