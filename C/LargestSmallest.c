#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int main()
{
    int arr[100],i,n,j,x,k;
    printf("Size: ");
    scanf("%d",&n);
    printf("Enter elements \n");
    k = 99999999;
    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        arr[i] = x;
    }
    x = k = 9999999;
    for(i=0;i<n;i++)
    {
        if (arr[i] < x)
        {
            k = x;
            x = arr[i];
        }
        else if (arr[i] < k && arr[i] != x)
        {
            k = arr[i];
        }
    }
    printf("Smallest : %d \n",x);
    printf("SecondSmallest : %d \n",k);
    x = k = -9999999;
    for(i=0;i<n;i++)
    {
        if (arr[i] > x)
        {
            k = x;
            x = arr[i];
        }
        else if (arr[i] > k && arr[i] != x)
        {
            k = arr[i];
        }
    }
    printf("Largest : %d\n",x);
    printf("SecondLargest : %d\n",k);
    return 0;
}