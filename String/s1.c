#include <stdio.h>
#include <string.h>

void findDuplicateCharacters(const char *input_string) {
    int char_count[256] = {0};  // Initialize an array to store character counts

    // Iterate through the string
    for (int i = 0; i < strlen(input_string); i++) {
        char_count[(int)input_string[i]]++;  // Increment the count for the current character
    }

    // Iterate through the character counts
    printf("Duplicate characters: ");
    for (int i = 0; i < 256; i++) {
        if (char_count[i] > 1) {
            printf("%c ", (char)i);  // Print characters with count > 1
        }
    }
    printf("\n");
}

int main() {
    const char *input_str = "aplllle";
    findDuplicateCharacters(input_str);
    return 0;
}
