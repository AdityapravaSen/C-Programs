#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int main()
{
	FILE *f1;
	char another,choice;
	long int recsize;
	struct item
	{
		char name[50];
		int code;
		int stock;
	};
	struct item i;
	//clrscr();
	f1=fopen("STOCKS.dat","rb+");
	if(f1==NULL)
	{
		f1=fopen("STOCKS.dat","wb+");
		if(f1==NULL)
		{
			printf("cannot open file");
			exit(0);
		}
	}
	recsize=sizeof(i);
	while(1)
	{
		printf("1.enter record\n");
		printf("2.list record\n");
		printf("0.Exit\n");
		fflush(stdin);
		choice=getche();
		switch(choice)
		{
			case '1':
				fseek(f1,0,SEEK_END);
				another='Y';
				while(another=='Y')
				{
					printf("enter item name\n");
					gets(i.name);
					printf("enter item code\n");
					scanf("%d",&i.code);
					printf("enter item stock\n");
					scanf("%d",&i.stock);
					fwrite(&i,recsize,1,f1);
					printf("enter another record?(Y/N)\n");
					another=getche();
					fflush(stdin);
				}
				break;
			case '2':
				rewind(f1);
				while(fread(&i,recsize,1,f1)==1)
				{
					printf("name:%s	 code:%d  stock:%d\n",i.name,i.code,i.stock);
				}
				break;
			case '0':
				fclose(f1);
				exit(0);
		}
	}
	fflush(stdin);
	getch();
	return 0;
}
