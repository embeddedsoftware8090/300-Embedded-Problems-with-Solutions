#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Function to check if a string is an interleaving of two other strings
bool isInterleaving(const char *str1, const char *str2, const char *interleaved) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int len3 = strlen(interleaved);

    // If the combined length of str1 and str2 is not equal to the length of interleaved, it's not possible
    if (len1 + len2 != len3) {
        return false;
    }

    // Create a 2D array to store whether substrings of interleaved can be formed by interleaving str1 and str2
    bool dp[len1 + 1][len2 + 1];
    memset(dp, false, sizeof(dp)); // Initialize the array to false

    // Initialize the base case
    dp[0][0] = true;

    // Fill in the first row
    for (int j = 1; j <= len2; j++) {
        if (str2[j - 1] == interleaved[j - 1] && dp[0][j - 1]) {
            dp[0][j] = true;
        }
    }

    // Fill in the first column
    for (int i = 1; i <= len1; i++) {
        if (str1[i - 1] == interleaved[i - 1] && dp[i - 1][0]) {
            dp[i][0] = true;
        }
    }

    // Fill in the rest of the table
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if ((str1[i - 1] == interleaved[i + j - 1] && dp[i - 1][j]) || (str2[j - 1] == interleaved[i + j - 1] && dp[i][j - 1])) {
                dp[i][j] = true;
            }
        }
    }

    // Return the result at the bottom-right corner of the table
    return dp[len1][len2];
}

int main() {
    const char *str1 = "xyz";
    const char *str2 = "789";
    const char *interleaved = "x7y8z9";

    if (isInterleaving(str1, str2, interleaved)) {
        printf("True\n");
    } else {
        printf("False\n");
    }

    return 0;
}
