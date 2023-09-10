#include <stdio.h>

// Function to perform sentinel search
int sentinelSearch(int arr[], int size, int target) {
    // Add the target as a sentinel element at the end of the array
    arr[size] = target;
    int i = 0;

    // Search for the target element
    while (arr[i] != target) {
        i++;
    }

    // If the search reached the last (sentinel) element, it means the target was not found
    if (i == size) {
        return -1;
    }

    return i;
}

int main() {
    int arr[] = {5, 2, 9, 1, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 1;

    int result = sentinelSearch(arr, size, target);

    if (result != -1) {
        printf("Element %d found at index %d\n", target, result);
    } else {
        printf("Element %d not found in the array\n", target);
    }

    return 0;
}
