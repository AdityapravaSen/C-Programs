			//odd and even array elements
#include<stdio.h>
int main()
{
	int n,i,arr[10],odd=0,even=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	for(i=0;i<n;i++)
	{
		if(arr[i]%2==0)
			even++;
		else
			odd++;
	}
	printf("odd:%d\teven:%d\n",odd,even);
	return 0;
}
