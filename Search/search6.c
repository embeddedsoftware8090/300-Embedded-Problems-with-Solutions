#include <stdio.h>
#include <math.h>

// Function to perform jump search
int jumpSearch(int arr[], int size, int target) {
    int step = sqrt(size); // Set the step size
    int prev = 0;

    // Jump ahead by step size
    while (arr[(int)fmin(step, size) - 1] < target) {
        prev = step;
        step += sqrt(size);

        if (prev >= size) {
            return -1; // Element not found
        }
    }

    // Perform linear search within the step
    for (int i = prev; i < fmin(step, size); i++) {
        if (arr[i] == target) {
            return i; // Target found
        }
    }

    return -1; // Target not found
}

int main() {
    int arr[] = {1, 3, 5, 7, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 7;

    int result = jumpSearch(arr, size, target);

    if (result != -1) {
        printf("Element %d found at index %d\n", target, result);
    } else {
        printf("Element %d not found in the array\n", target);
    }

    return 0;
}
