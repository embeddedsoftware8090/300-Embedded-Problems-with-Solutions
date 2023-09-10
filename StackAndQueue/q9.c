#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Define a structure for a queue node
typedef struct QueueNode {
    char data[256]; // Assuming words are less than 256 characters
    struct QueueNode *next;
} QueueNode;

// Define a structure for a queue
typedef struct {
    QueueNode *front;
    QueueNode *rear;
} StringQueue;

// Initialize an empty queue
void initStringQueue(StringQueue *queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

// Check if the queue is empty
bool isStringQueueEmpty(const StringQueue *queue) {
    return queue->front == NULL;
}

// Enqueue a string into the queue
void enqueueString(StringQueue *queue, const char *data) {
    QueueNode *newNode = (QueueNode *)malloc(sizeof(QueueNode));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    strcpy(newNode->data, data);
    newNode->next = NULL;

    if (isStringQueueEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Dequeue a string from the queue
void dequeueString(StringQueue *queue) {
    if (!isStringQueueEmpty(queue)) {
        QueueNode *temp = queue->front;
        queue->front = temp->next;
        free(temp);
    }
}

// Free memory used by the queue
void destroyStringQueue(StringQueue *queue) {
    while (!isStringQueueEmpty(queue)) {
        dequeueString(queue);
    }
}

// Check if a word is in the queue
bool isInQueue(const StringQueue *queue, const char *word) {
    QueueNode *current = queue->front;
    while (current != NULL) {
        if (strcmp(current->data, word) == 0) {
            return true;
        }
        current = current->next;
    }
    return false;
}

// Filter words from the text
char *filterText(const char *text, StringQueue *filterWords) {
    char *filteredText = strdup(text);
    if (filteredText == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    
    char *word = strtok(filteredText, " ");
    char *prevWord = NULL;
    
    while (word != NULL) {
        if (isInQueue(filterWords, word)) {
            if (prevWord != NULL) {
                size_t wordLen = strlen(word);
                // Replace word with spaces of the same length
                memset(prevWord + strlen(prevWord), ' ', wordLen);
            } else {
                // If the first word is filtered, replace it with spaces
                size_t wordLen = strlen(word);
                memset(word, ' ', wordLen);
            }
        }
        prevWord = word;
        word = strtok(NULL, " ");
    }
    
    return filteredText;
}

int main() {
    StringQueue filterWords;
    initStringQueue(&filterWords);
    
    // Add words to filter out
    enqueueString(&filterWords, "world");
    
    const char *text = "Hello world"; // Replace with your input text
    char *filteredText = filterText(text, &filterWords);
    
    if (filteredText != NULL) {
        printf("%s\n", filteredText);
        free(filteredText);
    }
    
    destroyStringQueue(&filterWords);
    
    return 0;
}
