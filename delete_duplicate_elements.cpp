		//remove duplicate elements
#include<stdio.h>
int main()
{
	int arr[10],i,j,c,n,flag=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(arr[i]==arr[j])
			{
				for(c=j;c<n;c++)
				{
					arr[c]=arr[c+1];
				}
				n--;
				j--;
			}
		}
	}
	for(c=0;c<n;c++)
		printf("%d",arr[c]);
	return 0;
	
}
