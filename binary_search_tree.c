#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node{
    int data;
    struct node* right;
    struct node* left;
};

struct node* createNode(int data)
{
    struct node* newnode = malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

void insert(struct node* root, int data)
{
    if (root== NULL)
    {
        struct node *newnode = createNode(data);
        root = newnode;
    }
    else if (root->data < data)
    insert(root->right, data);
    else
    insert(root->left,data);
}

void display(struct node* root)
{
    if (root != NULL)
    {
        display(root->left);
        printf("%d ", root->data);
        display(root->right);
    }
}

int main()
{
    struct node* root = NULL;

    // Insert nodes into the binary search tree
    insert(root, 5);
    insert(root, 3);
    insert(root, 7);
    insert(root, 2);
    insert(root, 4);
    insert(root, 6);
    insert(root, 8);

    // Display the binary search tree
    printf("Binary Search Tree: ");
    display(root);

    return 0;
}
    
