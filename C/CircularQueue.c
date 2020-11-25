#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

struct queue
{
    int front;
    int rear;
    int *array;
    int capacity;
    int size;
};

struct queue *init(int n)
{
    struct queue *q;
    q = (struct queue*)malloc(sizeof(struct queue));
    q->array = (int *)malloc(sizeof(int)*n);
    q->front = 0;
    q->rear = -1;
    q->capacity = n;
    q->size = 0;
    return &(*q);
}

void enqueue(struct queue **q,int x)
{
    if((*q)==NULL)
    {
        printf("queue empty, use init(**q,value) to create a queue of capacity = value\n");
        return;
    }
    int n = ((*q)->rear + 1) % ((*q)->capacity);
    if((*q)->size!=(*q)->capacity)
    {
        (*q)->array[n] = x;
        (*q)->rear = n;
        (*q)->size = (*q)->size + 1;
    }
    else
    {
        printf("queue full \n");
    }
}

void dequeue(struct queue **q)
{
    if((*q)!=NULL||(*q)->size!=0)
    {
        int temp = (*q)->array[(*q)->front];
        printf("%d removed from queue or dequed \n",temp);
        (*q)->front = ((*q)->front + 1)%((*q)->capacity);
        (*q)->size = (*q)->size - 1;
    }
    else
    {
        printf("queue is empty \n");
    }
    
}

void print(struct queue **q)
{
    int i  = (*q)->front;
    printf("Queue is as follows\n");
    while(i<(*q)->capacity)
    {
        printf("%d ",(*q)->array[i]);
        i = i + 1;
    }
    printf("\n");
}

int main()
{
    struct queue *q = NULL;
    int c,n,x;
    bool loop = true;
    printf("Enter Capacity of queue \n");
    scanf("%d",&c);
    q = init(c);
    while(loop)
    {
        printf("1)To enter value\n");
        printf("2)To Dequeue\n");
        printf("3)To exit\n");
        printf("enter choice\n");
        scanf("%d",&c);
        switch(c)
        {
            case 1:printf("enter elements\n");
                   for(int j=0;j<q->capacity;j++)
                   {
                       scanf("%d",&x);
                       enqueue(&q,x);
                   }
                   print(&q);
                   break;
            case 2:printf("enter number times to dequeue\n");
                   scanf("%d",&x);
                   for(int j=0;j<x;j++)
                   {
                       dequeue(&q);
                   }
                   print(&q);
                   break;
            default:loop=false;
        }
    }
    return 0;
}