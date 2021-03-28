#include<stdio.h>
#define MAX 100

void insertion_sort(int a[],int d){
	int i,j,val;
	for(i=1;i<d;i++){
		j=i-1;
		val=a[i];
		while(j>=0 && a[j]>val){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=val;
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
	insertion_sort(arr,n);
	printf("\nThe sorted array is:");
	for(i=0;i<n;i++)
		printf(" %d ",arr[i]);
}