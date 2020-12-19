			//largest among n nos. using DMA
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,i;
	int *arr;
	scanf("%d",&n);
	arr=(int*)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
	{
		scanf("%d",arr+i);
	}
	for(i=0;i<n;i++)
	{
		if(*arr<*(arr+i))
			*arr=*(arr+i);
	}
	printf("largest no.: %d",*arr);
	return 0;
}
