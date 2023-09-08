#include <stdio.h>
#include <stdlib.h>

// Structure to represent a memory block
typedef struct {
    size_t size; // Size of the allocated memory block
    void* data;  // Pointer to the allocated memory
} MemoryBlock;

MemoryBlock* allocatedBlocks[100]; // Array to store allocated memory blocks
int numAllocatedBlocks = 0;        // Number of allocated memory blocks

// Custom memory allocation function
void* customMalloc(size_t size) {
    void* memory = malloc(size);
    if (memory == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }

    // Store information about the allocated block
    MemoryBlock* block = (MemoryBlock*)malloc(sizeof(MemoryBlock));
    block->size = size;
    block->data = memory;

    allocatedBlocks[numAllocatedBlocks++] = block;

    return memory;
}

// Custom memory deallocation function
void customFree(void* ptr) {
    // Find the allocated block corresponding to the pointer
    for (int i = 0; i < numAllocatedBlocks; i++) {
        if (allocatedBlocks[i]->data == ptr) {
            free(ptr);
            free(allocatedBlocks[i]);
            // Remove the block from the list
            for (int j = i; j < numAllocatedBlocks - 1; j++) {
                allocatedBlocks[j] = allocatedBlocks[j + 1];
            }
            numAllocatedBlocks--;
            return;
        }
    }

    fprintf(stderr, "Attempt to free unallocated memory: %p\n", ptr);
}

// Custom memory leak detection function
void detectMemoryLeaks() {
    if (numAllocatedBlocks > 0) {
        fprintf(stderr, "Memory leaks detected:\n");
        for (int i = 0; i < numAllocatedBlocks; i++) {
            fprintf(stderr, "Block at address %p (size: %zu) was not deallocated.\n",
                    allocatedBlocks[i]->data, allocatedBlocks[i]->size);
        }
    } else {
        printf("No memory leaks detected.\n");
    }
}

int main() {
    // Allocate 5 memory blocks
    int* arr1 = (int*)customMalloc(5 * sizeof(int));
    int* arr2 = (int*)customMalloc(10 * sizeof(int));
    int* arr3 = (int*)customMalloc(20 * sizeof(int));
    int* arr4 = (int*)customMalloc(30 * sizeof(int));
    int* arr5 = (int*)customMalloc(40 * sizeof(int));

    // Deallocate 4 memory blocks
    customFree(arr1);
    customFree(arr2);
    customFree(arr3);
    customFree(arr4);

    // Detect memory leaks at the end
    detectMemoryLeaks();

    return 0;
}
