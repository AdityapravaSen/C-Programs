			//student information using structure
#include<stdio.h>
struct student
{
	char name[50];
	int roll;
	float marks;
};
int main()
{
	struct student s;
	printf("name:\n");
	gets(s.name);
	printf("roll and total marks:\n");
	scanf("%d %f",&s.roll,&s.marks);
	printf("\nrecord-\n");
	puts(s.name);
	printf("\n");
	printf("roll:%d\tmarks:%f",s.roll,s.marks);
	return 0;
}
