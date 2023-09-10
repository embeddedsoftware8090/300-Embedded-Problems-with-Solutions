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

// Count the depth of nested statements
int countNestedDepth(const char *input) {
    CharStack stack;
    initStack(&stack);
    int depth = 0;

    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == '{') {
            push(&stack, input[i]);
        } else if (input[i] == '}') {
            if (!isEmpty(&stack)) {
                pop(&stack);
                depth++;
            } else {
                printf("Mismatched closing brace at position %d\n", i);
                // Handle error: Unmatched closing brace
            }
        }
    }

    if (!isEmpty(&stack)) {
        printf("Unmatched opening brace(s) in the input\n");
        // Handle error: Unmatched opening brace(s)
    }

    return depth;
}

int main() {
    const char *input = "{{}}";  // Replace with your input string
    int depth = countNestedDepth(input);
    printf("Depth - %d\n", depth);  // Output: Depth - 2

    return 0;
}
