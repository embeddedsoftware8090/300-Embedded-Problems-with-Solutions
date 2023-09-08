#include <stdio.h>

void findOverlap(int arr1[], int size1, int arr2[], int size2) {
    int *ptr1 = arr1;
    int *ptr2 = arr2;
    
    printf("Overlapping Part: {");
    
    while (ptr1 < arr1 + size1 && ptr2 < arr2 + size2) {
        if (*ptr1 == *ptr2) {
            if (ptr1 != arr1) {
                printf(",");
            }
            printf("%d", *ptr1);
            ptr1++;
            ptr2++;
        } else if (*ptr1 < *ptr2) {
            ptr1++;
        } else {
            ptr2++;
        }
    }
    
    printf("}\n");
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5, 6};
    int arr2[] = {5, 6, 7, 8};
    
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    
    findOverlap(arr1, size1, arr2, size2);
    
    return 0;
}
