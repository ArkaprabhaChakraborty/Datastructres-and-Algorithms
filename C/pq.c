#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

struct node
{
    int data;
    int p;
    struct node *next;
};

struct queue 
{
    struct node *head;
    struct node *rear;
};
struct queue *createqueue() //utility function allocating memory for the front and rear structure pointer
{
    struct queue *q = (struct queue*)malloc(sizeof(struct queue));
    q->head = q->rear = NULL;
    return q;
}
void insert(struct queue **q,int x,int pr)
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->p = pr;
    newnode->next = NULL;
    if(((*q)->rear)==NULL)
    {
        (*q)->head = newnode;
        (*q)->rear = newnode;
        return ;
    }
    else
    {
        struct node *temp = ((*q)->head);
        while((temp->p < pr) && (temp->next !=NULL))
        {
            temp = temp->next;
        }
        newnode->next = temp->next->next;
        temp->next = newnode;
    }
}

void print(struct queue **q)
{
    struct node *temp = ((*q)->head);
    while(temp!=NULL)
    {
        printf("Data : %D\n",temp->data);
        printf("Priority : %D\n",temp->p);
        temp = temp->next;
    }
}

int main()
{
    int i;
    struct queue *q = createqueue();
    for(i=0;i<5;i++)
    {
        insert(&q,i,i);
    }
    print(&q);
    return 0;
}