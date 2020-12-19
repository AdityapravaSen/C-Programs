			//string palindrome using DMA
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
	int i=0,len=0,f=0;
	char *text,*p;
	clrscr();
	printf("enter text\n");
	gets(text);
	p=text;
	while(*p!=NULL)
	{
		p++;
		len++;

	}
	p--;
	while(p>=text)
	{
		if(*p==*text)
		{
			f++;
			p--;
			text++;
		}
		else
			break;
	}
	if(f==(len/2)+1)
		printf("palindrome");
	else
		printf("not palindrome");
	getch();
}





