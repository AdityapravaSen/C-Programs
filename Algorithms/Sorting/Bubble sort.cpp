		//bubble sort
#include<stdio.h>
#define MAX 20
int main()
{
	int arr[MAX],n,i,j,temp;
	printf("enter limit:\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("unsorted list is:\n");
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	printf("sorted list is:\n");
	for(i=0;i<n;i++)
		printf("%d  ",arr[i]);
	return 0;
}
