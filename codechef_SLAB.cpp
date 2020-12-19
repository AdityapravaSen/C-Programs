#include<stdio.h>
int main()
{
	int test;
	long int n,tax;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%ld",&n);
		if(n<=250000)
			tax=0;
		else if(n>250000 && n<=500000)
		{
			tax=12500;
		}
		else if(n>500000 && n<=750000)
		{
			tax=12500+((n-500000)*0.1);
		}
		else if(n>750000 && n<=1000000)
		{
			tax=37500+((n-750000)*0.15);
		}
		else if(n>1000000 && n<=1250000)
		{
			tax=75000+((n-1000000)*0.2);
		}
		else if(n>1250000 && n<=1500000)
		{
			tax=125000+((n-1250000)*0.25);
		}
		else if(n>1500000)
		{
			tax=187500+((n-1500000)*0.30);
		}
		printf("%ld\n",n-tax);
	}
}
