#include <stdio.h>
#include <stdlib.h>

// Define a singly linked list node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to find the middle element of the linked list
int findMiddle(struct Node* head) {
    struct Node* slow_ptr = head;
    struct Node* fast_ptr = head;

    if (head != NULL) {
        while (fast_ptr != NULL && fast_ptr->next != NULL) {
            fast_ptr = fast_ptr->next->next; // Move fast pointer by two steps
            slow_ptr = slow_ptr->next;       // Move slow pointer by one step
        }
        return slow_ptr->data; // The slow pointer is now at the middle element
    }
    return -1; // Return -1 if the list is empty
}

// Function to insert a new node at the end of the linked list
void insert(struct Node** head, int data) {
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

// Function to display the linked list
void display(struct Node* head) {
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
    insert(&head, 5);

    printf("Linked List: ");
    display(head);

    int middle = findMiddle(head);
    if (middle != -1) {
        printf("Middle element: %d\n", middle);
    } else {
        printf("The list is empty.\n");
    }

    return 0;
}
