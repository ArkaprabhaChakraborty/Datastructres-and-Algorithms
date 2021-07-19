/*
Students of Kendriya Vidyalaya were out on a field trip to Bokaro. 
The class had been divided into 26 groups denoted by a,b,c...z. 

They are all standing in a line to visit the Jawahar Lal Nehru Park. 

Given a list of the groups of students standing in the line. 
Determine how many students will remain after the last student of a given group visits the memorial. 
If no student of a given group has attended the field trip, output “No student exists”.

Assume that the students visit the memorial in a given order. 

Input has two lines. 
The first line has an integer, denoting the size of the class, followed by the group.
The second line has the sequence of students.

Eg, For Test case 
2 f
f a
After the last f has visited the memorial, only 1 student remains belonging to group a. So output is 1.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>


struct node 
{
    char data;
    struct node *next;
};

void append(struct node **head,char x)
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


int search_count(struct node *head, char ch)
{
    int count = 0;
    while(head!= NULL)
    {
        if(head->data!=ch)
        {
            count ++;
        }
        else
        {
            break;    
        }
        head = head->next;
    }
    return count;
}

int main()
{
    struct node *head = NULL;
    int n; 
    char ch,c;
    scanf("%d",&n);
    scanf("%c",&ch);
    for(int i=0;i<n;i++)
    {
        scanf("%c",&c);
        append(&head,c);
    }
    reverse(&head);
    int a;
    a = search_count(head,ch);
    printf("%d",a);
    return 0;
}
