#include <stdio.h>
#include <stdlib.h>

// Define a singly linked list node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the end of the linked list
void insert(struct Node** head, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

// Function to pairwise swap elements of the linked list
void pairwiseSwap(struct Node** head) {
    if (*head == NULL || (*head)->next == NULL) {
        return; // No or only one element in the list
    }

    struct Node* prev = NULL;
    struct Node* current = *head;

    while (current != NULL && current->next != NULL) {
        struct Node* nextNode = current->next;
        current->next = nextNode->next;
        nextNode->next = current;

        if (prev != NULL) {
            prev->next = nextNode;
        } else {
            *head = nextNode; // Update the head if swapping the first two nodes
        }

        prev = current;
        current = current->next;
    }
}

// Function to print the linked list
void printList(struct Node* head) {
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
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);

    printf("Original Linked List: ");
    printList(head);

    pairwiseSwap(&head);

    printf("Linked List after pairwise swapping: ");
    printList(head);

    return 0;
}
