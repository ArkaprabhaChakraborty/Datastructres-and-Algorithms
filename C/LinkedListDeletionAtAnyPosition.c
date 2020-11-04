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
int len(struct node **head)
{
    int count = 0;
    struct node *temp = (*head);
    while(temp!=NULL)
    {
        count = count + 1;
        temp = temp->next;
    }
    return count;
}
void deletebeg(struct node **head)
{
    struct node *temp;
    if((*head)==NULL)
    {
        return;
    }
    if((*head)->next==NULL)
    {
        free(*head);
        return;
    }
    temp = *head;
    (*head) = (*head)->next;
    free(temp);
}
void deleteatpos(struct node **head,int pos)
{
    struct node *nod,*temp = (*head);
    int i;
    if((*head)==NULL)
    {
        return ;
    }
    if(pos==0)
    {
        deletebeg(&(*head));
    }
    else if(pos<len(&(*head)))
    {
        for(i=2;i<=pos;i++)
        {
            temp=temp->next;
        }
        nod = temp->next->next;
        free(temp->next);
        temp->next = nod;
    }
}
int main()
{
    struct node *head = NULL; //Set to null as append would assign the rest of the nodes... at the end
    int n = 5,pos;
    for(int i=1;i<=n;i++)
    {
        append(&head,i);
    }
    print(&head); 
    n = 2;
    for(int i=1;i<=n;i++)
    {
        printf("\nEnter a position \n");
        scanf("%d",&pos);
        deleteatpos(&head,pos);
        print(&head);
    }
    return 0;
}
