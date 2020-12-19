		//length of string without strlen()
#include<stdio.h>
int main()
{
	char str[10];
	int i,flag=0;
	gets(str);
	for(i=0;str[i]!='\0';i++)
		flag++;
	printf("length:%d",flag);
	return 0;
}
