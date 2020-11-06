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

int main()
{
    struct node *head = NULL;
    append(&head,1);
    return 0; 
}