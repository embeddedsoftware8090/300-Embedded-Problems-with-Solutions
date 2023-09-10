#include <stdio.h>
#include <stdlib.h>

// Define a singly linked list node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to find the length of the linked list
int findLength(struct Node* head) {
    int length = 0;
    struct Node* current = head;

    while (current != NULL) {
        length++;
        current = current->next;
    }

    return length;
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

    printf("Linked List: ");
    display(head);

    int length = findLength(head);
    printf("Length of the linked list: %d\n", length);

    return 0;
}
