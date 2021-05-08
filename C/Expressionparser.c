#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

int main(void)
{
    char hp,fch,prevfch;
    scanf("%c",&hp);
    int res=0,rem=0,op1,op2;
    scanf("%d",&op1);
    if(!(op1>=0&&op1<=9))
    {
        printf("-1");
        return 0;
    }
    if(hp=='*')
    {
        int count=0;
        while(1)
        {
            scanf("%c %d",&fch,&op2);
            if(fch==';')
            { 
                break;
            }
            if((op2>=0&&op2<=9)&&(fch=='+'||fch=='*')) 
            {
                prevfch=fch;
                if(op1==0&&prevfch==fch)
                { 
                    count++;
                }
                else
                {
                count=0;
                }
                if(fch=='*')
                {
                    res=op1*op2;
                    op1=res;
                }
                else 
                {
                    rem+=op1;
                    op1=op2;
                }
            } 
            else 
            {
                printf("-1");
                return 0;
            }
            if(count>=10000) 
            {
                printf("-1");
                return 0;
            }
        }
        if(fch==';')
        { 
            printf("%d",res+rem);
        }
        else 
        {
            printf("-1");
        }
    }
    else 
    {
        int count=0;
        rem=1;
        while(1)
        {
            scanf("%c",&fch);
            scanf("%d",&op2);
            if(fch==';')
            { 
                break;
            }
            if((op2>=0&&op2<=9)&&(fch=='+'||fch=='*')) 
            {
                prevfch=fch;
                if(op1==op2&&prevfch==fch) count++;
                else count=0;
                if(fch=='+')
                {
                    res=op1+op2;
                    op1=res;
                }
                else 
                {
                    rem*=op1;
                    op1=op2;
                }
            } 
            else 
            {
                printf("-1");
                return 0;
            }
            if(count>=10000) 
            {
                printf("-1");
                return 0;
            }
        }
        if(fch==';')
        { 
            printf("%d",rem*op1);
        }
        else
        { 
            printf("-1");
        }
    }
    return 0;
}