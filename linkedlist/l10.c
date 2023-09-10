#include <stdio.h>
#include <stdbool.h>
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

// Function to detect a cycle and find its starting node
bool detectAndFindCycle(struct Node* head, struct Node** startingNode) {
    struct Node* slowPtr = head;
    struct Node* fastPtr = head;

    // Detect a cycle using Floyd's cycle-finding algorithm
    while (fastPtr != NULL && fastPtr->next != NULL) {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;

        if (slowPtr == fastPtr) {
            break; // Cycle detected
        }
    }

    // If there is no cycle, return false
    if (fastPtr == NULL || fastPtr->next == NULL) {
        return false;
    }

    // Find the starting node of the cycle
    slowPtr = head;
    while (slowPtr != fastPtr) {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next;
    }

    *startingNode = slowPtr;
    return true;
}

int main() {
    struct Node* head = NULL;

    // Insert elements into the linked list
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);

    // Create a cycle (3 points back to 1)
    head->next->next->next = head;

    struct Node* startingNode = NULL;
    bool hasCycle = detectAndFindCycle(head, &startingNode);

    if (hasCycle) {
        printf("The linked list contains a cycle.\n");
        printf("Starting Node of the Cycle: %d\n", startingNode->data);
    } else {
        printf("The linked list does not contain a cycle.\n");
    }

    return 0;
}
