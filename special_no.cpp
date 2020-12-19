#include<stdio.h>
int main()
{
	int num,temp,rem,sum=0,p=1,check;
	scanf("%d",&num);
	temp=num;
	while(temp!=0)
	{
		rem=temp%10;
		sum=sum+rem;
		p=p*rem;
		temp=temp/10;
	}
	check=sum+p;
	printf("sum=%d\n",sum);
	printf("p=%d\n",p);
	if(check==num)
		printf("special no.\n");
	else
		printf("not special");
}
