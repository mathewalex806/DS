#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

void search(struct Node* root, int value)
{
    if (root->data == value)
    {
        printf("Value Found \n");
    }
    else if (root->data <value)
    {
        search(root->right, value);
    }
    else if(root->data>value)
    {
        search(root->left,value);
    }
    else
    {
        printf("Value not found\n");
    }
}

void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    struct Node* root = NULL;

    // Inserting nodes into the binary search tree
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 8);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 7);
    root = insert(root, 9);
    root = insert(root, 1);
    root = insert(root, 6);
    root = insert(root, 10);


    search(root, 5);
    search(root, 3);
    search(root, 8);
    search(root,15);
    


    // Printing the binary search tree in inorder traversal
    printf("Inorder traversal of the binary search tree: ");
    inorderTraversal(root);

    return 0;
}

