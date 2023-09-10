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

// Function to merge two sorted linked lists
struct Node* mergeSortedLists(struct Node* list1, struct Node* list2) {
    struct Node dummy;
    dummy.next = NULL;
    struct Node* tail = &dummy;

    while (1) {
        if (list1 == NULL) {
            tail->next = list2;
            break;
        } else if (list2 == NULL) {
            tail->next = list1;
            break;
        }

        if (list1->data <= list2->data) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }

    return dummy.next;
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

    // Insert elements into the first sorted linked list
    insertAtEnd(&list1, 1);
    insertAtEnd(&list1, 3);
    insertAtEnd(&list1, 5);

    // Insert elements into the second sorted linked list
    insertAtEnd(&list2, 2);
    insertAtEnd(&list2, 4);
    insertAtEnd(&list2, 6);

    printf("First Sorted Linked List: ");
    printList(list1);

    printf("Second Sorted Linked List: ");
    printList(list2);

    // Merge the two sorted linked lists
    struct Node* mergedList = mergeSortedLists(list1, list2);

    printf("Merged Sorted Linked List: ");
    printList(mergedList);

    return 0;
}
