#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
	int data;
	struct node *next;
};

struct node *head = NULL;

struct node* createnode()								//Creating node
{
	int val;
	printf("Enter value for the node ");
	scanf("%d",&val);
	struct node *newnode = malloc(sizeof(struct node));
	newnode->next = NULL;
	newnode->data = val;
	return newnode;
}

void insert_begin()					
{
	struct node *newnode = createnode();
	if (head == NULL)								//Empty list case
	{
		newnode->next = newnode;
		head = newnode;
		printf("First node added\n");
	}
	else
	{
		newnode->next = head;
		struct node *ptr = head;
		while (ptr->next !=head)						//traversing till last element
		{
			ptr = ptr->next;
		}
		ptr ->next = newnode;							//linking last element to newnode
		head = newnode;
		printf("New node added %d\n",newnode->data);
		
	}
	
}

void insert_end()
{
	struct node *newnode = createnode();
	if (head == NULL)								// If list is empty
	{
		newnode ->next = newnode;
		head = newnode;
		printf("Adding first element %d\n",newnode->data);
	}
	else
	{
		struct node *ptr = head;
		while(ptr->next !=head)							//Traversing till last element
		{
			ptr = ptr->next;
		}
		ptr->next = newnode;								
		newnode->next = head;								//Updating last element address
	}
}
void delete_begin()
{
	if (head == NULL)									//Empty list case
	{
		printf("Empty list\n");
	}
	else
	{
		struct node *temp = head;							//Only one element in the list case
		if (temp->next == head)
		{
			head = NULL;
			printf("The element %d has been deleted\n",temp->data);
			free(temp);
		}
		else
		{
			head = head->next;
			free(temp);
			struct node *ptr = head;
			while(ptr->next != NULL)						// Traversing till last element
			{
				ptr = ptr->next;
			}
			ptr->next = head;
		}
		
	}
}

void delete_end()
{
	if (head == NULL)
	{
		printf("Empty list\n");
	}
	else
	{
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
