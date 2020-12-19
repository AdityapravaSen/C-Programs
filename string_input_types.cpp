		//different ways to input string
#include<stdio.h>
#include<string.h>
int main()
{
	char str[20];
	printf("input string 1:\n");
	gets(str);
	printf("using gets():\n");
	puts(str);
	printf("\n");
	printf("input string 2:\n");
	scanf("%s",str);
	printf("using scanf():\n");
	puts(str);
	//printf("\n");
	return 0;
}
