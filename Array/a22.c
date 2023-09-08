#include <stdio.h>

// Function to compute the product of an array except self
void productExceptSelf(int arr[], int n, int result[]) {
    int leftProduct[n];
    int rightProduct[n];

    // Initialize prefix and suffix product arrays
    leftProduct[0] = 1;
    rightProduct[n - 1] = 1;

    // Calculate prefix products
    for (int i = 1; i < n; i++) {
        leftProduct[i] = leftProduct[i - 1] * arr[i - 1];
    }

    // Calculate suffix products
    for (int i = n - 2; i >= 0; i--) {
        rightProduct[i] = rightProduct[i + 1] * arr[i + 1];
    }

    // Calculate the final result by multiplying prefix and suffix products
    for (int i = 0; i < n; i++) {
        result[i] = leftProduct[i] * rightProduct[i];
    }
}

int main() {
    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int result[n];

    productExceptSelf(arr, n, result);

    printf("Result: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    return 0;
}
