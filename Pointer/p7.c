#include <stdio.h>
#include <stdlib.h> // Include this header for malloc and free
#include <string.h>

void splitString(const char *input, char **firstHalf, char **secondHalf) {
    int len = strlen(input);

    // Calculate the midpoint of the string
    int midpoint = len / 2;

    // Allocate memory for the two halves
    *firstHalf = (char *)malloc(midpoint + 1);
    *secondHalf = (char *)malloc(len - midpoint + 1);

    // Copy the first half of the string
    strncpy(*firstHalf, input, midpoint);
    (*firstHalf)[midpoint] = '\0';

    // Copy the second half of the string
    strcpy(*secondHalf, input + midpoint);
}

int main() {
    const char *input = "HelloWorld";
    char *firstHalf;
    char *secondHalf;

    splitString(input, &firstHalf, &secondHalf);

    printf("First Half: %s\n", firstHalf);
    printf("Second Half: %s\n", secondHalf);

    // Don't forget to free the allocated memory
    free(firstHalf);
    free(secondHalf);

    return 0;
}
