#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Function to check if a string can be formed by repeating a substring
bool repeatedSubstringPattern(const char *str) {
    int len = strlen(str);

    // Iterate through possible substring lengths
    for (int substringLen = 1; substringLen <= len / 2; substringLen++) {
        if (len % substringLen == 0) {
            int repetitions = len / substringLen;
            bool isRepeated = true;

            // Check if the string can be formed by repeating the current substring
            for (int i = 0; i < len; i++) {
                if (str[i] != str[i % substringLen]) {
                    isRepeated = false;
                    break;
                }
            }

            if (isRepeated) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    const char *input_str = "abab";
    bool result = repeatedSubstringPattern(input_str);

    if (result) {
        printf("The string can be formed by repeating a substring.\n");
    } else {
        printf("The string cannot be formed by repeating a substring.\n");
    }

    return 0;
}
