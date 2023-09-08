#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Function to find the length of the longest substring without repeating characters
int lengthOfLongestSubstring(const char *str) {
    int len = strlen(str);

    if (len == 0) {
        return 0; // If the string is empty, the longest substring is of length 0
    }

    int maxLen = 0; // Maximum length of the substring
    int start = 0; // Start of the current substring
    int charIndex[256]; // Hash table to store the last seen index of each character
    memset(charIndex, -1, sizeof(charIndex)); // Initialize all indices to -1

    for (int end = 0; end < len; end++) {
        char ch = str[end];

        // If the character has been seen in the current substring, update the start position
        if (charIndex[ch] >= start) {
            start = charIndex[ch] + 1;
        }

        // Update the last seen index of the character
        charIndex[ch] = end;

        // Calculate the length of the current substring
        int currentLen = end - start + 1;

        // Update the maximum length if needed
        if (currentLen > maxLen) {
            maxLen = currentLen;
        }
    }

    return maxLen;
}

int main() {
    const char *input_str = "pwwkew";
    int length = lengthOfLongestSubstring(input_str);

    printf("Length of the longest substring without repeating characters: %d\n", length);

    return 0;
}
