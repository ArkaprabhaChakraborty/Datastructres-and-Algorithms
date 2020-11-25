#include<stdio.h>
void example(int a[10])
{
    int j;
    j = sizeof(a)/sizeof(a[0]);
    printf("%d \n",j);
    printf("%d \n",sizeof(a));
    printf("%d \n",sizeof(a[0]));
}
int main()
{
    int a[50];
    int s = sizeof(a)/sizeof(a[0]);
    example(a);
    printf("%d \n",sizeof(a));
    printf("%d \n",sizeof(a[0]));
    printf("%d \n",s);
}