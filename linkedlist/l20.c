#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node {
    int data;
    struct Node* next;
    struct Node* child;
};

// Function to append a new node at the end of a linked list
void append(struct Node** head, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->child = NULL;

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

// Function to flatten a multi-level linked list
void flatten(struct Node* head) {
    if (head == NULL) {
        return;
    }

    struct Node* current = head;
    while (current != NULL) {
        if (current->child != NULL) {
            struct Node* next = current->next;
            current->next = current->child;
            current->child = NULL;

            struct Node* temp = current->next;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = next;
        }
        current = current->next;
    }
}

// Function to print the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    // Construct the multi-level linked list
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);

    head->child = (struct Node*)malloc(sizeof(struct Node));
    head->child->data = 4;

    head->child->next = (struct Node*)malloc(sizeof(struct Node));
    head->child->next->data = 5;

    // Print the original multi-level linked list
    printf("Original Multi-level Linked List:\n");
    printList(head);

    // Flatten the linked list
    flatten(head);

    // Print the flattened linked list
    printf("\nFlattened Linked List:\n");
    printList(head);

    return 0;
}
