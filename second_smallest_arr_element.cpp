		//second smallest array element
#include<stdio.h>
int main()
{
	int arr[10],i,j,temp,xchanges=0,n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	for(i=0;i<n-1;i++)
	{
		xchanges=0;
		for(j=0;j<n-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp=arr[i];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
				xchanges++;
			}
		}
		if(xchanges==0)
			break;
	}
	printf("second smallest element:%d",arr[1]);
	return 0;
}
