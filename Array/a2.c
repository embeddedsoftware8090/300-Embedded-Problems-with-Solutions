#include <stdio.h>

int findDuplicate(int arr[], int n) {
    // Initialize a hash set to store seen elements
    int hashSet[501] = {0}; // Assuming the array contains numbers from 1 to 500

    for (int i = 0; i < n; i++) {
        if (hashSet[arr[i]]) {
            // If the element is already in the hash set, it's a duplicate
            return arr[i];
        }
        // Mark the element as seen
        hashSet[arr[i]] = 1;
    }

    // If no duplicate is found, return -1
    return -1;
}

int main() {
    int arr[] = {3, 1, 3, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    int duplicate = findDuplicate(arr, n);

    if (duplicate != -1) {
        printf("Duplicate Number: %d\n", duplicate);
    } else {
        printf("No duplicate found.\n");
    }

    return 0;
}
