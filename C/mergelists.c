#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

struct node 
{
    int data;
    struct node *next;
};

void append(struct node **head,int x)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;
    if ((*head)==NULL)
    {
        (*head) = newnode;
    }
    else
    { 
        struct node *temp = (*head);
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}


int len(struct node **head)
{
    struct node *temp = (*head);
    int c = 0;
    while(temp!=NULL)
    {
        c = c + 1;
        temp = temp->next;
    }
    return c;
}


void merge(struct node **l,struct node **r)
{
    int n,m;
    n = len(&(*l));
    m = len(&(*r));
    int i = 0;
    struct node *newmerge = NULL;
    struct node *temp = (*l),*ltemp = (*l),*rtemp = (*r);
    if(n<m)
    {
        append(&(*l),99999999);
    }
    else
    {
        append(&(*r),99999999);
    }
    while (i<(n+m))
    {
        if (ltemp->data < rtemp->data)
        {
            int x = ltemp->data;
            append(&newmerge,x);
            ltemp = ltemp->next; 
        }
        else
        {
            int y = rtemp->data;
            append(&newmerge,y);
            rtemp = rtemp->next;
        }
        i = i+1;   
    }
    temp = temp->next;
    (*l) = newmerge;
    free(temp);
}

void print(struct node **head)
{
    struct node *temp = (*head);
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next; 
    }
    printf("\n");
}

int main()
{
    struct node *l = NULL;
    struct node *r = NULL;
    for(int i = 1;i <= 5;i++)//user input can be taken outcome will be same
    {
        append(&l,i);
    }
    printf("List 1: ");
    print(&l);
    for(int j = 10;j<=20;j++)
    {
        append(&r,j);
    }
    printf("List 2: ");
    print(&r);
    printf("Merged List:");
    merge(&l,&r);
    print(&l);
    return 0;
}