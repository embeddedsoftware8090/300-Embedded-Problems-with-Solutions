#include <stdio.h>
#include <stdbool.h>

// Function to find if there's a subarray with zero sum
bool hasZeroSumSubarray(int arr[], int n) {
    // Create a hash table to store cumulative sums and their positions
    int sum = 0;
    int hashTable[10000] = {0}; // Assuming the sum won't exceed 10000

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        // If the current sum is zero or has been encountered before, there is a zero-sum subarray
        if (sum == 0 || hashTable[sum] == 1) {
            return true;
        }

        // Mark the current sum as encountered
        hashTable[sum] = 1;
    }

    return false;
}

int main() {
    int arr[] = {4, 2, -3, 1, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    if (hasZeroSumSubarray(arr, n)) {
        printf("Subarray with zero sum exists\n");
    } else {
        printf("Subarray with zero sum does not exist\n");
    }

    return 0;
}
