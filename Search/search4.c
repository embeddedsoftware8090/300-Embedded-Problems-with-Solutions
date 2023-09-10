#include <stdio.h>

// Function to perform interpolation search
int interpolationSearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right && target >= arr[left] && target <= arr[right]) {
        if (left == right) {
            if (arr[left] == target) {
                return left;
            }
            return -1; // Target not found
        }

        // Calculate the probable position using interpolation formula
        int pos = left + ((double)(right - left) / (arr[right] - arr[left])) * (target - arr[left]);

        if (arr[pos] == target) {
            return pos; // Target found
        }

        if (arr[pos] < target) {
            left = pos + 1;
        } else {
            right = pos - 1;
        }
    }

    return -1; // Target not found
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 4;

    int result = interpolationSearch(arr, size, target);

    if (result != -1) {
        printf("Element %d found at index %d\n", target, result);
    } else {
        printf("Element %d not found in the array\n", target);
    }

    return 0;
}
