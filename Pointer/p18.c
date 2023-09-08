#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to find the length of the linked list
int findLinkedListLength(struct Node** head) {
    int length = 0;
    struct Node* current = *head;  // Initialize a current pointer to the head of the list

    while (current != NULL) {
        length++;
        current = current->next;  // Move the current pointer to the next node
    }

    return length;
}

// Function to insert a new node at the end of the linked list
void insertNodeAtEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        // If the list is empty, make the new node the head
        *head = newNode;
    } else {
        // Otherwise, traverse to the end and add the new node there
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to display the linked list
void displayLinkedList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    // Insert elements into the linked list
    insertNodeAtEnd(&head, 1);
    insertNodeAtEnd(&head, 2);
    insertNodeAtEnd(&head, 3);
    insertNodeAtEnd(&head, 4);
    insertNodeAtEnd(&head, 5);

    // Display the linked list
    printf("Linked List: ");
    displayLinkedList(head);

    // Find the length of the linked list
    int length = findLinkedListLength(&head);
    printf("Length of the Linked List: %d\n", length);

    return 0;
}
