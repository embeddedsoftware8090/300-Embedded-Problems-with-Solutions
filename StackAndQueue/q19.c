#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the heap
#define MAX_SIZE 100

typedef struct {
    int *data;
    int size;
    int capacity;
} MaxHeap;

// Initialize the max-heap
MaxHeap *initMaxHeap(int capacity) {
    MaxHeap *heap = (MaxHeap *)malloc(sizeof(MaxHeap));
    if (heap == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    heap->data = (int *)malloc(capacity * sizeof(int));
    if (heap->data == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    heap->size = 0;
    heap->capacity = capacity;

    return heap;
}

// Swap two elements in the heap
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify the max-heap (downward)
void heapify(MaxHeap *heap, int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < heap->size && heap->data[left] > heap->data[largest]) {
        largest = left;
    }

    if (right < heap->size && heap->data[right] > heap->data[largest]) {
        largest = right;
    }

    if (largest != index) {
        swap(&heap->data[index], &heap->data[largest]);
        heapify(heap, largest);
    }
}

// Insert an element into the max-heap
void insert(MaxHeap *heap, int value) {
    if (heap->size >= heap->capacity) {
        printf("Heap overflow.\n");
        exit(1);
    }

    int index = heap->size;
    heap->data[index] = value;
    heap->size++;

    // Fix the max-heap property by moving the element up
    while (index > 0 && heap->data[index] > heap->data[(index - 1) / 2]) {
        swap(&heap->data[index], &heap->data[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

// Remove and return the maximum element from the max-heap
int removeMax(MaxHeap *heap) {
    if (heap->size <= 0) {
        printf("Heap underflow.\n");
        exit(1);
    }

    int max = heap->data[0];
    heap->data[0] = heap->data[heap->size - 1];
    heap->size--;

    // Restore the max-heap property by heapifying the root
    heapify(heap, 0);

    return max;
}

// Clean up and destroy the max-heap
void destroyMaxHeap(MaxHeap *heap) {
    free(heap->data);
    free(heap);
}

int main() {
    MaxHeap *heap = initMaxHeap(MAX_SIZE);

    // Insert elements into the max-heap
    insert(heap, 3);
    insert(heap, 1);
    insert(heap, 4);

    // Remove and print the maximum element
    int max = removeMax(heap);
    printf("RemoveMax - %d\n", max);

    // Clean up and destroy the max-heap
    destroyMaxHeap(heap);

    return 0;
}
