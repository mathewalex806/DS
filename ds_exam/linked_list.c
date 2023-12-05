#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node 
{
    int data;
    struct node *next;
};

struct node *head = NULL;

struct node* create_node(int a)
{
    struct node *newnode = malloc(sizeof(struct node));
    newnode ->data = a;
    newnode->next = NULL;
    return newnode;
}

void insert_end()
{
    int val;
    printf("Enter the value to insert to the end of the node \n");
    scanf("%d",&val);
    struct node *newnode = create_node(val);
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        struct node *ptr = head;
        while (ptr->next!= NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = newnode;
        printf("The value has been added.\n");
    }
}

void insert_begin()
{
    int val;
    printf("Enter the value to insert to the end of the node \n");
    scanf("%d",&val);
    struct node *newnode = create_node(val);
    if (head == NULL)
    {
        head = newnode;
        printf("The first element has been added %d.\n",head->data);
    }
    else
    {
        struct node *ptr = head;
        newnode->next = head;
        head = newnode;
        printf("Value has been added %d",head->data);
    }
}

void delete_begin()
{
    if (head == NULL)
    printf("Empty list");
    else
    {
        struct node *ptr = head;
        head = head->next;
        printf("The element to be deleted is %d",ptr->data);
        free(ptr);
        printf("Element successfully deleted.");
    }
}

void delete_end()
{
    struct node *ptr = head;
    if (head == NULL)
    printf("Empty list");
    else
    {
        while (ptr->next->next!= NULL)
        {
            ptr = ptr->next;
        }
        printf("The element to be deleted is %d",ptr->next->data);
        struct node *temp = ptr->next->next;
        ptr->next = NULL;
        free(temp);
        printf("Element deleted");
        
    }
}

void display()
{
	if (head == NULL)
	printf("The list is empty\n");
	else
	{
		struct node *ptr = head;
		while(ptr->next != NULL)
		{
			printf("%d\t",ptr->data);
			ptr = ptr->next;
		}
		printf("%d\t",ptr->data);
	}
}


void main()
{
    bool condition = false;
	int choice;
	while (condition == false)
	{
		printf("\nMenu\n1.Insertion at end\n2.Insertion at begining\n3.Deletion at end\n4.Deletion at begining\n5.Display\nEnter your choice");
		scanf("%d",&choice);
		switch (choice)
		{
			case 1:
				insert_end();
				break;
			case 2:
				insert_begin();
				break;
			case 3:
				delete_end();
				break;
			case 4:
				delete_begin();
				break;
			case 5:
				display();
				break;
			default:
				printf("Invalid choice.");
				break;
		}
		
	}
}