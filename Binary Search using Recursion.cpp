#include <stdio.h> 
int binarySearch(int arr[], int l, int r, int x) 
{ 
	if (r >= l) 
	{ 
		int mid = l + (r - l) / 2; 
		if (arr[mid] == x) 
			return mid; 
		if (arr[mid] > x) 
			return binarySearch(arr, l, mid - 1, x); 
		return binarySearch(arr, mid + 1, r, x);
	} 
	return -1; 
}

int selectionSort(int arr[],int lim,int x){
	int temp,i,j;
	
	for(i=0;i<lim;i++){
		for(j=i+1;j<lim;j++){
			if(arr[i]>arr[j]){
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
	printf("sorted array is:\n");
	for(i=0;i<lim;i++){
		printf("%d\t",arr[i]);
	}
	printf("\n");
	
	int result = binarySearch(arr, 0, lim - 1, x);
	return result;
}

int main(void) 
{ 
	int arr[20],n,x,i;
	printf("enter limit:");
	scanf("%d",&n);
	
	printf("enter array:");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("enter no. to search:");
	scanf("%d",&x);
	
	int result = selectionSort(arr,n, x);
	(result == -1) ? printf("Element is not present in array") : printf("Element is present at index %d", result); 
	return 0; 
} 

