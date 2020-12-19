		//10 student record using structure
#include<stdio.h>
struct student
{
	char name[50];
	int roll;
	float marks;
}s[10];
int main()
{
	int i;
	for(i=0;i<10;i++)
	{
		printf("name:\n");
		scanf("%s",s[i].name);
		printf("roll and marks:\n");
		scanf("%d %f",&s[i].roll,&s[i].marks);
	}
	for(i=0;i<10;i++)
	{
		puts(s[i].name);
		printf("\nroll:%d\tmarks:%f\n",s[i].roll,s[i].marks);
	}
	return 0;
}
