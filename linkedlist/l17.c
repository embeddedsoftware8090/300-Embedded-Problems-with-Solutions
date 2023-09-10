#include <stdio.h>
#include <stdlib.h>

// Define a singly linked list node structure
struct Node {
    int data;
    struct Node* next;
    struct Node* random;
};

// Function to insert a new node at the beginning of the list
void insertAtBegin(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    newNode->random = NULL;
    *head = newNode;
}

// Function to clone a linked list with next and random pointers
struct Node* cloneLinkedList(struct Node* head) {
    if (head == NULL) {
        return NULL;
    }

    // Create a mapping of original nodes to their corresponding copies
    struct Node* originalToCopy[1000] = {NULL};
    
    // Create a new head for the cloned list
    struct Node* newHead = (struct Node*)malloc(sizeof(struct Node));
    newHead->data = head->data;
    newHead->next = NULL;
    newHead->random = NULL;
    
    originalToCopy[(unsigned long)head] = newHead;
    
    struct Node* currentOriginal = head;
    struct Node* currentNew = newHead;
    
    while (currentOriginal != NULL) {
        // Clone the next pointer
        if (currentOriginal->next != NULL) {
            if (originalToCopy[(unsigned long)currentOriginal->next] == NULL) {
                originalToCopy[(unsigned long)currentOriginal->next] = (struct Node*)malloc(sizeof(struct Node));
                originalToCopy[(unsigned long)currentOriginal->next]->data = currentOriginal->next->data;
                originalToCopy[(unsigned long)currentOriginal->next]->next = NULL;
                originalToCopy[(unsigned long)currentOriginal->next]->random = NULL;
            }
            currentNew->next = originalToCopy[(unsigned long)currentOriginal->next];
        }
        
        // Clone the random pointer
        if (currentOriginal->random != NULL) {
            if (originalToCopy[(unsigned long)currentOriginal->random] == NULL) {
                originalToCopy[(unsigned long)currentOriginal->random] = (struct Node*)malloc(sizeof(struct Node));
                originalToCopy[(unsigned long)currentOriginal->random]->data = currentOriginal->random->data;
                originalToCopy[(unsigned long)currentOriginal->random]->next = NULL;
                originalToCopy[(unsigned long)currentOriginal->random]->random = NULL;
            }
            currentNew->random = originalToCopy[(unsigned long)currentOriginal->random];
        }
        
        currentOriginal = currentOriginal->next;
        currentNew = currentNew->next;
    }
    
    return newHead;
}

// Function to print the linked list with both next and random pointers
void printLinkedList(struct Node* head) {
    while (head != NULL) {
        printf("Data: %d, ", head->data);
        
        if (head->random != NULL) {
            printf("Random: %d", head->random->data);
        }
        
        printf("\n");
        head = head->next;
    }
}

int main() {
    // Create the original linked list with next and random pointers
    struct Node* head = NULL;
    insertAtBegin(&head, 3);
    insertAtBegin(&head, 2);
    insertAtBegin(&head, 1);
    
    // Set random pointers
    head->random = head->next->next;
    head->next->random = head;
    head->next->next->random = head->next;
    
    printf("Original List:\n");
    printLinkedList(head);
    
    // Clone the linked list
    struct Node* clonedHead = cloneLinkedList(head);
    
    printf("\nCloned List:\n");
    printLinkedList(clonedHead);
    
    return 0;
}
