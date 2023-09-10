#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10

typedef struct {
  char *event;
} LogEntry;

typedef struct {
  LogEntry *entries[MAX_QUEUE_SIZE];
  int front;
  int rear;
} LogQueue;

void log_init(LogQueue *queue) {
  queue->front = 0;
  queue->rear = 0;
}

void log_enqueue(LogQueue *queue, char *event) {
  if (queue->rear == MAX_QUEUE_SIZE) {
    // The queue is full, so remove the oldest log entry.
    queue->front = (queue->front + 1) % MAX_QUEUE_SIZE;
  }

  queue->entries[queue->rear] = event;
  queue->rear = (queue->rear + 1) % MAX_QUEUE_SIZE;
}

char *log_dequeue(LogQueue *queue) {
  if (queue->front == queue->rear) {
    // The queue is empty.
    return NULL;
  }

  char *event = queue->entries[queue->front];
  queue->front = (queue->front + 1) % MAX_QUEUE_SIZE;

  return event;
}

int main() {
  LogQueue queue;

  log_init(&queue);

  log_enqueue(&queue, "Event1");
  log_enqueue(&queue, "Event2");

  char *event = log_dequeue(&queue);
  printf("Retrieved event: %s\n", event);

  return 0;
}
