		//open a file write in it and close it
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n;
	FILE *fptr;
	fptr=fopen("program.txt","w");
	if(fptr==NULL)
	{
		printf("error!");
		exit(1);
	}
	printf("enter no.:\n");
	scanf("%d",&n);
	fprintf(fptr,"%d",n);
	fclose(fptr);
	return 0;
}
