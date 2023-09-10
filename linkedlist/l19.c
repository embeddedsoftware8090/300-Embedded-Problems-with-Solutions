#include <stdio.h>
#include <stdlib.h>

// Define a singly linked list node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to detect and remove a loop in a linked list
void detectAndRemoveLoop(struct Node* head) {
    struct Node* slow = head;
    struct Node* fast = head;
    struct Node* loopStart = NULL;

    // Detect the loop using Floyd's algorithm
    while (slow && fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            loopStart = slow;
            break;
        }
    }

    // If a loop is found, remove it
    if (loopStart) {
        struct Node* ptr1 = head;
        struct Node* ptr2 = loopStart;

        // Move one pointer to the head of the linked list
        while (ptr1->next != ptr2->next) {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }

        // Find the last node in the loop
        while (ptr2->next != loopStart) {
            ptr2 = ptr2->next;
        }

        // Remove the loop by setting the next pointer of the last node to NULL
        ptr2->next = NULL;
    }
}

// Function to insert a new node at the end of the linked list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to print the linked list
void printLinkedList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    
    // Create a linked list with a loop (1->2->3->4->5->3)
    for (int i = 1; i <= 5; i++) {
        insertAtEnd(&head, i);
    }
    head->next->next->next->next->next = head->next;

    detectAndRemoveLoop(head);

    printf("Linked List after removing the loop: ");
    printLinkedList(head);

    return 0;
}
