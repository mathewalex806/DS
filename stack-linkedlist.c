#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node 
{
    int data;
    struct node *next;
};
bool condition = false;

struct node *head = NULL;

void addelement(int val)
{
    if (head == NULL)
    {
        struct node *newnode = malloc(sizeof(struct node));
        
        newnode->data = val;
        newnode->next= NULL;
        head = newnode;
        printf("First element created\n");
    }
    else
    {
        struct node *newnode = malloc(sizeof(struct node));
        newnode->data = val;
        newnode->next = head;
        head = newnode;
        printf("Element add to the stack\n");
    }
}

void remove_element()
{
    if (head == NULL)
    printf("Stack is empty");
    else
    {
        struct node *ptr = head;
        head = head->next;
        int rem = ptr->data;
        free(ptr);
        printf("Freed element %d",rem);
    }
}

void display()
{
    struct node *ptr = head;
    while (ptr!= NULL)
    {
        printf("%d\n",ptr->data);
        ptr = ptr->next;
    }
    
}


void main()
{
    int choice;
    printf("Program that implements stack using linked list");
    
    while (condition== false)
    {
        printf("\nMenu \n1.Add element\n2.Remove element\n3.Display stack\n4.Exit\nEnter your choice:\t");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            int val;
            printf("Enter value \t:");
            scanf("%d",&val);
            addelement(val);
            break;
        
        case 2:
                remove_element();
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