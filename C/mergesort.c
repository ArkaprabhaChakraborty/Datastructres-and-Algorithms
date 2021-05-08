#include <stdio.h>
void merge(int arr[],int low,int mid,int high)
{
	int n1 = mid - low + 1;
	int n2 = high - mid;
	int l[n1+1],r[n2+1];
	for(int i = 1; i<=n1; i++)
	{
		l[i] = arr[low + i-1];
	}
	for(int j=1;j <=n2; j++)
	{
		r[j] = arr[mid + j];
	}
	l[n1 + 1] = 99999;
	r[n2 + 1] = 99999;
	int i = 1;
	int j = 1;
	for(int k = low; k <=high; k++)
	{
		if(l[i]<r[j])
		{
			arr[k] = l[i];
			i++;
		}
		else
		{
			arr[k] = r[j];
			j++;
		}
	}
}

void mergesort(int arr[],int low,int high)
{
	if(low<high)
	{
		int q = low + (high - low)/2;
		mergesort(arr, low, q);
		mergesort(arr, q+1, high);
		merge(arr, low, q, high); 
	}	
}

void print(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
}

int main()
{
	int arr[] = {1,4,7,6,8,5,3,0,2};
	print(arr,9);
	mergesort(arr, 0, 8);
	printf("\n");
	print(arr,9);
  return 0;
}
