#include <stdio.h>

int findMissingNumber(int arr[], int n) {
    // Calculate the expected sum of consecutive integers from 1 to 500
    int expectedSum = (500 * (500 + 1)) / 2; // Sum of an arithmetic series

    // Calculate the actual sum of the elements in the array
    int actualSum = 0;
    for (int i = 0; i < n; i++) {
        actualSum += arr[i];
    }

    // The missing number is the difference between the expected sum and the actual sum
    int missingNumber = expectedSum - actualSum;
    return missingNumber;
}

int main() {
    int arr[] = {1, 2, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    int missingNumber = findMissingNumber(arr, n);

    printf("Missing Number: %d\n", missingNumber);

    return 0;
}

