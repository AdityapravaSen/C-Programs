		//repeating & non-repeating array elements
#include<stdio.h>
void repeating(int arr[],int n)
{
	int i,j,flag=0;
	printf("repeating elements-\n");
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(arr[i]==arr[j])
			{
				flag++;
				printf("%d\n",arr[i]);
			}
		}
		flag=0;
	}
}
void non_repeat(int arr[],int n)
{
	int i,j,flag=0;
	printf("non repeating elements-\n");
	for(i=0;i<n-1;i++)
	{
		flag=0;
		for(j=i+1;j<n;j++)
		{
			if(arr[i]==arr[j])
				flag++;
		}
		if(flag==0)
			printf("%d\t",arr[i]);
	}
}
int main()
{
	int i,arr[10],n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	repeating(arr,n);
	non_repeat(arr,n);
	return 0;
	
}
