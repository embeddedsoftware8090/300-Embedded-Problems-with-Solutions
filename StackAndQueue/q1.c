#include <stdio.h>
#include <stdint.h>

#define STACK_SIZE 32  // Define the size of the stack in 32-bit words

typedef struct {
    uint32_t memory[STACK_SIZE];
    int SP;  // Stack Pointer
} BytePackingStack;

void initStack(BytePackingStack *stack) {
    for (int i = 0; i < STACK_SIZE; i++) {
        stack->memory[i] = 0;  // Initialize the memory to zeros
    }
    stack->SP = 0;  // Initialize the stack pointer to 0
}

void push(BytePackingStack *stack, uint8_t value) {
    // Ensure that the stack pointer is within bounds
    if (stack->SP < STACK_SIZE) {
        // Calculate the index of the 32-bit word in memory
        int wordIndex = stack->SP / 4;
        // Calculate the position of the 8-bit value within the word
        int byteOffset = (stack->SP % 4) * 8;
        // Pack the 8-bit value into the word using bitwise operations
        stack->memory[wordIndex] |= ((uint32_t)value << byteOffset);
        stack->SP++;  // Increment the stack pointer
    } else {
        printf("Stack overflow!\n");
    }
}

void printMemoryContent(BytePackingStack *stack) {
    printf("Memory content - ");
    for (int i = STACK_SIZE - 1; i >= 0; i--) {
        printf("%08X", stack->memory[i]);
    }
    printf("\n");
}

int main() {
    BytePackingStack stack;
    initStack(&stack);

    push(&stack, 0x01);
    push(&stack, 0x02);
    push(&stack, 0x03);
    push(&stack, 0x04);

    printMemoryContent(&stack);  // Output: Memory content - 04030201

    return 0;
}
