		//read and write from binary file
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int main()
{
	FILE *f1;
	char c;
	printf("data input\npress e when done\n");
	f1=fopen("input.bin","w");
	while((c=getchar())!='e')
		putc(c,f1);
	fclose(f1);
	printf("\ndata output\n");
	f1=fopen("input.bin","r");
	while((c=getc(f1))!=EOF)
	{
		printf("%c",c);
	}
	fclose(f1);
	return 0;
}
