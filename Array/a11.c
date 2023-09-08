#include <stdio.h>

// Function to perform Quicksort
void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = (low - 1);

        for (int j = low; j <= high - 1; j++) {
            if (arr[j] >= pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;

        int pivotIndex = i + 1;

        quicksort(arr, low, pivotIndex - 1);
        quicksort(arr, pivotIndex + 1, high);
    }
}

// Function to find the kth maximum element
int findKthMax(int arr[], int n, int k) {
    if (k <= 0 || k > n) {
        return -1; // Invalid k value
    }

    quicksort(arr, 0, n - 1);
    return arr[k - 1];
}

// Function to find the kth minimum element
int findKthMin(int arr[], int n, int k) {
    if (k <= 0 || k > n) {
        return -1; // Invalid k value
    }

    quicksort(arr, 0, n - 1);
    return arr[n - k];
}

int main() {
    int arr[] = {7, 10, 4, 3, 20, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    int kthMax = findKthMax(arr, n, k);
    int kthMin = findKthMin(arr, n, k);

    printf("Kth Max: %d\n", kthMax);
    printf("Kth Min: %d\n", kthMin);

    return 0;
}
