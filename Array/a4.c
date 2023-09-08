#include <stdio.h>
#include <stdlib.h>

// Structure to represent a pair of integers
typedef struct {
    int first;
    int second;
} Pair;

// Function to compare two pairs for equality
int arePairsEqual(Pair p1, Pair p2) {
    return (p1.first == p2.first && p1.second == p2.second) ||
           (p1.first == p2.second && p1.second == p2.first);
}

// Function to find all pairs with a given sum
void findPairsWithSum(int arr[], int n, int targetSum) {
    // Create a hash set to store seen elements
    int seen[1000] = {0}; // Assuming a reasonable range of input values

    // Create an array to store pairs
    Pair *pairs = malloc(sizeof(Pair) * n);
    int pairCount = 0;

    // Iterate through the array
    for (int i = 0; i < n; i++) {
        int complement = targetSum - arr[i];

        // Check if the complement exists in the hash set
        if (complement >= 0 && seen[complement]) {
            // Create a pair with the current element and its complement
            Pair newPair;
            newPair.first = arr[i];
            newPair.second = complement;

            // Check if the pair already exists in the pairs array
            int found = 0;
            for (int j = 0; j < pairCount; j++) {
                if (arePairsEqual(pairs[j], newPair)) {
                    found = 1;
                    break;
                }
            }

            // If the pair is not already found, add it to the pairs array
            if (!found) {
                pairs[pairCount] = newPair;
                pairCount++;
            }
        }

        // Mark the current element as seen
        seen[arr[i]] = 1;
    }

    // Print the pairs with the given sum
    printf("Pairs with sum %d: [", targetSum);
    for (int i = 0; i < pairCount; i++) {
        printf("(%d, %d)", pairs[i].first, pairs[i].second);
        if (i < pairCount - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    free(pairs);
}

int main() {
    int arr[] = {2, 4, 3, 5, 6, -2, 4, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int targetSum = 7;

    findPairsWithSum(arr, n, targetSum);

    return 0;
}
