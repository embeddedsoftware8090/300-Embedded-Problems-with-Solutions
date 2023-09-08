#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Structure to represent a stack
struct Stack {
    int top;
    char *array;
};

// Function to create a new stack
struct Stack* createStack(int size) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->array = (char*)malloc(size * sizeof(char));
    return stack;
}

// Function to check if the stack is empty
bool isEmpty(struct Stack* stack) {
    return (stack->top == -1);
}

// Function to push a character onto the stack
void push(struct Stack* stack, char item) {
    stack->array[++stack->top] = item;
}

// Function to pop a character from the stack
char pop(struct Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->array[stack->top--];
    }
    return '\0'; // Return null character if the stack is empty
}

// Function to check if the string has balanced parentheses, brackets, and braces
bool isBalanced(char* str) {
    int len = strlen(str);
    struct Stack* stack = createStack(len);

    for (int i = 0; i < len; i++) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            push(stack, str[i]);
        } else if (str[i] == ')' || str[i] == ']' || str[i] == '}') {
            if (isEmpty(stack)) {
                return false; // Closing symbol with no corresponding opening symbol
            }

            char top = pop(stack);

            // Check if the current closing symbol matches the top of the stack
            if ((str[i] == ')' && top != '(') ||
                (str[i] == ']' && top != '[') ||
                (str[i] == '}' && top != '{')) {
                return false; // Mismatched symbols
            }
        }
    }

    return isEmpty(stack); // Stack should be empty for balanced symbols
}

int main() {
    char input_str[] = "()[{}]";
    bool result = isBalanced(input_str);

    if (result) {
        printf("True\n");
    } else {
        printf("False\n");
    }

    return 0;
}
