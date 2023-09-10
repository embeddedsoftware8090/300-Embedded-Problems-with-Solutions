#include <stdio.h>
#include <stdlib.h>

// Define a singly linked list node structure for characters
struct Node {
    char data;
    struct Node* next;
};

// Function to compare two linked lists representing strings
int compareStrings(struct Node* list1, struct Node* list2) {
    while (list1 != NULL && list2 != NULL) {
        if (list1->data != list2->data) {
            return 0; // Not equal
        }
        list1 = list1->next;
        list2 = list2->next;
    }

    // If both lists have reached the end, they are equal
    return (list1 == NULL && list2 == NULL);
}

// Function to print a linked list of characters
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%c -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    // Create the first linked list representing "abc"
    struct Node* node1 = (struct Node*)malloc(sizeof(struct Node));
    node1->data = 'a';
    node1->next = NULL;
    list1 = node1;

    struct Node* node2 = (struct Node*)malloc(sizeof(struct Node));
    node2->data = 'b';
    node2->next = NULL;
    node1->next = node2;

    struct Node* node3 = (struct Node*)malloc(sizeof(struct Node));
    node3->data = 'c';
    node3->next = NULL;
    node2->next = node3;

    // Create the second linked list representing "abc"
    struct Node* node4 = (struct Node*)malloc(sizeof(struct Node));
    node4->data = 'a';
    node4->next = NULL;
    list2 = node4;

    struct Node* node5 = (struct Node*)malloc(sizeof(struct Node));
    node5->data = 'b';
    node5->next = NULL;
    node4->next = node5;

    struct Node* node6 = (struct Node*)malloc(sizeof(struct Node));
    node6->data = 'c';
    node6->next = NULL;
    node5->next = node6;

    printf("List 1: ");
    printList(list1);

    printf("List 2: ");
    printList(list2);

    // Compare the two lists
    int result = compareStrings(list1, list2);

    if (result) {
        printf("Equal\n");
    } else {
        printf("Not Equal\n");
    }

    return 0;
}
