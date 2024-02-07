#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node* left;
    struct node *right;
};

struct node* createNode(int data)
{
    struct node* newnode =malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

void addLeft(struct node* root,int data)
{
    struct node* newnode=  createNode(data);
    root->left = newnode;
}

void addRight(struct node* root, int data)
{
    struct node* newnode = createNode(data);
    root->right = newnode;
}

void inorder(struct node* root)
{
     if (root != NULL){
        inorder(root->left);
    printf("%d ->", root->data);
    inorder(root->right);
     }
  
}

void fillArrayRepresentation(struct node* root, int treeArray[], int index) {
    if (root == NULL) {
        return;
    }

    // Fill the current node's data in the array
    treeArray[index] = root->data;

    // Recursively fill the left and right subtrees
    fillArrayRepresentation(root->left, treeArray, 2 * index + 1);
    fillArrayRepresentation(root->right, treeArray, 2 * index + 2);
}


void main()
{
    printf("Creating a basic tree structure");
    struct node* root = malloc(sizeof(struct node));
    root->data = 0;
    addLeft(root,1);
    addRight(root,2);
    addLeft(root->left,3);
    addRight(root->left,4);
    printf("Completed tree creation ");

    inorder(root);
    printf("\n");
    int a[50];
    fillArrayRepresentation(root,a,0);

}