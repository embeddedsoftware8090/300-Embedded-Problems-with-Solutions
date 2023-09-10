#include <stdio.h>
#include <stdlib.h>

// Define a structure for a stack node
typedef struct StackNode {
    int data;
    struct StackNode *next;
} StackNode;

// Define a structure for a stack
typedef struct {
    StackNode *top;
} Stack;

// Initialize an empty stack
void initStack(Stack *stack) {
    stack->top = NULL;
}

// Check if the stack is empty
int isStackEmpty(Stack *stack) {
    return stack->top == NULL;
}

// Push an element onto the stack
void push(Stack *stack, int data) {
    StackNode *newNode = (StackNode *)malloc(sizeof(StackNode));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

// Pop an element from the stack
int pop(Stack *stack) {
    if (!isStackEmpty(stack)) {
        StackNode *temp = stack->top;
        int data = temp->data;
        stack->top = temp->next;
        free(temp);
        return data;
    } else {
        printf("Stack is empty.\n");
        exit(1);
    }
}

// Fibonacci function using an iterative approach with a stack
int iterativeFibonacci(int n) {
    if (n <= 1) {
        return n;
    }

    Stack fibStack;
    initStack(&fibStack);
    push(&fibStack, 1);
    push(&fibStack, 0);

    int result = 0;

    for (int i = 2; i <= n; i++) {
        int a = pop(&fibStack);
        int b = pop(&fibStack);
        result = a + b;
        push(&fibStack, a);
        push(&fibStack, result);
    }

    return result;
}

int main() {
    int n = 5; // Replace with the desired Fibonacci number
    int result = iterativeFibonacci(n);
    printf("Fibonacci(%d) = %d\n", n, result);
    return 0;
}
