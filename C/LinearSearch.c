#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>


int Linearsearch(int arr[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;
}
 

int main()
{

    int arr[100],i,n,x,k;
    printf("Size: ");
    scanf("%d",&n);
    printf("Enter elements \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        arr[i] = x;
    }
    printf("Enter key to be searched: ");
    scanf("%d",&k);
    k = LinearSearch(arr,n,k);
    if(k!=-1)
    {
        printf("element found at position %d",k);
    }
    else
    {
        printf("Not found \n");
    }
    return 0;
}