#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void entermatrix(float mat[100][100],int m,int n)
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            float x;
            scanf("%f",&x);
            mat[i][j] = x;
        }
    }
}

void printmatrix(float mat[100][100],int m,int n)
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%f ",mat[i][j]);
        }
        printf("\n");
    }
}

void swaprows(float mat[100][100],int r1,int r2,int m)
{
    if(r1!=r2)
    {
        for(int i=0;i<m;i++)
        {
            float temp = mat[r1][i];
            mat[r1][i] = mat[r2][i];
            mat[r2][i] = temp;
        }
    }
}

void rowreducedechelon(float mat[100][100],int m,int n)
{
    int lead = 0;
    int rowcount = m;
    int columncount = n;
    for(int r = 0;r<columncount;r++)
    {
        if(lead>=columncount)
        {
            return;
        }
        int i = r;
        while(mat[i][lead]==0)
        {
            i = i + 1;
            if(i == rowcount)
            {
                i = r;
                lead = lead +1;
                if(columncount == lead)
                {
                    return;
                }
            }
        }
        swaprows(mat,i,r,columncount);
        float lv = mat[r][lead];
        for(int x=0;x<columncount;x++)
        {
            mat[r][x] = mat[r][x]/lv;
        }
        for(int x=0;x<rowcount;x++)
        {
            if(x!=r)
            {
                lv = mat[x][lead];
                for(int y =0;y<columncount;y++)
                {
                    mat[x][y] = mat[x][y] - (lv *mat[r][y]);
                }
            }
        }
        lead = lead + 1;
    }
}


int main()
{
    float mat[100][100];
    int m,n;
    printf("enter number of rows: ");
    scanf("%d",&m);
    printf("enter no of columns: ");
    scanf("%d",&n);
    printf("enter data in matrix: \n");
    entermatrix(mat,m,n);
    printmatrix(mat,m,n);
    rowreducedechelon(mat,m,n);
    printmatrix(mat,m,n);
    return 0;
}