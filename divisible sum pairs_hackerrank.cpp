#include<stdio.h>
int main()
{
	int a[20],k,n,i,j,flag=0;
	printf("enter n and k");
	scanf("%d %d",&n,&k);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(a[i]<a[j] && (a[i]+a[j])%k==0)
				flag++;
		}
	}
	printf("\n%d",flag);
	return 0;
}
