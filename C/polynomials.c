#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>


struct node 
{
    int power;
    int coeff;
    struct node *next;
};

void create(struct node **temp,int dat,int x)
{
    struct node *r, *z;
	z = *temp;
	if (z == NULL) 
    {
		r = (struct node*)malloc(sizeof(struct node));
		r->coeff = dat;
		r->power = x;
		*temp = r;
		r->next = (struct node*)malloc(sizeof(struct node));
		r = r->next;
		r->next = NULL;
	}
	else {
		r->coeff = dat;
		r->power = x;
		r->next = (struct node*)malloc(sizeof(struct node));
		r = r->next;
		r->next = NULL;
	}
}

void add(struct node **p,struct node **q,struct node *s)
{
    while((*p)->next && (*q)->next)
    {
        if((*p)->power > (*q)->power)
        {
            s->power = (*p)->power;
            s->coeff = (*p)->coeff;
            (*p) = (*p)->next;
        }
        else if((*p)->power < (*q)->power)
        {
            s->power = (*q)->power;
            s->coeff = (*q)->coeff;
            (*q) = (*q)->next;
        }
        else
        {
            s->power = (*p)->power;
            s->coeff = ((*p)->coeff) + ((*q)->coeff);
            (*p) = (*p)->next;
            (*q) = (*q)->next;
        }
        s->next = (struct node*)malloc(sizeof(struct node));
        s = s->next;
        s->next = NULL;
    }
    while((*p)->next || (*q)->next)
    {
        if((*p)->next)
        {
            s->power = (*p)->power;
            s->coeff = (*p)->coeff;
            (*p) = (*p)->next;
        }
        else if((*q)->next)
        {
            s->power = (*q)->power;
            s->coeff = (*q)->coeff;
            (*q) =(*q)->next;
        }
        s->next = (struct node *)malloc(sizeof(struct node));
        s = s->next;
        s->next = NULL;
    }
}

void difference(struct node **p,struct node **q,struct node *s)
{
    while((*p)->next && (*q)->next)
    {
        if((*p)->power > (*q)->power)
        {
            s->power = (*p)->power;
            s->coeff = (*p)->coeff;
            (*p) = (*p)->next;
        }
        else if((*p)->power < (*q)->power)
        {
            s->power = (*q)->power;
            s->coeff =  0 - (*q)->coeff;
            (*q) = (*q)->next;
        }
        else
        {
            s->power = (*p)->power;
            s->coeff = ((*p)->coeff) - ((*q)->coeff);
            (*p) = (*p)->next;
            (*q) = (*q)->next;
        }
        s->next = (struct node*)malloc(sizeof(struct node));
        s = s->next;
        s->next = NULL;
    }
    while((*p)->next || (*q)->next)
    {
        if((*p)->next)
        {
            s->power = (*p)->power;
            s->coeff = (*p)->coeff;
            (*p) = (*p)->next;
        }
        if((*q)->next || (*p)==NULL)
        {
            s->power = (*q)->power;
            s->coeff = 0 - (*q)->coeff;
            (*q) =(*q)->next;
        }
        s->next = (struct node *)malloc(sizeof(struct node));
        s = s->next;
        s->next = NULL;
    }
}


void print(struct node **temp)
{
    struct node *head = (*temp);
    while ((head)->next != NULL) 
    {
        printf("%dx^%d", (head)->coeff, (head)->power);
        (head) = (head)->next;
        if ((head)->coeff >= 0) 
        {
            if ((head)->next != NULL)
                printf("+");
        }
    }
    printf("\n");
}


int contains(struct node **p,int exp)
{
    struct node *q = (*p);
    int c = 0;
    while(q!=NULL)
    {
        if(q->power == exp)
        {
            c = 1;
            break;
        }
        q = q->next;
    }
    return c;
}

void multiply(struct node **p,struct node **q,struct node *s)
{
    int m_c,s_p,c; 
    struct node *ptr1=(*p),*ptr2=(*q),*t = s,*d = s;
    while(ptr1->next!=NULL)
    {
        ptr2=(*q);
        t = d;
        while(ptr2->next!=NULL)
        {
            m_c = (ptr2->coeff) * (ptr1->coeff);
            s_p = (ptr1->power) * (ptr2->power);
            c = contains(&t,s_p);
            if(c==0)
            {
                s->coeff = m_c;
                s->power = s_p;
                s->next = (struct node*)malloc(sizeof(struct node));
                s = s->next;
                s->next = NULL;
            }
            else
            {
                while(t->power!=s_p)
                {
                    t = t->next;
                }
                t->coeff = t->coeff + m_c;
            }
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
}

int main()
{
    //can be done menu driven ... but ... it took one full day to figure out what's going wrong with the logic...so .. please :)
    struct node *p = NULL,*q =NULL,*added = (struct node*)malloc(sizeof(struct node)) , *diff = (struct node*)malloc(sizeof(struct node));
    for(int i = 4;i>1;i--)
    {
        create(&p,i+1,i);
    }
    for(int i = 4;i>0;i--)
    {
        create(&q,i+1,i);
    }
    struct node *r = p,*t = q,*n = p,*m = q,*mul = (struct node*)malloc(sizeof(struct node));
    printf("Polynomial 1: ");
    print(&p);
    printf("Polynomial 2: ");
    print(&q);
    printf("Sum of polynomials: ");
    add(&p,&q,added);
    print(&added);
    printf("Difference of polynomials: ");
    difference(&r,&t,diff);
    print(&diff);
    multiply(&m,&n,mul);
    printf("Product of polynomials: ");
    print(&mul);
    return 0;
}