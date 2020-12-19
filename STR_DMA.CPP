#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#include<malloc.h>
void main()
{
	int n;
	char *text;
	clrscr();
   //	printf("\nenter limit");
     //	scanf("%d",&n);
     //	text=(char*)malloc(n*sizeof(char));
	printf("enter text\n");
	gets(text);
	printf("%s",text);
	fflush(stdin);
	getch();
}