#include <stdio.h>
#include <string.h>

// Function to reverse a string from start to end
void reverseString(char *start, char *end) {
    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

// Function to reverse words in a sentence
void reverseWords(char *sentence) {
    int len = strlen(sentence);

    // Reverse the entire sentence first
    reverseString(sentence, sentence + len - 1);

    // Initialize pointers for word reversal
    char *word_start = sentence;
    char *word_end = sentence;

    // Iterate through the sentence
    while (*word_end != '\0') {
        if (*word_end == ' ') {
            // Found a space, reverse the current word
            reverseString(word_start, word_end - 1);

            // Move to the next word (skip spaces)
            while (*word_end == ' ') {
                word_end++;
            }

            // Update word_start to the beginning of the next word
            word_start = word_end;
        } else {
            word_end++;
        }
    }

    // Reverse the last word (or the only word if there's only one)
    reverseString(word_start, word_end - 1);
}

int main() {
    char input_sentence[] = "Hello Word";
    reverseWords(input_sentence);
    printf("Reversed sentence: %s\n", input_sentence);

    return 0;
}
