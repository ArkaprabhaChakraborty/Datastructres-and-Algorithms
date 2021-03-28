#include<stdio.h>
#define MAX 100

void selection_sort(int a[],int d){
	int i,j,min,pos;
	for(i=0;i<d-1;i++){
		min=a[i];
		pos=i;
		for(j=i+1;j<d;j++){
			if(a[j]<min){
				min=a[j];
				pos=j;
			}
		}
		if(pos!=i){
			a[pos]=a[i];
			a[i]=min;
		}
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
	selection_sort(arr,n);
	printf("\nThe sorted array is:");
	for(i=0;i<n;i++)
		printf(" %d ",arr[i]);
}