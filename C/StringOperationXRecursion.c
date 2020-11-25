#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

static int i = 0 ,k = 0;
void removes(char *arr,char x)
{
    int n = strlen(arr), j=0;
    if(n==0)
    {
        return;
    }
    else
    {
        arr[i]=arr[i+k];
        if(arr[i]==x)
        {
            k++;
            i--;
        }
        i++;
        removes(arr,x);
    }
}

int main()
{
    char s[] = "Arxhxxxxjxjxuhxlxjxxxxx";
    printf("%s \n",s);
    removes(s,'x');
    printf("%s \n",s);
    return 0;
}