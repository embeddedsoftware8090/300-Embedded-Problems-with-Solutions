#include <stdio.h>

void rearrangeArray(int arr[], int n) {
    int positiveIndex = 0;

    // Traverse the array and move positive numbers to the front
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            int temp = arr[i];
            // Shift elements to the right to make space for the positive number
            for (int j = i; j > positiveIndex; j--) {
                arr[j] = arr[j - 1];
            }
            arr[positiveIndex] = temp;
            positiveIndex++;
        }
    }
}

int main() {
    int arr[] = {-1, 2, -3, 4, 5, 6, -7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    rearrangeArray(arr, n);

    printf("\nRearranged array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
