#include<stdio.h>
main()
{
	int m,n,i,j,temp,k;
	printf("\nEnter the number of rows");
	scanf("%d",&m);
	printf("\nEnter the number of column\n");
	scanf("%d",&n);
	int arr[m][n];
	printf("\nenter the elements in the array");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	printf("\nThe matrix is\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d\t",arr[i][j]);
		}
		printf("\n");
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			for (k=0;k<n-j-1;k++)
			if(arr[i][k]>arr[i][k+1])
			{
				temp=arr[i][k];
				arr[i][k]=arr[i][k+1];
				arr[i][k+1]=temp;
			}
		}
	}
	printf("\nThe matrix after row wise sorting\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d\t",arr[i][j]);
		}
		printf("\n");
	}
	for (j=0;j<n;j++) 
	{
		for (i=0;i<m;i++) {
			for (k=0;k<m-1-i;k++) {
				if (arr[k][j] > arr[k+1][j]) 
				{

					temp=arr[k+1][j];
					arr[k+1][j]=arr[k][j];
					arr[k][j]=temp;

				}
			}
		}
	}
	printf("\nThe matrix after column wise sorting\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d\t",arr[i][j]);
		}
		printf("\n");
	}
}
