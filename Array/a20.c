#include <stdio.h>

// Function to rearrange the array as described
void rearrangeArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] += (arr[arr[i]] % n) * n;
    }

    for (int i = 0; i < n; i++) {
        arr[i] /= n;
    }
}

int main() {
    int arr[] = {0, 1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    rearrangeArray(arr, n);

    printf("Rearranged Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
