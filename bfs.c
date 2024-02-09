#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct queue
{
    struct node * node;
};

void addLeft(struct node* root, int value)
{
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;
    root->left = newnode;
} 

void addRight(struct node* root, int value)
{
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;
    root->right = newnode;
}

void bfs_tree(struct node*root)
{
    if (root == NULL)
    printf("Empty graph");

    else
    {
        
    }
}

void main()
{
    struct node *root  = malloc(sizeof(struct node));
    root->data = 0;
    addLeft(root, 1);
    addRight(root, 2);
    addLeft(root->left, 3);
    addRight(root->right,4);

}