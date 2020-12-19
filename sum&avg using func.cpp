#include<stdio.h>
void sum(int n)
{
	int i,sum=0;
	for(i=1;i<=n;i++)						
		sum=sum+i;
	printf("sum=%d\n",sum);
}
void avg(int n)
{
	int i,sum=0;
	float avg;
	for(i=1;i<=n;i++)
		sum=sum+i;
	avg=(float)sum/n;
	printf("avg=%f\n",avg);
}
int main()
{
	int n;
	scanf("%d",&n);
	sum(n);
	avg(n);
	return 0;
}
