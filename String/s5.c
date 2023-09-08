#include <stdio.h>
#include <string.h>

int isNumeric(const char *str) {
    int len = strlen(str);

    // Iterate through the characters in the string
    for (int i = 0; i < len; i++) {
        // Check if the current character is not a digit
        if (str[i] < '0' || str[i] > '9') {
            return 0; // Not a numeric digit
        }
    }

    return 1; // All characters are numeric digits
}

int main() {
    const char *input_str = "1234a";
    
    if (isNumeric(input_str)) {
        printf("True\n");
    } else {
        printf("False\n");
    }

    return 0;
}
