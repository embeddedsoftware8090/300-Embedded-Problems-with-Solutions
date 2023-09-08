#include <stdio.h>

// Function to find the first occurrence of a number in a sorted array
int findFirstOccurrence(int arr[], int n, int target) {
    int low = 0;
    int high = n - 1;
    int result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            result = mid;
            high = mid - 1; // Search in the left half
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return result;
}

// Function to find the last occurrence of a number in a sorted array
int findLastOccurrence(int arr[], int n, int target) {
    int low = 0;
    int high = n - 1;
    int result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            result = mid;
            low = mid + 1; // Search in the right half
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return result;
}

// Function to count occurrences of a number in a sorted array
int countOccurrences(int arr[], int n, int target) {
    int first = findFirstOccurrence(arr, n, target);
    int last = findLastOccurrence(arr, n, target);

    if (first != -1 && last != -1) {
        return last - first + 1;
    }

    return 0; // Number not found in the array
}

int main() {
    int arr[] = {1, 2, 2, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 2;

    int count = countOccurrences(arr, n, target);

    printf("Number of occurrences of %d: %d\n", target, count);

    return 0;
}
