#include <stdio.h>
#include <stdlib.h>

// Define a singly linked list node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the beginning of the linked list
void insertAtBegin(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

// Function to add two numbers represented by linked lists
struct Node* addLists(struct Node* list1, struct Node* list2) {
    struct Node* result = NULL;
    struct Node* current = NULL;
    int carry = 0;

    while (list1 != NULL || list2 != NULL) {
        int sum = carry;

        if (list1 != NULL) {
            sum += list1->data;
            list1 = list1->next;
        }

        if (list2 != NULL) {
            sum += list2->data;
            list2 = list2->next;
        }

        carry = sum / 10;
        sum %= 10;

        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = sum;
        newNode->next = NULL;

        if (result == NULL) {
            result = newNode;
            current = newNode;
        } else {
            current->next = newNode;
            current = newNode;
        }
    }

    if (carry > 0) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = carry;
        newNode->next = NULL;
        current->next = newNode;
    }

    return result;
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
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    // Insert elements into the first linked list (represents 24)
    insertAtBegin(&list1, 4);
    insertAtBegin(&list1, 2);

    // Insert elements into the second linked list (represents 56)
    insertAtBegin(&list2, 6);
    insertAtBegin(&list2, 5);

    printf("First Linked List: ");
    printList(list1);

    printf("Second Linked List: ");
    printList(list2);

    // Add the two linked lists
    struct Node* sumList = addLists(list1, list2);

    printf("Sum Linked List: ");
    printList(sumList);

    return 0;
}
