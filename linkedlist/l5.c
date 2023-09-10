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

// Function to remove duplicate nodes from the linked list
void removeDuplicates(struct Node* head) {
    if (head == NULL) {
        return;
    }

    // Create a hash table to keep track of encountered values
    int hashTable[1000] = {0}; // Assuming a maximum of 1000 unique values

    struct Node* current = head;
    struct Node* prev = NULL;

    while (current != NULL) {
        if (hashTable[current->data] == 0) {
            // This is the first occurrence of the current data
            hashTable[current->data] = 1;
            prev = current;
        } else {
            // Duplicate node, remove it
            prev->next = current->next;
            free(current);
            current = prev;
        }
        current = current->next;
    }
}

// Function to display the linked list
void display(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf(" -> ");
        }
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    // Insert elements into the linked list
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 2);
    insert(&head, 3);

    printf("Original Linked List: ");
    display(head);

    // Remove duplicate nodes
    removeDuplicates(head);

    printf("Linked List after Removing Duplicates: ");
    display(head);

    return 0;
}
