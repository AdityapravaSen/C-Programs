#include<stdio.h>
int main()
{
	int num,t,rem,sum=0;
	scanf("%d",&num);
	t=num;
	while(t!=0)
	{
		rem=t%10;
		sum=sum+(rem*rem*rem);
		t=t/10;
	}
	if(sum==num)
		printf("palindrome\n");
	else
		printf("not palindrome");
	return 0;
}
