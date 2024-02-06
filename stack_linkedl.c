#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    struct node *next;
};
struct node *head = NULL;

struct node* createNode(int data)
{
    struct node * newnode = malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void enqueue()
{
    printf("Enter the value to add to stack");
    int data;
    scanf("%d",&data);
    struct node *newnode = createNode(data);
    if (head == NULL)
    head = newnode;
    else{
        newnode->next = head;
        head = newnode;
    }
}

void dequeue()
{
    if (head == NULL)
    printf("Stack is empty");
    else{
        printf("%d",head->data);
        struct node *temp = head;
        head = head->next;
        free(temp);
    }
}

void top()
{
    if (head == NULL)
    printf("Stack is empty");
    else{
        printf("%d",head->data);
    }
}

void main()
{
    printf("Program to create a linked list");
    bool loop = true;
    int choice;
    while (loop)
    {
         printf("\n");
            printf("Menu \n 1.Enqueue \n 2.Dequeue \n 3.Top element \n Enter your choice (1-4): \t");
            scanf("%d",&choice);
            switch (choice)
            {
                case (1):
                    enqueue();
                    break;
                
                case (2):
                    dequeue();
                    break;
                case(3):
                    top();
                    break;
                default:
                    printf("Invalid choice ");
                    break;

            }
    
    }
}