#include <stdio.h>
#include <string.h>

// Function to decode a string
void decodeString(char *str) {
    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        char ch = str[i];

        if (ch >= 'a' && ch <= 'z') {
            // Apply the decoding transformation, wrapping around 'a'
            ch = 'a' + (ch - 'a' - 3 + 26) % 26;
        } else if (ch >= 'A' && ch <= 'Z') {
            // Apply the decoding transformation, wrapping around 'A'
            ch = 'A' + (ch - 'A' - 3 + 26) % 26;
        }

        str[i] = ch; // Update the character in the string
    }
}

int main() {
    char input_str[] = "edonxpdu";

    printf("Encoded string: %s\n", input_str);

    decodeString(input_str);

    printf("Decoded string: %s\n", input_str);

    return 0;
}
