#include <stdio.h>

int stringToInteger(const char *str) {
    int result = 0;
    int sign = 1;  // To handle negative numbers

    // Check for a negative sign
    if (*str == '-') {
        sign = -1;
        str++;  // Move past the negative sign
    }

    // Iterate through the characters in the string
    while (*str != '\0') {
        if (*str >= '0' && *str <= '9') {
            // Convert the character to its integer value and update the result
            result = result * 10 + (*str - '0');
        } else {
            // If a non-numeric character is encountered, stop the conversion
            break;
        }
        str++;  // Move to the next character
    }

    // Apply the sign to the result
    return result * sign;
}

int main() {
    const char *input_str = "1234";
    int result = stringToInteger(input_str);
    printf("Integer representation: %d\n", result);
    return 0;
}
