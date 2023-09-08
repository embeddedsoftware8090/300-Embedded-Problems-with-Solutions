#include <stdio.h>

// Function to merge two sorted arrays into one sorted array
void mergeSortedArrays(int arr1[], int n1, int arr2[], int n2, int mergedArr[]) {
    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2) {
        if (arr1[i] <= arr2[j]) {
            mergedArr[k] = arr1[i];
            i++;
        } else {
            mergedArr[k] = arr2[j];
            j++;
        }
        k++;
    }

    // Copy any remaining elements from arr1
    while (i < n1) {
        mergedArr[k] = arr1[i];
        i++;
        k++;
    }

    // Copy any remaining elements from arr2
    while (j < n2) {
        mergedArr[k] = arr2[j];
        j++;
        k++;
    }
}

int main() {
    int arr1[] = {1, 3, 5};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = {2, 4, 6};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    int mergedArr[n1 + n2];

    mergeSortedArrays(arr1, n1, arr2, n2, mergedArr);

    printf("Merged Array: ");
    for (int i = 0; i < n1 + n2; i++) {
        printf("%d ", mergedArr[i]);
    }
    printf("\n");

    return 0;
}
