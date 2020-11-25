#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

struct node
{
    struct node *next;
    struct node *prev;
    int data;
};

struct queue
{
    struct node *front;
    struct node *rear;
};

void push_end(struct queue **q,int x)
{
    if((*q)==NULL)
    {
        (*q) = (struct queue*)malloc(sizeof(struct queue));
        struct node *newnode = (struct node*)malloc(sizeof(struct node));
        (*q)->front = newnode;
        (*q)->rear = newnode;
        newnode->data = x;
        newnode->next = NULL;
        newnode->prev = NULL;
    }
    else
    {
        struct node *temp = (*q)->rear;
        struct node *newnode = (struct node*)malloc(sizeof(struct node));
        temp->next = newnode;
        newnode->next = NULL;
        newnode->data = x;
        newnode->prev = temp;
        (*q)->rear = newnode;
    }
}

void push_beg(struct queue **q,int x)
{
    if((*q)==NULL)
    {
        (*q) = (struct queue*)malloc(sizeof(struct queue));
        struct node *newnode = (struct node*)malloc(sizeof(struct node));
        (*q)->front = newnode;
        (*q)->rear = newnode;
        newnode->data = x;
        newnode->next=NULL;
        newnode->prev=NULL;
    }
    else
    {
        struct node *temp = (*q)->front;
        struct node *newnode = (struct node*)malloc(sizeof(struct node));
        newnode->next = temp;
        newnode->data = x;
        temp->prev = newnode;
        newnode->prev = NULL;
        (*q)->front = newnode;
    }    
}

void pop_end(struct queue **q)
{
    if((*q)!=NULL)
    {
        struct node *temp = (*q)->rear;
        printf("%d deleted \n",temp->data);
        (*q)->rear = temp->prev;
        temp->prev->next = NULL;
        free(temp);
    }
    else
    {
        printf("Empty Queue \n");
    }
    
}

void pop_beg(struct queue **q)
{
    if((*q)!=NULL)
    {
        struct node *temp = (*q)->front;
        printf("%d deleted \n",temp->data);
        (*q)->front = temp->next;
        temp->next->prev = NULL;
        free(temp);
    }
    else
    {
        printf("Empty queue \n");
    }
    
}

void print(struct queue **q)
{
    printf("Queue is: ");
    struct node *temp = (*q)->front;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int c,x,n;
    struct queue *q = NULL;
    bool loop = true;
    while(loop)
    {
        printf("1 to enter elements[push-front]\n2 to enter elements[push-rear]\n3 to pop[pop-front]\n4 to pop[pop-rear]\n enter your choice\n");
        scanf("%d",&c);
        switch(c)
        {
            case 1: printf("Enter number of elements\n");
                    scanf("%d",&n);
                    printf("enter elements\n");
                    for(int i =0;i<n;i++)
                    {
                        scanf("%d",&x);
                        push_beg(&q,x);
                    }
                    print(&q);
                    break;
            case 2: printf("Enter number of elements\n");
                    scanf("%d",&n);
                    printf("enter elements\n");
                    for(int i =0;i<n;i++)
                    {
                        scanf("%d",&x);
                        push_end(&q,x);
                    }
                    print(&q);
                    break;
            case 3: printf("Enter number of times to delete [pop-front]\n ");
                    scanf("%d",&n);
                    for(int i = 0;i<n;i++)
                    {
                        pop_beg(&q);
                    }
                    print(&q);
                    break;
            case 4: printf("Enter number of times to delete [pop-rear]\n ");
                    scanf("%d",&n);
                    for(int i = 0;i<n;i++)
                    {
                        pop_end(&q);
                    }
                    print(&q);
                    break;
            default: loop = false;
        }
    }
    return 0;
}