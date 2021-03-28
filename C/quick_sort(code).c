#include<stdio.h>
#define MAX 100

int partition(int a[],int start,int end){
	int pivot=a[start];
	int i=start,j=end,temp;
	while(i<j){
		while(a[i]<=pivot)
			i++;
		while(a[j]>pivot)
			j--;
		if(i<j){
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}
	temp=a[start];
	a[start]=a[j];
	a[j]=temp;
	return j;
}

void quick_sort(int a[],int start,int end){
	int loc;
	if(start<end){
		loc=partition(a,start,end);
		quick_sort(a,start,loc-1);
		quick_sort(a,loc+1,end);
	}
}

void main(){
	int arr[MAX],i,n=0;
	do{
		printf("\nEnter 1 to enter new array element or 0 to stop:");
		scanf("%d",&i);
		if(i==1){
			printf("\nEnter the array element:");
			scanf("%d",&arr[n]);
			n++;
		}
	}while(i);
	printf("\nThe given array is:");
	for(i=0;i<n;i++)
		printf(" %d ",arr[i]);
	quick_sort(arr,0,n-1);
	printf("\nThe sorted array is:");
	for(i=0;i<n;i++)
		printf(" %d ",arr[i]);
}