		//merge sort
#include<stdio.h>
int main()
{
	int arr1[20],arr2[20],arr3[40];
	int i,j,k;
	int max1,max2;
	printf("limit of list1 and list2:\n");
	scanf("%d%d",&max1,&max2);
	printf("elements in list1 in sorted order:\n");
	for(i=0;i<max1;i++)
		scanf("%d",&arr1[i]);
	printf("elements in list2 in sorted order:\n");
	for(i=0;i<max2;i++)
		scanf("%d",&arr2[i]);
	i=0;
	j=0;
	k=0;
	while((i<max1)&&(j<max2))
	{
		if(arr1[i]<arr2[j])
			arr3[k++]=arr1[i++];
		else
			arr3[k++]=arr2[j++];
	}
	while(i<max1)
		arr3[k++]=arr1[i++];
	while(j<max2)
		arr3[k++]=arr2[j++];
	printf("sorted array:\n");
	for(i=0;i<max1+max2;i++)
	{
		printf("%d ",arr3[i]);
	}
	return 0;
}
