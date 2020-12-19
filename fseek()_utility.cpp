		//showing utility of fseek()
#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *fptr;
	printf("contents of file:\n");
	fptr=fopen("program.txt","r");
	fseek(fptr,0,SEEK_END);
	printf("%d",ftell(fptr));
	return 0;
}
