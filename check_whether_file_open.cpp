			//checking whether file is opened or not
#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *f;
	f=fopen("program.txt","a");
	fprintf(f,"successfully opened file");
	fclose(f);
	f=fopen("program.txt","r");
	char c=fgetc(f);
	while(c!=EOF)
	{
		printf("%c",c);
		c=fgetc(f);
		//printf("\n");
	}
	fclose(f);
	return 0;
}
