#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
	FILE *fse,*fst;
	clrscr();
	long int recsize_stock,recsize_item;
	char another,choice;
	struct item
	{
		int itmcode,itmqnty,rate,price;
		char itmname[50];
	};
	struct stock
	{
		int stkqnty,stkcode;
		char stkname[50];
	};
	struct item i;
	struct stock t;
	fse=fopen("SELL.dat","rb+");
	if(fse==NULL)
	{
		fse=fopen("SELL.dat","wb+");
		if(fse==NULL)
		{
			printf("cannot open file");
			exit(0);
		}
	}
	fst=fopen("STOCKS.dat","rb+");
	if(fst==NULL)
	{
		fst=fopen("STOCKS.dat","wb+");
		if(fst==NULL)
		{
			printf("cannot open file");
			exit(0);
		}
	}
	recsize_item=sizeof(i);
	recsize_stock=sizeof(t);
	/*while(fread(&t,recsize_stock,1,fst)==1)
	{
		printf("name:%s  code:%d stock:%d\n",t.stkname,t.stkqnty,t.stkcode);
	}*/
	while(1)
	{
		printf("\n1.tally record\n");
		printf("\n2.show record\n");
		printf("\n0.exit\n");
		choice=getche();
		switch(choice)
		{
			case '1':
				another='Y';
				while(another=='Y')
				{
					fseek(fse,0,SEEK_END);
					printf("\nenter item name:\n");
					gets(i.itmname);
					printf("\nenter item code:\n");
					scanf("%d",&i.itmcode);
					fflush(stdin);
					//printf("name:%s code:%d\n",i.itmname,i.itmcode);
					while(fread(&t,recsize_stock,1,fst)==1)
					{
						if(t.stkcode==i.itmcode)
						{
							printf("item found.\n");
							printf("\nenter quantity\n");
							scanf("%d",&i.itmqnty);
							if(i.itmqnty<=t.stkqnty)
							{
								printf("item is in range.\n");
								printf("\nenter rate\n");
								scanf("%d",&i.rate);
								i.price=i.rate*i.itmqnty;
								fwrite(&i,recsize_item,1,fse);
							}
							else
							{
								printf("\nquantity not in stock.\n");
								break;
							}
						}
						else
						{
							printf("\nitem code not found\n");
							break;
						}
					}
					printf("\nenter another record(Y/N)?\n");
					another=getche();
				}
				break;
			case '2':
				 rewind(fse);
				 while(fread(&i,recsize_item,1,fse)==1)
				 {
					printf("\nitem name is %s and code is %d\n",i.itmname,i.itmcode);
					printf("\nthe price is %d",i.price);
				 }
				 break;
			case '0':
				 fclose(fse);
				 fclose(fst);
				 exit(0);
		}
	}
	fflush(stdin);
	getch();
}