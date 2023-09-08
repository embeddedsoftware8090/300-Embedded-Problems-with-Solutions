#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

// Function to check if a string is a palindrome
bool isPalindrome(const char *str) {
    int len = strlen(str);
    int i = 0;        // Start from the beginning of the string
    int j = len - 1;  // Start from the end of the string

    while (i < j) {
        // Ignore non-alphanumeric characters from the beginning
        while (!isalnum(str[i]) && i < j) {
            i++;
        }
        
        // Ignore non-alphanumeric characters from the end
        while (!isalnum(str[j]) && i < j) {
            j--;
        }

        // Compare the characters (ignoring case)
        if (tolower(str[i]) != tolower(str[j])) {
            return false; // Mismatch found
        }

        i++;  // Move to the next character from the beginning
        j--;  // Move to the next character from the end
    }

    return true; // No mismatches found, it's a palindrome
}

int main() {
    const char *input_str = "radar";
    
    if (isPalindrome(input_str)) {
        printf("True\n");
    } else {
        printf("False\n");
    }

    return 0;
}
