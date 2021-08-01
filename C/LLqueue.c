#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
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
void dequeue(struct queue **q)
{
    if((*q)->front == NULL)
    {
        (*q)->rear = NULL;
        return;
    }
    struct node *temp = (*q)->front;
    printf("%d deleted \n",temp->data);
    (*q)->front = (*q)->front->next;
    free(temp);
}
int main()
{
    struct queue *q = createqueue();
    bool loop = true;
    while(loop)
    {
        printf("\nQueue Operations\n1)To insert elements\n2)To remove elements\nAny other to exit\n \nEnter your choice: ");
        int c,n,x;
        scanf("%d",&c);
        switch(c)
        {
            case 1:printf("Enter No of elements \n");
                  scanf("%d",&n);
                  printf("enter elements \n");
                  for(int i=1;i<=n;i++)
                  {
                    scanf("%d",&x);
                    enqueue(&q,x);
                  }
                  printf("Queue Formed\n");
                  print(&q);
            break;
            case 2:printf("Enter No of elements \n");
                  scanf("%d",&n);
                  if(n<=len(&q))
                  {
                      for(int i=1;i<=n;i++)
                      {
                          dequeue(&q);
                      }
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

