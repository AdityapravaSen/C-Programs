#include<stdio.h>
#define MAX 100

int arr[MAX],n;

void maxheapify(int lim,int loc){
	int largest,l,r,temp;
	largest=loc;
	l=(2*loc)+1;
	r=(2*loc)+2;
	
	if(l<lim && arr[l]>arr[largest]){
		largest=l;
	}
	if(r<lim && arr[r]>arr[largest]){
		largest=r;
	}
	if(largest!=loc){
		temp=arr[loc];
		arr[loc]=arr[largest];
		arr[largest]=temp;
		
		maxheapify(lim,largest);
	}
}

void heapsort(){
	int i,temp;
	for(i=n/2-1;i>=0;i--){
		maxheapify(n,i);
	}
	
	for(i=n-1;i>=0;i--){
		temp=arr[0];
		arr[0]=arr[i];
		arr[i]=temp;
		
		maxheapify(i,0);
	}
	
	printf("the sorted array is:\n");
	for(i=0;i<n;i++){
		printf("%d\t",arr[i]);
	}
}

int main(){
	int i;
	printf("enter limit:");
	scanf("%d",&n);
	
	printf("\nenter array:\n");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	
	heapsort();
	return 0;
}
