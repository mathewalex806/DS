 #include <stdio.h>
 int front = -1 , rear  = -1, n;

void enqueue(int n, int a[n], int front, int rear)
{
    if (rear == n-1)
    {
        printf("Queue overflow");

    }
    else if (rear == -1 && front ==-1)
    {
        front ++;
        rear ++;
        printf("Enter element");
        scanf("%d",&a[rear]);
    }
    else
    {
        rear ++;
        printf("Enter element");
        scanf("%d",&a[rear]);
    }
}


void dequeue(int n, int a[n], int front , int rear)
{
    if (front == -1 && rear == -1)
    {
        printf("Queue underflow");
    }
    else if (front == n-1 )
    {}
    else
    {
        printf("Element removed from the queue is  %d",a[front]);
        front ++;
    }
}















 void main()
 {
    int choice;
    printf("Queue Program");
    printf("Enter size of queue");
    scanf("%d",&n);
    int a[n];
    printf("Menu\n 1.Enqueue \n 2.Dequeue \n Enter your choice : ");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        //enqueue
        break;


    case 2:
        // dequeue
        break;


    default:
        break;
    }

    
 }