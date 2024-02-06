#include <stdio.h>

#include <stdio.h>
#include <stdbool.h>
int front =-1, rear =-1, n;


bool isFull(int a[])
{
    return(front==(rear+1)%n);
}

bool isEmpty(int a[])
{
    return(front==-1);
}


void enqueue(int a[])
{
    if(isFull(a))
    printf("Queue overflow");
    else if (isEmpty(a))
    {
        rear =0;
        front=0;
        printf("Enter value");
        scanf("%d",&a[rear]);
    }
    else{
        rear = (rear+1)%n;
        printf("Enter value");
        scanf("%d",&a[rear]);
    }
}

void dequeue(int a[])
{
    if (isEmpty(a))
    printf("Queue underflow");
    else{
        printf("%d",a[front]);
        if(front == rear)
        {
            front = -1;
            rear = -1;
        }
        else{
            front = (front+1)%n;
        }
    }
}


void main()
{
    printf("Enter size of the queue \t");
    scanf("%d",&n);
    int a[n];
    int choice;
    bool loop = true;
    while (loop)
    {
            printf("\n");
            printf("Menu \n 1.Enqueue \n 2.Dequeue \n 3.Size \n 4.Exit \n Enter your choice (1-4): \t");
            scanf("%d",&choice);
            switch (choice)
            {
                case (1):
                    enqueue(a);
                    break;
                
                case (2):
                    dequeue(a);
                    break;
                default:
                    printf("Invalid choice ");
                    break;

            }
    }
}
