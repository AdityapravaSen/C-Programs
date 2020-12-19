		//n student record using structure
#include<stdio.h>
struct student
{
	char name[50];
	int roll;
	float marks;
};
int main()
{
	int i,n;
	printf("limit:");
	scanf("%d",&n);
	struct student s[n];
	for(i=0;i<n;i++)
	{
		printf("name:\n");
		scanf("%s",s[i].name);
		printf("roll and marks:\n");
		scanf("%d %f",&s[i].roll,&s[i].marks);
	}
	for(i=0;i<n;i++)
	{
		puts(s[i].name);
		printf("\nroll:%d\tmarks:%f\n",s[i].roll,s[i].marks);
	}
	return 0;
	fflush(stdin);
}
