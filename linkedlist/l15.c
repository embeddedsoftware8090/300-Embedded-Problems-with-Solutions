#include <stdio.h>
#include <stdlib.h>

// Define a singly linked list node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to push a digit onto a stack
void push(struct Node** top, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *top;
    *top = newNode;
}

// Function to pop a digit from a stack
int pop(struct Node** top) {
    if (*top == NULL) {
        return 0; // Stack is empty
    }
    struct Node* temp = *top;
    *top = (*top)->next;
    int data = temp->data;
    free(temp);
    return data;
}

// Function to add two linked lists represented by stacks
struct Node* addLists(struct Node* stack1, struct Node* stack2) {
    struct Node* result = NULL;
    int carry = 0;

    while (stack1 != NULL || stack2 != NULL || carry != 0) {
        int num1 = pop(&stack1);
        int num2 = pop(&stack2);

        int sum = num1 + num2 + carry;
        carry = sum / 10;
        int digit = sum % 10;

        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = digit;
        newNode->next = result;
        result = newNode;
    }

    return result;
}

// Function to print a linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* stack1 = NULL;
    struct Node* stack2 = NULL;

    // Push elements onto the first stack (represents 24)
    push(&stack1, 4);
    push(&stack1, 2);

    // Push elements onto the second stack (represents 56)
    push(&stack2, 6);
    push(&stack2, 5);

    printf("First Stack: ");
    printList(stack1);

    printf("Second Stack: ");
    printList(stack2);

    // Add the two stacks and store the result in a new stack
    struct Node* sumStack = addLists(stack1, stack2);

    printf("Sum Stack: ");
    printList(sumStack);

    return 0;
}
