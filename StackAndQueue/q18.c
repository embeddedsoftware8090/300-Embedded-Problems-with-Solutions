#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Define the maximum size of the stack
#define MAX_SIZE 100

typedef struct {
    double data[MAX_SIZE];
    int top;
} Stack;

// Initialize the stack
void initStack(Stack *stack) {
    stack->top = -1;
}

// Check if the stack is empty
bool isStackEmpty(Stack *stack) {
    return stack->top == -1;
}

// Check if the stack is full
bool isStackFull(Stack *stack) {
    return stack->top >= MAX_SIZE - 1;
}

// Push an element onto the stack
void push(Stack *stack, double value) {
    if (isStackFull(stack)) {
        printf("Stack overflow.\n");
        exit(1);
    }

    stack->top++;
    stack->data[stack->top] = value;
}

// Pop an element from the stack
double pop(Stack *stack) {
    if (isStackEmpty(stack)) {
        printf("Stack underflow.\n");
        exit(1);
    }

    double poppedValue = stack->data[stack->top];
    stack->top--;
    return poppedValue;
}

// Evaluate a postfix expression
double evaluatePostfix(char *expression) {
    Stack operandStack;
    initStack(&operandStack);

    char *token = strtok(expression, " ");
    while (token != NULL) {
        if (isdigit(token[0])) {
            // If the token is a number, push it onto the operand stack
            push(&operandStack, atof(token));
        } else {
            // If the token is an operator, pop the top two operands, apply the operator, and push the result
            double operand2 = pop(&operandStack);
            double operand1 = pop(&operandStack);
            double result;

            switch (token[0]) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
                default:
                    printf("Invalid operator: %s\n", token);
                    exit(1);
            }

            push(&operandStack, result);
        }

        token = strtok(NULL, " ");
    }

    // The final result should be at the top of the operand stack
    return pop(&operandStack);
}

int main() {
    char expression[] = "5 1 2 + 4 * + 3 -";
    double result = evaluatePostfix(expression);
    printf("Result: %.2lf\n", result);

    return 0;
}
