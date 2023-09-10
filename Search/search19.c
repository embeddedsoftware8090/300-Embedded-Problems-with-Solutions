#include <stdio.h>

int countRotations(int arr[], int size) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        // If the array is already sorted, no rotations have occurred
        if (arr[left] <= arr[right]) {
            return left;
        }

        int mid = left + (right - left) / 2;
        int next = (mid + 1) % size; // Index of the next element

        // Check if the mid element is the pivot
        if (arr[mid] <= arr[next] && arr[mid] <= arr[(mid + size - 1) % size]) {
            return mid;
        }

        // Decide whether to search the left or right half
        if (arr[mid] <= arr[right]) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return -1; // In case of an empty array or invalid input
}

int main() {
    int arr[] = {15, 18, 2, 3, 6, 12};
    int size = sizeof(arr) / sizeof(arr[0]);

    int rotations = countRotations(arr, size);

    if (rotations != -1) {
        printf("The array is rotated %d times.\n", rotations);
    } else {
        printf("Invalid input or empty array.\n");
    }

    return 0;
}
