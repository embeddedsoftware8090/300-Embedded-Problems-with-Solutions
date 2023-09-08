#include <stdio.h>
#include <stdlib.h>

// Function to find duplicate numbers in an array
int* findDuplicates(int arr[], int n, int* duplicateCount) {
    // Create a hash set to store seen elements
    int* seen = (int*)calloc(1000, sizeof(int)); // Assuming a reasonable range of input values

    // Create an array to store duplicate numbers
    int* duplicates = (int*)malloc(n * sizeof(int));
    *duplicateCount = 0;

    // Iterate through the array
    for (int i = 0; i < n; i++) {
        int num = arr[i];

        // Check if the number is already in the hash set
        if (seen[num]) {
            // Add the number to the list of duplicates
            duplicates[*duplicateCount] = num;
            (*duplicateCount)++;
        } else {
            // Mark the number as seen
            seen[num] = 1;
        }
    }

    free(seen);
    return duplicates;
}

int main() {
    int arr[] = {4, 3, 2, 7, 8, 2, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int duplicateCount;
    
    int* duplicateNumbers = findDuplicates(arr, n, &duplicateCount);

    printf("Duplicate Numbers: [");
    for (int i = 0; i < duplicateCount; i++) {
        printf("%d", duplicateNumbers[i]);
        if (i < duplicateCount - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    free(duplicateNumbers);

    return 0;
}
