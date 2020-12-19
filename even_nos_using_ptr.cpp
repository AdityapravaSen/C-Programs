			//even nos. in a given range
#include<stdio.h>
int main()
{
	int i,low,high,*p,*q;
	printf("lower and upper limit:\n");
	scanf("%d %d",&low,&high);
	p=&low;
	q=&high;
	for(i=*p;i<=*q;i++)
	{
		if(i%2==0)
			printf("%d\t",i);
	}
	return 0;
}
