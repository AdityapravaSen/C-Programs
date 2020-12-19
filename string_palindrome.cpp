		//checking whether string is palindrome
#include<stdio.h>
#include<string.h>
int main()
{
	char str[20];
	int i,flag=0;
	gets(str);
	int l=strlen(str)-1;
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]!=str[l-i])
			flag++;
	}
	if(flag)
		printf("not plindrome");
	else
		printf("palindrome");
	
	return 0;
}
