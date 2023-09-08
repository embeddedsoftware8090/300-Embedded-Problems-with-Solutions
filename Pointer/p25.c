#include <stdio.h>
#include <stdbool.h>

// Custom function to check if a pointer is out of bounds of an array
bool isPointerOutOfBounds(const int* arr, const int* ptr) {
    const int* firstElement = &arr[0];
    const int* pastTheLastElement = &arr[sizeof(arr) / sizeof(arr[0])];
    
    return (ptr < firstElement || ptr >= pastTheLastElement);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int* pointer1 = &arr[2]; // Points to the third element (3)
    int* pointer2 = &arr[5]; // Points after the last element
    
    if (isPointerOutOfBounds(arr, pointer1)) {
        printf("Pointer1 is out of bounds.\n");
    } else {
        printf("Pointer1 is within bounds.\n");
    }
    
    if (isPointerOutOfBounds(arr, pointer2)) {
        printf("Pointer2 is out of bounds.\n");
    } else {
        printf("Pointer2 is within bounds.\n");
    }
    
    return 0;
}
