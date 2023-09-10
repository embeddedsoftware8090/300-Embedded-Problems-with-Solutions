#include <stdio.h>

// Function to find the first occurrence of an element in a sorted array
int findFirstOccurrence(int arr[], int size, int target) {
    int left = 0, right = size - 1;
    int firstOccurrence = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            firstOccurrence = mid;
            right = mid - 1; // Continue searching in the left half
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return firstOccurrence;
}

// Function to find the last occurrence of an element in a sorted array
int findLastOccurrence(int arr[], int size, int target) {
    int left = 0, right = size - 1;
    int lastOccurrence = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            lastOccurrence = mid;
            left = mid + 1; // Continue searching in the right half
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return lastOccurrence;
}

int main() {
    int arr[] = {2, 2, 2, 2, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 2;

    int first = findFirstOccurrence(arr, size, target);
    int last = findLastOccurrence(arr, size, target);

    if (first != -1 && last != -1) {
        printf("First occurrence = %d\n", first);
        printf("Last occurrence = %d\n", last);
    } else {
        printf("Element not found in the array.\n");
    }

    return 0;
}
