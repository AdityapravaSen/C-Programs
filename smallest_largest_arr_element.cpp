		//smallest and largest array element
#include<stdio.h>
void largest_arr_element(int arr[],int n){
	int i,largest=arr[0];
	for(i=1;i<n;i++){
		if(largest<arr[i])
			largest=arr[i];
	}
	printf("Largest array element: %d",largest);
}


int main()
{
	int arr[10],i,smallest,largest,n;
	printf("limit:\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	largest_arr_element(arr,n);
	return 0;
}
