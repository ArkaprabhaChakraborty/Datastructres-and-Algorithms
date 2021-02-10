#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//The backbone of quicksort is the partition function

int partition(int a[], int j, int r)
{
    /*Here I take the last element position to be the pivot element.The basic idea is to 
    place the pivot element in its right position such that all elements before pivot element
    are less or equal to itself and all elements after pivot element are greater than itself....
    Creating a partition... */
    int pivot = r; //last element position
    int i = j - 1; /*Hotfix for initial iteration/recursion .. keeping i at -1 ensures that we dont 
                     Skip the first element...*/
    int temp;
    while (j < r)
    {
        if (a[j] <= a[pivot])
        {
            i++; //First increment i because i was sitting at -1 at the beginning of the recursion
            temp = a[i]; /* Swapping a[i] with a[j] for a[j]<a[pivot]*/
            a[i] = a[j];
            a[j] = temp;
        }
        j++; //increment j till pivot-1 as we want to position pivot element
    }
    /*At this stage i either lags behind or is equal to j
    The position where (i+1) is now is the actual position where the pivot element should be...
    So we swap them.. */
    temp = a[i+1]; 
    a[i+1] = a[pivot];
    a[pivot] = temp;
    return i + 1;
}
void quicksort(int a[], int lb, int ub)
{
    int part;
    if (lb <= ub)
    {
        part = partition(a, lb, ub);
        quicksort(a, lb, part-1); //calling quicksort on first half of the array
        quicksort(a, part+1, ub); //calling quicksort on the second half of the array
    }
}
int main()
{
    int n,i;
    printf("Enter No of elements \n");
    scanf("%d",&n);
    int a[10000]; //sample array
    printf("Enter elements \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Before Sorting :");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n After Sorting :");
    quicksort(a, 0, n-1);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}