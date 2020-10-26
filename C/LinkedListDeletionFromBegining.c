#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

struct node
{
    int data;    //To hold Data
    struct node *next;  //Pointer to Next Node
};
/*Some data has to be present to show insertion at any position.... So..*/
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
void print(struct node **head) //Prints the Data
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
    struct node *head = NULL; //Set to null as append would assign the rest of the nodes... at the end
    int n = 5,x,pos;
    for(int i=1;i<=n;i++)
    {
        append(&head,i); //can be any... using scanf too..
    }
    print(&head);
    printf("Enter no of elements to Delete from... \n");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        deletebeg(&head);
        print(&head);
    }
    return 0;
}