#include <stdio.h>
#include <string.h>

void findDuplicateCharacters(const char *str) {
    int char_count[256] = {0}; // Initialize an array to store character counts (assuming ASCII characters)

    int len = strlen(str);

    // Iterate through the string and count the occurrences of each character
    for (int i = 0; i < len; i++) {
        char_count[(int)str[i]]++;
    }

    // Iterate through the character counts and print duplicate characters
    printf("Duplicate characters: ");
    for (int i = 0; i < 256; i++) {
        if (char_count[i] > 1) {
            printf("%c,", (char)i); // Print characters with count > 1
        }
    }
    printf("\n");
}

int main() {
    const char *input_str = "programming";
    findDuplicateCharacters(input_str);
    return 0;
}
