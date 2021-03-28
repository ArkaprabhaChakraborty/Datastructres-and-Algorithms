#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <math.h>

int main()
{
    int arr[100][100],trans[100][100];
    int i,j,m,n,x,size = 0;
    printf("Enter number of Rows: ");
    scanf("%d",&m);
    printf("Enter number of Columns: ");
    scanf("%d",&n);
    printf("Enter Matrix \n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("A[%d][%d] : ",i,j);
            scanf("%d",&x);
            arr[i][j] = x;
            if(x!=0)
            {
                size++;
            }
        }
        printf("\n");
    }
    int res[size][3];
    x = 0;
    for(i = 0;i<m;i++)
    {
        for(j = 0;j<n;j++)
        {
            if(arr[i][j]!=0)
            {
                res[x][0] = i;
                res[x][1] = j;
                res[x][2] = arr[i][j];
                x++;
            }
        }
    }
    printf("Three Tuple format \n");
    printf("Row Column value \n");
    for(i=0;i<size;i++)
    {
        for(j = 0;j<3;j++)
        {
            printf(" %d    ",res[i][j]);
        }
        printf("\n");
    }

    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            trans[j][i] = arr[i][j];
        }
    }
    x = 0;
    for(i = 0;i<m;i++)
    {
        for(j = 0;j<n;j++)
        {
            if(trans[i][j]!=0)
            {
                res[x][0] = i;
                res[x][1] = j;
                res[x][2] = trans[i][j];
                x++;
            }
        }
    }
    printf("Three Tuple format for transpose\n");
    printf("Row Column value \n");
    for(i=0;i<size;i++)
    {
        for(j = 0;j<3;j++)
        {
            printf(" %d    ",res[i][j]);
        }
        printf("\n");
    }
    return 0;
}