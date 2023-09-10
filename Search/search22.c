#include <stdio.h>

int findSmallestMissing(int arr[], int size) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // If the middle element is not equal to its index, the smallest missing number is on the left.
        if (arr[mid] != mid) {
            right = mid - 1;
        } else {
            // Otherwise, it's on the right.
            left = mid + 1;
        }
    }

    // The smallest missing number is found when left > right.
    return left;
}

int main() {
    int arr[] = {0, 1, 2, 6, 9};
    int size = sizeof(arr) / sizeof(arr[0]);

    int smallestMissing = findSmallestMissing(arr, size);

    printf("I/P: [");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("]; O/P: %d\n", smallestMissing);

    return 0;
}
