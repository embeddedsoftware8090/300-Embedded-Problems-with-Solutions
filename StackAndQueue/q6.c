#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h> // Include for character manipulation functions

// Define a stack structure for characters
#define MAX_STACK_SIZE 100

typedef struct {
    char items[MAX_STACK_SIZE];
    int top;
} CharStack;

// Initialize an empty stack
void initStack(CharStack *stack) {
    stack->top = -1;
}

// Check if the stack is empty
bool isEmpty(const CharStack *stack) {
    return stack->top == -1;
}

// Push a character onto the stack
void push(CharStack *stack, char c) {
    if (stack->top < MAX_STACK_SIZE - 1) {
        stack->items[++stack->top] = c;
    } else {
        printf("Stack overflow!\n");
    }
}

// Pop a character from the stack
char pop(CharStack *stack) {
    if (!isEmpty(stack)) {
        return stack->items[stack->top--];
    } else {
        printf("Stack underflow!\n");
        return '\0';  // Return a default value (you can handle errors differently)
    }
}

// Check if a string is a palindrome
bool isPalindrome(const char *str) {
    CharStack stack;
    initStack(&stack);

    // Push lowercase characters onto the stack after stripping non-alphanumeric characters
    for (int i = 0; str[i] != '\0'; i++) {
        char c = tolower(str[i]);
        if (isalnum(c)) {
            push(&stack, c);
        }
    }

    // Pop characters from the stack and compare them with the original string
    for (int i = 0; str[i] != '\0'; i++) {
        char c = tolower(str[i]);
        if (isalnum(c)) {
            if (c != pop(&stack)) {
                return false; // Not a palindrome
            }
        }
    }

    // If the stack is empty, it's a palindrome
    return isEmpty(&stack);
}

int main() {
    const char *str = "RACECAR"; // Replace with your input string
    bool isPalin = isPalindrome(str);

    if (isPalin) {
        printf("Palindrome\n");
    } else {
        printf("Not a Palindrome\n");
    }

    return 0;
}
