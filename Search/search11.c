#include <stdio.h>

// Function to find a peak element in an array using binary search
int findPeakElement(int arr[], int left, int right) {
    while (left < right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] > arr[mid + 1]) {
            // The peak element must be in the left half (including mid)
            right = mid;
        } else {
            // The peak element must be in the right half (excluding mid)
            left = mid + 1;
        }
    }
    return left;
}

int main() {
    int arr[] = {1, 3, 5, 4, 2};
    int size = sizeof(arr) / sizeof(arr[0]);

    int peakIndex = findPeakElement(arr, 0, size - 1);
    int peakElement = arr[peakIndex];

    printf("Peak element: %d\n", peakElement);

    return 0;
}
