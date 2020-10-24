#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
/*Algorithm for moves is that smaller disk is always on top..

tower A --source
tower C --sink
tower B --aux
n --no of disks .. lets consider 2..
Firstly A to B 
Then A to C 
Then B to C

General formula for moves: 2^n - 1  */

void moves(char a, char c, char b , int n)
{
    if(n==1)
    {
        printf("Move disk 1 from %c to %c \n",a,c);
        return;
    }
    else
    {
        moves(a,b,c,n-1);
        printf("Move disk %d from %c to %c \n",n,a,c);
        moves(b,c,a,n-1);
    }
}

int main()
{
    int n;
    printf("Source Tower is A \n");
    printf("Sink Tower is B \n");
    printf("Auxiliary Tower is C \n");
    printf("Enter No of disks \n");
    scanf("%d",&n);
    moves('A','C','B',n);
    return 0;
}