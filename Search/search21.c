#include <stdio.h>

void findTwoSum(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left < right) {
        int currentSum = arr[left] + arr[right];

        if (currentSum == target) {
            printf("I/P: [");
            for (int i = 0; i < size; i++) {
                printf("%d", arr[i]);
                if (i < size - 1) {
                    printf(", ");
                }
            }
            printf("], N = %d; O/P: (%d, %d)\n", target, arr[left], arr[right]);
            return;
        } else if (currentSum < target) {
            left++;
        } else {
            right--;
        }
    }

    printf("No such pair found.\n");
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 9;

    findTwoSum(arr, size, target);

    return 0;
}
