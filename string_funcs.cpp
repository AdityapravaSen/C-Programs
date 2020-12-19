		//utility of strlen() strcpy() strcat() strcmp()
#include<stdio.h>
#include<string.h>
int main()
{
	char str[20],cpy[20];
	int l,result;
	printf("enter string:\n");
	gets(str);
	l=strlen(str);
	printf("length is:%d\n",l);
	strcpy(cpy,str);
	printf("string after copying:\n");
	puts(cpy);
	char cat[20];
	printf("enter text to concatenate:\n");
	gets(cat);
	strcat(str,cat);
	printf("string after concatinating:\n");
	puts(str);
	result=strcmp(str,cat);
	printf("result after comparing 2 strings:%d",result);
	return 0;
	
}
