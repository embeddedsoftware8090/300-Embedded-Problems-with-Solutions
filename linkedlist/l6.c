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

// Function to find the nth node from the end of the linked list
struct Node* findNthFromEnd(struct Node* head, int n) {
    if (head == NULL || n <= 0) {
        return NULL;
    }

    struct Node* firstPtr = head;
    struct Node* secondPtr = head;

    // Move the first pointer n nodes ahead
    for (int i = 0; i < n; i++) {
        if (firstPtr == NULL) {
            return NULL; // List length is less than n
        }
        firstPtr = firstPtr->next;
    }

    // Move both pointers until the first pointer reaches the end
    while (firstPtr != NULL) {
        firstPtr = firstPtr->next;
        secondPtr = secondPtr->next;
    }

    return secondPtr;
}

int main() {
    struct Node* head = NULL;

    // Insert elements into the linked list
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);

    printf("Original Linked List: 1 -> 2 -> 3 -> 4\n");

    int n = 2; // Find the 2nd node from the end
    struct Node* nthNode = findNthFromEnd(head, n);

    if (nthNode != NULL) {
        printf("The %dth node from the end is: %d\n", n, nthNode->data);
    } else {
        printf("The list is too short or n is invalid.\n");
    }

    return 0;
}
