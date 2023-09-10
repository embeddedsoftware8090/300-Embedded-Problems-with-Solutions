#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform partition (used in QuickSort)
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// QuickSort algorithm
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to find the Kth maximum and minimum elements
void findKthMinMax(int arr[], int size, int k) {
    if (k > size) {
        printf("Invalid value of K.\n");
        return;
    }

    // Sort the array in ascending order using QuickSort
    quickSort(arr, 0, size - 1);

    // Kth minimum element is at index k-1
    int minK = arr[k - 1];

    // Kth maximum element is at index size-k
    int maxK = arr[size - k];

    printf("Kth Minimum: %d\n", minK);
    printf("Kth Maximum: %d\n", maxK);
}

int main() {
    int arr[] = {7, 10, 4, 3, 20, 15};
    int size = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    findKthMinMax(arr, size, k);

    return 0;
}
