#include <stdio.h>
#include <stdlib.h>

struct node {
    int coeff;
    int degree;
    struct node *next;
};

struct node *createNode(int coeff, int degree) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->coeff = coeff;
    newNode->degree = degree;
    newNode->next = NULL;
    return newNode;
}

struct node *insertNode(struct node *head, int coeff, int degree) {
    struct node *newNode = createNode(coeff, degree);
    if(head == NULL) {
        return newNode;
    }
    struct node *temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

struct node *addPolynomials(struct node *poly1, struct node *poly2) {
    struct node *poly3 = NULL;
    while(poly1 != NULL && poly2 != NULL) {
        if(poly1->degree > poly2->degree) {
            poly3 = insertNode(poly3, poly1->coeff, poly1->degree);
            poly1 = poly1->next;
        } else if(poly1->degree < poly2->degree) {
            poly3 = insertNode(poly3, poly2->coeff, poly2->degree);
            poly2 = poly2->next;
        } else {
            poly3 = insertNode(poly3, poly1->coeff + poly2->coeff, poly1->degree);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }
    while(poly1 != NULL) {
        poly3 = insertNode(poly3, poly1->coeff, poly1->degree);
        poly1 = poly1->next;
    }
    while(poly2 != NULL) {
        poly3 = insertNode(poly3, poly2->coeff, poly2->degree);
        poly2 = poly2->next;
    }
    return poly3;
}

void printPolynomial(struct node *head) {
    while(head != NULL) {
        printf("%dx^%d", head->coeff, head->degree);
        if(head->next != NULL) {
            printf(" + ");
        }
        head = head->next;
    }
    printf("\n");
}

int main() {
    int n, coeff, degree;
    struct node *poly1 = NULL, *poly2 = NULL, *poly3;

    printf("Enter the number of terms in the first polynomial: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        printf("Enter coefficient and degree for term %d: ", i+1);
        scanf("%d%d", &coeff, &degree);
        poly1 = insertNode(poly1, coeff, degree);
    }

    printf("Enter the number of terms in the second polynomial: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        printf("Enter coefficient and degree for term %d: ", i+1);
        scanf("%d%d", &coeff, &degree);
        poly2 = insertNode(poly2, coeff, degree);
    }

    poly3 = addPolynomials(poly1, poly2);

    printf("The sum of the polynomials is: ");
    printPolynomial(poly3);

    return 0;
}