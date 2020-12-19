		//swaping without third variable using pointer
#include<stdio.h>
int main()
{
	int a,b,*p,*q;
	scanf("%d %d",&a,&b);
	p=&a;
	q=&b;
	*p=*p+*q;
	*q=*p-*q;
	*p=*p-*q;
	printf("%d\t%d",*p,*q);
	return 0;
}
