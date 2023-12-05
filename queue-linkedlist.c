#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node 
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void enqueue(int val)
{
    if (head == NULL)
    {
        struct node *newnode = malloc(sizeof(struct node));
        newnode ->data= val;
        newnode->next = NULL;
        head = newnode;
    }
    else
    {
        struct node *newnode = malloc(sizeof(struct node));
        newnode->data = val;
        newnode->next = NULL;
        struct node *ptr = head;
        while (ptr->next=NULL)
        {
            ptr = ptr->next;
        }
        ptr->next->next = newnode;
        printf("New element added \n");
        
    }
}

void dequeue()
{}

void display()
{
    if (head == NULL)
    printf("Queue is empty\n");
    else
    {
        struct node *ptr = head;
        while (ptr!=NULL)
        {
            printf("%d\t",ptr->data);
            ptr = ptr->next;
        }
        
    }
}



void main()
{
    bool condition = false;

    while (condition == false)
    {
    int choice;
    printf("Program that implements queue using linked list");
    
    while (condition== false)
    {
        printf("\nMenu \n1.Add element\n2.Remove element\n3.Display queue\n4.Exit\nEnter your choice:\t");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            int val;
            printf("Enter value \t:");
            scanf("%d",&val);
            enqueue(val);
            break;
        
        case 2:
                dequeue();
                break;
        case 3:
                display();
                break;
        case 4:
                condition = true;
                break;
        
        default:
            printf("Invalid choice. To exit, enter 4 or try again.\n");
            break;
        }
    }
    }
    
}