#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define a structure for a stack node
typedef struct StackNode {
    char* text;
    struct StackNode* next;
} StackNode;

// Define a structure for a stack
typedef struct {
    StackNode* top;
} TextEditorStack;

// Initialize an empty stack
void initTextEditorStack(TextEditorStack* stack) {
    stack->top = NULL;
}

// Check if the stack is empty
bool isTextEditorStackEmpty(TextEditorStack* stack) {
    return stack->top == NULL;
}

// Push the current text onto the stack
void pushTextEditorState(TextEditorStack* stack, const char* text) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->text = strdup(text);
    newNode->next = stack->top;
    stack->top = newNode;
}

// Pop the top state from the stack and return it
char* popTextEditorState(TextEditorStack* stack) {
    if (!isTextEditorStackEmpty(stack)) {
        StackNode* temp = stack->top;
        char* text = temp->text;
        stack->top = temp->next;
        free(temp);
        return text;
    } else {
        printf("Stack is empty.\n");
        exit(1);
    }
}

// Free memory used by the stack
void destroyTextEditorStack(TextEditorStack* stack) {
    while (!isTextEditorStackEmpty(stack)) {
        char* text = popTextEditorState(stack);
        free(text);
    }
}

int main() {
    TextEditorStack editorStack;
    initTextEditorStack(&editorStack);
    
    char* currentText = NULL;
    char input[256]; // Assuming input lines are less than 256 characters
    
    while (1) {
        printf("Enter a command (Add/Undo/Redo/Quit): ");
        fgets(input, sizeof(input), stdin);
        
        if (strncmp(input, "Add", 3) == 0) {
            // Add operation
            if (currentText != NULL) {
                free(currentText);
            }
            currentText = (char*)malloc(strlen(input) - 4); // Exclude "Add " prefix
            strcpy(currentText, input + 4);
            pushTextEditorState(&editorStack, currentText);
        } else if (strncmp(input, "Undo", 4) == 0) {
            // Undo operation
            if (!isTextEditorStackEmpty(&editorStack)) {
                char* undoneText = popTextEditorState(&editorStack);
                if (currentText != NULL) {
                    free(currentText);
                }
                currentText = undoneText;
            }
        } else if (strncmp(input, "Redo", 4) == 0) {
            // Redo operation
            // (You can implement redo functionality if needed)
        } else if (strncmp(input, "Quit", 4) == 0) {
            // Quit the editor
            break;
        } else {
            printf("Invalid command. Try again.\n");
        }
        
        // Print the current text
        printf("Current Text: %s", (currentText != NULL) ? currentText : "(empty)\n");
    }
    
    // Clean up and exit
    if (currentText != NULL) {
        free(currentText);
    }
    destroyTextEditorStack(&editorStack);
    
    return 0;
}
