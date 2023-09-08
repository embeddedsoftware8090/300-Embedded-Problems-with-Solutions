#include <stdio.h>
#include <stdbool.h>

// Function to find the longest consecutive subsequence in an array
void findLongestConsecutiveSubsequence(int arr[], int n) {
    int longestLength = 0;
    int currentLength = 0;
    int startOfSubsequence = 0;
    int endOfSubsequence = 0;
    
    // Create a hash set to store elements
    bool hashSet[10000] = {false}; // Assuming the range of elements won't exceed 10000

    // Fill the hash set with elements from the array
    for (int i = 0; i < n; i++) {
        hashSet[arr[i]] = true;
    }

    // Iterate through the array to find the longest consecutive subsequence
    for (int i = 0; i < n; i++) {
        int currentElement = arr[i];

        if (!hashSet[currentElement - 1]) {
            int j = currentElement;
            while (hashSet[j]) {
                j++;
            }

            currentLength = j - currentElement;

            if (currentLength > longestLength) {
                longestLength = currentLength;
                startOfSubsequence = currentElement;
                endOfSubsequence = j - 1;
            }
        }
    }

    // Print the longest consecutive subsequence
    printf("Longest Consecutive Subsequence: ");
    for (int i = startOfSubsequence; i <= endOfSubsequence; i++) {
        printf("%d ", i);
    }
    printf("\n");
}

int main() {
    int arr[] = {1, 9, 3, 10, 4, 20, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    findLongestConsecutiveSubsequence(arr, n);

    return 0;
}
