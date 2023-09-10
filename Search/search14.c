#include <stdio.h>

// Function to find a fixed point in a sorted array
int findFixedPoint(int arr[], int size) {
    int left = 0, right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == mid) {
            return mid; // Found a fixed point
        } else if (arr[mid] < mid) {
            left = mid + 1; // Search in the right half
        } else {
            right = mid - 1; // Search in the left half
        }
    }

    return -1; // No fixed point found
}

int main() {
    int arr[] = {-10, -5, 1, 3, 7, 9, 12, 17};
    int size = sizeof(arr) / sizeof(arr[0]);

    int fixedPoint = findFixedPoint(arr, size);

    if (fixedPoint != -1) {
        printf("Fixed point is found at index %d\n", fixedPoint);
    } else {
        printf("No fixed point found in the array.\n");
    }

    return 0;
}
