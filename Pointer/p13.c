#include <stdio.h>

void toLowerCase(char *str) {
    while (*str != '\0') {
        if (*str >= 'A' && *str <= 'Z') {
            *str = *str + ('a' - 'A');
        }
        str++;
    }
}

int main() {
    char str[] = "HELLO";
    
    printf("Original string: %s\n", str);
    toLowerCase(str);
    printf("Lowercase string: %s\n", str);

    return 0;
}
