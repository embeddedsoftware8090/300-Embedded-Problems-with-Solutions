#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the maximum size of the queue
#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int front, rear;
} Queue;

// Initialize the queue
void initQueue(Queue *queue) {
    queue->front = queue->rear = -1;
}

// Check if the queue is empty
bool isQueueEmpty(Queue *queue) {
    return queue->front == -1;
}

// Check if the queue is full
bool isQueueFull(Queue *queue) {
    return (queue->rear + 1) % MAX_SIZE == queue->front;
}

// Enqueue an element into the queue with the specified priority
void enqueue(Queue *queue, int value, bool highPriority) {
    if (isQueueFull(queue)) {
        printf("Queue overflow.\n");
        exit(1);
    }

    if (isQueueEmpty(queue)) {
        queue->front = queue->rear = 0;
    } else {
        queue->rear = (queue->rear + 1) % MAX_SIZE;
    }

    if (highPriority) {
        // Move all elements to the right to make space for the high-priority element
        int i = queue->rear;
        while (i > queue->front) {
            queue->data[(i + 1) % MAX_SIZE] = queue->data[i];
            i = (i - 1 + MAX_SIZE) % MAX_SIZE;
        }
        queue->rear = (queue->rear + 1) % MAX_SIZE;
        queue->data[queue->front] = value;
    } else {
        queue->data[queue->rear] = value;
    }
}

// Dequeue an element from the queue
int dequeue(Queue *queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue underflow.\n");
        exit(1);
    }

    int dequeuedValue = queue->data[queue->front];

    if (queue->front == queue->rear) {
        // Queue has only one element
        queue->front = queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX_SIZE;
    }

    return dequeuedValue;
}

int main() {
    Queue queue;
    initQueue(&queue);

    // Enqueue elements with different priorities
    enqueue(&queue, 1, true);  // High priority
    enqueue(&queue, 2, false); // Low priority

    // Dequeue and print elements
    int dequeuedValue = dequeue(&queue);
    printf("Dequeue - %d\n", dequeuedValue);

    return 0;
}
