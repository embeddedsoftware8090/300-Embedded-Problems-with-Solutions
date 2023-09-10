#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the function to perform exponential search
bool exponentialSearch(int arr[], int size, int target) {
    if (arr[0] == target) {
        return true; // Element found at the first position
    }
    
    int bound = 1;
    
    // Double the bound until it exceeds the array size or the element is found
    while (bound < size && arr[bound] < target) {
        bound *= 2;
    }
    
    // Perform binary search within the identified range
    int left = bound / 2;
    int right = (bound < size) ? bound : (size - 1);
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target) {
            return true; // Element found
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return false; // Element not found
}

int main() {
    // Example sorted array (in this case, just an ascending sequence)
    int size = 100;
    int arr[size];
    for (int i = 0; i < size; i++) {
        arr[i] = i + 1;
    }
    
    int target = 5; // Element to search for
    
    if (exponentialSearch(arr, size, target)) {
        printf("I/P: [1, 2, 3, 4, 5, ....]; Element = %d; O/P: Found\n", target);
    } else {
        printf("I/P: [1, 2, 3, 4, 5, ....]; Element = %d; O/P: Not Found\n", target);
    }
    
    return 0;
}
