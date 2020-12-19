			//verifies condition inside if block
#include<stdio.h>
#include<stdlib.h>
int main()
{int a,f=0;
printf("Enter a number ");
scanf("%d",&a);
if(a%2==0)
{   f=1;
	if(f==1)
 	printf("Condition is verified.\n");
 	else
 	exit(1);
	
printf("Number is even.\n");
}
else
printf("Number is odd.");	

return 0;
}


