#include <stdio.h>

// Function to reverse an array from 'start' to 'end'
void reverse(int arr[], int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

// Function to rotate an array to the right by 'k' elements
void rotateRight(int arr[], int size, int k) {
    k = k % size; // Ensure 'k' is within the range of array size
    
    if (k == 0) {
        return; // No need to rotate
    }
    
    reverse(arr, 0, size - 1);      // Reverse the entire array
    reverse(arr, 0, k - 1);         // Reverse the first 'k' elements
    reverse(arr, k, size - 1);      // Reverse the remaining elements
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int k = 2; // Number of elements to rotate
    
    rotateRight(arr, size, k);
    
    printf("Rotated Array: {");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("}\n");
    
    return 0;
}
