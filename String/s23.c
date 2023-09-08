#include <stdio.h>
#include <string.h>

// Function to find the maximum occurring character in a string
char findMaxOccurringCharacter(const char *str) {
    int len = strlen(str);

    // Create an array to store the frequency count of each character
    int frequency[256] = {0};

    // Initialize variables to keep track of the maximum frequency and the character with that frequency
    int maxFrequency = 0;
    char maxChar = '\0';

    // Iterate through the string and update the frequency count
    for (int i = 0; i < len; i++) {
        char ch = str[i];
        frequency[ch]++;
        
        // Check if the current character has a higher frequency than the previous maximum
        if (frequency[ch] > maxFrequency) {
            maxFrequency = frequency[ch];
            maxChar = ch;
        }
    }

    return maxChar;
}

int main() {
    const char *input_str = "success";
    char maxChar = findMaxOccurringCharacter(input_str);

    printf("Maximum occurring character: %c\n", maxChar);

    return 0;
}
