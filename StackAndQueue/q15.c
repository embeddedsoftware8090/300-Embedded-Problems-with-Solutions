#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the maximum size of the stack
#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int top;
} MinElementStack;

typedef struct {
    int data[MAX_SIZE];
    int top;
} MinElementAuxStack;

// Initialize the main stack
void initMinElementStack(MinElementStack *stack) {
    stack->top = -1;
}

// Initialize the auxiliary stack for minimum elements
void initMinElementAuxStack(MinElementAuxStack *auxStack) {
    auxStack->top = -1;
}

// Check if the main stack is empty
bool isMinElementStackEmpty(MinElementStack *stack) {
    return stack->top == -1;
}

// Check if the auxiliary stack for minimum elements is empty
bool isMinElementAuxStackEmpty(MinElementAuxStack *auxStack) {
    return auxStack->top == -1;
}

// Push an element onto the main stack
void pushMinElement(MinElementStack *stack, MinElementAuxStack *auxStack, int value) {
    if (stack->top >= MAX_SIZE - 1) {
        printf("Stack overflow.\n");
        exit(1);
    }

    stack->top++;
    stack->data[stack->top] = value;

    // Update the auxiliary stack for minimum elements
    if (isMinElementAuxStackEmpty(auxStack) || value <= auxStack->data[auxStack->top]) {
        auxStack->top++;
        auxStack->data[auxStack->top] = value;
    }
}

// Pop an element from the main stack
int popMinElement(MinElementStack *stack, MinElementAuxStack *auxStack) {
    if (isMinElementStackEmpty(stack)) {
        printf("Stack underflow.\n");
        exit(1);
    }

    int poppedValue = stack->data[stack->top];
    stack->top--;

    // Check if the popped value is the minimum element
    if (poppedValue == auxStack->data[auxStack->top]) {
        auxStack->top--;
    }

    return poppedValue;
}

// Get the minimum element from the main stack
int getMinElement(MinElementAuxStack *auxStack) {
    if (isMinElementAuxStackEmpty(auxStack)) {
        printf("Stack is empty.\n");
        exit(1);
    }

    return auxStack->data[auxStack->top];
}

int main() {
    MinElementStack stack;
    MinElementAuxStack auxStack;
    initMinElementStack(&stack);
    initMinElementAuxStack(&auxStack);

    // Push elements onto the main stack
    pushMinElement(&stack, &auxStack, 4);
    pushMinElement(&stack, &auxStack, 2);
    pushMinElement(&stack, &auxStack, 8);

    // Get the minimum element from the main stack
    int minElement = getMinElement(&auxStack);
    printf("Min - %d\n", minElement);

    return 0;
}
