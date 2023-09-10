#include <stdio.h>

// Function to find the majority element using Boyer-Moore Voting Algorithm
int findMajorityElement(int arr[], int size) {
    int candidate = -1;
    int count = 0;

    // Find a candidate for the majority element
    for (int i = 0; i < size; i++) {
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
    for (int i = 0; i < size; i++) {
        if (arr[i] == candidate) {
            count++;
        }
    }

    if (count > size / 2) {
        return candidate;
    } else {
        return -1; // No majority element
    }
}

int main() {
    int arr[] = {3, 3, 4, 2, 4, 4, 2, 4, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    int majorityElement = findMajorityElement(arr, size);

    if (majorityElement != -1) {
        printf("Majority element: %d\n", majorityElement);
    } else {
        printf("No majority element found.\n");
    }

    return 0;
}
