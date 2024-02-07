#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct node {
    int data;
    struct node* next;
    struct node* prev;
};
struct node* head = NULL;

struct node* createNode(int data)
{
    struct node* newnode = malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}

bool isEmpty()
{
    if (head == NULL)
    return true;
    else
    return false;
}

void addEnd()
{
    int data;
    printf("Enter the value to enrter in the list");
    scanf("%d",&data);
    struct node* newnode = createNode(data);
    if (isEmpty())
    {
        head = newnode;
    }
    else{
        struct node* temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
    }
}

void addFront()
{
    int data;
    printf("Enter the value to enter in the list");
    scanf("%d",&data);
    struct node* newnode = createNode(data);
    if (isEmpty())
    {
        head = newnode;
    }
    else{
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }

}

void Dequeue_front()
{
    if(isEmpty)
    printf("Empty queue");
    else{
        
    }
}

void Display()
{
    struct node* temp =  head;
    if (isEmpty())
    printf("Empty queue");
    else{
        while (temp != NULL)
        {
            printf("%d \t",temp->data);
            temp = temp->next;
        }
        
    }
}

void main()
{
    int choice;
    while (1)
    {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Add element at the end\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Add Front\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addEnd();
                break;
            case 2:
                Dequeue();
                break;
            case 3:
                Display();
                break;
            case 4:
                addFront();
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}