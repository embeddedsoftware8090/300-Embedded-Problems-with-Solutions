#include <stdio.h>
#include <stdlib.h>

// Define a singly linked list node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to merge two sorted linked lists
struct Node* merge(struct Node* left, struct Node* right) {
    struct Node dummy;
    struct Node* tail = &dummy;
    dummy.next = NULL;

    while (left != NULL && right != NULL) {
        if (left->data < right->data) {
            tail->next = left;
            left = left->next;
        } else {
            tail->next = right;
            right = right->next;
        }
        tail = tail->next;
    }

    if (left != NULL) {
        tail->next = left;
    } else {
        tail->next = right;
    }

    return dummy.next;
}

// Function to perform Merge Sort on a linked list
struct Node* mergeSort(struct Node* head) {
    if (head == NULL || head->next == NULL) {
        return head; // Base case: List is empty or has one element
    }

    struct Node* slow = head;
    struct Node* fast = head->next;

    // Use slow and fast pointers to split the list into two halves
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    struct Node* left = head;
    struct Node* right = slow->next;
    slow->next = NULL; // Split the list into two halves

    left = mergeSort(left);   // Recursively sort the left half
    right = mergeSort(right); // Recursively sort the right half

    // Merge the sorted halves
    return merge(left, right);
}

// Function to insert a new node at the beginning of the list
void insertAtBegin(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

// Function to print a linked list
void printLinkedList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    insertAtBegin(&head, 2);
    insertAtBegin(&head, 1);
    insertAtBegin(&head, 3);

    printf("Original List: ");
    printLinkedList(head);

    head = mergeSort(head);

    printf("Sorted List: ");
    printLinkedList(head);

    return 0;
}
