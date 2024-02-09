#include <stdio.h>

int partition(int arr[], int l, int h)
{
    if (l<h)
    {
        int pivot  = arr[h];
        int i = l-1;
        for (int j=l; j<h; j++)
        {
            if (arr[j]<pivot)
            {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i+1];
        arr[i+1] = arr[h];
        arr[h] = temp;
        return i+1;
        
   }
}
void quicksort(int arr[], int l, int h)
{
    if (l<h)
    {
        int p = partition( arr,l,h );
        quicksort(arr, l, p-1);
        quicksort(arr, p+1, h);
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

    quicksort(a,0,n);

    for(int i=0; i<n; i++)
    printf("%d  ",a[i]);
}