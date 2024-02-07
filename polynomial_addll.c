#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node{
    int degree;
    int coeff;
    struct node *next;
};

struct node *poly1 = NULL, *poly2 = NULL, *poly3 = NULL;

struct node* createNode(int coeff,int deg)
{
    struct node *newnode = malloc(sizeof(struct node));
    newnode->degree = deg;
    newnode->coeff = coeff;
    newnode->next = NULL;
    return newnode;
}

struct node* readPoly(struct node* poly,int coeff, int deg)
{
    struct node* newnode = createNode(coeff,deg);
    if (poly == NULL)
    poly = newnode;

    else{
        struct node* temp = poly;
        while (temp->next!= NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    return poly;
}

bool isEmpty(struct node*ptr)
{
    if (ptr == NULL)
    return true;
}

void addPoly()
{
    struct node *temp1 = poly1;
    struct node *temp2 = poly2;
    struct node *temp3 = poly3;

    while (temp1!= NULL && temp2!= NULL)
    {
        if(temp1->degree == temp2->degree)
        {
            poly3 = readPoly(poly3,(temp1->coeff+temp2->coeff),temp1->degree);
        }
    }
    
}


void display(struct node* poly)
{
    while(poly->next!= NULL)
    {
        printf("%dx^%d+ ",poly->coeff, poly->degree);
        poly = poly->next;
    }
    printf("%dx^%d ",poly->coeff, poly->degree);

}

void  main() {
    int choice, coeff, deg;
    while(1)
    {
        printf("\nSelect an option:\n");
        printf("1. Enter term for polynomial 1\n");
        printf("2. Enter term for polynomial 2\n");
        printf("3. Perform Addition\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter coefficient and degree for the term: ");
                scanf("%d%d", &coeff, &deg);
                poly1 = readPoly(poly1, coeff, deg);
                break;
            case 2:
                printf("Enter coefficient and degree for the term: ");
                scanf("%d%d", &coeff, &deg);
                poly2 = readPoly(poly2, coeff, deg);
                break;
            case 5:
                exit(0);
                break;
            case 3:
                addPoly();
                break;
            case 4:
                display(poly1);
                break;
                
            default:
                printf("Invalid choice!\n");
        }
    }
}


