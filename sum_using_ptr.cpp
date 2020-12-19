			//sum of two variabes using pointer
#include<stdio.h>
int main()
{
	int n1,n2,*p,*q;
	scanf("%d %d",&n1,&n2);
	p=&n1;
	q=&n2;
	printf("sum:%d",*p+*q);
	return 0;
}
