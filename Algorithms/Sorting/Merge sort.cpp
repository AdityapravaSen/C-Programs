		//merge sort
#include<stdio.h>
void Merge(int a[],int left, int mid,int right )
{
	int i,j,k;
	int size1=mid-left+1;
	int size2=right -mid;
	
	int LeftArray[size1],RightArray[size2]; 		
	
	for(i=0;i<size1;i++)
		LeftArray[i]=a[left+i];
	
	for(j=0;j<size2;j++)
		RightArray[j]=a[mid+1+j];
	
	i=0,j=0,k=left; 			
	while(i<size1 && j<size2)
	{
			if(LeftArray[i]<=RightArray[j])
			{a[k]=LeftArray[i];
			i++;
			}
			else
			{a[k]=RightArray[j];
			j++;
			}
			k++;
		
	}

	while(i<size1)
	{
		a[k]=LeftArray[i];
		i++;
		k++;
	}
	
	while(j<size2)
	{	
		a[k]=RightArray[j];
		k++;
		j++;
	}
}

void Mergesort(int a[],int left,int right)
{
	if(left<right)
	{
		int mid=(left+(right-1))/2;   
		Mergesort(a,left,mid);
		Mergesort(a,mid+1,right);
		Merge(a,left,mid,right);
	}
}


int main()
{
 int a[100];
 int i;
 int n;
 printf("Enter the number of elements you want to enter ");
 scanf("%d", &n);
 printf("Enter %d elements into the array \n", n);
 
 for(i=0;i<n;i++)
	scanf("%d",&a[i]);
 Mergesort(a,0,n-1); //Calling Mergesort function
	
printf("\nSorted array is : ");
 	for(i=0;i<n;i++)
 	printf("  %d  ",a[i]);	
	 return 0;
}
