	//sum of +ve elements
#include<stdio.h>
int main()
{
	int i,arr[10],sum=0,n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	for(i=0;i<n;i++)
	{
		if(arr[i]>=0)
			sum+=arr[i];
	}
	printf("\n%d",sum);
	return 0;
}
