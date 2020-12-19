			//c program to demontrate types of pointers 
#include<stdio.h> 
#include<stdlib.h>

int *dangling() 
{ 
	int x = 5; 
	return &x; 
} 

int main() 
{ 
	int *p = dangling(); 
	fflush(stdin);
	printf("dangling pointer->\n");  
	printf("%d", *p); 
	int x=4;
	void *ptr;
	ptr=&x;
	printf("\nvoid pointer-.\n");
	printf("%d",*(int*)ptr);
	int *r=NULL;
	printf("\nNULL pointer->\n");
	printf("%p",r);
	int *q;
	printf("\nwilp pointer->\n");
	printf("%p",q);
	return 0; 
} 

