#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to represent a string message node
typedef struct MessageNode {
    char *message;
    struct MessageNode *next;
} MessageNode;

// Define a structure to represent the message queue
typedef struct {
    MessageNode *front;  // Front of the queue
    MessageNode *rear;   // Rear of the queue
} StringMessageQueue;

// Initialize an empty message queue
void initStringMessageQueue(StringMessageQueue *queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

// Enqueue a message into the queue
void enqueue(StringMessageQueue *queue, const char *message) {
    // Create a new message node
    MessageNode *newNode = (MessageNode *)malloc(sizeof(MessageNode));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    // Allocate memory for the message and copy it
    newNode->message = (char *)malloc(strlen(message) + 1);
    if (newNode->message == NULL) {
        printf("Memory allocation failed.\n");
        free(newNode);
        exit(1);
    }
    strcpy(newNode->message, message);

    newNode->next = NULL;

    if (queue->rear == NULL) {
        // If the queue is empty, set both front and rear to the new node
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        // Otherwise, add the new node to the rear
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Dequeue a message from the queue
char *dequeue(StringMessageQueue *queue) {
    if (queue->front == NULL) {
        // Queue is empty
        return NULL;
    }

    // Get the message from the front node
    char *message = queue->front->message;

    // Remove the front node and update the front pointer
    MessageNode *temp = queue->front;
    queue->front = queue->front->next;
    free(temp);

    // If the queue is now empty, update the rear pointer
    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    return message;
}

// Free the memory used by the queue
void destroyStringMessageQueue(StringMessageQueue *queue) {
    while (queue->front != NULL) {
        MessageNode *temp = queue->front;
        queue->front = queue->front->next;
        free(temp->message);
        free(temp);
    }
}

int main() {
    StringMessageQueue queue;
    initStringMessageQueue(&queue);

    enqueue(&queue, "HELLO");
    enqueue(&queue, "WORLD");

    char *message1 = dequeue(&queue);
    char *message2 = dequeue(&queue);

    if (message1 != NULL) {
        printf("Dequeue - \"%s\"\n", message1);
        free(message1);
    }
    if (message2 != NULL) {
        printf("Dequeue - \"%s\"\n", message2);
        free(message2);
    }

    destroyStringMessageQueue(&queue);

    return 0;
}
