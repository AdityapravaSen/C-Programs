			//sum of arr using DMA
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,i,sum=0;
	int *arr;
	scanf("%d",&n);
	arr=(int*)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
	{
		scanf("%d",arr+i);
	}
	for(i=0;i<n;i++)
		sum+=*(arr+i);
	printf("sum:%d",sum);
	return 0;
}
