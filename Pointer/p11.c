#include <stdio.h>

void mergeSortedArrays(int arr1[], int size1, int arr2[], int size2, int merged[]) {
    int *ptr1 = arr1;
    int *ptr2 = arr2;
    int *ptrMerged = merged;

    while (size1 > 0 && size2 > 0) {
        if (*ptr1 < *ptr2) {
            *ptrMerged = *ptr1;
            ptr1++;
            size1--;
        } else {
            *ptrMerged = *ptr2;
            ptr2++;
            size2--;
        }
        ptrMerged++;
    }

    // If elements are left in arr1, copy them to merged
    while (size1 > 0) {
        *ptrMerged = *ptr1;
        ptr1++;
        ptrMerged++;
        size1--;
    }

    // If elements are left in arr2, copy them to merged
    while (size2 > 0) {
        *ptrMerged = *ptr2;
        ptr2++;
        ptrMerged++;
        size2--;
    }
}

int main() {
    int arr1[] = {1, 3, 5};
    int arr2[] = {2, 4, 6};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int merged[size1 + size2];

    mergeSortedArrays(arr1, size1, arr2, size2, merged);

    printf("Merged Array: ");
    for (int i = 0; i < size1 + size2; i++) {
        printf("%d ", merged[i]);
    }

    return 0;
}
