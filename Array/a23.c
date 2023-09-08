#include <stdio.h>
#include <stdbool.h>

// Function to compute and print the leaders in an array
void findLeaders(int arr[], int n) {
    int leader = arr[n - 1];
    printf("Leaders: %d ", leader);

    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] >= leader) {
            leader = arr[i];
            printf("%d ", leader);
        }
    }

    printf("\n");
}

int main() {
    int arr[] = {16, 17, 4, 3, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    findLeaders(arr, n);

    return 0;
}
