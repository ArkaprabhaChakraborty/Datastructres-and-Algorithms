//creation of Linked list by simple insertion at the end or append method
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//Declare struct
struct node
{
    int data;    //To hold Data
    struct node *next;  //Pointer to Next Node
};

void append(struct node **head,int x) //appends to headnode.....
{
    struct node *newnode,*temp;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;
    temp = (*head);
    if((*head)==NULL)
    {
        *head = newnode;
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;   
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
        append(&head,i);
    }
    print(&head);
    return 0;
}
