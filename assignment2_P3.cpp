#include<stdio.h>
int power(int n,int p)
{
	int i,m=1;
	for(i=1;i<=p;i++)
		m=m*n;
	return m;
}
int main()
{
	int num,ans,pow;
	printf("no. and power:\n");
	scanf("%d %d",&num,&pow);
	ans=power(num,pow);
	printf("\n%d",ans);
	return 0;
}
