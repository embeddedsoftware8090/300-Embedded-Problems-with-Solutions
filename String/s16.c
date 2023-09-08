#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

// Function to check if a string is a pangram
bool isPangram(const char *str) {
    // Initialize an array to track the occurrence of each letter in the alphabet
    bool alphabet[26] = {false};

    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        char ch = tolower(str[i]); // Convert the character to lowercase for case insensitivity

        if (ch >= 'a' && ch <= 'z') { // Check if the character is a lowercase alphabet
            alphabet[ch - 'a'] = true; // Mark the presence of the letter
        }
    }

    // Check if all letters are present in the alphabet array
    for (int i = 0; i < 26; i++) {
        if (!alphabet[i]) {
            return false; // If any letter is missing, it's not a pangram
        }
    }

    return true; // All letters are present, it's a pangram
}

int main() {
    const char *input_str = "Jinxed wizards pluck ivy from the big quilt";

    if (isPangram(input_str)) {
        printf("True\n");
    } else {
        printf("False\n");
    }

    return 0;
}
