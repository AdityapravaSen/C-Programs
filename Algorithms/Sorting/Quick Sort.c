#include<stdio.h>
#define MAX 100

int arr[MAX],n;

void swap(int *a,int *b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

int partition(int l, int h){
	int pivot=arr[l], i=l,j=h;
	while(i<j){
		
		while(arr[i]<=pivot && i<h)
			i++;
		
		while(arr[j]>pivot)
			j--;
		
		if(i<j){
			swap(&arr[i],&arr[j]);
		}
	}
	swap(&arr[l],&arr[j]);
	return j;
}

void quicksort(int l,int h){
	int j;
	if(l<h){
		j=partition(l,h);
		quicksort(l,j-1);
		quicksort(j+1,h);
	}
}

void display(){
	int i;
	printf("sorted array:\n");
	for(i=0;i<n;i++){
		printf("%d\t",arr[i]);
	}
}

int main(){
	int i;
	printf("enter limit:");
	scanf("%d",&n);
	
	printf("enter elements:\n");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	
	quicksort(0,n-1);
	
	display();
	return 0;
}
