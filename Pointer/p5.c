#include <stdio.h>

void segregateEvenOdd(int arr[], int size) {
    int *left = arr;
    int *right = arr + size - 1;

    while (left < right) {
        // Move left pointer to the right while it points to an even number
        while ((*left % 2 == 0) && (left < right)) {
            left++;
        }

        // Move right pointer to the left while it points to an odd number
        while ((*right % 2 != 0) && (left < right)) {
            right--;
        }

        // Swap the elements at left and right pointers
        if (left < right) {
            int temp = *left;
            *left = *right;
            *right = temp;
        }
    }
}

int main() {
    int arr[] = {12, 34, 9, 8, 45, 90};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    segregateEvenOdd(arr, size);

    printf("\nArray After Segregation:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
