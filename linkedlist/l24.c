#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the structure for a node in the binary tree with parent pointers
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    struct TreeNode* parent;
};

// Function to find the common ancestor of two nodes in a binary tree
struct TreeNode* findCommonAncestor(struct TreeNode* node1, struct TreeNode* node2) {
    // Create a set to store ancestors
    struct TreeNode* ancestors[100];
    int top = -1;

    // Traverse from node1 to the root and add all ancestors to the set
    while (node1 != NULL) {
        ancestors[++top] = node1;
        node1 = node1->parent;
    }

    // Traverse from node2 to the root and check for common ancestors
    while (node2 != NULL) {
        for (int i = 0; i <= top; i++) {
            if (node2 == ancestors[i]) {
                return node2; // Common ancestor found
            }
        }
        node2 = node2->parent;
    }

    return NULL; // No common ancestor found
}

int main() {
    // Construct a binary tree as a doubly linked list with parent pointers
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = 4;
    root->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->left->val = 5;
    root->left->parent = root;
    root->left->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->left->right->val = 6;
    root->left->right->parent = root->left;
    root->left->right->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->left->right->right->val = 7;
    root->left->right->right->parent = root->left->right;
    root->left->right->right->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->left->right->right->right->val = 8;
    root->left->right->right->right->parent = root->left->right->right;
    root->left->right->right->right->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->left->right->right->right->right->val = 9;
    root->left->right->right->right->right->parent = root->left->right->right->right;

    // Nodes for which we want to find the common ancestor
    struct TreeNode* node1 = root->left->right->right; // Node with value 7
    struct TreeNode* node2 = root->left->right->right->right->right; // Node with value 9

    // Find the common ancestor
    struct TreeNode* commonAncestor = findCommonAncestor(node1, node2);

    if (commonAncestor != NULL) {
        printf("Common Ancestor: %d\n", commonAncestor->val);
    } else {
        printf("No Common Ancestor found.\n");
    }

    // Clean up the dynamically allocated memory (not shown in the example)

    return 0;
}
