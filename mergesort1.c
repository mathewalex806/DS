#include <stdio.h>

void merge(int arr[], int l, int m, int h)
{
    int i=l, j = m+1, k=l;
    int temp[h];

    while (i<=m && j <=h)
    {
        if (arr[i]<=arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }
    if (i>m)
    {
        while (j<=h)
        {
            temp[k] = arr[j];
            j++;
            k++;
        }
        
    }
    else
    {
        while(i<=m)
        {
            temp[k] = arr[i];
            i++;
            k++;
        }
    }

    for (int k=l; k<=h; k++)
    {
        arr[k] = temp[k];
    }
    
}

void mergeSort(int arr[],int l, int h)
{
    if (l<h)
    {
        int mid = (l+h)/2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, h);
        merge(arr, l, mid,h);
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

    mergeSort(a,0,n);

    for(int i=0; i<n; i++)
    printf("%d  ",a[i]);
}