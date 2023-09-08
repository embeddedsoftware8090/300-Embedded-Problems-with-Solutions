#include <stdio.h>
#include <string.h>

// Function to find the longest palindrome substring in a given string
char* longestPalindrome(char* s) {
    int len = strlen(s);
    if (len <= 1) {
        return s; // A single character or an empty string is a palindrome
    }

    // Create a table to store the palindrome information
    int table[len][len];
    memset(table, 0, sizeof(table));

    int max_len = 1; // Initialize the maximum palindrome length
    int start = 0;   // Initialize the starting index of the longest palindrome

    // All substrings of length 1 are palindromes
    for (int i = 0; i < len; i++) {
        table[i][i] = 1;
    }

    // Check for palindromes of length 2
    for (int i = 0; i < len - 1; i++) {
        if (s[i] == s[i + 1]) {
            table[i][i + 1] = 1;
            max_len = 2;
            start = i;
        }
    }

    // Check for palindromes of length greater than 2
    for (int curr_len = 3; curr_len <= len; curr_len++) {
        for (int i = 0; i < len - curr_len + 1; i++) {
            int j = i + curr_len - 1; // Ending index of the current substring

            // Check if the characters at the current indices match and if the
            // substring between them is a palindrome
            if (s[i] == s[j] && table[i + 1][j - 1] == 1) {
                table[i][j] = 1;

                // Update the maximum length and starting index if needed
                if (curr_len > max_len) {
                    max_len = curr_len;
                    start = i;
                }
            }
        }
    }

    // Extract and return the longest palindrome substring
    char* result = malloc(max_len + 1);
    strncpy(result, s + start, max_len);
    result[max_len] = '\0';

    return result;
}

int main() {
    char input_str[] = "babad";
    char* result = longestPalindrome(input_str);

    printf("Longest palindrome substring: %s\n", result);

    // Free dynamically allocated memory
    free(result);

    return 0;
}
