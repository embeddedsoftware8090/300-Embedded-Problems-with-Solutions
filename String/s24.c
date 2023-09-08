#include <stdio.h>
#include <string.h>

// Function to check if a string is a palindrome
int isPalindrome(const char *str, int start, int end) {
    while (start < end) {
        if (str[start] != str[end]) {
            return 0; // Not a palindrome
        }
        start++;
        end--;
    }
    return 1; // Palindrome
}

// Function to find the minimum cuts for palindrome partitioning
int minPalindromePartition(const char *str) {
    int len = strlen(str);

    // Create a 2D array to store whether substrings are palindromes
    int isPalindromeArray[len][len];

    // Initialize the array
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            isPalindromeArray[i][j] = 0;
        }
    }

    // Initialize the cut array to store minimum cuts
    int minCuts[len];

    // Initialize the cut array with the maximum possible cuts
    for (int i = 0; i < len; i++) {
        minCuts[i] = i;
    }

    for (int end = 1; end < len; end++) {
        for (int start = end; start >= 0; start--) {
            if (str[start] == str[end] && (end - start < 2 || isPalindromeArray[start + 1][end - 1])) {
                isPalindromeArray[start][end] = 1;

                if (start > 0) {
                    // Update the minimum cuts if necessary
                    minCuts[end] = (start > 0) ? (minCuts[start - 1] + 1) : 0;
                } else {
                    minCuts[end] = 0;
                }
            }
        }
    }

    return minCuts[len - 1];
}

int main() {
    const char *input_str = "aab";
    int minCuts = minPalindromePartition(input_str);

    printf("Minimum cuts for palindrome partitioning: %d\n", minCuts);

    return 0;
}
