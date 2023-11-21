#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

void main ()
{
    struct node *head = malloc(sizeof(struct node));        // First Node
    head ->data = 45;
    head ->next = NULL;

    struct node *current = malloc(sizeof(struct node));     // Second node
    current ->data = 90;
    current ->next = NULL;
    head ->next = current;


    current = malloc(sizeof(struct node));                  // Third node
    current ->data = 35;
    current ->next = NULL;

    head ->next ->next = current;

    struct node *ptr = NULL;                                // Traversing through nodes
    ptr = head;
    while (ptr != NULL)
    {
        printf("%d \n",ptr->data);
        ptr = ptr->next;
    }
}