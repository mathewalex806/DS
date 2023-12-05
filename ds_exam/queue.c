#include <stdio.h>
#include <stdbool.h>
int front =-1, rear = -1;
int n;
void push(int a[])
{
    if (rear == n-1)
    printf("Queue overflow.");

    else
    {
        if (front ==-1 && rear == -1)
        {
            front = 0;
            rear =0;
            printf("Enter the value into the queue");
            scanf("%d",&a[rear]);
        }
        else
        {
            rear = rear+1;
            printf("Enter the value into the queue");
            scanf("%d",&a[rear]);
        }
    }
}

void pop(int a[])
{
    if (front ==n-1)
    printf("Queue underflow");

    else
    {
        printf("The value deleted is %d",a[front]);
        front = front+1;
    }
}

void main()
{
    bool condition = true;
    printf("Enter the size of the queue");
    scanf("%d",&n);
    int a [n];
    int choice;
    while(condition)
    {
        printf("\n Menu \n 1.Push \n 2.Pop \n 3. Exit \n Enter your choice (1-5) \t");
    scanf("%d",&choice);
    switch (choice)
    {
    case  (1):
				push(a);
				break;
    case (2):
				pop(a);
				break;
    default:
				condition = false;
      			break;
    }
    }

}