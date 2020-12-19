#include <stdio.h>
int main()
{
   int n, t, p=1, remainder;

   printf("Enter an integer\n");
   scanf("%d", &n);

   t = n;

   while (t != 0)
   {
      remainder = t % 10;
      p      =  p* remainder;
      t         = t / 10;
   }

   printf("product of digits using while loop is :%d\n",p);
   t=n;
   for(p=1;n>0;n=n/10)
    {
		   p = p * (n%10);
	}
    printf("product of digits using for loop is :%d\n",p);

   return 0;
}
