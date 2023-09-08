#include <stdio.h>
#include <stdbool.h>
#include <string.h>  // Include the string.h header for strchr

// Custom strtok function
char* customStrtok(char* str, const char* delimiter) {
    static char* nextToken = NULL;  // Pointer to the next token
    if (str != NULL)
        nextToken = str;  // Initialize with the input string
    
    if (nextToken == NULL || *nextToken == '\0')
        return NULL;  // No more tokens to find
    
    // Find the start of the token
    char* tokenStart = nextToken;
    
    // Find the end of the token (delimiter or null terminator)
    while (*nextToken != '\0' && !strchr(delimiter, *nextToken))
        nextToken++;
    
    if (*nextToken != '\0') {
        *nextToken = '\0';  // Replace delimiter with null terminator
        nextToken++;       // Move to the next character after the delimiter
    }
    
    return tokenStart;
}

int main() {
    char input[] = "embedded,systems,linux";
    const char delimiter[] = ",";

    // Use customStrtok to tokenize the input string
    char* token = customStrtok(input, delimiter);
    
    while (token != NULL) {
        printf("%s\n", token);
        token = customStrtok(NULL, delimiter);
    }

    return 0;
}
