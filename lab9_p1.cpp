		//checking nos. without using arithmatic or comparison operators
#include<stdio.h>
int main()
{int a,b;
printf("Enter two numbers to find if they are equal or not. ");
scanf("%d%d",&a,&b);
if((a & ~b)==0 && (~a & b)==0)
printf("\nThey are the same.");
else
printf("\nThey are not the same.");
return 0;	
}

