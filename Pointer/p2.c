#include <stdio.h>
#include <stdbool.h>

// A function that returns true if two pointers point to the same array
bool same_array(int *p1, int *p2) {
    // Initialize two pointers to store the boundaries of the arrays
    int *start1 = p1;
    int *start2 = p2;
    int *end1 = p1;
    int *end2 = p2;

    // Traverse from p1 in backward direction until null or boundary is hit
    while (start1 != NULL && *start1 != '\0') {
        start1--;
    }

    // Traverse from p2 in backward direction until null or boundary is hit
    while (start2 != NULL && *start2 != '\0') {
        start2--;
    }

    // Traverse from p1 in forward direction until null or boundary is hit
    while (end1 != NULL && *end1 != '\0') {
        end1++;
    }

    // Traverse from p2 in forward direction until null or boundary is hit
    while (end2 != NULL && *end2 != '\0') {
        end2++;
    }

    // Compare the boundaries of the arrays
    if (start1 == start2 && end1 == end2) {
        return true; // The pointers belong to the same array
    } else {
        return false; // The pointers belong to different arrays
    }
}

int main() {
    // Test cases
    int arr[] = {1, 2, 3, 4};
    int *ptr1 = &arr[1];
    int *ptr2 = &arr[3];
    printf("%d\n", same_array(ptr1, ptr2)); // Output: 1 (true)

    int arr1[] = {5, 6, 7};
    int arr2[] = {8, 9};
    int *ptr3 = &arr1[0];
    int *ptr4 = &arr2[0];
    printf("%d\n", same_array(ptr3, ptr4)); // Output: 0 (false)

    return 0;
}
