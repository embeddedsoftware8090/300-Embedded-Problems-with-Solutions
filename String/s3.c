#include <stdio.h>
#include <string.h>

char firstNonRepeatedCharacter(const char *str) {
    int char_count[256] = {0};  // Initialize an array to store character counts

    // Iterate through the string and count the occurrences of each character
    for (int i = 0; i < strlen(str); i++) {
        char_count[(int)str[i]]++;
    }

    // Iterate through the string again to find the first non-repeated character
    for (int i = 0; i < strlen(str); i++) {
        if (char_count[(int)str[i]] == 1) {
            return str[i];  // Return the first non-repeated character
        }
    }

    // If no non-repeated character is found, return a sentinel value (e.g., '\0')
    return '\0';
}

int main() {
    const char *input_str = "swiss";
    char result = firstNonRepeatedCharacter(input_str);

    if (result != '\0') {
        printf("First non-repeated character: %c\n", result);
    } else {
        printf("No non-repeated character found.\n");
    }

    return 0;
}
