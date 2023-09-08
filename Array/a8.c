#include <stdio.h>

// Function to check if an element is in the array
int isInArray(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return 1; // Element found in the array
        }
    }
    return 0; // Element not found in the array
}

// Function to find the intersection of two arrays
void findIntersection(int arr1[], int n1, int arr2[], int n2) {
    printf("Intersection: [");
    for (int i = 0; i < n1; i++) {
        if (isInArray(arr2, n2, arr1[i])) {
            printf("%d", arr1[i]);
            if (i < n1 - 1) {
                printf(", ");
            }
        }
    }
    printf("]\n");
}

int main() {
    int arr1[] = {1, 2, 4, 5, 6};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = {2, 3, 5, 7};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    findIntersection(arr1, n1, arr2, n2);

    return 0;
}
