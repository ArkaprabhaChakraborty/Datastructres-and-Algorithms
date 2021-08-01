#include <stdio.h>

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

void enter_edge(int graph[100][100],int a,int b)
{
    graph[a][b] = 1;
    graph[b][a] = 1;
}

void enter_directed_edge(int graph[100][100],int a,int b)
{
    graph[a][b] = 1;
}

void enter_weighted_undirected_edge(int graph[100][100],int a,int b,int w)
{
    graph[a][b] = w;
    graph[b][a] = w;
}

void enter_directed_weighted_edge(int graph[100][100],int a,int b,int w)
{
    graph[a][b] = w;
}

int minweight(int key[100],int mst[100],int n)
{
    int min  = 100000000;
    int minindex = -1;
    for(int i =0;i<n;i++)
    {
        if(key[i]< min && mst[i] == 0)
        {
            min = key[i];
            minindex = i;
        }
    }
    return minindex;
}

void PrimsMST(int graph[100][100],int n)
{
   int mst[100],keys[100],parent[110];
   for(int t = 0;t<n;t++)
   {
       keys[t] = 100000000;
   }
   int u;
   parent[0] = -1;
   for(int k=0;k<n;k++)
   {
       u = minweight(keys,mst,n);
       mst[u] = 1;
       for(int v = 0;v<n;v++)
       {
           if(graph[u][v]>0 && mst[v]==0 && keys[v]>graph[u][v])
           {
               keys[v] = graph[u][v];
               parent[v] = u;
           }
       }
   }
   for(int i = 0;i<n;i++)
   {
       printf("%d --> %d -- %d \n",parent[i],i,graph[i][parent[i]]);
   }
   printf("\n"); 
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
        enter_weighted_undirected_edge(graph,u,v,w);       
    }
    print_graph(n,graph);
    printf("MST(Prim's Algorithm) for the graph is \n");
    PrimsMST(graph,n);
    return 0;
}