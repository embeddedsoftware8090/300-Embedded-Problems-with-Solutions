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

// Function to partition a linked list around a given value
struct Node* partition(struct Node* head, int partitionValue) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct Node* lessList = NULL;
    struct Node* lessTail = NULL;
    struct Node* greaterList = NULL;
    struct Node* greaterTail = NULL;
    struct Node* current = head;

    while (current != NULL) {
        if (current->data < partitionValue) {
            if (lessList == NULL) {
                lessList = current;
                lessTail = current;
            } else {
                lessTail->next = current;
                lessTail = current;
            }
        } else {
            if (greaterList == NULL) {
                greaterList = current;
                greaterTail = current;
            } else {
                greaterTail->next = current;
                greaterTail = current;
            }
        }
        current = current->next;
    }

    if (lessList == NULL) {
        return greaterList;
    }

    lessTail->next = greaterList;
    if (greaterTail != NULL) {
        greaterTail->next = NULL;
    }

    return lessList;
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
    append(&head, 4);
    append(&head, 3);
    append(&head, 2);
    append(&head, 5);
    append(&head, 2);

    // Print the original linked list
    printf("Original Linked List:\n");
    printList(head);

    int partitionValue = 3;

    // Partition the linked list
    head = partition(head, partitionValue);

    // Print the partitioned linked list
    printf("\nPartitioned Linked List (around %d):\n", partitionValue);
    printList(head);

    return 0;
}
