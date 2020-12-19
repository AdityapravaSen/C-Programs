#include<stdio.h>
#include<conio.h>
void main()
{
	int i,rev=0,temp,n,arr[6];
	clrscr();
	for(i=0;i<6;i++)
	{
		printf("enter nos.:");
		scanf("%d",&arr[i]);
	}
	for(i=0;i<6;i++)
	{
		n=arr[i];
		rev=0;
		while(n!=0)
		{
		      rev= rev*10;
		      rev= rev+(n%10);
		      n=n/10;
		}
		printf("the reversed no. is:%d\n",rev);
	}
	getch();
}

