		  //to read contents of stu_rec.dat
#include<conio.h>
#include<stdio.h>
void main()
{
	FILE *f1;
	struct student
	{
		char name[40];
		int roll,m1,m2,m3;
	};
	struct student s;
	int recsize=sizeof(s);
	f1=fopen("stu_rec.dat","r");
	while(fread(&s,recsize,1,f1))
	{
		printf("\nname-%s\n",s.name);
		printf("roll no.-%d\n",s.roll);
		printf("marks in sub1-%d\n",s.m1);
		printf("marks in sub2-%d\n",s.m2);
		printf("marks in sub3-%d\n",s.m3);
	}
	fclose(f1);
	fflush(stdin);
	getchar();
}