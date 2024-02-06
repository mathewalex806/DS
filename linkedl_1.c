#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

 struct node{
    int data;
    struct node *next;
 };

 struct node *head = NULL;

struct node* createNode(int data)
{
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void enqueue()
{
    int data;
    printf("Enter the value to add to the list \n");
    scanf("%d",&data);
    struct node *newnode = createNode(data);
    if (head == NULL)
    head = newnode;
    else{
        struct node *temp = head;
        while(temp->next !=NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void display()
{
    if (head == NULL)
    printf("Empty linked list");
    else{
        struct node *temp = head;
        while(temp!= NULL)
        {
            printf("%d  ",temp->data);
            temp = temp->next;
        }
        
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
            printf("Menu \n 1.Enqueue \n 2.Dequeue \n 3.Size \n 4.Exit \n Enter your choice (1-4): \t");
            scanf("%d",&choice);
            switch (choice)
            {
                case (1):
                    enqueue();
                    break;
                
                case (2):
                    display();
                    break;
                default:
                    printf("Invalid choice ");
                    break;

            }
    
    }
}