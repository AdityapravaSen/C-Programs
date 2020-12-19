#include<stdio.h>
int main()
{
	int test,n,j,k,a[10],b[10];
	long long int d=0;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d",&n);
		for(j=0;j<n;j++)
			scanf("%d",&a[j]);
		printf("\n");
		for(k=0;k<n;k++)
			scanf("%d",&b[k]);
	}
	while(test--)
	{
		for(j=n-1,k=0;j>=0 && k<n;j--,k++)
		{
			if(a[j]>b[k])
				d=d+ b[k];
			else
				d=d+a[j];
		}
		printf("%lld\n",d);
		d=0;
	}
}
