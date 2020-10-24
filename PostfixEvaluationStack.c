#include <limits.h> 
#include <stdio.h> 
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
struct stack
{
    int data;
    struct stack *next;
};

void push(struct stack **root,int a)
{
    struct stack *new = (struct stack*)malloc(sizeof(struct stack));
    new->data  = a;
    new->next = (*root);
    (*root) = new;
}

int isempty(struct stack **node)
{
    return !(*node);
}

int pop(struct stack **root)
{
    int r;
    if(isempty(&(*root)))
    {
        return -1;
    }
    struct stack *temp = *root;
    r = (*root)->data;
    (*root) = (*root)->next;
    free(temp);
    return r;
}

int main()
{
    struct stack *head = NULL;
    int i;
    int n;
    char s[1000],num[1000];
    int x,number,k,l,a,b,r;
    printf("Enter Space separated espression ending with space\n");
    scanf("%[^\n]s",s);
    n = strlen(s);
    k = 0;
    for(i=0;i<=n;i++)
    {
        if(s[i]!=' ')
        {
            num[k] = s[i];
            k++;
        }
        else
        {
            k = 0;
            l = strlen(num);
            if(l==1)
            {
                if(isdigit(num[0]))
                {
                    number  = num[0];
                    printf("%d \n",number - '0');
                    push(&head,number - '0');
                }
                else
                {
                    char ch = num[0];
                    a = pop(&head);
                    b = pop(&head);
                    printf("%d %d \n",a,b);
                    if(ch=='+')
                    {
                        r = a + b;
                    }
                    else if(ch=='-')
                    {
                        r = a - b; 
                    }
                    else if(ch=='*')
                    {
                        r = a * b;
                    }
                    else if(ch=='/')
                    {
                        r = a / b;
                    }
                    else if(ch=='%')
                    {
                        r = a % b;
                    }
                    push(&head,r);
                }
            }
            else
            {
                number = atoi(num);
                push(&head,number);
                printf("%d \n",number);
            }

        }   
    }
    printf(" Final Answer : %d ",pop(&head));
    return 0;
}