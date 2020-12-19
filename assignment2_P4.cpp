#include<stdio.h>
int factorial(int n)
{
	int i,fact=1;
	for(i=1;i<=n;i++)
		fact=fact*i;
	return fact;
}
int permutation(int n,int r)
{
	double ans;
	int p=n-r;
	ans=(double)factorial(n)/factorial(p);
	return ans;
}
int combination(int n,int r)
{
	double ans;
	ans=(double)permutation(n,r)*factorial(r);
	return ans;
}
int main()
{
	int n,r,f;
	double p,c;
	printf("n and r:\n");
	scanf("%d %d",&n,&r);
	f=factorial(n);
	p=permutation(n,r);
	c=combination(n,r);
	printf("factorial=%d	permutation=%lf	combination=%lf",f,p,c);
	return 0;
}
