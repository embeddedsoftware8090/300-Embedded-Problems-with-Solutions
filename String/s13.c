#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to count vowels and consonants in a string
void countVowelsAndConsonants(const char *str) {
    int vowels = 0;
    int consonants = 0;
    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        char ch = tolower(str[i]); // Convert the character to lowercase for case insensitivity

        if (ch >= 'a' && ch <= 'z') { // Check if the character is an alphabet
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                vowels++; // It's a vowel
            } else {
                consonants++; // It's a consonant
            }
        }
    }

    printf("Vowels: %d, Consonants: %d\n", vowels, consonants);
}

int main() {
    const char *input_str = "apple";
    countVowelsAndConsonants(input_str);

    return 0;
}
