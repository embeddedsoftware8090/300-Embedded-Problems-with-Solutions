#include <stdio.h>
#include <string.h>

// Function to swap two characters in a string
void swap(char *x, char *y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}

// Function to find all permutations of a string
void findPermutations(char *str, int start, int end) {
    if (start == end) {
        printf("%s\n", str); // Print the current permutation
    } else {
        for (int i = start; i <= end; i++) {
            // Swap characters at positions start and i
            swap(&str[start], &str[i]);

            // Recursively generate permutations for the substring str[start+1:end]
            findPermutations(str, start + 1, end);

            // Restore the original order of characters for backtracking
            swap(&str[start], &str[i]);
        }
    }
}

int main() {
    char input_str[] = "bal";
    int len = strlen(input_str);

    printf("Permutations of \"%s\":\n", input_str);
    findPermutations(input_str, 0, len - 1);

    return 0;
}
