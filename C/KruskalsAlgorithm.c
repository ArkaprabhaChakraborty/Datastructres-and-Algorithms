#include <stdio.h>
#include <stdlib.h>


int find(int parent[100],int a)
{
    while(parent[a]!=a)
    {
        a = parent[a];
    }
    return a;
}


void union_find(int parent[100],int a, int b)
{
    int i,j;
    i = find(parent,a);
    j = find(parent,b);
    parent[i] = j;
}


void print_graph(int n,int graph[100][100])
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }
}


void create_graph(int n, int graph[100][100])
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            graph[i][j] = 0;
        }
    }
}


void KruskalMST(int graph[100][100],int n)
{
    int min_cost = 0;
    int edgecount = 0;
    int parent[n];
    int min,a,b;
    for(int i=0;i<n;i++)
    {
        parent[i] = i;
    }
    while(edgecount<n-1)
    {
        min = 100000;
        a = -1;
        b = -1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(find(parent,i) != find(parent,j) && graph[i][j]<min && graph[i][j]!=0)
                {
                    min = graph[i][j];
                    a = i;
                    b = j;
                }
            }
        }
        union_find(parent,a,b);
        printf("Edge %d:(%d, %d) cost: %d \n",edgecount, a, b, min);
        edgecount =edgecount+ 1;
        min_cost = min_cost + min;
    }
    printf("\nMinimum cost: %d \n",min_cost);
}

int main()
{
    int n, graph[100][100];
    int u,v,w;
    printf("enter number of vertices \n");
    scanf("%d",&n);
    printf("adjacency matrix \n");
    create_graph(n,graph);
    print_graph(n,graph);
    while(1)
    {
        printf("Enter two vertices and weight(non zero) to create a directed weighted edge (enter 10000 10000 10000to exit) \n");
        scanf("%d %d %d",&u,&v,&w);
        if(u==10000 && v == 10000)
        {
            break;
        }
        graph[u][v] = w;       
    }
    print_graph(n,graph);
    int s = 0;
    printf("MST(kruskal's Algorithm) for the graph is \n");
    KruskalMST(graph,n);
    return 0;
}