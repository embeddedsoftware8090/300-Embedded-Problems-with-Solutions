#include <stdio.h>

// Function to find the peak element (maximum) in a bitonic array
int findPeak(int arr[], int low, int high) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1]) {
            return mid;
        } else if (arr[mid] > arr[mid + 1]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1; // Should not happen for a valid bitonic array
}

// Function to perform binary search on the increasing part of the array
int binarySearchIncreasing(int arr[], int low, int high, int target) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

// Function to perform binary search on the decreasing part of the array
int binarySearchDecreasing(int arr[], int low, int high, int target) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

// Function to search for an element in a bitonic array
int searchBitonicArray(int arr[], int size, int target) {
    int peakIndex = findPeak(arr, 0, size - 1);
    
    if (arr[peakIndex] == target) {
        return peakIndex;
    }
    
    int leftResult = binarySearchIncreasing(arr, 0, peakIndex - 1, target);
    int rightResult = binarySearchDecreasing(arr, peakIndex + 1, size - 1, target);
    
    if (leftResult != -1) {
        return leftResult;
    } else if (rightResult != -1) {
        return rightResult;
    } else {
        return -1; // Element not found in the bitonic array
    }
}

int main() {
    int arr[] = {1, 3, 8, 12, 4, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 8;

    int result = searchBitonicArray(arr, size, target);

    if (result != -1) {
        printf("Element %d found at index %d\n", target, result);
    } else {
        printf("Element %d not found in the bitonic array\n", target);
    }

    return 0;
}
