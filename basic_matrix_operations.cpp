			//matrix operations
#include<stdio.h>
void add(int arr1[][20],int arr2[][20],int r,int c)
{
	int i,j,sum[50][50];
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
			sum[i][j]=arr1[i][j]+arr2[i][j];
	}
	printf("\nSum of two matrices: \n");
    for (i = 0; i < r; ++i)
        for (j = 0; j < c; ++j) 
		{
            printf("%d   ", sum[i][j]);
            if (j == c - 1) 
			{
                printf("\n\n");
            }
        }
}
void sub(int arr1[][20],int arr2[][20],int r,int c)
{
	int i,j,sub[50][50];
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
			sub[i][j]=arr1[i][j]-arr2[i][j];
	}
	printf("\nSubstraction of two matrices: \n");
    for (i = 0; i < r; ++i)
        for (j = 0; j < c; ++j) 
		{
            printf("%d   ", sub[i][j]);
            if (j == c - 1) 
			{
                printf("\n\n");
            }
        }
}
void multiply(int first[][20], int second[][20], int r1, int c1, int r2, int c2) 
{
	int mult[10][10];
    for (int i = 0; i < r1; ++i) 
	{
        for (int j = 0; j < c2; ++j) 
		{
            mult[i][j] = 0;
        }
    }
	for (int i = 0; i < r1; ++i) {
        for (int j = 0; j < c2; ++j) 
		{
            for (int k = 0; k < c1; ++k) 
			{
                mult[i][j] += first[i][k] * second[k][j];
            }
        }
    }
    printf("\nOutput Matrix:\n");
    for (int i = 0; i < r1; ++i) 
	{
        for (int j = 0; j < c2; ++j) 
		{
            printf("%d  ", mult[i][j]);
            if (j == c2 - 1)
                printf("\n");
        }
    }
}

int main()
{
	int r1,c1,arr1[20][20],arr2[20][20],r2,c2;
	printf("Enter rows and column for the first matrix: ");
    scanf("%d %d", &r1, &c1);
    printf("Enter rows and column for the second matrix: ");
    scanf("%d %d", &r2, &c2);
	printf("\nEnter elements of matrix 1:\n");

    for (int i = 0; i < r1; ++i) {
        for (int j = 0; j < c1; ++j) {
            printf("Enter a%d%d: ", i + 1, j + 1);
            scanf("%d", &arr1[i][j]);
        }
    }
    printf("\nEnter elements of matrix 2:\n");

    for (int i = 0; i < r2; ++i) {
        for (int j = 0; j < c2; ++j) {
            printf("Enter b%d%d: ", i + 1, j + 1);
            scanf("%d", &arr2[i][j]);
        }
    }
    add(arr1,arr2,r1,c1);
    sub(arr1,arr2,r1,c1);
    multiply(arr1,arr2,r1,c1,r2,c2);
    return 0;
}
