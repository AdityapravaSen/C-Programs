#include<stdio.h> 
int main()
{
	int num,i=1,p=1;
	printf("enter no.\n");
	scanf("%d",&num);
	printf("using while loop\n");
	while(i<=num)
	{
		p=p*i;
		i++;
	}
	printf("factorial=%d\n",p);
	p=1;
	//i=1;
	printf("using for loop\n");
	for(i=1;i<=num;i++)
		p=p*i;
	printf("factorial=%d",p);
	return 0;
}
