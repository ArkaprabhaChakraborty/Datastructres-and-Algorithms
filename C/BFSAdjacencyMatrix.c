#include <stdio.h>
#include <stdlib.h>

struct node   //LinkedList node-struct
{
    int data;
    struct node *next;
}; 
struct queue //queue-struct... required for fifo movement
{
    struct node *front;
    struct node *rear;
};
//Basically this queue struct has two node pointers.
/* 1)front: pointing to the first node of the Linked list
   2)rear: pointing to the last node of the Linked list */ 
struct queue *createqueue() //utility function allocating memory for the front and rear structure pointer
{
    struct queue *q = (struct queue*)malloc(sizeof(struct queue));
    q->front = q->rear = NULL;
    return q;
}
void enqueue(struct queue **q,int k) // k will be inserted to the queue using a linkedlist node
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = k;
    newnode->next = NULL;
    if((*q)->rear == NULL || (*q)->front == NULL)
    {
        (*q)->front = (*q)->rear = newnode;
        return;
    }
    else
    {
        (*q)->rear->next = newnode;
        (*q)->rear = newnode;
    }
}
void print(struct queue **q)
{
    struct node *temp = (*q)->front;
    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int len(struct queue **q)
{
    int c = 0;
    struct node *temp = (*q)->front;
    while(temp != NULL)
    {
        c = c + 1;
        temp = temp->next;
    }
    return c;
}
int dequeue(struct queue **q)
{
    int x;
    if((*q)->front == NULL)
    {
        (*q)->rear = NULL;
        return -1;
    }
    struct node *temp = (*q)->front;
    x = temp->data;
    (*q)->front = (*q)->front->next;
    free(temp);
    return x;
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


void enter_edge(int graph[100][100],int a,int b)
{
    graph[a][b] = 1;
    graph[b][a] = 1;
}



void BFS(int n,int u, int graph[100][100])
{
   struct queue *q = createqueue();
   int visited[100];
   for(int i=0;i<n;i++)
   {
       visited[i] = 0;
   }
   enqueue(&q,u);
   visited[u] = 1;
   int s = 0;
   while(len(&q))
   {
       s = dequeue(&q);
       if(s==-1)
       {
           break;
       }
       for(int j=0;j<n;j++)
       {
           if(graph[s][j] == 1 && visited[j] == 0)
           {
               int x = graph[s][j];
               enqueue(&q,j);
               visited[j] = 1;
           }
       }
       printf("%d  ",s);
   }
   printf("\n");
}



int main()
{
    int n, graph[100][100];
    int u,v;
    printf("enter number of vertices \n");
    scanf("%d",&n);
    printf("adjacency matrix \n");
    create_graph(n,graph);
    print_graph(n,graph);
    while(1)
    {
        printf("Enter edge between two vertices enter 10000 10000 to exit \n");
        scanf("%d %d",&u,&v);
        if(u==10000 && v == 10000)
        {
            break;
        }
        enter_edge(graph,u,v);       
    }
    print_graph(n,graph);
    int s = 0;
    printf("Enter source vertex to start BFS: ");
    scanf("%d",&s);
    printf("BFS for the graph is \n");
    BFS(n,s,graph);
    return 0;
}