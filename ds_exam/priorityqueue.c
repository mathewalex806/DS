#include <stdio.h>
#include <stdbool.h>
int front =-1, rear = -1,n;

void push(int a[])
{
    int element=0;
    if (front ==n)
    printf("Queue underflow");

    else
    {
        if (front ==-1 && rear ==-1)
        {
            front =0;
            rear =0;
            printf("Enter the element \n");
            scanf("%d",&a[rear]);

        }
        else
        {
        rear = rear+1;
        printf("Enter the element \n");
        scanf("%d",&a[rear]);

        for (int i=0 ; i<n-1; i++ )
    {
        for (int j= 0 ; j< n-1-i ; j++)
        {
            if (a[j+1]< a[j])
            {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }

    printf("Sorted array : \n");
    for (int i=0 ; i< n; i++)
    printf("%d \t",a[i]);

        
        }
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
    default:
				condition = false;
      			break;
    }
    }
}