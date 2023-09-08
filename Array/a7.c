#include <stdio.h>

void removeDuplicates(int arr[], int *n) {
    if (*n <= 1) {
        return; // Nothing to remove if the array has 0 or 1 elements
    }

    int uniqueIndex = 1; // Index to track unique elements

    for (int i = 1; i < *n; i++) {
        int isDuplicate = 0;

        // Check if the current element is a duplicate of any previous elements
        for (int j = 0; j < uniqueIndex; j++) {
            if (arr[i] == arr[j]) {
                isDuplicate = 1;
                break;
            }
        }

        // If it's not a duplicate, add it to the unique elements section
        if (!isDuplicate) {
            arr[uniqueIndex] = arr[i];
            uniqueIndex++;
        }
    }

    // Update the size of the array to reflect the number of unique elements
    *n = uniqueIndex;
}

int main() {
    int arr[] = {1, 1, 2, 2, 3, 4, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    removeDuplicates(arr, &n);

    printf("Array with Duplicates Removed: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
