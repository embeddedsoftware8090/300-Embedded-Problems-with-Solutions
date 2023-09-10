#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to append a new node at the end of a linked list
void append(struct Node** head, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

// Function to convert a binary linked list to an integer
int convertBinaryToInteger(struct Node* head) {
    int result = 0;

    while (head != NULL) {
        result = (result << 1) | head->data;
        head = head->next;
    }

    return result;
}

// Function to print a linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    // Construct the binary linked list (LSB to MSB)
    append(&head, 1);
    append(&head, 0);
    append(&head, 1);

    // Print the binary linked list
    printf("Binary Linked List:\n");
    printList(head);

    // Convert the binary linked list to an integer
    int result = convertBinaryToInteger(head);

    // Print the integer result
    printf("\nInteger Value: %d\n", result);

    return 0;
}
