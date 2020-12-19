		//removing space from string
#include<stdio.h>
#include<string.h>
int main()
{
	char str[30],ch[30];
	int i,j=0;
	gets(str);
	for(i=0;str[i]!='\0';i++)
	{
		if(!(str[i]==' '))
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
