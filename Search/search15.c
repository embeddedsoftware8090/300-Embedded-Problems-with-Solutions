#include <stdio.h>

// Function to find the first occurrence of a target element
int findFirstOccurrence(int arr[], int size, int target) {
    int left = 0, right = size - 1;
    int result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            result = mid; // Update the result and continue searching in the left half
            right = mid - 1;
        } else if (arr[mid] < target) {
            left = mid + 1; // Search in the right half
        } else {
            right = mid - 1; // Search in the left half
        }
    }

    return result;
}

// Function to find the last occurrence of a target element
int findLastOccurrence(int arr[], int size, int target) {
    int left = 0, right = size - 1;
    int result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            result = mid; // Update the result and continue searching in the right half
            left = mid + 1;
        } else if (arr[mid] < target) {
            left = mid + 1; // Search in the right half
        } else {
            right = mid - 1; // Search in the left half
        }
    }

    return result;
}

// Function to count occurrences of a target element in a sorted array
int countOccurrences(int arr[], int size, int target) {
    int firstOccurrence = findFirstOccurrence(arr, size, target);
    int lastOccurrence = findLastOccurrence(arr, size, target);

    if (firstOccurrence != -1 && lastOccurrence != -1) {
        return lastOccurrence - firstOccurrence + 1;
    } else {
        return 0;
    }
}

int main() {
    int arr[] = {2, 2, 2, 2, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 2;

    int occurrences = countOccurrences(arr, size, target);

    printf("Occurrences of %d in the array: %d\n", target, occurrences);

    return 0;
}
