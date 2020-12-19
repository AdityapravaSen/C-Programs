		//sum of boundary elements of matrix
#include<stdio.h>
int main()
{
	int arr[20][20],sum=0,r,c,i,j;
	printf("enter rows and columns:\n");
	scanf("%d %d",&r,&c);
	printf("enter data:\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
			scanf("%d",&arr[i][j]);
	}
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			if(i==0 || j==0 || i==r-1 || j==c-1)
				sum+=arr[i][j];
		}
	}
	printf("sum: %d",sum);
	return 0;
}
