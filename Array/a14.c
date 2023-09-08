#include <stdio.h>

// Function to find the majority element
int findMajorityElement(int arr[], int n) {
    int candidate = arr[0];
    int count = 1;

    // Find a candidate for the majority element
    for (int i = 1; i < n; i++) {
        if (count == 0) {
            candidate = arr[i];
            count = 1;
        } else if (candidate == arr[i]) {
            count++;
        } else {
            count--;
        }
    }

    // Verify if the candidate is the majority element
    count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == candidate) {
            count++;
        }
    }

    if (count > n / 2) {
        return candidate; // Candidate is the majority element
    }

    return -1; // No majority element found
}

int main() {
    int arr[] = {3, 3, 4, 2, 4, 4, 2, 4, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    int majorityElement = findMajorityElement(arr, n);

    if (majorityElement != -1) {
        printf("Majority Element: %d\n", majorityElement);
    } else {
        printf("No Majority Element Found\n");
    }

    return 0;
}
