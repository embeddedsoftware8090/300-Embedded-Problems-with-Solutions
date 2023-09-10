#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the maximum size of the queue and the number of digits (0-9)
#define MAX_SIZE 100
#define NUM_DIGITS 10

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

// Enqueue an element into the queue
void enqueue(Queue *queue, int value) {
    if (isQueueFull(queue)) {
        printf("Queue overflow.\n");
        exit(1);
    }

    if (isQueueEmpty(queue)) {
        queue->front = queue->rear = 0;
    } else {
        queue->rear = (queue->rear + 1) % MAX_SIZE;
    }

    queue->data[queue->rear] = value;
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

// Find the maximum number of digits in an array of numbers
int findMaxDigits(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    int digits = 0;
    while (max > 0) {
        digits++;
        max /= 10;
    }

    return digits;
}

// Perform Radix Sort on an array of numbers
void radixSort(int arr[], int n) {
    int maxDigits = findMaxDigits(arr, n);
    Queue digitQueues[NUM_DIGITS];

    for (int i = 0; i < NUM_DIGITS; i++) {
        initQueue(&digitQueues[i]);
    }

    int divisor = 1;
    for (int digitPosition = 1; digitPosition <= maxDigits; digitPosition++) {
        // Distribute numbers into digit queues based on the current digit position
        for (int i = 0; i < n; i++) {
            int digit = (arr[i] / divisor) % 10;
            enqueue(&digitQueues[digit], arr[i]);
        }

        // Collect numbers from digit queues back into the original array
        int j = 0;
        for (int i = 0; i < NUM_DIGITS; i++) {
            while (!isQueueEmpty(&digitQueues[i])) {
                arr[j] = dequeue(&digitQueues[i]);
                j++;
            }
        }

        divisor *= 10;
    }
}

int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Input Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    radixSort(arr, n);

    printf("Sorted Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
