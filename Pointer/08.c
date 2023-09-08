#include <stdio.h>
#include <string.h>

void trimString(char *str) {
    if (str == NULL) {
        return; // Handle NULL input gracefully
    }

    char *start = str;
    char *end = str + strlen(str) - 1;

    // Trim leading whitespace
    while (*start == ' ' || *start == '\t' || *start == '\n') {
        start++;
    }

    // Trim trailing whitespace
    while (*end == ' ' || *end == '\t' || *end == '\n') {
        end--;
    }

    // Move characters to the beginning of the string
    while (start <= end) {
        *str = *start;
        str++;
        start++;
    }

    *str = '\0'; // Null-terminate the trimmed string
}

int main() {
    char str[] = "  Hello World  ";
    trimString(str);
    printf("Trimmed String: \"%s\"\n", str);

    return 0;
}
