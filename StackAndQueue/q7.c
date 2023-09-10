#include <stdio.h>
#include <stdlib.h>

// Define a structure for a queue node
typedef struct QueueNode {
    int data;
    struct QueueNode *next;
} QueueNode;

// Define a structure for a queue
typedef struct {
    QueueNode *front;
    QueueNode *rear;
} Queue;

// Initialize an empty queue
void initQueue(Queue *queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

// Check if the queue is empty
int isEmpty(Queue *queue) {
    return (queue->front == NULL);
}

// Enqueue a number into the queue
void enqueue(Queue *queue, int data) {
    QueueNode *newNode = (QueueNode *)malloc(sizeof(QueueNode));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Dequeue a number from the queue
int dequeue(Queue *queue) {
    if (!isEmpty(queue)) {
        QueueNode *temp = queue->front;
        int data = temp->data;
        queue->front = temp->next;
        free(temp);
        return data;
    } else {
        printf("Queue is empty.\n");
        exit(1);
    }
}

// Generate and print the Fibonacci sequence up to n numbers
void generateFibonacci(int n) {
    Queue queue;
    initQueue(&queue);

    int a = 0, b = 1;

    for (int i = 0; i < n; i++) {
        enqueue(&queue, a);
        printf("%d, ", a);

        int next = a + b;
        a = b;
        b = next;
    }

    printf("\n");

    // Dequeue and print any remaining numbers in the queue (if any)
    while (!isEmpty(&queue)) {
        int data = dequeue(&queue);
        printf("%d, ", data);
    }
}

int main() {
    int n = 5;  // Replace with the desired number of Fibonacci numbers
    generateFibonacci(n);
    return 0;
}
