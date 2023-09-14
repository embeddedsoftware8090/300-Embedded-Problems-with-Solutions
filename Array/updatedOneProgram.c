#include <stdio.h>

int findMissingNumber(int arr[], int n) {
    int expectedSum = (n + 1) * (n + 2) / 2;
    int actualSum = 0;

    for (int i = 0; i < n; i++) {
        actualSum += arr[i];
    }

    return expectedSum - actualSum;
}

int main() {
    int arr[] = {1, 2, 4, 5}; // Input array
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int missingNumber = findMissingNumber(arr, n);
    
    printf("The missing number is: %d\n", missingNumber);

    return 0;
}
