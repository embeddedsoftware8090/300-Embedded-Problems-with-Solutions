#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Function to check if two strings are anagrams
bool areAnagrams(const char *str1, const char *str2) {
    int count1[26] = {0}; // Initialize an array to store character counts for str1 (assuming lowercase letters only)
    int count2[26] = {0}; // Initialize an array to store character counts for str2

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    // If the lengths of the strings are different, they cannot be anagrams
    if (len1 != len2) {
        return false;
    }

    // Count characters in str1
    for (int i = 0; i < len1; i++) {
        count1[str1[i] - 'a']++;
    }

    // Count characters in str2
    for (int i = 0; i < len2; i++) {
        count2[str2[i] - 'a']++;
    }

    // Compare the character counts
    for (int i = 0; i < 26; i++) {
        if (count1[i] != count2[i]) {
            return false; // If any character count differs, they are not anagrams
        }
    }

    return true; // If all character counts are the same, they are anagrams
}

int main() {
    const char *str1 = "listen";
    const char *str2 = "silent";
    
    if (areAnagrams(str1, str2)) {
        printf("The strings are anagrams.\n");
    } else {
        printf("The strings are not anagrams.\n");
    }

    return 0;
}
