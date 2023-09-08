#include <stdio.h>

int main() {
    int *ptr1, *ptr2;
    
    ptr1 = ptr2 + 1; // Increment the pointer by 1
    
    // Calculate the size of the data type
    int size = (int)ptr1 - (int)ptr2;
    
    printf("Size of int: %d\n", size);

    return 0;
}
