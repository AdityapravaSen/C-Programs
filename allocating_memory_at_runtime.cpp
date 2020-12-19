			//dynamically allocate memory at runtime
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int *ptr1;
	char *ptr2;
	float *ptr3;
	ptr1=(int*)malloc(1*sizeof(int));
	ptr2=(char*)malloc(1*sizeof(char)*1);
	ptr3=(float*)malloc(1*sizeof(float));
	printf("enter values:\n");
	scanf("%d %c %f",ptr1,ptr2,ptr3);
	printf("%d %c %f",*ptr1,*ptr2,*ptr3);
	return 0;
}
