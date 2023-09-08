#include <stdio.h>
#include <string.h>

// Function to count the number of times a substring appears in a string
int countSubstringOccurrences(const char *mainStr, const char *subStr) {
    int mainLen = strlen(mainStr);
    int subLen = strlen(subStr);
    int count = 0;

    // Iterate through the main string
    for (int i = 0; i <= mainLen - subLen; i++) {
        // Check if the substring matches the portion of the main string starting at position i
        if (strncmp(mainStr + i, subStr, subLen) == 0) {
            count++;
        }
    }

    return count;
}

int main() {
    const char *mainStr = "banana";
    const char *subStr = "ana";
    int occurrences = countSubstringOccurrences(mainStr, subStr);

    printf("Substring \"%s\" appears %d times in \"%s\"\n", subStr, occurrences, mainStr);

    return 0;
}
