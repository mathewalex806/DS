#include <stdio.h>
#include <stdlib.h>

// Node structure for a binary tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to convert a binary tree to array
void ConvertBinaryTreeToArray(struct Node* root, int* array, int index) {
    // Base case: if the node is NULL, mark the index as empty or use a sentinel value
    if (root == NULL) {
        array[index] = -1; // Using -1 as a sentinel value for an empty node
        return;
    }

    // Store the value of the root at the current index
    array[index] = root->data;

    // Recursively call for the left child with index 2 * index
    ConvertBinaryTreeToArray(root->left, array, 2 * index);

    // Recursively call for the right child with index 2 * index + 1
    ConvertBinaryTreeToArray(root->right, array, 2 * index + 1);
}

int main() {
    // Example binary tree
    struct Node* root = (struct Node*)malloc(sizeof(struct Node));
    root->data = 1;
    root->left = (struct Node*)malloc(sizeof(struct Node));
    root->left->data = 2;
    root->left->left = root->left->right = NULL;
    root->right = (struct Node*)malloc(sizeof(struct Node));
    root->right->data = 3;
    root->right->left = root->right->right = NULL;

    // Calculate the size of the array needed to represent the binary tree
    int size = 4; // In this example, the tree has 2 levels, so the array size is 2^(2+1) - 1 = 4

    // Create an array to store the binary tree
    int* array = (int*)malloc(size * sizeof(int));

    // Convert the binary tree to array
    ConvertBinaryTreeToArray(root, array, 1); // Starting level is 1

    // Print the array representation
    printf("Array representation of the binary tree: ");
    for (int i = 1; i <= size; i++) {
        printf("%d ", array[i]);
    }

    // Clean up memory
    free(array);
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}
