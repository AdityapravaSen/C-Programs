		     //enter student records
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void main()
{
	FILE *f1,*f2;
	clrscr();
	printf("data input\n");
	struct student
	{
		char name[40];
		int roll,m1,m2,m3;
	};
	struct student s;
	char another;
	int recsize=sizeof(s);
	printf("do you want to enter record(Y/N):\n");
	another=getche();
	if(another=='Y')
	{
	f1=fopen("stu_rec.dat","wb");
	if(f1==NULL)
	{
		puts("cannot open file");
		exit(0);
	}
	fseek(f1,0,SEEK_END);
	another='Y';
	while(another=='Y')
	{
		printf("\nenter name,rollno., marks of sub1,marks of sub2,marks of sub3\n");
		scanf("%s %d %d %d %d",s.name,&s.roll,&s.m1,&s.m2,&s.m3);
		fwrite(&s,recsize,1,f1);
		printf("\nadd another record(Y/N):\n");
		another=getche();
	}
     //	fclose(f1);
	}
      //	printf("\ndo you wish to see records(Y/N):\n");
     //	another=getche();
    /*	if(another=='Y')
	{
       //		f2=fopen("stu_rec.dat","r");
	       //	rewind(f2);
		if(f2==NULL)
		{
			puts("cannot open file");
			exit(0);
		}
    */
		rewind(f1);
		while(fread(&s,recsize,1,f1)==1)
		{
			printf("\nname-%s\n",s.name);
			printf("roll no.-%d\n",s.roll);
			printf("marks in sub1-%d\n",s.m1);
			printf("marks in sub2-%d\n",s.m2);
			printf("marks in sub3-%d\n",s.m3);
		}
		fclose(f1);

	fflush(stdin);
	getch();
}