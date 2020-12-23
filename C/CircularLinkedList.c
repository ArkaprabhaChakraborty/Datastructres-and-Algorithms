#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>

struct node
{
    int data;
    struct node *next;
};

void append(struct node **head,int x)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    if((*head)==NULL)
    {
        (*head) = newnode;
        (*head)->next = (*head);
    }
    else
    {
        struct node *temp = (*head);
        while(temp->next!=(*head))
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = (*head);
    }
}

void print(struct node **head)
{
    struct node *temp = *head;
    while(temp->next!=(*head))
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("%d",temp->data);
}

void insert(struct node **head,int pos,int x)
{
    struct node *temp = *head;
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    if((*head)==NULL)
    {
        if(pos == 0)
        {
            append(&(*head),x);
        }
        else
        {
            printf("wrong position value \n");
        }
    }
    else
    {
        for(int i=0;i<pos;i++)
        {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
}
void delend(struct node **head)
{
    struct node *temp = *head, *x;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    x = temp->next;
    temp->next = temp->next->next;
    free(x);
}

void delete(struct node **head, int pos)
{

}
int main()
{
    struct node *head = NULL;
    for(int i = 0;i<10;i++)
    {
        append(&head,i);
    }
    insert(&head,9,15);
    print(&head);
    return 0; 
}