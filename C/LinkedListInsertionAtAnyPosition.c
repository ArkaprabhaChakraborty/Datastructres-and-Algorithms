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

int len(struct node **head)//returns the length of the list
{
    struct node *temp = (*head);
    int c = 0;
    while(temp!=NULL)
    {
        c++;
        temp = temp->next;
    }
    return c;
}

/*Here we will use array convention for position index.. that is index=0 for head and n-1 for nth element*/
void insertatpos(struct node **head,int x,int pos)
{
    struct node *newnode,*temp;
    int l = len(&(*head));
    temp = (*head);
    int i;
    if((*head)==NULL)
    {
        append(&(*head),x);
    }
    else if(pos<=l)
    {
        for(i=1;i<pos;i++)
        {
            temp=temp->next;
        }
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = x;
        newnode->next = temp->next;
        temp->next = newnode;
    }
    else
    {
        printf("Index out of bounds \n");
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
