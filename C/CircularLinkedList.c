#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node * next;
};

void create(struct node **head,int n)
{
    int x;
    struct node *newnode, *temp;
    temp = *head;
    for(int i=2;i<=n;i++)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        scanf("%d",&x);
        newnode->val = x;
        newnode->next = newnode;
        temp->next = newnode;
        temp = temp->next;
    }
    temp->next = *head;
}

void print(struct node **head)
{
    struct node *temp;
    temp = *head;
    while(temp->next!= *head)
    {
        printf("%d ",temp->val);
        temp = temp->next;
    }
    printf("%d ",temp->val);
    printf("\n");
}

int len(struct node **head)
{
    int c =0;
    struct node *temp = *head;
    while(temp->next!= *head)
    {
        c++;
    }
    return c;
}

void insertbeg(struct node **head, int n)
{
    struct node *newnode, *curNode;
    if(*head == NULL)
    {
        printf(" No data found in the List yet.");
    }
    else
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->val = n;
        newnode->next = *head;
        curNode = *head;
        while(curNode->next != *head)
        {
            curNode = curNode->next;
        }
        curNode->next = newnode;
        *head = newnode;
    }
}

void insertany(struct node **head, int n)
{
    int e;
    struct node *current, *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter element \n");
    scanf("%d",&e);
    newnode->val = e;
    newnode->next = NULL;
    current = *head;
    int j=0;
    if(n==0)
    {
        insertbeg(&(*head),e);
    }
    else
    {
        while (j<n-1) 
        {
        current = current->next;
        j++;
        }
        newnode->next =  current->next;
        current->next = newnode;
    }
}
    

void delete(struct node **head, int n)
{

    struct node *temp, *del;
    temp = *head;
    del = NULL;
    if(n==0)
    {
        temp = temp->next;
        del = *head;
        *head = temp;
        while(temp->next!=del)
        {
            temp = temp->next;
        }
        temp->next = *head;
        free(del);
    }
    else
    {
        n = n-1;
        while(n)
        {
            temp = temp->next;
            n--;
        }
        del = temp->next;
        temp->next = del->next;
        free(del);
    }
}

int main()
{
    //all types of insertion can be performed using the same insert function
    //same goes with deletion.
    int i,n,x,c;
    struct node *head, *newnode, *temp;
    
    printf("Enter No of elements \n");
    scanf("%d",&n);
    printf("Enter Elements \n");
    head = (struct node*)malloc(sizeof(struct node));
    scanf("%d",&x);
    head->val = x;
    head->next = NULL;
    temp = head;
    create(&head,n);
    printf("Created Successfully \n");
    printf("Output List: ");
    print(&head);
    printf("No of elements for insert\n");
    scanf("%d",&n);
    while(n)
    {
        printf("enter position \n"); 
        scanf("%d",&x);
        insertany(&head,x);
        n--;
        printf("Output List: ");
        print(&head);
    }
    printf("Enter no of elements to Delete \n");
    scanf("%d",&n);
    while(n)
    {
        printf("Enter position \n");
        scanf("%d",&x);
        delete(&head,x);
        n--;
        printf("Output list :");
        print(&head);
    }
    return 0;
}