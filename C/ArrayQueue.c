#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

struct queue
{
    int front,size,rear;
    int *array;   
};
void create(struct queue **q,int c)
{
    if((*q)==NULL)
    {
        (*q) = (struct queue*)malloc(sizeof(struct queue));
        (*q)->array = (int *)malloc(sizeof(int)*c);
        (*q)->front = 0;
        (*q)->rear = 0;
    }
}
int isfull(struct queue **q)
{
    return ((*q)->rear == (*q)->size);
}
int isempty(struct queue **q)
{
    return ((*q)->front == (*q)->size);
}
void insert(struct queue **q,int x)
{
    if(!isfull(&(*q)))
    {
    (*q)->array[((*q)->rear)++] = x;
    }
}
void delete(struct queue **q)
{
    if(!isempty(&(*q)))
    {
    int x;
    x = (*q)->array[((*q)->front++)];
    printf("%d deleted\n",x);
    }
}
void print(struct queue **q)
{
    int x = (*q)->front;
    while(x<(*q)->rear)
    {
        printf("%d ",(*q)->array[x]);
        x++;
    }
    printf("\n");
}
int main()
{
    struct queue *q = NULL;
    int c,n,x;
    bool loop = true;
    while(loop)
    {
        printf("\nQueue Operations\n1)To insert elements(enqueue)\n2)To remove elements(dequeue)\nAny other to exit\n \nEnter your choice: ");
        scanf("%d",&c);
        switch(c)
        {
            case 1:printf("Enter No of elements to enter in queue \n");
                  scanf("%d",&n);
                  create(&q,n-1);
                  printf("enter elements \n");
                  for(int i=1;i<=n;i++)
                  {
                    scanf("%d",&x);
                    insert(&q,x);
                  }
                  printf("Queue Formed\n");
                  print(&q);
            break;
            case 2:printf("Enter No of elements to dequeue from queue \n");
                  scanf("%d",&n);
                  for(int i=1;i<=n;i++)
                  {
                        delete(&q);
                  }
                  printf("New Queue\n");
                  print(&q);
            break;
            default:loop=false;
            break;
        }
    }
    return 0;
}