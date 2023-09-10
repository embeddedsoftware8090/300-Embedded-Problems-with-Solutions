#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the maximum size of the array
#define MAX_SIZE 100

// Define the number of stacks (change as needed)
#define NUM_STACKS 2

// Calculate the size allocated for each stack
#define STACK_SIZE (MAX_SIZE / NUM_STACKS)

// Define the MultiStack structure
typedef struct {
    int data[MAX_SIZE];
    int stackTops[NUM_STACKS];
} MultiStack;

// Initialize the MultiStack
void initMultiStack(MultiStack *stack) {
    for (int i = 0; i < NUM_STACKS; i++) {
        stack->stackTops[i] = i * STACK_SIZE - 1;
    }
}

// Check if a stack is empty
bool isStackEmpty(MultiStack *stack, int stackNumber) {
    return stack->stackTops[stackNumber] < stackNumber * STACK_SIZE;
}

// Check if a stack is full
bool isStackFull(MultiStack *stack, int stackNumber) {
    return stack->stackTops[stackNumber] >= (stackNumber + 1) * STACK_SIZE - 1;
}

// Push an element onto a stack
void push(MultiStack *stack, int stackNumber, int value) {
    if (!isStackFull(stack, stackNumber)) {
        stack->stackTops[stackNumber]++;
        stack->data[stack->stackTops[stackNumber]] = value;
    } else {
        printf("Stack %d is full. Cannot push %d.\n", stackNumber, value);
    }
}

// Pop an element from a stack
int pop(MultiStack *stack, int stackNumber) {
    if (!isStackEmpty(stack, stackNumber)) {
        int value = stack->data[stack->stackTops[stackNumber]];
        stack->stackTops[stackNumber]--;
        return value;
    } else {
        printf("Stack %d is empty.\n", stackNumber);
        return -1; // Return a sentinel value to indicate an empty stack
    }
}

int main() {
    MultiStack stack;
    initMultiStack(&stack);

    // Push elements onto different stacks
    push(&stack, 0, 1); // Push 1 to Stack 0
    push(&stack, 1, 'a'); // Push 'a' to Stack 1

    // Pop elements from different stacks
    int poppedValue1 = pop(&stack, 0);
    int poppedValue2 = pop(&stack, 1);

    // Print the popped values
    printf("Popped from Stack 0: %d\n", poppedValue1);
    printf("Popped from Stack 1: %c\n", (char)poppedValue2);

    return 0;
}
