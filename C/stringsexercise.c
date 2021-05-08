#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    char ch;
    long s = 0, x = 0; int count = 0;
    while(ch!='.')
    {
        int n = 0;
        scanf("%c",&ch);
        if((ch==' ') || (ch=='.'))
        {
            long y = s;
            while(y!=0)
            {
                count++;
                y=y/10;
            }
            x = x * pow(10,count) + s;
            s = 0;
        }
        else
        {
           s = s+ch;
           count = 0;
        }
    }
    long tp = x;
    int sum = 0;
    do
    {
        sum = 0;
        while(tp)
        {
            sum = sum + (tp%10);
            tp = tp/10;
        }
        if(sum>10)
        {
            tp = sum;
        }
    }while(sum>10);
    if(sum == 1)
    {
        printf("YES \n");
    }
    else
    {
        printf("NO \n");
    }
    return 0;
}
