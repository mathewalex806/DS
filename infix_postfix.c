#include <stdio.h>
#include <stdbool.h>
#include <string.h>

char postfix[50];
int count =0;

char stack[50];
int top =-1;

bool isOperator(char ch)
{
    if(ch == '+'|| ch == '-'|| ch == '*'|| ch == '/'|| ch == ')'|| ch == '(')
    return true;
    else
    return false;
}

void add_postfix(char ch)
{
    postfix[count] =ch;
    count++;

    printf("%s",postfix);
}

void add_stack(char ch)
{
    top =top+1;
    stack[top] = ch;
}

char pop()
{
    char ch  = stack[top];
    top = top-1;
    return ch;
}

int priority(char ch)
{
    switch ( ch)
    {
    case '+':
        return 1;
        break;
    case '-':
        return 1;
        break;
    case '*':
        return 2;
        break;
    case '/':
        return 2;
        break;
    case ')':
        return 0;
        break;
    case '(':
        return 0;
        break;
    default:
        break;
    }
}


void main()
{
    char infix[50];
    printf("Enter the infix expression");
    scanf("%s",&infix);
    int len = strlen(infix);
    for (int i=0; i<len; i++)
    {
        if (!isOperator)
        {
            add_postfix(infix[i]);
        }

        else if (infix[i] == ')')
        {
            while(stack[top]!= '(')
            {
                add_postfix(pop());
            }
            add_postfix(pop());
        }
        else
        {
            if(priority(infix[i])>priority(stack[top]))
            add_postfix(infix[i]);

            else{
                while (priority(infix[i])<=priority(stack[top]))
                {
                    char x = pop();
                    add_postfix(x);
                }
                add_stack(infix[i]);
                
            }
        }
    }
    while (top!=-1)
    {
        add_postfix(pop());
    }

    printf("%s",postfix);
    
}
 