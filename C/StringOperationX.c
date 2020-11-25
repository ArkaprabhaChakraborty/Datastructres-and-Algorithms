#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>


void removes(char *arr,char x)
{
    int n = strlen(arr), j=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]!=x)
        {
            arr[j++] = arr[i];
        }
    }
    arr[j] = '\0';
}
int main()
{
    char s[] = "Arxhxxxxjxjxuhxlxjxxxxx";
    printf("%s \n",s);
    removes(s,'x');
    printf("%s \n",s);
    return 0;
}