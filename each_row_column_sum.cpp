		//sum of each row and column
#include<stdio.h>
int main()
{
	int arr[20][20],i,j,r,c,sum=0;
	printf("enter rows and columns:\n");
	scanf("%d %d",&r,&c);
	printf("enter data:\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
			scanf("%d",&arr[i][j]);
	}
	for (i = 0; i < r; ++i) 
        {
            for (j = 0; j < c; ++j) 
            {
                sum = sum + arr[i][j] ;
            }
 
            printf("Sum of the %d row is = %d\n", i+1, sum);
            sum = 0;
 
        }
        sum = 0;
    for (j = 0; j < c; ++j) 
    {
        for (i = 0; i < r; ++i)
        {
            sum = sum + arr[i][j];
        }
 
        printf("Sum of the %d column is = %d\n", j+1, sum);
        sum = 0;
 
    }
 
}
