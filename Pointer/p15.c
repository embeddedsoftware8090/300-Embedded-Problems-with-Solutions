#include <stdio.h>

void findIntersection(int arr1[], int size1, int arr2[], int size2) {
    int i = 0, j = 0;

    printf("Intersection: ");

    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            i++;
        } else if (arr1[i] > arr2[j]) {
            j++;
        } else {
            // When elements match, print and increment both pointers
            printf("%d ", arr1[i]);
            i++;
            j++;
        }
    }

    printf("\n");
}

int main() {
    int arr1[] = {1, 2, 3, 4};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = {3, 4, 5, 6};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    findIntersection(arr1, size1, arr2, size2);

    return 0;
}
