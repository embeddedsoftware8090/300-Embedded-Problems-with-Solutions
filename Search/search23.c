#include <stdio.h>

int modifiedBinarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid; // Element found at index mid.
        }

        if (mid > left && arr[mid - 1] == target) {
            return mid - 1; // Element found at index mid - 1.
        }

        if (mid < right && arr[mid + 1] == target) {
            return mid + 1; // Element found at index mid + 1.
        }

        if (arr[mid] > target) {
            right = mid - 2; // Adjust the search range to the left.
        } else {
            left = mid + 2; // Adjust the search range to the right.
        }
    }

    return -1; // Element not found.
}

int main() {
    int arr[] = {2, 1, 3, 5, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 2;

    int index = modifiedBinarySearch(arr, size, target);

    printf("I/P: [");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("], %d; O/P: %d\n", target, index);

    return 0;
}
