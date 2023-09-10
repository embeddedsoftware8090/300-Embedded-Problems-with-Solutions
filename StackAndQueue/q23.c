#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a binary tree node
typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Define a structure to represent a stack node for tree nodes
typedef struct StackNode {
    TreeNode* node;
    struct StackNode* next;
} StackNode;

// Initialize the stack
void initStack(StackNode** stack) {
    *stack = NULL;
}

// Check if the stack is empty
bool isStackEmpty(StackNode* stack) {
    return stack == NULL;
}

// Push a tree node onto the stack
void push(StackNode** stack, TreeNode* node) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    if (newNode == NULL) {
        printf("Memory allocation error.\n");
        exit(1);
    }
    newNode->node = node;
    newNode->next = *stack;
    *stack = newNode;
}

// Pop a tree node from the stack
TreeNode* pop(StackNode** stack) {
    if (isStackEmpty(*stack)) {
        printf("Stack underflow.\n");
        exit(1);
    }
    TreeNode* node = (*stack)->node;
    StackNode* temp = *stack;
    *stack = (*stack)->next;
    free(temp);
    return node;
}

// Post-order traversal using a stack
void postOrderTraversal(TreeNode* root) {
    if (root == NULL) return;
    
    StackNode* stack1;
    StackNode* stack2;
    
    initStack(&stack1);
    initStack(&stack2);
    
    push(&stack1, root);
    
    while (!isStackEmpty(stack1)) {
        TreeNode* node = pop(&stack1);
        push(&stack2, node);
        
        if (node->left) push(&stack1, node->left);
        if (node->right) push(&stack1, node->right);
    }
    
    while (!isStackEmpty(stack2)) {
        TreeNode* node = pop(&stack2);
        printf("%d ", node->data);
    }
}

// Create a new binary tree node
TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if (newNode == NULL) {
        printf("Memory allocation error.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int main() {
    // Create a binary tree
    TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);

    // Perform post-order traversal
    printf("Post-order Traversal: ");
    postOrderTraversal(root);
    printf("\n");

    return 0;
}
