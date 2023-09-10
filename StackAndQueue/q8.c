#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100

typedef struct {
    char items[MAX_STACK_SIZE][256]; // Assuming function names are less than 256 characters
    int top;
} FunctionCallStack;

// Initialize an empty function call stack
void initFunctionCallStack(FunctionCallStack *stack) {
    stack->top = -1;
}

// Check if the function call stack is empty
bool isFunctionCallStackEmpty(const FunctionCallStack *stack) {
    return stack->top == -1;
}

// Push a function call onto the stack
void pushFunctionCall(FunctionCallStack *stack, const char *functionName) {
    if (stack->top < MAX_STACK_SIZE - 1) {
        strcpy(stack->items[++stack->top], functionName);
    } else {
        printf("Function call stack overflow!\n");
        exit(1);
    }
}

// Pop a function call from the stack
void popFunctionCall(FunctionCallStack *stack) {
    if (!isFunctionCallStackEmpty(stack)) {
        stack->top--;
    } else {
        printf("Function call stack underflow!\n");
        exit(1);
    }
}

// Get the current function being executed
const char *getCurrentFunction(const FunctionCallStack *stack) {
    if (!isFunctionCallStackEmpty(stack)) {
        return stack->items[stack->top];
    } else {
        return "No function";
    }
}

int main() {
    FunctionCallStack callStack;
    initFunctionCallStack(&callStack);

    // Simulate function calls and returns
    pushFunctionCall(&callStack, "FuncA");
    printf("Current function - %s\n", getCurrentFunction(&callStack));

    pushFunctionCall(&callStack, "FuncB");
    printf("Current function - %s\n", getCurrentFunction(&callStack));

    popFunctionCall(&callStack);
    printf("Returning from %s\n", getCurrentFunction(&callStack));

    popFunctionCall(&callStack);
    printf("Returning from %s\n", getCurrentFunction(&callStack));

    return 0;
}
