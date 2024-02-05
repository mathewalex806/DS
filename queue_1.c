#include <stdio.h>
#include <stdbool.h>
int front = -1, rear = -1,n;

void enqueue(int a[])
{
    if (rear == n-1)
    printf("Queue overflow");
    else{
        
        if(rear == -1 && front ==-1)
        {
            printf("Enter the value to input in the queue");
            int val;
            scanf("%d",&val);
            rear =0; 
            front=0;
            a[rear] = val;
        }
        else{
            rear = rear+1;
            printf("Enter the value to enter in the queue");
            int val;
            scanf("%d",&val);
            a[rear] = val;

        }
    }
}

void dequeue(int a[])
{
    if (rear == -1 && front ==-1 || front>rear)
    printf("Queue underflow");
    else{
        if(rear == front)
        {
            printf("%d",a[front]);
            front =-1;
            rear =-1;
        }
        else{
            printf("%d",a[front]);
            front ++;
        }
    }
}
void main(){
   printf("Enter size of the queue \t");
    scanf("%d",&n);
    int a[n];
    int choice;
    bool loop = true;
    while (loop )
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