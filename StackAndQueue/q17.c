#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the maximum size of the stacks
#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

typedef struct {
    Stack enqueueStack;
    Stack dequeueStack;
} Queue;

// Initialize a stack
void initStack(Stack *stack) {
    stack->top = -1;
}

// Check if a stack is empty
bool isStackEmpty(Stack *stack) {
    return stack->top == -1;
}

// Check if a stack is full
bool isStackFull(Stack *stack) {
    return stack->top >= MAX_SIZE - 1;
}

// Push an element onto a stack
void push(Stack *stack, int value) {
    if (isStackFull(stack)) {
        printf("Stack overflow.\n");
        exit(1);
    }

    stack->top++;
    stack->data[stack->top] = value;
}

// Pop an element from a stack
int pop(Stack *stack) {
    if (isStackEmpty(stack)) {
        printf("Stack underflow.\n");
        exit(1);
    }

    int poppedValue = stack->data[stack->top];
    stack->top--;
    return poppedValue;
}

// Initialize the queue
void initQueue(Queue *queue) {
    initStack(&(queue->enqueueStack));
    initStack(&(queue->dequeueStack));
}

// Enqueue an element into the queue
void enqueue(Queue *queue, int value) {
    push(&(queue->enqueueStack), value);
}

// Dequeue an element from the queue
int dequeue(Queue *queue) {
    if (isStackEmpty(&(queue->dequeueStack))) {
        // If the dequeue stack is empty, transfer elements from enqueue stack
        while (!isStackEmpty(&(queue->enqueueStack))) {
            int temp = pop(&(queue->enqueueStack));
            push(&(queue->dequeueStack), temp);
        }
    }

    if (!isStackEmpty(&(queue->dequeueStack))) {
        return pop(&(queue->dequeueStack));
    } else {
        printf("Queue is empty.\n");
        exit(1);
    }
}

int main() {
    Queue queue;
    initQueue(&queue);

    // Enqueue elements
    enqueue(&queue, 1);
    enqueue(&queue, 2);

    // Dequeue and print elements
    int dequeuedValue = dequeue(&queue);
    printf("Dequeue - %d\n", dequeuedValue);

    return 0;
}
