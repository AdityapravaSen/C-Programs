#include<conio.h>
#include<stdio.h> 
int main()
{
	int n,rev,t;
	printf("enter no.");
	scanf("%d",&n);
	rev=0;
	t=n;
	printf("using while loop\n");
	while(t!=0)
	{
		rev=rev*10+t%10;
		t=t/10;
	}
	if(n==rev)
	{
		printf("the no. %d is palindrome\n",n);
	}
	t=n;
	rev=0;
	printf("using for loop\n");
	for(rev=0;t>0;t=t/10)
		rev=rev*10+t%10;
	if(n==rev)
	{
		printf("the no. %d is palindrome\n",n);
	}
	return 0;
	getch();
}
