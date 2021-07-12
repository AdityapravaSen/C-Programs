#include<stdio.h>
#include<limits.h>
int s[100][100];
void matrix_chain(int dim[],int n)
{
	int m[n+1][n+1],i,j,k,l,q;
	for (i=1;i<=n;i++)
	{
		m[i][i]=0;
		s[i][i]=0;
	}
	for(l=2;l<=n;l++)
	{
		for(i=1;i<=n-l+1;i++)
		{
			j=i+l-1;
			m[i][j]=INT_MAX;
			for(k=i;k<=j-1;k++)
			{
				q=m[i][k]+m[k+1][j]+dim[i-1]*dim[k]*dim[j];
				if(q<m[i][j])
				{
					m[i][j]=q;
					s[i][j]=k;
				}
			}
		}
	}
	printf("\nMULTIPLICATION MATRIX IS\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(i>j)
			{
				printf(" \t");
			}
			else
			{
				printf("%d\t",m[i][j]);
			}
		}
		printf("\n");
	}
	printf("\nS MATRIX IS\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(i>j)
			{
				printf(" \t");
			}
			else
			{
			printf("%d\t",s[i][j]);
			}	
		}
		printf("\n");
	}
	printf("\nminimum no of multiplication%d\n",m[1][n]);	
}
void fully_parenthesize(int i,int j)
{
	if(i==j)
	{
		printf("A%d",i);
	}
	else
	{
		printf("(");
		fully_parenthesize(i,s[i][j]);
		fully_parenthesize(s[i][j]+1,j);
		printf(")");
	}
}
main()
{
	int l,n,i;
	printf("Enter number of matrices : ");
	scanf("%d",&n);
	l=n+1;
	int dim[l];
	printf("\nEnter dimensions\n");
	for(i=0;i<l;i++)
	{
		scanf("%d",&dim[i]);
	}
	matrix_chain(dim,n);
	printf("\nmultiplication sequence\n");
	fully_parenthesize(1,n);
}
