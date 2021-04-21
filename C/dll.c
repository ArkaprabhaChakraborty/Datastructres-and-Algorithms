#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node { 
    int data; 
    struct node *next; // Pointer to next node 
    struct node *prev; // Pointer to previous node 
};

void insertatfront(struct node **head, int x) 
{ 
    struct node *newnode = (struct node*)malloc(sizeof(struct node)); 
    newnode->data = x; 
    newnode->next = (*head); 
    newnode->prev = NULL; 
    if (*head != NULL)
    {
        (*head)->prev = newnode;
    }
    *head = newnode; 
}

void append(struct node **head, int x)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;
    struct node *temp;
    temp = *head;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;
}

void printforward(struct node **head)  
{  
    struct node *temp;
    temp = *head;
    printf("\nTraversal in forward direction \n");  
    while (temp != NULL) 
    {  
        printf(" %d ", temp->data);
        temp = temp->next;  
    }
    printf("\n");
}
void printbackward(struct node **head)
{
    struct node *last,*node;
    node = *head; 
    printf("\nTraversal in reverse direction \n");
    while (node != NULL) 
    {
        last = node;  
        node = node->next;  
    }
    while (last != NULL) 
    {  
        printf(" %d ", last->data);  
        last = last->prev;  
    }
    printf("\n");
}  

void insertatend(struct node ** head,int data)
{
    struct node * newNode,*last;
    last = *head;
    while(last->next!=NULL)
    {
        last = last->next;
    }
    if(last == NULL)
    {
        printf("Error, List is empty!\n");
    }
    else
    {
        newNode = (struct node *)malloc(sizeof(struct node));

        newNode->data = data;
        newNode->next = NULL;
        newNode->prev = last;

        last->next = newNode;
        last = newNode;
    }
}

void insertatany(struct node **head, int data, int position)
{
    int i;
    struct node * newNode, *temp,*last;
    last = *head;
    while(last->next!=NULL)
    {
        last = last->next;
    }
    if(*head == NULL)
    {
        printf("Error, List is empty!\n");
    }
    else
    {
        temp = *head;
        i=1;

        while(i<position && temp!=NULL)
        {
            temp = temp->next;
            i++;
        }

        if(position == 0)
        {
            insertatfront(&(*head),data);
        }
        else if(temp == last)
        {
            insertatend(&(*head),data);
        }
        else if(temp!=NULL)
        {
            newNode = (struct node *)malloc(sizeof(struct node));

            newNode->data = data;
            newNode->next = temp->next; // Connect new node with n+1th node
            newNode->prev = temp;      // Connect new node with n-1th node

            if(temp->next != NULL)
            {
                /* Connect n+1th node with new node */
                temp->next->prev = newNode;
            }
            /* Connect n-1th node with new node */
            temp->next = newNode;
        }
        else
        {
            printf("Error, Invalid position\n");
        }
    }
}

void deletefrombeginning(struct node **head)
{
    struct node * toDelete;

    if(*head == NULL)
    {
        printf("Unable to delete. List is empty.\n");
    }
    else
    {
        toDelete = *head;
        *head = (*head)->next; // Move head pointer to node
        if (*head != NULL)
            (*head)->prev = NULL; // Remove the link to previous node

        free(toDelete); // Delete the first node from memory
        printf("Successful deletion from begining.\n");
    }
}

void deletefromend(struct node **head)
{
    struct node *toDelete,*last;
    last = *head;
    while(last->next!=NULL)
    {
        last = last->next;
    }

    if(last == NULL)
    {
        printf("Unable to delete. List is empty.\n");
    }
    else
    {
        toDelete = last;
        last = last->prev; // Move last pointer to 2nd last node
        
        if (last != NULL)
            last->next = NULL; // Remove link to of 2nd last node with last node

        free(toDelete);       // Delete the last node
        printf("Successful deletion from end.\n");
    }
}

void deletefromany(struct node **head,int position)
{
    struct node *current,*last;
    int i;
    last = *head;
    while(last->next!=NULL)
    {
        last = last->next;
    }
    current = *head;
    for(i=0; i<position && current!=NULL; i++)
    {
        current = current->next;
    }

    if(position == 0)
    {
        deletefrombeginning(&(*head));
    }
    else if(current == last)
    {
        deletefromend(&(*head));
    }
    else if(current != NULL)
    {
        current->prev->next = current->next;
        current->next->prev = current->prev;

        free(current); // Delete the n node
    }
    else
    {
        printf("Invalid position!\n");
    }
}



int main()
{
    struct node *head,*temp;
    int n,x,i,l,pos;
    printf("Enter no of elements: \n");
    scanf("%d",&n);
    if(n==0)
    {
        printf("empty list");
    }
    else
    {
        printf("Enter elements: \n");
        scanf("%d",&x);
        head->data = x;
        head->next = NULL;
        head->prev = NULL;
        for(i=2;i<=n;i++)
        {
            scanf("%d",&x);
            append(&head,x);//basically insertion at end operation
        }
        printforward(&head);
        printbackward(&head);
        printf("Enter no of elements to insert at beg\n");
        scanf("%d",&l);
        printf("enter elements\n");
        for(i=0;i<l;i++)
        {
            scanf("%d",&x);
            insertatfront(&head,x);
        }
        printforward(&head);
        
        printf("Enter no of elements to insert at end\n");
        scanf("%d",&l);
        printf("enter elements\n");
        for(i=0;i<l;i++)
        {
            scanf("%d",&x);
            insertatend(&head,x);
        }
        printforward(&head);
        printf("Enter no of elements to insert at any position\n");
        scanf("%d",&l);
        for(i=0;i<l;i++)
        {
            printf("enter elements\n");
            scanf("%d",&x);
            printf("enter position\n");
            scanf("%d",&pos);
            insertatany(&head,x,pos);
        }
        printforward(&head);
        printf("Enter no of elements to delete from any position\n");
        scanf("%d",&l);
        for(i=0;i<l;i++)
        {
            printf("enter position\n");
            scanf("%d",&pos);
            deletefromany(&head,pos);
            printforward(&head);
        }
        printforward(&head);
        
        
    }
    return 0;
}