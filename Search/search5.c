#include <stdio.h>

// Function to perform binary search within a range
int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid; // Target found
        }

        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1; // Target not found
}

// Function to perform exponential search
int exponentialSearch(int arr[], int size, int target) {
    if (arr[0] == target) {
        return 0; // Target found at the first element
    }

    int i = 1;
    while (i < size && arr[i] <= target) {
        i *= 2;
    }

    // Apply binary search within the found range
    return binarySearch(arr, i / 2, (i < size) ? i : size - 1, target);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 3;

    int result = exponentialSearch(arr, size, target);

    if (result != -1) {
        printf("Element %d found at index %d\n", target, result);
    } else {
        printf("Element %d not found in the array\n", target);
    }

    return 0;
}
