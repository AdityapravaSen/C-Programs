		//missing nos. in a range
#include<stdio.h>
int main()
{
	int i,n,arr[10];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	for(i=0;i<n;i++)
	{
		if(i==n-1)
			break;
		else if(arr[i]+1!=arr[i+1])
			printf("%d\n",arr[i]+1);
	}
	return 0;
}
