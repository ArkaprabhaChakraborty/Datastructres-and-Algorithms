#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <math.h>

int gcd(int a,int b)
{
    while(a!=b)
    {
        if (a>b)
        {
            a = a - b;
        }
        else
        {
            b = b - a;
        }
    }
    return a;
}

int main()
{
    int n;
    printf("enter no of elements: ");
    scanf("%d",&n);
    int arr[10000];
    int i,result=0,lcm = 0;
    printf("enter elements: \n");
    for (i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    result = gcd(arr[0],arr[1]);
    lcm = (arr[0] * arr[1])/result;
    for (i=2;i<n;i++)
    {
        result = gcd(result,arr[i]);
        lcm = (lcm * arr[i])/result;
    }
    printf("GCD: %d\nLCM: %d\n",result,lcm);
    return 0;
}
