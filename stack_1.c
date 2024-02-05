#include <stdio.h>
#include <stdbool.h>

int n,  top=-1;
bool loop = false;

void push(int a[])
{
    if (top == n-1)
    {
        printf("Stack overflow");
    }
    else{
        top = top+1;
        printf("Enter the value into stack");
        scanf("%d",&a[top]);
    }
}

int pop(int a[])
{
    if (top ==-1){
        printf("Stack underflow");
        return -1;
    }
    
    else{
        int elem = a[top];
        top --;
        return elem;
    }
}


void main()
{
  printf("Enter the size of the stack .");
  scanf("%d",&n);
  int a[n]; 
  int choice;
  while (loop == false)
  {
    printf("\n Menu \n 1.Push \n 2.Pop \n 3.Peek \n 4.isFull \n 5.isEmpty \n 6. Exit \n Enter your choice (1-5) \t");
    scanf("%d",&choice);
    switch (choice)
    {
    case  (1):
				push(a);
				break;
    case (2):
				int item = pop(a);
                printf("%d",item);
				break;
    default:
				printf("Invalid choice");
      			break;
    }

  }


}