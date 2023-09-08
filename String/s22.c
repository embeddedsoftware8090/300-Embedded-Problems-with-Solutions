#include <stdio.h>
#include <string.h>

// Function to encode a string
void encodeString(char *str) {
    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        char ch = str[i];

        if (ch >= 'a' && ch <= 'z') {
            // Apply the encoding transformation, wrapping around 'z'
            ch = 'a' + (ch - 'a' + 3) % 26;
        } else if (ch >= 'A' && ch <= 'Z') {
            // Apply the encoding transformation, wrapping around 'Z'
            ch = 'A' + (ch - 'A' + 3) % 26;
        }

        str[i] = ch; // Update the character in the string
    }
}

int main() {
    char input_str[] = "balkumar";

    printf("Original string: %s\n", input_str);

    encodeString(input_str);

    printf("Encoded string: %s\n", input_str);

    return 0;
}
