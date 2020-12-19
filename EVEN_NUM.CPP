#include<stdio.h>
#include<conio.h>

void main()
{
	int arr[6],i,sum=0;
	clrscr();
	for(i=0;i<6;i++)
	{
		printf("enter nos.");
		scanf("%d",&arr[i]);
	}
	for(i=0;i<6;i++)
	{	if(arr[i]%2==0)
		{
			printf("the no. %d\n",arr[i]);
			sum=sum+arr[i];
		}
	}
	printf("the sum is %d",sum);
	getch();
}

