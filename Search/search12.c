#include <stdio.h>

// Function to find the missing number using binary search
int findMissingNumberBinary(int arr[], int size) {
    int left = 0, right = size - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        // Check if the mid element is in its correct position
        if (arr[mid] == mid + 1) {
            left = mid + 1; // Move to the right half
        } else {
            right = mid - 1; // Move to the left half
        }
    }
    
    return left + 1;
}

// Function to find the missing number using the mathematical formula
int findMissingNumberFormula(int arr[], int size) {
    int totalSum = ((size + 1) * (size + 2)) / 2;
    int arraySum = 0;
    
    for (int i = 0; i < size; i++) {
        arraySum += arr[i];
    }
    
    return totalSum - arraySum;
}

int main() {
    int arr[] = {1, 2, 4, 6, 5, 7, 8};
    int size = sizeof(arr) / sizeof(arr[0]);

    int missingNumberBinary = findMissingNumberBinary(arr, size);
    int missingNumberFormula = findMissingNumberFormula(arr, size);

    printf("Missing number (Binary Search): %d\n", missingNumberBinary);
    printf("Missing number (Formula): %d\n", missingNumberFormula);

    return 0;
}
