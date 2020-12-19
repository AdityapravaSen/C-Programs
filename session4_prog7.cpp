#include<stdio.h>
int main()
{
	int num,i,p;
	scanf("%d",&num);
	for(i=1;i<=12;i++)
	{
		p=num*i;
		printf("%d * %d= %d\n",num,i,p);
	}
	return 0;
}
