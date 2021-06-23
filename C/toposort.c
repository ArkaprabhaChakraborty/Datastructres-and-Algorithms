

#include <stdio.h>
#include<stdbool.h>

int stack[100];
int sp = 0;



void create(int arr[100][100],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            arr[i][j] = 0;
        }
    }
}

void insert_edge(int arr[100][100],int n,int a,int b)
{
    arr[a][b] = 1;
}


void discard_self_loops(int arr[100][100],int n)
{
    for(int i=0;i<n;i++)
    {
        arr[i][i] = 0;
    }
}


void toposortutil(int arr[100][100], int n, bool visited[n],int start)
{
    visited[start] = true;
    for(int i=0;i<n;i++)
    {
        if(arr[start][i]==1 && visited[i]==false)
        {
            toposortutil(arr,n,visited,i);
        }
    }
    stack[sp] = start;
    sp = sp+1;
}

void toposort(int arr[100][100], int n, bool visited[n])
{
    for(int i=0;i<n;i++)
    { 
        if (visited[i] == false)
        {
            toposortutil(arr,n,visited,i);
        }
    }
}

int main()
{
    int arr[100][100], n, a,b,x;
    bool visited[100];
    for(int i=0;i<100;i++)
    {
        visited[i] = false;
    }
    printf("Enter Number of vertices \n");
    scanf("%d",&n);
    create(arr,n);
    while(true)
    {
        printf("Enter source and destination vertices to add an edge (-1 in any to exit)\n");
        scanf("%d",&a);
        scanf("%d",&b);
        if(a!=-1 || b!=-1)
        {
            insert_edge(arr,n,a,b);
        }
        else
        {
            break;
        }
    }
    
    discard_self_loops(arr,n);
    printf("Topological Sort: ");
    toposort(arr,n,visited);
    for(int i = n-1 ;i>=0;i--)
    {
        printf("%d  ",stack[i]);
    }
    return 0;
}
