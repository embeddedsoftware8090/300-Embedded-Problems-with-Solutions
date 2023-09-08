#include <stdio.h>

// Merge two subarrays: one containing positive numbers and the other containing negative numbers
void merge(int arr[], int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    // Create temporary arrays to store positive and negative subarrays
    int positive[n1], negative[n2];

    // Copy data to temporary arrays positive[] and negative[]
    for (int i = 0; i < n1; i++)
        positive[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        negative[j] = arr[middle + 1 + j];

    // Merge the temporary arrays back into arr[left..right]
    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        arr[k++] = (positive[i] <= negative[j]) ? positive[i++] : negative[j++];
    }

    // Copy the remaining elements of positive[], if any
    while (i < n1) {
        arr[k++] = positive[i++];
    }

    // Copy the remaining elements of negative[], if any
    while (j < n2) {
        arr[k++] = negative[j++];
    }
}

// Rearrange positive and negative numbers in the array
void rearrangePosNeg(int arr[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        // Recursively sort the two halves
        rearrangePosNeg(arr, left, middle);
        rearrangePosNeg(arr, middle + 1, right);

        // Merge the sorted halves
        merge(arr, left, middle, right);
    }
}

int main() {
    int arr[] = {-1, 2, -3, 4, 5, 6, -7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    rearrangePosNeg(arr, 0, n - 1);

    printf("Rearranged Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}


