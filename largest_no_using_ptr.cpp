			//biggest of 3 nos. using pointer
#include<stdio.h>
int main()
{
	int a,b,c,*p,*q,*r;
	scanf("%d %d %d",&a,&b,&c);
	p=&a;
	q=&b;
	r=&c;
	if(*p>*q && *p>*r)
		printf("%d",*p);
	else if(*q>*p && *q>*r)
		printf("%d",*q);
	else
		printf("%d",*r);
	return 0;
}
