			//sum of digits in a string
#include<stdio.h>
int main()
{
	char str[20];
	int i,sum=0;
	gets(str);
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]>='0' && str[i]<='9')
			sum+=(str[i]-'0');
	}
	printf("%d",sum);
	return 0;
}
