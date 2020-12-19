		//check 2 arrays are same
#include<stdio.h>
int main()
{
	int arr1[10],arr2[10],i,flag=0,n1,n2;
	printf("limit for 2 arrays\n");
	scanf("%d %d",&n1,&n2);
	for(i=0;i<n1;i++)
		scanf("%d",&arr1[i]);
	for(i=0;i<n2;i++)
		scanf("%d",&arr2[i]);
	if(n1!=n2)
		flag++;
	else
	{
		for(i=0;i<n1;i++)
		{
			if(arr1[i]!=arr2[i])
				flag++;
		}	
	}
	if(flag==0)
		printf("same array\n");
	else
		printf("not same array\n");
	return 0;	
}
