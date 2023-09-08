#include <stdio.h>
#include <string.h>

// Function to check if one string is a rotation of another and determine the rotation position
int isRotation(const char *str1, const char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    // Check if both strings have the same length and are not empty
    if (len1 != len2 || len1 == 0) {
        return -1; // Invalid or not a rotation
    }

    // Concatenate str1 with itself
    char concatenatedStr[2 * len1 + 1]; // +1 for the null terminator
    strcpy(concatenatedStr, str1);
    strcat(concatenatedStr, str1);

    // Check if str2 is a substring of concatenatedStr
    char *rotationPosition = strstr(concatenatedStr, str2);

    if (rotationPosition != NULL) {
        // Calculate the rotation position (index at which str2 starts in concatenatedStr)
        int rotationIndex = rotationPosition - concatenatedStr;

        if (rotationIndex < len1) {
            // Rotation to the left
            return len1 - rotationIndex;
        } else {
            // Rotation to the right
            return 2 * len1 - rotationIndex;
        }
    } else {
        return -1; // Not a rotation
    }
}

int main() {
    const char *str1 = "abcde";
    const char *str2 = "cdeab";
    int rotation = isRotation(str1, str2);

    if (rotation != -1) {
        printf("Rotation: %d%s\n", rotation, (rotation > 0) ? "L" : "R");
    } else {
        printf("Not a rotation.\n");
    }

    return 0;
}
