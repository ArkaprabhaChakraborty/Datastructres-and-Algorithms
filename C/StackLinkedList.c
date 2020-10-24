#include <limits.h> 
#include <stdio.h> 
#include <stdlib.h>
//necessary imports for warning free code

struct stack
{ 
    //creating stack struct ...... as usual
    int data;
    struct stack *next; // to point to next node
};

void push(struct stack **root,int a)
{
    struct stack *node;
    node = (struct stack*)malloc(sizeof(struct stack));
    node->data = a;
    node->next = (*root);
    (*root) = node;
    /*for creation from head we take head = NULL..so root = NULL
    then node->next = NULL and then root = node creates the head node
    by shifting root (or head as root points to head)*/ 
    
    /*basically its more of like adding an element at the begining 
    of a linked list. Why? Cuz by this approach popping elements doen't require 
    any loop to travel to the last element. Just pop out the head by shifting it.
    It still follows the LIFO(Last In First Out) movement :) 
    Just not the way you Imagine!!*/
}

int isempty(struct stack **head)
{
    return !(*head);
    /*! operator return 1 if head == NULL and 0 if head has value*/
}

int pop(struct stack **root)
{
    int r;
    if(isempty(&(*root)))
    {
        return -14142452;
    }
    struct stack *temp = *root;
    r = (*root)->data;
    (*root) = (*root)->next; // move root to root next as decided
    free(temp); /*Here pop() completely deletes the element ... unlike the one done in StackArray.c*/
    return r;
}

int main()
{
    struct stack *head = NULL;
    int n,i,x;
    printf("Enter no of elements \n");
    scanf("%d",&n);
    printf("Enter elements \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        push(&head,x);
    }
    printf("Popping Out \n");
    for(i=0;i<n;i++)
    {
        x = pop(&head);
        printf("%d ",x);
    }
    return 0;
}