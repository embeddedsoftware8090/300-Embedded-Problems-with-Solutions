#include <stdio.h>
#include <string.h>

int countCharacterOccurrences(const char *str, char target) {
    int count = 0;
    int len = strlen(str);

    // Iterate through the string and count occurrences of the target character
    for (int i = 0; i < len; i++) {
        if (str[i] == target) {
            count++;
        }
    }

    return count;
}

int main() {
    const char *input_str = "apple";
    char target_char = 'p';
    int result = countCharacterOccurrences(input_str, target_char);

    printf("Occurrences of '%c': %d\n", target_char, result);

    return 0;
}
