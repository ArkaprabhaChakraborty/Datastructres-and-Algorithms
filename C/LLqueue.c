#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

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
    if((*q)->rear == NULL)
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
    struct queue *temp = *q;
    while(temp != NULL)
    {
        printf("%d ",temp->front->data);
        temp->front = temp->front->next;
    }
}
int main()
{
    struct queue *q = createqueue();
    for(int i=1;i<=5;i++)
    {
        enqueue(&q,i);
    }
    print(&q);
    return 0;
}

