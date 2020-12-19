#include<stdio.h> 
int armstrong(int n)
{
	int flag=0,temp,sum=0,rem;
	temp=n;
	while(temp!=0)
	{
		rem=temp%10;
		sum=sum+(rem*rem*rem);
		temp=temp/10;
	}
	if(sum==n)
		flag++;
	return flag;
}
int main()
{
	int n,result;
	scanf("%d",&n);
	result=armstrong(n);
	if(result==1)
		printf("\narmstrong no.");		//5.
	else
		printf("not armstrong");
	return 0;
}
