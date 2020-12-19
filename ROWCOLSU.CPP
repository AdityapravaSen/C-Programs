		     //sum of row and col of matrix using DMA
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void main()
{
	int i,j,m,n, **arr,sum=0;
	clrscr();
	printf("enter order of matrix");
	scanf("%d %d",&m,&n);
	printf("enter values\n");
	arr=(int**)malloc(m*sizeof(int*));
	for(i=0;i<m;i++)
	{
		arr[i]=(int*)malloc(n*sizeof(int));
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			//printf("enter values\n");
			scanf("%d",(*(arr+i)+j));
		}
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			sum=sum+ *(*(arr+i)+j);
		}
		printf("sum of row %d is %d\n",i+1,sum);
		sum=0;
	}
	sum=0;
	for(j=0;j<n;j++)
	{
		for(i=0;i<m;i++)
		{
			sum=sum+ *(*(arr+i)+j);
		}
		printf("sum of col %d is %d\n",j+1,sum);
		sum=0;
	}
	getch();
}


