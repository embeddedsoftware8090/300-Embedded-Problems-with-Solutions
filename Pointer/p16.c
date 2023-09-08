#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isPalindrome(const char *str) {
    int length = strlen(str);

    const char *start = str;
    const char *end = str + length - 1;

    while (start < end) {
        if (*start != *end) {
            return false; // Characters don't match
        }
        start++;
        end--;
    }

    return true; // All characters matched
}

int main() {
    const char *input = "radar";

    if (isPalindrome(input)) {
        printf("'%s' is a palindrome.\n", input);
    } else {
        printf("'%s' is not a palindrome.\n", input);
    }

    return 0;
}
