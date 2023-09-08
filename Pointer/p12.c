#include <stdio.h>
#include <stdbool.h>

bool isPrefix(const char *str1, const char *str2) {
    while (*str1 != '\0' && *str2 != '\0') {
        if (*str1 != *str2) {
            return false;  // Characters don't match, not a prefix
        }
        str1++;
        str2++;
    }
    
    // If str2 is also null-terminated, it means str2 is a prefix of str1
    return (*str2 == '\0');
}

int main() {
    const char *str1 = "Hello";
    const char *str2 = "Hel";

    if (isPrefix(str1, str2)) {
        printf("%s is a prefix of %s\n", str2, str1);
    } else {
        printf("%s is not a prefix of %s\n", str2, str1);
    }

    return 0;
}
