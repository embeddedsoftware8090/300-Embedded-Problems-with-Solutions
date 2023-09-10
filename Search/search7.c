#include <stdio.h>
#include <stdlib.h>

// Function to find the minimum of two integers
int min(int x, int y) {
    return (x <= y) ? x : y;
}

// Function to perform Fibonacci search
int fibonacciSearch(int arr[], int size, int target) {
    int fibM_minus_2 = 0; // (m-2)th Fibonacci number
    int fibM_minus_1 = 1; // (m-1)th Fibonacci number
    int fibM = fibM_minus_1 + fibM_minus_2; // mth Fibonacci number

    // Find the smallest Fibonacci number greater than or equal to size
    while (fibM < size) {
        fibM_minus_2 = fibM_minus_1;
        fibM_minus_1 = fibM;
        fibM = fibM_minus_1 + fibM_minus_2;
    }

    int offset = -1; // Offset to indicate comparison range

    while (fibM > 1) {
        // Check if fibM_minus_2 is a valid index
        int i = min(offset + fibM_minus_2, size - 1);

        // If the target is greater than the current element, move the offset and update Fibonacci numbers
        if (arr[i] < target) {
            fibM = fibM_minus_1;
            fibM_minus_1 = fibM_minus_2;
            fibM_minus_2 = fibM - fibM_minus_1;
            offset = i;
        }
        // If the target is smaller than the current element, update Fibonacci numbers only
        else if (arr[i] > target) {
            fibM = fibM_minus_2;
            fibM_minus_1 = fibM_minus_1 - fibM_minus_2;
            fibM_minus_2 = fibM - fibM_minus_1;
        }
        // If the target is found, return the index
        else {
            return i;
        }
    }

    // If the target is not found, return -1
    if (fibM_minus_1 && arr[offset + 1] == target) {
        return offset + 1;
    }

    return -1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 2;

    int result = fibonacciSearch(arr, size, target);

    if (result != -1) {
        printf("Element %d found at index %d\n", target, result);
    } else {
        printf("Element %d not found in the array\n", target);
    }

    return 0;
}
