			//capitalize first and last letter of string
#include<stdio.h>
#include<string.h>
int main()
{
	char str[20];
	int l;
	gets(str);
	l=strlen(str)-1;
	str[0]=str[0]-32;
	str[l]-=32;
	puts(str);
	return 0;
}
