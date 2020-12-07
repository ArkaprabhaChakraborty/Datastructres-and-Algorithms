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

void reverse(struct node **head)
{
    struct node *prev,*curr,*next;
    curr = (*head);
    while(curr!=NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    (*head) = prev;
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
    struct node *head = NULL;
    for(int i=0;i<10;i++)
    {
        append(&head,i);
    }
    printf("Before Reversal: ");
    print(&head);
    reverse(&head);
    printf("After Reversal: ");
    print(&head);
    return 0;
}