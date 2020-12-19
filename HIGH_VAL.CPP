#include<stdio.h>
#include<conio.h>

void main()
{
	int arr[50],i,temp,n;
	clrscr();
	printf("enter limit");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter nos.");
		scanf("%d",&arr[i]);
	}
	temp=arr[0];
	for(i=1;i<n;i++)
	{
		if(arr[i]>temp)
		temp=arr[i];
	}
	printf("the highest value is %d",temp);
	getch();
}