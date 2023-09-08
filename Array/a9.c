#include <stdio.h>

// Function to reverse an array or a subarray
void reverse(int arr[], int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

// Function to rotate an array to the right by k steps
void rotateArray(int arr[], int n, int k) {
    // Handle the case where k is greater than the array size
    k = k % n;

    // Reverse the entire array
    reverse(arr, 0, n - 1);

    // Reverse the first k elements
    reverse(arr, 0, k - 1);

    // Reverse the remaining elements
    reverse(arr, k, n - 1);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;

    printf("Original Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    rotateArray(arr, n, k);

    printf("Rotated Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
