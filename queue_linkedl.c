#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    struct node *next ;
};
struct node *head = NULL;

struct node* createNode(int data)
{
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

bool isEmpty()
{
    return(head== NULL);
}

void enqueue()
{
    printf("Enter the value to enter in the queue");
    int data;
    scanf("%d",&data);
    struct node *newnode = createNode(data);
    if (isEmpty())
    head = newnode;
    else{
        struct node *temp = head;
        while (temp->next!= NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void dequeue()
{
    if(isEmpty())
    printf("Queue is empty");
    else{
        struct node *temp = head;
        printf("%d",temp->data);
        head = head->next;
        free(temp);
    }
}

void display()
{
    if(isEmpty())
    printf("Queue is empty");
    else{
        struct node *temp = head;
        while (temp!= NULL)
        {
            printf("%d\t",temp->data);
            temp = temp->next;
        }
        
    }
}

void main()
{
    printf("Program to create a queue using a linked list");
    bool loop = true;
    int choice;
    while (loop)
    {
         printf("\n");
            printf("Menu \n 1.Enqueue \n 2.Dequeue \n 3.Display queue \n Enter your choice (1-3): \t");
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
                    display();
                    break;
                default:
                    printf("Invalid choice ");
                    break;

            }
    
    }
}
