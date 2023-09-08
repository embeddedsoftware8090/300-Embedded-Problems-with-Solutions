#include <stdio.h>

// Function to find the equilibrium index of an array
int findEquilibriumIndex(int arr[], int n) {
    int totalSum = 0;
    int leftSum = 0;

    // Calculate the total sum of the array
    for (int i = 0; i < n; i++) {
        totalSum += arr[i];
    }

    for (int i = 0; i < n; i++) {
        // Subtract the current element from the total sum to get the right sum
        totalSum -= arr[i];

        // If left sum equals right sum, it's an equilibrium index
        if (leftSum == totalSum) {
            return i;
        }

        // Otherwise, add the current element to the left sum
        leftSum += arr[i];
    }

    // No equilibrium index found
    return -1;
}

int main() {
    int arr[] = {-7, 1, 5, 2, -4, 3, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    int equilibriumIndex = findEquilibriumIndex(arr, n);

    if (equilibriumIndex != -1) {
        printf("Equilibrium Index: %d\n", equilibriumIndex);
    } else {
        printf("No Equilibrium Index Found\n");
    }

    return 0;
}
