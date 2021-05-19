#include <stdio.h>
  void swap(int *first,int *second) {
    int t=*first;
    *first=*second;
    *second=t;
  } 
  void heapify(int arr[],int n,int i) {
    int max=i; 
    int l=2*i+1;
    int r=2*i+2;
    if (l<n && arr[l]>arr[max])
      max=l;
    if (r<n && arr[r]>arr[max])
      max=r;
    if (max!=i) {
      swap(&arr[i],&arr[max]);
      heapify(arr,n,max);
    }
  }
  void heapsort(int arr[], int num) {
  	int i=num/2;
    for (i = num/2 - 1; i >= 0; i--)
    heapify(arr,num,i);
    for (i=num-1;i>=0;i--) {
      swap(&arr[0], &arr[i]); 
      heapify(arr,i,0); 
    }
  }
  void d(int arr[],int num) 
  {
  	int i=0;
    for (i=0;i<num;i++)
      printf("%d ", arr[i]);
  }
  int main() {
  	int i,num;
    printf("\nEnter the number of elements in the array\n");
    scanf("%d",&num);
    int arr[num];
    printf("\nEnter the elements\n");
    for(i=0;i<num;i++)
    {
    	scanf("%d",&arr[i]);
	}
    printf("Original array:\n");
    d(arr,num);
    heapsort(arr,num);
    printf("\nSorted array:\n");
    d(arr,num);
  }
