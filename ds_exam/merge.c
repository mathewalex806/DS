#include <stdio.h>

void merge(int a[],int l, int mid, int h)
{
    int i=l,j = mid+1, k=l, B[h];

    while (i<=mid && j<=h)
    {
        if (a[i]<= a[j])
        {
            B[k] = a[i];
            i++; 
        }
        else
        {
            B[k] = a[j];
            j++;
        }
        k++;
    }

    if (i>mid)
    {
        while (j<=h)
        {
            B[k] = a[j];
            j++;
            k++;
        }
    }
    else
    {
        while (i<=mid)
        {
            B[k] = a[i];
            i++;
            k++;
        }
        
    }
    for(k=l;k<=h;k++)
    {
        a[k] = B[k];
    }
    
}
void mergesort(int a[], int l, int h)
{
    if (l<h)
    {
        int mid = (l+h)/2;
        mergesort(a,l,mid);
        mergesort(a, mid+1,h);
        merge(a,l,mid,h);
    }
}
void main()
{
    int n;
    printf("Enter the size of the array");
    scanf("%d",&n);
    int a[n];
    printf("enter the value into the array");
    for(int i=0; i<n; i++)
    scanf("%d",&a[i]);

    mergesort(a,0,n);

    for(int i=0; i<n; i++)
    printf("%d  ",a[i]);

    
}