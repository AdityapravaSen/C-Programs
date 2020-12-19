		//frequency of each array element
#include<stdio.h>
int main()
{
	int i,j,n,flag=0,arr[10];
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	int fr[n],check=-1;
	for(i=0;i<n;i++)
	{
		flag=1;
		for(j=i+1;j<n;j++)
		{
			if(arr[i]==arr[j])
			{
				flag++;
				fr[j]=check;
			}
		}
		if(fr[i]!=check)
			fr[i]=flag;
	}
	printf("array-2:\n");
	for(int i = 0; i <n; i++){    
        if(fr[i] != check){    
            printf("%d ",fr[i]);    
    
        }    
    }    
	return 0;
}
