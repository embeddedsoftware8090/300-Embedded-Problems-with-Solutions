#include <stdio.h>
void printSubarrayWithLeastSum (int arr [], int n) {
    int min_sum = arr [0]; // initialize minimum sum as first element
    int start = 0; // initialize starting index as 0
    int end = 0; // initialize ending index as 0
    for (int i = 0; i < n; i++) { // loop for each element of the array
        int curr_sum = 0; // initialize current sum as 0
        for (int j = i; j < n; j++) { // loop for each subarray starting from i
            curr_sum += arr [j]; // add current element to current sum
            if (curr_sum < min_sum) { // if current sum is smaller than minimum sum
                min_sum = curr_sum; // update minimum sum
                start = i; // update starting index
                end = j; // update ending index
            }
        }
    }
    printf("The subarray with the least sum is: ");
    for (int i = start; i <= end; i++) { // loop for printing the subarray
        printf("%d ", arr [i]);
    }
    printf("\nThe least sum is: %d", min_sum);
}
int main () {
    int arr [] = {3, 1, -4, 2, 0};
    int n = sizeof(arr) / sizeof(arr [0]);
    printSubarrayWithLeastSum (arr, n);
    return 0;
}
