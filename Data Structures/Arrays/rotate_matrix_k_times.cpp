		//rotating matrix k times
#include<stdio.h>
void displaymatrix(int arr[][20],int n,int m)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
}
int main()
{
	int arr[20][20],n,m,i,j,k,t;
	printf("enter rows and columns:\n");
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
			scanf("%d",&arr[i][j]);
	}
	printf("matrix-\n");
	displaymatrix(arr,n,m);
	int temp[m];
	printf("no. of rotations:\n");
	scanf("%d",&k);
	k=k%m;
	for(i=0;i<n;i++)
	{
		for(t=0;t<m-k;t++)
		{
			temp[t]=arr[i][t];
		}
		for(j=m-k;j<m;j++)
		{
			arr[i][j-m+k]=arr[i][j];
		}
		for(j=k;j<m;j++)
		{
			arr[i][j]=temp[j-k];
		}
	}
	printf("rotated matrix:\n");
	displaymatrix(arr,n,m);
	return 0;
}
