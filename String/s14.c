#include <stdio.h>
#include <string.h>

// Function to reverse a string using recursion
void reverseStringRecursive(char *str, int start, int end) {
    if (start >= end) {
        return; // Base case: when the start index is greater than or equal to the end index
    }

    // Swap the characters at the start and end positions
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;

    // Recursively reverse the substring between start+1 and end-1
    reverseStringRecursive(str, start + 1, end - 1);
}

int main() {
    char input_str[] = "hello";
    int len = strlen(input_str);

    // Reverse the string using recursion
    reverseStringRecursive(input_str, 0, len - 1);

    printf("Reversed string: %s\n", input_str);

    return 0;
}
