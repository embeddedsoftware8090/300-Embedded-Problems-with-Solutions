#include <stdio.h>
#include <stdlib.h>

// Define a singly linked list node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the end of the linked list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to segregate even and odd nodes in a linked list
struct Node* segregateEvenOdd(struct Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct Node* evenStart = NULL;
    struct Node* evenEnd = NULL;
    struct Node* oddStart = NULL;
    struct Node* oddEnd = NULL;

    struct Node* current = head;

    while (current != NULL) {
        int data = current->data;

        if (data % 2 == 0) { // Even node
            if (evenStart == NULL) {
                evenStart = current;
                evenEnd = current;
            } else {
                evenEnd->next = current;
                evenEnd = current;
            }
        } else { // Odd node
            if (oddStart == NULL) {
                oddStart = current;
                oddEnd = current;
            } else {
                oddEnd->next = current;
                oddEnd = current;
            }
        }

        current = current->next;
    }

    if (evenStart == NULL) {
        return oddStart;
    } else {
        evenEnd->next = oddStart;
        oddEnd->next = NULL;
        return evenStart;
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
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);

    printf("Original Linked List: ");
    printList(head);

    // Segregate even and odd nodes
    head = segregateEvenOdd(head);

    printf("Segregated Linked List: ");
    printList(head);

    return 0;
}
