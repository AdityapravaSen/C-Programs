#include<stdio.h>
int gcd(int num1,int num2)
{
	int numerator,denominator,remainder;
	if (num1 > num2)
    {
        numerator = num1;
        denominator = num2;			//6.
    }
    else
    {
        numerator = num2;
        denominator = num1;
    }
    remainder = numerator % denominator;
    while (remainder != 0)
    {
        numerator   = denominator;
        denominator = remainder;
        remainder   = numerator % denominator;
    }
    return denominator;
}
int lcm(int num1,int num2)
{
	int a,l;
	a=gcd(num1,num2);
	l=(num1*num2)/a;
	return l;
}
int main()
{
	int num1,num2,a,b;
	scanf("%d %d",&num1,&num2);
	a=gcd(num1,num2);
	b=lcm(num1,num2);
	printf("gcd=%d	lcm=%d",a,b);
	return 0;
} 
