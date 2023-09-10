#include <stdio.h>
#include <stdbool.h>
#include <string.h>

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

// Parse and count the depth of nested commands
int countNestedDepth(const char *command) {
    CharStack stack;
    initStack(&stack);
    int depth = 0;

    for (int i = 0; command[i] != '\0'; i++) {
        char c = command[i];
        if (c == '{') {
            push(&stack, c);
        } else if (c == '}') {
            if (!isEmpty(&stack)) {
                pop(&stack);
                depth++;
            } else {
                printf("Mismatched closing brace at position %d\n", i);
                // Handle error: Unmatched closing brace
            }
        }
    }

    // Check if there are any unmatched opening braces
    if (!isEmpty(&stack)) {
        printf("Unmatched opening brace(s) in the command\n");
        // Handle error: Unmatched opening brace(s)
    }

    return depth;
}

int main() {
    const char *command = "{CMD1 {CMD2}}"; // Replace with your input command
    int depth = countNestedDepth(command);
    printf("Depth - %d\n", depth);  // Output: Depth - 2

    return 0;
}
