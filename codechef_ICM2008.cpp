#include<stdio.h>
#include<stdlib.h>
int main()
{
	long long int a,b,c,d,test,d1,d2;
	scanf("%lld",&test);
	while(test--)
	{
		scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
		d1=abs(a-b);
		d2=abs(c-d);
		if(d1==0)
		{
			printf("YES\n");
			continue;
		}
		if(d2==0)
		{
			printf("NO\n");
			continue;
		}
		if(d1%d2==0)
			printf("YES\n");
		else
			printf("NO\n");
	}
}
