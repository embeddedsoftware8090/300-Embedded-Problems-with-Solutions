#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct ListNode {
    int val;
    struct ListNode* next;
};

// Function to reverse a linked list
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* current = head;
    struct ListNode* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

// Function to check if a linked list is a palindrome
bool isPalindrome(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return true; // Empty list or single-node list is a palindrome
    }

    struct ListNode* slow = head;
    struct ListNode* fast = head;
    
    // Move slow to the middle and fast to the end of the list
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse the second half of the list
    struct ListNode* secondHalf = reverseList(slow->next);
    
    // Compare the first half and the reversed second half
    struct ListNode* firstHalf = head;
    while (secondHalf != NULL) {
        if (firstHalf->val != secondHalf->val) {
            return false; // Not a palindrome
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    return true; // It's a palindrome
}

int main() {
    // Construct a sample linked list
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val = 1;
    head->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->val = 2;
    head->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->val = 2;
    head->next->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->next->val = 1;
    head->next->next->next->next = NULL;

    // Check if the linked list is a palindrome
    if (isPalindrome(head)) {
        printf("Linked list is a palindrome.\n");
    } else {
        printf("Linked list is not a palindrome.\n");
    }

    // Clean up the dynamically allocated memory (not shown in the example)

    return 0;
}
