#include <stdio.h>
#include <stdlib.h>


void main()
{
    int row, col,count,k=0;
    printf("Enter the number of rows and columns in the matrix");
    scanf("%d",&row);
    scanf("%d",&col);

    int a[row][col];
    for (int i=0; i<row; i++)
    {
        for (int j=0; j<col; j++)
        {
            printf("Enter the value for (%d,%d)",i,j);
            scanf("%d",&a[i][j]);
            if (a[i][j]!= 0)
            count = count+1;
        }
    }

    int sparse_mat[count][3];
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            if (a[i][j]!=0)
            {
                sparse_mat[k][0] = i;
                sparse_mat[k][1] = j;
                sparse_mat[k][2] = a[i][j];
                k++;
            }
        }
    }

    printf("The sparse matrix represenstation of the matrix is :\n Row : Column : Value\n");


    for (int i=0; i<k; i++)
    {
        for (int j=0; j<3; j++)
        {
            printf("%d ",sparse_mat[i][j]);
        }
        printf("\n");
    }
    
}