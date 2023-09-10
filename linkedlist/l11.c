#include <stdio.h>
#include <stdlib.h>

// Define a singly linked list node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to find the length of a linked list
int length(struct Node* head) {
    int count = 0;
    struct Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

// Function to find the intersection point of two linked lists
struct Node* findIntersection(struct Node* head1, struct Node* head2) {
    int len1 = length(head1);
    int len2 = length(head2);

    struct Node* ptr1 = head1;
    struct Node* ptr2 = head2;

    // Move the longer list's pointer ahead by the difference in lengths
    if (len1 > len2) {
        int diff = len1 - len2;
        for (int i = 0; i < diff; i++) {
            ptr1 = ptr1->next;
        }
    } else if (len2 > len1) {
        int diff = len2 - len1;
        for (int i = 0; i < diff; i++) {
            ptr2 = ptr2->next;
        }
    }

    // Move both pointers simultaneously until they meet at the intersection point
    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1 == ptr2) {
            return ptr1; // Intersection point found
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return NULL; // No intersection point found
}

int main() {
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;

    // Create the first linked list: 1->2->3
    struct Node* node1 = (struct Node*)malloc(sizeof(struct Node));
    node1->data = 1;
    node1->next = NULL;
    head1 = node1;

    struct Node* node2 = (struct Node*)malloc(sizeof(struct Node));
    node2->data = 2;
    node2->next = NULL;
    node1->next = node2;

    struct Node* node3 = (struct Node*)malloc(sizeof(struct Node));
    node3->data = 3;
    node3->next = NULL;
    node2->next = node3;

    // Create the second linked list: 4->5
    struct Node* node4 = (struct Node*)malloc(sizeof(struct Node));
    node4->data = 4;
    node4->next = NULL;
    head2 = node4;

    struct Node* node5 = (struct Node*)malloc(sizeof(struct Node));
    node5->data = 5;
    node5->next = NULL;
    node4->next = node5;

    // Connect the two linked lists at node3
    node5->next = node3;

    // Find the intersection point
    struct Node* intersection = findIntersection(head1, head2);

    if (intersection != NULL) {
        printf("Intersection Point: %d\n", intersection->data);
    } else {
        printf("No intersection point found.\n");
    }

    return 0;
}
