			//sum of array elements
#include<stdio.h>
int main()
{
	int sum=0,i,n,arr[10];
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	for(i=0;i<n;i++)
		sum+=arr[i];
	printf("\n%d",sum);
	return 0;
}
