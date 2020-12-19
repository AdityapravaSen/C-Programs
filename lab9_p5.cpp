		//dividing by 4 without / operator
#include<stdio.h>
#include<stdlib.h>
unsigned division (unsigned x, unsigned y)
{
	if(x<y)
	{printf("Remainder is %d\n",x);
    return 0;
	}
return 1 +division(x-y,y);	
}
int divide(int x,int y)
{if(y==0)
{printf("Error. Divisible by 0.");
exit(1);
}
int sgn=1;
if(x*y<0)
sgn=-1;
return sgn*division(abs(x),abs(y));
}
int main(void)
{int dividend,divisor=4;
printf("Enter any integer to be divided by 4.\n");
scanf("%d",&dividend);
printf("Quotient is %d\n ",divide(dividend,divisor));
return 0;
}

