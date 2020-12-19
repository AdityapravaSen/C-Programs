		//upper and lower triangle
#include<stdio.h>
void lower_t(int arr[][20],int r,int c)
{
	int i,j;
	for(i=0;i<r;i++)
	{
		printf("\n");
		for(j=0;j<c;j++)
		{
			if(j>=i)
				printf("%d  ",arr[i][j]);
			else
				printf("0  ");	
		}
	}
}
void upper_t(int arr[][20],int r,int c)
{
	int i,j;
	for(i=0;i<r;i++)
	{
		printf("\n");
		for(j=0;j<c;j++)
		{
			if(i>=j)
				printf("%d  ",arr[i][j]);
			else
				printf("0  ");	
		}
	}
}
int main()
{
	int arr[20][20],r,c,i,j;
	printf("enter rows and columns:\n");
	scanf("%d %d",&r,&c);
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	lower_t(arr,r,c);
	printf("\n\n");
	upper_t(arr,r,c);
	return 0;
}

