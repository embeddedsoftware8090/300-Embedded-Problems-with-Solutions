#include <stdio.h>
#include <stdlib.h>

char *concatenateStrings(const char *str1, const char *str2) {
    // Calculate the length of the concatenated string
    int len1 = 0;
    while (str1[len1] != '\0') {
        len1++;
    }

    int len2 = 0;
    while (str2[len2] != '\0') {
        len2++;
    }

    // Allocate memory for the concatenated string
    char *result = (char *)malloc(len1 + len2 + 1);

    // Copy characters from str1 to result
    int i, j;
    for (i = 0; i < len1; i++) {
        result[i] = str1[i];
    }

    // Copy characters from str2 to result
    for (j = 0; j < len2; j++) {
        result[i + j] = str2[j];
    }

    // Null-terminate the concatenated string
    result[i + j] = '\0';

    return result;
}

int main() {
    const char *str1 = "Good ";
    const char *str2 = "Morning";

    char *concatenated = concatenateStrings(str1, str2);

    printf("Concatenated String: %s\n", concatenated);

    free(concatenated); // Don't forget to free the allocated memory

    return 0;
}
