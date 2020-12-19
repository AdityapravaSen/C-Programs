		//concatenate and compare 2 strings
#include<stdio.h>
#include<string.h>
int main()
{
	char str1[20],str2[20],temp[20];
	int result;
	printf("enter 2 strings:\n");
	gets(str1);
	gets(str2);
	strcpy(temp,str1);
	strcat(str1,str2);
	printf("result after concatenating 2 strings:\n");
	puts(str1);
	result= strcmp(temp,str2);
	printf("result after comparing 2 strings:%d\n",result);
	return 0;
}
