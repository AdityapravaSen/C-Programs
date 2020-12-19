	//length without strlen()
#include<stdio.h>
int stringLength(const char *str)
{
	int len;
	for(len=0;str[len]!='\0';len++);
	return len;
}
int main()
{
	char a[100];
	printf("Enter a string ");
	gets(a);
	printf("string length of %s is %d",a,stringLength(a));
}

