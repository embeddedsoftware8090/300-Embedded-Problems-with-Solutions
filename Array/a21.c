#include <stdio.h>

// Function to find a peak element in the array
int findPeakElement(int arr[], int left, int right, int n) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if the middle element is a peak
        if ((mid == 0 || arr[mid] >= arr[mid - 1]) &&
            (mid == n - 1 || arr[mid] >= arr[mid + 1])) {
            return arr[mid];
        }

        // If the element to the right is greater, search in the right half
        if (mid < n - 1 && arr[mid] < arr[mid + 1]) {
            left = mid + 1;
        } else { // Otherwise, search in the left half
            right = mid - 1;
        }
    }

    return -1; // No peak element found
}

int main() {
    int arr[] = {1, 3, 20, 4, 1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    int peak = findPeakElement(arr, 0, n - 1, n);

    if (peak != -1) {
        printf("Peak Element: %d\n", peak);
    } else {
        printf("No Peak Element Found\n");
    }

    return 0;
}
