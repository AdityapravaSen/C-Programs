		//max value of unsigned int using ones compliment
#include<stdio.h>
int main()
{unsigned int max;
max=0x00;
max=~max;
printf("Maximum value : %X (Decimal value: %u )\n",max,max);
return 0;
}


