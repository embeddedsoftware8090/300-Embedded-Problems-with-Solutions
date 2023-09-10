#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 3

typedef struct {
    int *data;
    int front;
    int rear;
    int size;
} CircularQueue;

// Initialize the circular queue
void initCircularQueue(CircularQueue *queue) {
    queue->data = (int *)malloc(MAX_SIZE * sizeof(int));
    if (queue->data == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    queue->front = -1;
    queue->rear = -1;
    queue->size = 0;
}

// Check if the circular queue is empty
bool isCircularQueueEmpty(CircularQueue *queue) {
    return queue->size == 0;
}

// Check if the circular queue is full
bool isCircularQueueFull(CircularQueue *queue) {
    return queue->size == MAX_SIZE;
}

// Enqueue an element into the circular queue
void enqueue(CircularQueue *queue, int value) {
    if (isCircularQueueFull(queue)) {
        // If the queue is full, overwrite the oldest element
        queue->front = (queue->front + 1) % MAX_SIZE;
    }

    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->data[queue->rear] = value;

    if (isCircularQueueFull(queue)) {
        queue->front = (queue->front + 1) % MAX_SIZE;
    } else if (isCircularQueueEmpty(queue)) {
        queue->front = 0;
    }

    if (queue->size < MAX_SIZE) {
        queue->size++;
    }
}

// Dequeue an element from the circular queue
int dequeue(CircularQueue *queue) {
    if (!isCircularQueueEmpty(queue)) {
        int value = queue->data[queue->front];
        queue->front = (queue->front + 1) % MAX_SIZE;
        queue->size--;
        return value;
    } else {
        printf("Queue is empty.\n");
        exit(1);
    }
}

// Clean up and destroy the circular queue
void destroyCircularQueue(CircularQueue *queue) {
    free(queue->data);
    queue->front = -1;
    queue->rear = -1;
    queue->size = 0;
}

int main() {
    CircularQueue queue;
    initCircularQueue(&queue);

    // Enqueue elements
    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);
    enqueue(&queue, 4);

    // Dequeue and print elements
    while (!isCircularQueueEmpty(&queue)) {
        int value = dequeue(&queue);
        printf("%d, ", value);
    }

    printf("\n");

    // Clean up and destroy the circular queue
    destroyCircularQueue(&queue);

    return 0;
}
