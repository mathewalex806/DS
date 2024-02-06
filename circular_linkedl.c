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
    struct node *newnode = malloc(sizeof(struct node));
    newnode ->data = data;
    newnode ->next = NULL;
    return newnode;
}

bool isEmpty()
{
   if(head == NULL)
   return true;
   else
   return false;
}

void Enqueue()
{
    int data;
    printf("Enter the value to enter in the Queue");
    scanf("%d",&data);
    struct node *newnode = createNode(data);
    printf("%d",newnode->data);
    if (isEmpty())
    {
        newnode ->next = newnode;
        head = newnode;
        printf("Creating the head node");
        printf("%d",head->data);
    }
    else
    {
        struct node *temp = head;
            while(temp->next!= head)
            temp= temp->next;

            temp->next = newnode;
            newnode->next = head;
    }
}

void dequeue()
{
    if (isEmpty)
    {
    printf("Empty queue");
    }
    else{
        struct node *temp = head;
		if (temp->next == head)							// One element case
		{
			head = NULL;
			free(temp);
			printf("Element deleted\n");
		}
		else
		{							
		while(temp->next->next != head)							//traversing till 2nd last element
		{
			temp = temp->next;
		}
		struct node *end = temp->next;
		temp->next = head;
		printf("Deleting element %d\n",end->data);
		free(end);
		}
    }
}

void display()
{
   
    if (head == NULL)
	printf("The list is empty\n");
	else
	{
		struct node *ptr = head;
		while(ptr->next != head)
		{
			printf("%d\t",ptr->data);
			ptr = ptr->next;
		}
		printf("%d\t",ptr->data);
	}
}


int main() {
    int choice;
    
    do {
        printf("\n\n\n\nCircular Linked List Menu\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                Enqueue();
                break;
            case 2:
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);
    
    return 0;
}
































