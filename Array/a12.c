#include <stdio.h>

// Function to move all zeros to the left of the array
void moveZerosToLeft(int arr[], int n) {
    int nonZeroIndex = n - 1; // Index to track the position of non-zero elements

    // Iterate the array from right to left
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] != 0) {
            // Move non-zero elements to the rightmost positions
            arr[nonZeroIndex] = arr[i];
            nonZeroIndex--;
        }
    }

    // Fill the remaining leftmost positions with zeros
    while (nonZeroIndex >= 0) {
        arr[nonZeroIndex] = 0;
        nonZeroIndex--;
    }
}

int main() {
    int arr[] = {1, 2, 0, 4, 3, 0, 5, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    moveZerosToLeft(arr, n);

    printf("Modified Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
