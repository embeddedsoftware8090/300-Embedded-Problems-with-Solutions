#include <stdio.h>
#include <stdbool.h>

// Function to check if an array can be divided into pairs with sum divisible by k
bool canDivideArray(int arr[], int n, int k) {
    // Create an array to store the count of remainders
    int remainders[k];
    for (int i = 0; i < k; i++) {
        remainders[i] = 0;
    }

    // Count the remainders of elements
    for (int i = 0; i < n; i++) {
        int remainder = (arr[i] % k + k) % k; // Ensure positive remainder
        remainders[remainder]++;
    }

    // Check if each remainder can form pairs
    if (remainders[0] % 2 != 0) {
        return false; // The remainder 0 must have an even count
    }

    for (int i = 1; i <= k / 2; i++) {
        if (remainders[i] != remainders[k - i]) {
            return false; // Remainders i and k-i must have equal counts
        }
    }

    return true;
}

int main() {
    int arr[] = {9, 7, 5, -3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 6;

    bool canDivide = canDivideArray(arr, n, k);

    if (canDivide) {
        printf("Array can be divided into pairs with sum divisible by %d: True\n", k);
    } else {
        printf("Array cannot be divided into pairs with sum divisible by %d: False\n", k);
    }

    return 0;
}
