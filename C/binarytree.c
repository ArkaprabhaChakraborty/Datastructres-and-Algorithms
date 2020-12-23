#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

struct node 
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *newnode(int x)
{
    struct node *p = (struct node*)malloc(sizeof(struct node));
    p->data = x;
    p->left = p->right = NULL;
    return p;
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

void inorder(struct node *p)
{
    if(p != NULL)
    {
        inorder(p->left);
        printf("%d ",p->data);
        inorder(p->right);
    }
}

void preorder(struct node *p)
{
    if(p==NULL)
    {
        return;
    }
    printf("%d ",p->data);
    preorder(p->left);
    preorder(p->right);
}

void postorder(struct node *p)
{
    if(p==NULL)
    {
        return;
    }
    postorder(p->left);
    postorder(p->right);
    printf("%d ",p->data);
}

struct node *minval(struct node *q)
{
    struct node *p = q;
    while(p && p->left!=NULL)
    {
        p = p->left;
    }
    return p;
}


struct node *delete(struct node *p, int x)
{
    if(p == NULL)
    {
        return p;
    }
    if( x > p->data )
    {
        p->right = delete(p->right,x);
    }
    else if(x < p->data)
    {
        p->left = delete(p->left,x);
    }
    else
    {
        if(p->right == NULL)
        {
            struct node *temp = p->left;
            free(p);
            return temp;
        }
        else if(p->left == NULL)
        {
            struct node *temp = p->right;
            free(p);
            return temp; 
        }
        struct node *temp = minval(p->right);
        p->data = temp->data;
        p->right = delete(p->right,temp->data);
    }
    return p;
}



struct node *inordersuccessor(struct node *root, struct node *p)
{
    if(p->right!=NULL)
    {
        return minval(p);
    }
    else
    {
        struct node *s = NULL;
        while(root !=NULL)
        {
            if(p->data < root->data)
            {
                s = root;
                root = root->left;
            }
            else if(p->data > root->data)
            {
                root = root->right; 
            }
            else
            {
                break;
            }
        }
        return s;
    }
}

struct node *search(struct node *p,int x)
{
    if(x > p->data)
    {
        p = p->right;
        p = search(p,x);
    }
    else if(x < p->data)
    {
        p = p->left;
        p = search(p,x);
    }
    else if(p->data == x)
    {
        return p;
    }
    else
    {
        return NULL;
    }
}

int main()
{
    int i,n = 0;
    struct node *p = NULL;
    int c = 0;
    do
    {
        printf("1. To create/insert in a BST\n2. For Post-order Traversal\n3. For Pre-order Traversal\n4. To delete an element from the BST \n5. To get the inorder successor of value\nAnything else to exit\nEnter choice: ");
        scanf("%d",&c);
        switch(c)
        {
            case 1: printf("Enter number of elements\n");
                    scanf("%d",&n);
                    printf("Enter elements\n");
                    while(n--)
                    {
                        int x;
                        scanf("%d",&x);
                        p = init(p,x); 
                    }
                    printf("Inorder traversal: ");
                    inorder(p);
                    printf("\n");
                    break;
            case 2: printf("Post-order Traversal :");
                    postorder(p);
                    printf("\n");
                    break;
            case 3: printf("Pre-order Traversal :");
                    preorder(p);
                    printf("\n");
                    break;
            case 4: printf("Enter element to delete: ");
                    scanf("%d",&n);
                    p = delete(p,n);
                    printf("Inorder traversal: ");
                    inorder(p);
                    printf("\n");
                    break;
            case 5: printf("Enter value to get In-order successor\n");
                    scanf("%d",&n);
                    struct node *temp = search(p,n);
                    if(temp)
                    {
                        struct node *new = inordersuccessor(p,temp);
                        printf("In-order successor of %d is %d \n",temp->data,new->data);
                    }
                    else
                    {
                        printf("Node value doesn't exist\n");
                    }
                    break;
            default:c = 0; 
                    break;
        }
    } while (c);
    return 0;
}
