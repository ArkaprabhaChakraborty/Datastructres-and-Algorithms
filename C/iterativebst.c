#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

struct node
{
    int data;
    struct node *left,*right;
};

struct stack
{
    struct node **arr;
    int top;
    int capacity;  
};

struct node* newnode(int data) 
{ 
    struct node* node = (struct node*)malloc(sizeof(struct node)); 
    node->data = data; 
    node->left = node->right = NULL; 
    return node; 
} 

struct stack *create(int x)
{
    struct stack *s = (struct stack*)malloc(sizeof(struct stack));
    s->capacity = x;
    s->top = -1;
    s->arr = (struct node**)malloc(x * sizeof(struct node*));
    return s;
} 

int isempty(struct stack *s)
{
    return (s->top == -1);
}

int isfull(struct stack *s)
{
    return (s->top - 1 == s->capacity);
}

struct node *peek(struct stack *s)
{
    return s->arr[s->top];
}

struct node *init(struct node *p,int x)
{
    if(p == NULL)
    {
        return newnode(x); 
    }
    else
    {
        if (x < p->data)
        {
            p->left = init(p->left,x);
        }
        else
        {
            p->right = init(p->right,x);
        }
    }
    return p;
}


void push(struct stack *s,struct node *n)
{
    if (isfull(s))
    {
        return; 
    }
    s->arr[++(s->top)] = n;
}

struct node *pop(struct stack *s)
{
    if (isempty(s))
    {
        return NULL;
    }
    return s->arr[s->top--];
}


void postorder(struct node *root) 
{ 
    if (root == NULL) 
        return;
    struct stack *stack = create(9999999);
    while(true)
    {
        while(root)
        {
            if(root->right != NULL)
            {
                push(stack,root->right);
            }
            push(stack,root);
            root = root->left; 
        }
        root = pop(stack);
        if(root->right != NULL && peek(stack) == root->right)
        {
            pop(stack);
            push(stack,root);
            root = root->right;
        }
        else
        {
            printf("%d ",root->data);
            root = NULL;
        }
        if(stack->top < 0)
        {
            break;
        }
    }
} 

void inorder(struct node *temp)
{
    if(temp == NULL)
    {
        return;
    }
    struct stack *stack = create(99999);
    while(true)
    {
        if(temp != NULL)
        {
            push(stack,temp);
            temp = temp->left;
        }
        else if(isempty(stack)==0)
        {
            temp = pop(stack);
            printf("%d ",temp->data);
            temp = temp->right;
        }
        else
        {
            break;
        }         
    }
}

void preorder(struct node *root)
{
    if(root == NULL)
    {
        return;
    }
    struct stack *stack = create(999999);
    push(stack,root);
    while(isempty(stack) == 0)
    {
        struct node *n = pop(stack);
        printf("%d ",n->data);
        if(n->right)
        {
            push(stack,n->right);
        }
        if(n->left)
        {
            push(stack,n->left);
        }
    }
}

int main()
{
    int n;
    printf("Enter no of elements : ");
    scanf("%d",&n);
    struct node *root = NULL;
    struct node *r = NULL;
    printf("Enter Elements: \n");
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        root = init(root,x);
    }
    printf("Post-order : ");
    postorder(root);
    printf("\n");
    printf("In-order : ");
    inorder(root);
    printf("\n");
    printf("Pre-order : ");
    preorder(root);
    return 0;
}
