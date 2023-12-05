#include <stdio.h>
#include <stdbool.h>
int top =-1;
int n;
void push(int a[])
{
    if (top == n-1)
    printf("Stack Overflow \n");

    else
    {
        top = top+1;
        printf("Enter the value into the stack \n");
        scanf("%d",&a[top]);

    }
}

void pop(int a[])
{
    if (top == -1)
    printf("Stack Underflow");
    else
    {
        printf("The value removed is %d",a[top]);
        top = top-1;
    }
}

void main()
{
    bool condition = true;
    printf("Enter the size of the array");
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