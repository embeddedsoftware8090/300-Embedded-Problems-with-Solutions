#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    char data[MAX_SIZE];
    int top;
} Stack;

void initStack(Stack *stack) {
    stack->top = -1;
}

bool isStackEmpty(Stack *stack) {
    return stack->top == -1;
}

bool isStackFull(Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(Stack *stack, char value) {
    if (isStackFull(stack)) {
        printf("Stack overflow.\n");
        exit(1);
    }
    stack->data[++stack->top] = value;
}

char pop(Stack *stack) {
    if (isStackEmpty(stack)) {
        printf("Stack underflow.\n");
        exit(1);
    }
    return stack->data[stack->top--];
}

// Undo and Redo stacks
Stack undoStack;
Stack redoStack;

void undo() {
    if (!isStackEmpty(&undoStack)) {
        char value = pop(&undoStack);
        push(&redoStack, value);
    }
}

void redo() {
    if (!isStackEmpty(&redoStack)) {
        char value = pop(&redoStack);
        push(&undoStack, value);
    }
}

void write(char value) {
    push(&undoStack, value);
    // Clear redo stack when a new action is performed
    initStack(&redoStack);
}

int main() {
    initStack(&undoStack);
    initStack(&redoStack);

    // Simulate user actions
    write('H');
    write('e');
    write('l');
    write('l');
    write('o');

    printf("Current Text: ");
    while (!isStackEmpty(&undoStack)) {
        char value = pop(&undoStack);
        printf("%c", value);
    }
    printf("\n");

    // Undo and redo operations
    undo();
    undo();

    printf("After Undo: ");
    while (!isStackEmpty(&undoStack)) {
        char value = pop(&undoStack);
        printf("%c", value);
    }
    printf("\n");

    redo();

    printf("After Redo: ");
    while (!isStackEmpty(&undoStack)) {
        char value = pop(&undoStack);
        printf("%c", value);
    }
    printf("\n");

    return 0;
}
