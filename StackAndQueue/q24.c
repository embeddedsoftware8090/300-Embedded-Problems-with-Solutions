#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Define a structure for the stack
typedef struct {
    char* items;
    int top;
    int capacity;
} Stack;

// Initialize the stack
Stack* initStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (stack == NULL) {
        printf("Memory allocation error.\n");
        exit(1);
    }
    stack->items = (char*)malloc(sizeof(char) * capacity);
    if (stack->items == NULL) {
        printf("Memory allocation error.\n");
        free(stack);
        exit(1);
    }
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}

// Check if the stack is empty
bool isStackEmpty(Stack* stack) {
    return stack->top == -1;
}

// Push an element onto the stack
void push(Stack* stack, char item) {
    if (stack->top == stack->capacity - 1) {
        printf("Stack overflow.\n");
        exit(1);
    }
    stack->items[++stack->top] = item;
}

// Pop an element from the stack
char pop(Stack* stack) {
    if (isStackEmpty(stack)) {
        printf("Stack underflow.\n");
        exit(1);
    }
    return stack->items[stack->top--];
}

// Check if parentheses are balanced
bool areParenthesesBalanced(char* expression) {
    Stack* stack = initStack(strlen(expression));

    for (int i = 0; expression[i] != '\0'; i++) {
        char currentChar = expression[i];
        if (currentChar == '(' || currentChar == '[' || currentChar == '{') {
            push(stack, currentChar);
        } else if (currentChar == ')' || currentChar == ']' || currentChar == '}') {
            if (isStackEmpty(stack)) {
                free(stack->items);
                free(stack);
                return false; // Unmatched closing parenthesis
            }
            char topChar = pop(stack);
            if ((currentChar == ')' && topChar != '(') ||
                (currentChar == ']' && topChar != '[') ||
                (currentChar == '}' && topChar != '{')) {
                free(stack->items);
                free(stack);
                return false; // Mismatched opening and closing parentheses
            }
        }
    }

    bool balanced = isStackEmpty(stack); // Stack should be empty for balanced parentheses
    free(stack->items);
    free(stack);
    return balanced;
}

int main() {
    char expression[] = "{[()]}";

    if (areParenthesesBalanced(expression)) {
        printf("Balanced\n");
    } else {
        printf("Not balanced\n");
    }

    return 0;
}
