			//removing charecters from string
#include<stdio.h>
#include<string.h>
int main()
{
	char str[20],ch[20];
	int i,j=0;
	gets(str);
	for(i=0;str[i]!='\0';i++)
	{
		if((str[i]>='A' && str[i]<='Z')||(str[i]>='a' && str[i]<='z'))
		{
			ch[j]=str[i];
			j++;
		}
	}
	ch[j]='\0';
	strcpy(str,ch);
	puts(str);
	return 0;
}
