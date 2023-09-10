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

// Validate the correctness of an arithmetic expression
bool isValidExpression(const char *expression) {
    CharStack stack;
    initStack(&stack);

    for (int i = 0; expression[i] != '\0'; i++) {
        char c = expression[i];
        if (c == '(') {
            push(&stack, c);
        } else if (c == ')') {
            if (isEmpty(&stack) || pop(&stack) != '(') {
                return false; // Unmatched closing parenthesis
            }
        }
    }

    // Check if there are any unmatched opening parentheses
    if (!isEmpty(&stack)) {
        return false;
    }

    return true;  // All parentheses are balanced
}

int main() {
    const char *expression = "(a+b) * (c-d)"; // Replace with your expression
    bool isValid = isValidExpression(expression);

    if (isValid) {
        printf("Valid Expression\n");
    } else {
        printf("Invalid Expression\n");
    }

    return 0;
}
