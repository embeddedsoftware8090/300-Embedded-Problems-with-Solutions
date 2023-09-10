#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the maximum size of the stack
#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
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
void push(Stack *stack, int value) {
    if (isStackFull(stack)) {
        printf("Stack overflow.\n");
        exit(1);
    }

    stack->top++;
    stack->data[stack->top] = value;
}

// Pop an element from the stack
int pop(Stack *stack) {
    if (isStackEmpty(stack)) {
        printf("Stack underflow.\n");
        exit(1);
    }

    int poppedValue = stack->data[stack->top];
    stack->top--;
    return poppedValue;
}

// Sort a stack in ascending order using one additional stack
void sortStack(Stack *inputStack) {
    Stack auxStack;
    initStack(&auxStack);

    while (!isStackEmpty(inputStack)) {
        int temp = pop(inputStack);

        while (!isStackEmpty(&auxStack) && auxStack.data[auxStack.top] > temp) {
            push(inputStack, pop(&auxStack));
        }

        push(&auxStack, temp);
    }

    // Transfer elements back to the input stack for ascending order
    while (!isStackEmpty(&auxStack)) {
        push(inputStack, pop(&auxStack));
    }
}

int main() {
    Stack stack;
    initStack(&stack);

    // Push elements onto the stack
    push(&stack, 4);
    push(&stack, 3);
    push(&stack, 1);

    // Sort the stack
    sortStack(&stack);

    // Print the sorted stack
    printf("Stack - [");
    while (!isStackEmpty(&stack)) {
        printf("%d", pop(&stack));
        if (!isStackEmpty(&stack)) {
            printf(", ");
        }
    }
    printf("]\n");

    return 0;
}
