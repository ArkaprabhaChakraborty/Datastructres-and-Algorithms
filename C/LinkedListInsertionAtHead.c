#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//Declare struct
struct node
{
    int data;    //To hold Data
    struct node *next;  //Pointer to Next Node
};

void athead(struct node **head,int x) //shifts the head for every new node attached
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;
    if((*head)==NULL)
    {
        *head = newnode;
    }
    else
    {
        newnode->next = (*head);
        (*head) = newnode;
    }
}
void print(struct node **head)
{
    struct node *temp = (*head);
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
}

int main()
{
    struct node *head = NULL; //Set to null as append would assign the rest of the nodes... at the end
    int n = 5;
    for(int i=1;i<=n;i++)
    {
        athead(&head,i);
    }
    print(&head); //prints 1 to 5 in reverse
    return 0;
}