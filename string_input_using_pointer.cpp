		//string input using pointer
#include<stdio.h>
#include<stdlib.h>
int main()
{
	char *text;
	text=(char*)malloc(50*sizeof(char));
	gets(text);
	puts(text);
	return 0;
}
