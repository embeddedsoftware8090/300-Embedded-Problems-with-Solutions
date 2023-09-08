#include <stdio.h>

int countElementsInArray(int arr[], int size) {
    // The size parameter indicates the number of elements in the array
    return size;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int elementCount = countElementsInArray(arr, sizeof(arr) / sizeof(arr[0]));

    printf("Number of elements in the array: %d\n", elementCount);

    return 0;
}
