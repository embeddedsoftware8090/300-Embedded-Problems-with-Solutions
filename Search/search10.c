#include <stdio.h>

// Function to perform binary search on a sorted and rotated array
int searchInRotatedArray(int arr[], int left, int right, int target) {
    if (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid; // Element found
        }

        // Check if the left half is sorted
        if (arr[left] <= arr[mid]) {
            // Check if the target is in the left half
            if (arr[left] <= target && target <= arr[mid]) {
                return searchInRotatedArray(arr, left, mid - 1, target);
            }
            // If not, search in the right half
            return searchInRotatedArray(arr, mid + 1, right, target);
        }

        // If the left half is not sorted, then the right half must be sorted
        // Check if the target is in the right half
        if (arr[mid] <= target && target <= arr[right]) {
            return searchInRotatedArray(arr, mid + 1, right, target);
        }
        // If not, search in the left half
        return searchInRotatedArray(arr, left, mid - 1, target);
    }

    return -1; // Element not found
}

int main() {
    int arr[] = {3, 4, 5, 1, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 1;

    int result = searchInRotatedArray(arr, 0, size - 1, target);

    if (result != -1) {
        printf("Element %d found at index %d\n", target, result);
    } else {
        printf("Element %d not found in the array\n", target);
    }

    return 0;
}
