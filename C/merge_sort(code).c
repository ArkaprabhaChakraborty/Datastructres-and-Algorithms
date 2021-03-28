#include<stdio.h>
#define MAX 100

void merge(int a[],int start,int mid,int end){
	int b[MAX],i=start,j=mid+1,k=start;
	while(i<=mid && j<=end){
		if(a[i]<a[j]){
			b[k]=a[i];
			i++;
		}
		else{
			b[k]=a[j];
			j++;
		}
		k++;
	}
	while(i<=mid){
		b[k]=a[i];
		i++;
		k++;
	}
	while(j<=end){
		b[k]=a[j];
		j++;
		k++;
	}
	for(i=0;i<k;i++)
		a[i]=b[i];
}

void merge_sort(int a[],int start,int end){
	int mid;
	if(start<end){
		mid=(start+end)/2;
		merge_sort(a,start,mid);
		merge_sort(a,mid+1,end);
		merge(a,start,mid,end);
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
	merge_sort(arr,0,n-1);
	printf("\nThe sorted array is:");
	for(i=0;i<n;i++)
		printf(" %d ",arr[i]);
}