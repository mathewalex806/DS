#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int stack[50];
int top =-1;

void push(char ch)
{
    top = top+1;
    stack[top] = ch-'0';
}
void push_int(int ch)
{
    top = top+1;
    stack[top] = ch;
}

int pop()
{
    if(top!=-1){
        int element = stack[top];
        top = top-1;
        return element;
    }
}

bool isOperator(char chc)
{
    if(chc =='+'|| chc =='-'||chc=='*'||chc=='/')
    return true;
    else
    return false;
}

void main()
{
    char ch[50];
    printf("Enter the postfix expression");
    scanf("%s",&ch);
    int len = strlen(ch);

    for(int i=0; i<len;i++)
    {
        if (isOperator(ch[i]) == false)
        push(ch[i]);

        else{
            int ch1 = pop();
            int ch2 =pop();
            int r;
            switch(ch[i]){
                case '+':
                    r = (ch1+ch2);
                    break;
                case '-':
                    r =(ch1-ch2);
                    break;
                case '*':
                    r =(ch1*ch2);
                    break;
                case '/':
                    r =(ch1/ch2);
                    break;
                default:
                    printf("Invalid operator");
                    break;
            }
            push_int(r);
        }
    }
        printf("%d",pop());
}