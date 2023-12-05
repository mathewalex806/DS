//Double ended queue implementation using circular queue
#include <stdio.h>
#include<stdlib.h>
int n;
int front =-1;
int rear = -1;
int  loop= 0;

void insert_rear(int a[])
{
    if (front == -1 && rear == -1)
    {
        front =0, rear =0;
        printf("Enter value");
        scanf("%d",&a[front]);
    }
    else if (front = (rear+1)%n)
    {
    printf("The queue is full");
    }

    else if (front !=0 && rear == n-1)
    {
        rear = 0;
        printf("Enter value ");
        scanf("%d",&a[rear]);
    }
    else
    {
        rear = rear +1;
        printf("Enter value into the queue");
        scanf("%d",&a[rear]);
    }

}

void insert_front(int a[])
{
    if (front == -1 && rear == -1)
    {
        front = 0, rear =0;
        printf("Enter value ");
        scanf("%d",&a[front]);
    }
    else if (front == 0 && rear != n-1)
    {
        front = n-1 ;
        printf("Enter value");
        scanf("%d",&a[front]);
    }
    else if (front = (rear+1)%n)
    {
        printf("The queue is full");
    }
    else
    {
        front = front -1;
        printf("Enter value");
        scanf("%d",&a[front]);
    }
}


void display(int a[])
{
    for (int i=0; i<n; i++)
    printf("%d \t",a[i]);
}


void main()
{
    printf("Enter size of the queue \t");
    scanf("%d",&n);
    int a[n];
    int choice;
    while (loop == 0)
    {
            printf("\n");
            printf("Menu \n 1.Insert front \n 2.Insert rear \n Enter your choice (1-4): \t");
            scanf("%d",&choice);
            switch (choice)
            {
                case (1):
                    insert_front(a);
                    break;
                
                case (2):
                    insert_rear(a);
                    break;
                
                case (3):
                    display(a);
                    break;
                default:
                    printf("Invalid choice ");
                    break;

            }
    }
}