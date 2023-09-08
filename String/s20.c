#include <stdio.h>
#include <string.h>

// Function to find the lexicographically minimal rotation of a string
void findLexicographicallyMinimalRotation(const char *str) {
    int len = strlen(str);

    // Create a double-length string by concatenating the original string to itself
    char doubleStr[2 * len + 1];
    strcpy(doubleStr, str);
    strcat(doubleStr, str);

    // Initialize the lexicographically smallest string
    char minRotation[len + 1];
    strcpy(minRotation, str);

    // Iterate through all possible rotations
    for (int i = 1; i < len; i++) {
        // Compare the current rotation to the lexicographically smallest
        if (strncmp(doubleStr + i, minRotation, len) < 0) {
            strncpy(minRotation, doubleStr + i, len);
            minRotation[len] = '\0';
        }
    }

    printf("Lexicographically minimal rotation: %s\n", minRotation);
}

int main() {
    const char *input_str = "dacb";
    findLexicographicallyMinimalRotation(input_str);

    return 0;
}
