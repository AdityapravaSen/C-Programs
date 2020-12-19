		//max element in row and column
#include<stdio.h>
void max_element_row(int arr[][20],int r,int c)
{
	int i=0,j,max=0;
	int result[r];
	while(i<r)
	{
		for(j=0;j<c;j++)
		{
			if(arr[i][j]>max)
			{
				max=arr[i][j];
			}
		}
		result[i]=max;
		max=0;
		i++;
	}
	printf("\nmax element in each row:\n");
	for(i=0;i<r;i++)
		printf("%d\t",result[i]);
}
void max_element_column(int arr[][20],int r,int c)
{
	int i,j,max;
	printf("\nmax element in each column:\n");
	for(i=0;i<c;i++)
	{
		max=arr[0][i];
		for(j=0;j<r;j++)
		{
			if(arr[i][j]>max)
			{
				max=arr[j][i];
			}
		}
		printf("%d\t",max);
	}
}
int main()
{
	int arr[20][20],i,j,r,c;
	printf("enter rows and columns:\n");
	scanf("%d %d",&r,&c);
	printf("\nenter data:\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
			scanf("%d",&arr[i][j]);
	}
	max_element_row(arr,r,c);
	max_element_column(arr,r,c);
	return 0;
}
