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

void insert(struct node **head,int x,int pr)
{
    struct node *newnode , *temp;
    temp = (*head);
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->p = pr;
    newnode->next = NULL;
    if((*head)==NULL)
    {
        (*head) = newnode; 
    }
    else if(((*head)->p)>pr)
    {
        newnode->next = (*head);
        (*head) = newnode;
    }
    else
    {
        while((temp->next != NULL) && (temp->next->p < pr))
        {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

void print(struct node **head)
{
    struct node *temp = (*head);
    while(temp!=NULL)
    {
        printf("Data : %d\n",temp->data);
        printf("Priority : %d\n",temp->p);
        temp = temp->next;
    }
}

void pop(struct node **head)
{
    struct node *temp;
    temp = (*head);
    printf("%d popped having priority %d\n",temp->data,temp->p);
    (*head) = (*head)->next;
    free(temp);
} 

int main()
{
    int i;
    struct node *head = NULL;
    for(i=0;i<5;i++)
    {
        insert(&head,i,i);
    }
    print(&head);
    for(i=0;i<5;i++)
    {
        pop(&head);
    }
    return 0;
}