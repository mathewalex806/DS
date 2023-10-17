#include <stdio.h>
#include <stdbool.h>
void main()
{
    int n;
    printf("Enter number of items in the stack");
    scanf("%d",&n);
    int a[n];
    int top = -1;
    bool an = false;
    int choice;
    int len = n;
    while (an == false)
    {

        printf("\n Menu \n 1.Push \n 2.Pop \n 3.Peek  \n 4.isEmpty() \n 5.isFull() \n Enter your choice (1-5): \t");
        scanf("%d",&choice);
        switch(choice)
        {
            case (1):
                if (top == len-1)
                {
                printf("Stack Overflow");
                break;
                }
                else{
                    top ++;
                    printf("Enter element in the stack");
                    scanf("%d",&a[top]);
                    break;
                }
            case (2):

                if (top == -1)
                {
                    printf("Stack Underflow ");
                    break;
                }
                else{
                    printf("Element popped is %d",a[top]);
                    top --;
                    break;
                }
            case (3):
                if(top == -1)
                {
                    printf("Stack Underflow");
                    break;
                }
                else{
                    printf("The element at the top of the stack is  %d",a[top]);
                    break;
                }
            case(4):

                if(top == -1)
                {
                    printf("Stack is empty");
                    break;
                }
                else
                {
                    printf("Stack is not empty");
                    break;
                }

            case (5):
                if(top == len-1)
                {
                    printf("Stack is full");
                    break;
                }
                else
                {
                    printf("Stack is not full");
                    break;
                }
            default:
                char ch;
                printf("Do you wish to exit? [y/n]");
                scanf("%c",ch);
                if(ch == 'y')
                {
                    an = true;
                    break;
                }
        }
    }
    

}