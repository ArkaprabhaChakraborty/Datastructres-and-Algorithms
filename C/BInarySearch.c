#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>


int binarySearch(int arr[], int l, int r, int x)
{
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (arr[m] == x)
            return m;
        if (arr[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
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
    k = binarySearch(arr,0,n,k);
    if(k!=-1)
    {
        printf("element found at position %d \n",k);
    }
    else
    {
        printf("Not found \n");
    }
    return 0;
}
  