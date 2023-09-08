#include <stdio.h>

void swapStrings(char **str1, char **str2) {
    char *temp = *str1;
    *str1 = *str2;
    *str2 = temp;
}

int main() {
    char *str1 = "hello";
    char *str2 = "world";

    printf("Before Swap:\n");
    printf("str1 = %s\n", str1);
    printf("str2 = %s\n", str2);

    swapStrings(&str1, &str2);

    printf("\nAfter Swap:\n");
    printf("str1 = %s\n", str1);
    printf("str2 = %s\n", str2);

    return 0;
}
