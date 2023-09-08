#include <stdio.h>

void findMinMax(int arr[], int n, int *min, int *max) {
    // Initialize min and max with the first element of the array
    *min = *max = arr[0];

    // Iterate through the array to update min and max
    for (int i = 1; i < n; i++) {
        if (arr[i] < *min) {
            // Update min if a smaller value is found
            *min = arr[i];
        } else if (arr[i] > *max) {
            // Update max if a larger value is found
            *max = arr[i];
        }
    }
}

int main() {
    int arr[] = {34, 15, 88, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    int min, max;
    findMinMax(arr, n, &min, &max);

    printf("Max: %d, Min: %d\n", max, min);

    return 0;
}
