#include <stdio.h>

// Function to perform binary search recursively
int binarySearchRecursive(int arr[], int left, int right, int target) {
    if (left > right) {
        return -1; // Target not found
    }

    int mid = left + (right - left) / 2;

    if (arr[mid] == target) {
        return mid; // Target found at index mid
    }

    if (arr[mid] < target) {
        return binarySearchRecursive(arr, mid + 1, right, target); // Search in the right half
    } else {
        return binarySearchRecursive(arr, left, mid - 1, target); // Search in the left half
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 3;

    int result = binarySearchRecursive(arr, 0, size - 1, target);

    if (result != -1) {
        printf("Element %d found at index %d\n", target, result);
    } else {
        printf("Element %d not found in the array\n", target);
    }

    return 0;
}
