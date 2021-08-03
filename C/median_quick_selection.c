#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
 
int Partition(int arr[], int l, int r)
{
    int lst = arr[r], i = l, j = l;
    while (j < r) {
        if (arr[j] < lst) {
            swap(&arr[i], &arr[j]);
            i++;
        }
        j++;
    }
    swap(&arr[i], &arr[r]);
    return i;
}
 
int randomPartition(int arr[], int l, int r)
{
    int n = r - l + 1;
    int pivot = rand() % n;
    swap(&arr[l + pivot], &arr[r]);
    return Partition(arr, l, r);
}
 

void MedianUtil(int arr[], int l, int r, int k, int *a, int *b)
{
    // if l < r
    if (l <= r) {
 
        // Find the partition index
        int partitionIndex = randomPartition(arr, l, r);
 
        if (partitionIndex == k) {
            *b = arr[partitionIndex];
            if (*a != -1)
                return;
        }
 
        else if (partitionIndex == k - 1) {
            *a = arr[partitionIndex];
            if (*b != -1)
                return;
        }

        if (partitionIndex >= k)
            return MedianUtil(arr, l, partitionIndex - 1, k, &(*a), &(*b));
        else
            return MedianUtil(arr, partitionIndex + 1, r, k, &(*a), &(*b));
    }
 
    return;
}
 
// Function to find Median
void findMedian(int arr[], int n)
{
    int ans, a = -1, b = -1;
 
    // If n is odd
    if (n % 2 == 1) {
        MedianUtil(arr, 0, n - 1, n / 2, &a, &b);
        ans = b;
    }
 
    // If n is even
    else {
        MedianUtil(arr, 0, n - 1, n / 2, &a, &b);
        ans = (a + b) / 2;
    }
 
    // Print the Median of arr[]
    printf("Median = %d\n" ,ans);
}
 
// Driver program to test above methods
int main()
{
    int arr[] = { 12, 3, 5, 7, 4, 19, 26 };
    int n = sizeof(arr) / sizeof(arr[0]);
    findMedian(arr, n);
    return 0;
}