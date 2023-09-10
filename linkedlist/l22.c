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

// Function to remove nodes with a specific value from a linked list
void removeNodesWithValue(struct Node** head, int value) {
    if (*head == NULL) {
        return;
    }

    // Handle cases where the first node(s) have the specified value
    while (*head != NULL && (*head)->data == value) {
        struct Node* temp = *head;
        *head = (*head)->next;
        free(temp);
    }

    if (*head == NULL) {
        return;
    }

    struct Node* current = *head;

    while (current->next != NULL) {
        if (current->next->data == value) {
            struct Node* temp = current->next;
            current->next = temp->next;
            free(temp);
        } else {
            current = current->next;
        }
    }
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

    // Construct the linked list
    append(&head, 1);
    append(&head, 2);
    append(&head, 6);
    append(&head, 3);
    append(&head, 4);
    append(&head, 5);
    append(&head, 6);

    // Print the original linked list
    printf("Original Linked List:\n");
    printList(head);

    int valueToRemove = 6;

    // Remove nodes with the specified value
    removeNodesWithValue(&head, valueToRemove);

    // Print the modified linked list
    printf("\nLinked List after Removing Nodes with Value %d:\n", valueToRemove);
    printList(head);

    return 0;
}
