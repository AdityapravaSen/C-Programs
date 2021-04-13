      struct book
      {
	  char bid[8];
       char bname[25];
	char auth[30];
	char publ[30];
      }b;

      long int bsize=sizeof(struct book);
      FILE *fb;
/*===================================================================*/
  void bookadd(void)                          //Function definition
  {
       void valid1(char *);                   //Function prototype
       void valid2(char *);                   //      do
       void valid4(char *);                   //      do
       char temp[25],temp1[30],temp2[30], ans='y',id[8];
       int i,j;
       while(ans=='y'||ans=='Y')
       {
	     textbackground(8);
			   i=1;
			   j=0;
		      clrscr();
		      if((fb=fopen("d:\\lbrary\\book.dat","rb+"))==NULL)
		      {
			    strcpy(b.bid,"B10001");       //To auto generate
		      }                                   //purpose for book
		      else                                //id.
		      {
			    rewind(fb);
			    while(fread(&b,bsize,1,fb)==1);
			    for(i=1;b.bid[i]!='\0';i++,j++) //Auto generating
			    {                               //book id.
				id[j]=b.bid[i];
			    }
		       id[j]='\0';
		       i=atoi(id);
		       i++;
		       itoa(i,id,10);
		       strcpy(b.bid,"B");
		       strcat(b.bid,id);
		     }
	 gotoxy(30,3);
	 textcolor(YELLOW);
	 cprintf("BOOK ENTRY FORM");
	 gotoxy(29,4);
	 cprintf("=================");

	 textcolor(BLUE);
	 gotoxy(15,10);
	 cprintf("THE BOOK CODE:");
	 gotoxy(47,10);
	 textbackground(CYAN);
	 cprintf("           ");
	 gotoxy(48,10);
	 cprintf("%s",b.bid);

	 gotoxy(15,12);
	 textbackground(8);
	 cprintf("ENTER BOOK NAME: ");
	 gotoxy(47,12);
	 textbackground(CYAN);
	 cprintf("                     ");
	 gotoxy(48,12);
	 fflush(stdin);
	 gets(temp);
	 valid1(temp);                                      //Validation call
	 valid4(temp);                                      //    do
	 strcpy(b.bname,temp);
	 flushall();

	 gotoxy(15,14);
	 textbackground(8);
	 cprintf("ENTER AUTHOR NAME: ");
	 gotoxy(47,14);
	 textbackground(CYAN);
	 cprintf("                   ");
	 gotoxy(48,14);
	 fflush(stdin);
	 gets(temp1);
	 valid1(temp1);                                     //Validation call
	 valid4(temp1);                                     //     do
	 valid2(temp1);                                     //     do
	 strcpy(b.auth,temp1);
	 flushall();

	 gotoxy(15,16);
	 textbackground(8);
	 cprintf("ENTER PUBLISHER NAME: ");
	 gotoxy(47,16);
	 textbackground(CYAN);
	 cprintf("                      ");
	 gotoxy(48,16);
	 fflush(stdin);
	 gets(temp2);
	 valid1(temp2);                                     //Validation call
	 valid4(temp2);                                     //     do
	 strcpy(b.publ,temp2);
	 flushall();

	fclose(fb);
	fb=fopen("d:\\lbrary\\book.dat","ab+");
	fwrite(&b,bsize,1,fb);
	fclose(fb);
	gotoxy(29,22);
	textbackground(8);
	textcolor(RED);
	cprintf("Any more?(Y/N):");
	gotoxy(44,22);
	textbackground(YELLOW);
	cprintf("    ");
	gotoxy(45,22);
	scanf("%c",&ans);
	flushall();
      }
  return;                                     //Return to bookmenu
  }
/*===================================================================*/
    void bookdel(void)                        //Function definition
    {
       char ans='y',reply;
       char bid[8];
       int flag;
       FILE *ft;
       while(ans=='y'||ans=='Y')
       {
	      textbackground(8);
	      textcolor(CYAN);
	      flag=0;
	      clrscr();
	      gotoxy(25,3);
	      printf(" ^^^^^^^^BOOK DELETION^^^^^^^^^ ");
	      gotoxy(32,4);
	      printf("==================");
	      gotoxy(25,18);
	      printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
	      gotoxy(27,8);
	      printf("ENTER BOOK CODE: ");
	      fflush(stdin);
	      gets(bid);
	      flushall();
	      fb=fopen("d:\\lbrary\\book.dat","rb+");
	      while(fread(&b,bsize,1,fb)==1)
	      {
		   if(strcmpi(bid,b.bid)==0)
		   flag=1;
	      }
	      if(flag==1)
	      {
		 rewind(fb);
		 ft=fopen("d:\\lbrary\\temp.dat","wb+");
		 while(fread(&b,bsize,1,fb)==1)
		 {
		   if(strcmpi(bid,b.bid)!=0)
		   {
			 fwrite(&b,bsize,1,ft);
		   }
		   else
		   {
			gotoxy(27,10);
			printf("THE BOOK NAME:%s",b.bname);
			gotoxy(27,12);
			printf("AUTHOR NAME  :%s",b.auth);
			gotoxy(27,14);
			printf("THE PUBLISHER:%s",b.publ);
			gotoxy(27,16);
			printf("WISH TO DELETE?(Y/N):");
			scanf("%c",&reply);
			flushall();
			if(reply=='n'||reply=='N')
			{
			  fwrite(&b,bsize,1,ft);
			}
		   }
		 }

		  fclose(fb);
		  fclose(ft);
		  remove("d:\\lbrary\\book.dat");
		  rename("d:\\lbrary\\temp.dat","d:\\lbrary\\book.dat");
	       }
	    if(flag==1)
	    {
		 gotoxy(27,20);
		 printf(" ANY MORE?(Y/N):");
		 scanf("%c",&ans);
		 flushall();
	    }
	    if(flag==0)
	    {
		 fclose(fb);
		 gotoxy(27,20);
		 printf("*Invalid code!! ANY MORE?[Y/N]:");
		 fflush(stdin);
		 scanf("%c",&ans);
	    }
	 }
  return;                                     //Return to bookmenu()
  }
/*===================================================================*/
  void bookmod(void)                              //Function definition
  {
       void valid1(char *);                             //Function prototype
       void valid2(char *);                             //      do
       void valid4(char *);                             //      do
       char temp[25],temp1[30],temp2[30],did[8],ans='y';
       int i;
       while(ans=='y'||ans=='Y')
       {
	    clrscr();
	    i=0;
	    gotoxy(26,6);
	    printf("***BOOK MODIFICATION SCREEN***");
	    gotoxy(26,22);
	    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	    gotoxy(26,8);
	    printf("ENTER BOOK CODE: ");
	    scanf("%s",did);
	    flushall();
	    fb=fopen("d:\\lbrary\\book.dat","rb+");
	    while(fread(&b,bsize,1,fb)==1)
	    {
		 if(strcmp(did,b.bid)==0)
		 {
		      i=1;
		      gotoxy(26,10);
		      printf("BOOK NAME:%s",b.bname);
		      gotoxy(26,12);
		      printf("ENTER NEW NAME: ");
		      fflush(stdin);
		      gets(temp);
		      valid1(temp);                         //Validation call
		      valid4(temp);                         //     do
		      strcpy(b.bname,temp);
		      flushall();
		      gotoxy(26,14);
		      printf("AUTHOR NAME:%s",b.auth);
		      gotoxy(26,16);
		      printf("ENTER NEW AUTHOR NAME:");
		      fflush(stdin);
		      gets(temp1);
		      valid1(temp1);                        //Validation call
		      valid4(temp1);                        //     do
		      valid2(temp1);                        //     do
		      strcpy(b.auth,temp1);
		      gotoxy(26,18);
		      printf("PUBLISHER NAME:%s",b.publ);
		      gotoxy(26,20);
		      printf("ENTER NEW PUBLISHER:");
		      fflush(stdin);
		      gets(temp2);
		      valid1(temp2);                        //Validation call
		      valid4(temp2);                        //     do
		      strcpy(b.publ,temp2);
		      flushall();
		      fseek(fb,-bsize,SEEK_CUR);
		      fwrite(&b,bsize,1,fb);
		 }
	    }
	   if(i==0)
	   {
	      clrscr();
	      gotoxy(26,9);
	      printf("*Record not found*");
	   }
	   fclose(fb);
	   gotoxy(26,23);
	   printf("ANY MORE? [Y/N]: ");
	   scanf("%c",&ans);
	   flushall();
       }
     return;                                  //Return to bookmenu()
   }
/*===================================================================*/
  void bookquery(void)                        //Function definition.
					      //It is a menu based query
  {                                           //search the records by
       int i,flag,d,x=1,row=5;                //code,title,author.
       char title[25],author[30],bcode[8];
       clrscr();
       while(x)
       {
	    flag=1;
	    clrscr();
	    gotoxy(25,7);
	    printf("****?_BOOK QUERY SCREEN_?****");
	    gotoxy(25,17);
	    printf("_____________________________");
	    gotoxy(29,9);
	    printf("1.SEARCH BY CODE");
	    gotoxy(29,11);
	    printf("2.SEARCH BY TITLE");
	    gotoxy(29,13);
	    printf("3.SEARCH BY AUTHOR");
	    gotoxy(29,15);
	    printf("0.BACK TO MENU");
	    gotoxy(27,19);
	    printf("Enter your choice[0-3]: ");
	    scanf("%d",&d);
	    switch(d)
	    {
	      case 1:
	      clrscr();
	      fb=fopen("d:\\lbrary\\book.dat","rb+");
	      gotoxy(23,11);
	      printf("Enter the book code:");
	      fflush(stdin);
	      gets(bcode);
	      while(fread(&b,bsize,1,fb)==1)
	      {
		   if(strcmpi(bcode,b.bid)==0)
		   {
			flag=0;
			break;
		   }
	      }
	      if(flag==0)
	      {
			clrscr();
			gotoxy(26,7);
			printf("***_THIS IS YOUR RECORD_***");
			gotoxy(26,17);
			printf(":::::::::THANK YOU:::::::::");
			gotoxy(26,9);
			printf("Book_code : %s",b.bid);
			gotoxy(26,11);
			printf("Title     : %s",b.bname);
			gotoxy(26,13);
			printf("Author    : %s",b.auth);
			gotoxy(26,15);
			printf("Publisher : %s",b.publ);
	      }
	      else
	      {
			clrscr();
			gotoxy(26,11);
			printf("Book Code not found ......");
	      }
	      gotoxy(25,24);
	      printf("Press any key to return");
	      fclose(fb);
	      getch();
	      break;

	      case 2:
	      clrscr();
	      row=5;
	      fb=fopen("d:\\lbrary\\book.dat","rb+");
	      gotoxy(26,11);
	      printf("Enter the title to search:");
	      fflush(stdin);
	      gets(title);
	      clrscr();
	      gotoxy(26,2);printf("* BOOK TITLE QUERY *");
	      gotoxy(4,4);printf("Book_code:");
	      gotoxy(15,4);printf("Title:");
	      gotoxy(40,4);printf("Author:");
	      gotoxy(62,4);printf("Publisher:");
	      while(fread(&b,bsize,1,fb)==1)
	      {
		    if(strcmpi(title,b.bname)==0)
		    {
			  flag=0;
			  gotoxy(4,row);printf("%s",b.bid);
			  gotoxy(15,row);printf("%s",b.bname);
			  gotoxy(40,row);printf("%s",b.auth);
			  gotoxy(62,row);printf("%s",b.publ);
			  row++;
			  if(row==7)
			  {
			    gotoxy(4,row+1);
			    printf("*Press any key to continue----->>>>>>>.");
			    getch();
			    row=5;
			    clrscr();
			    gotoxy(26,2);printf("* BOOK TITLE QUERY *");
			    gotoxy(4,4);printf("Book_code:");
			    gotoxy(15,4);printf("Title:");
			    gotoxy(40,4);printf("Author:");
			    gotoxy(62,4);printf("Publisher:");
			  }
		    }

	      }
	      gotoxy(4,row+1);
	      printf("Press any key to return");

	      if(flag==1)
	      {
	      clrscr();
	      gotoxy(26,11);
	      printf("*Title not found..!!");
	      gotoxy(26,24);
	      printf("Press any key to return");
	      }
	      fclose(fb);
	      getch();
	      break;

	      case 3:
	      clrscr();
	      row=5;
	      fb=fopen("d:\\lbrary\\book.dat","rb+");
	      gotoxy(26,11);
	      printf("Enter the Author to search:");
	      fflush(stdin);
	      gets(author);
	      clrscr();
	      gotoxy(26,2);printf("* BOOK AUTHOR QUERY *");
	      gotoxy(4,4);printf("Book_code:");
	      gotoxy(15,4);printf("Title:");
	      gotoxy(40,4);printf("Author:");
	      gotoxy(62,4);printf("Publisher:");
	      while(fread(&b,bsize,1,fb)==1)
	      {
		   if(strcmpi(author,b.auth)==0)
		   {
			 flag=0;
			 gotoxy(4,row);printf("%s",b.bid);
			 gotoxy(15,row);printf("%s",b.bname);
			 gotoxy(40,row);printf("%s",b.auth);
			 gotoxy(62,row);printf("%s",b.publ);
			 row++;
			 if(row==7)
			 {
			    gotoxy(4,row+1);
			    printf("*Press any key to continue----->>>>>>>.");
			    getch();
			    row=5;
			    clrscr();
			    gotoxy(26,2);printf("* BOOK AUTHOR QUERY *");
			    gotoxy(4,4);printf("Book_code:");
			    gotoxy(15,4);printf("Title:");
			    gotoxy(40,4);printf("Author:");
			    gotoxy(62,4);printf("Publisher:");
			 }

		   }
	      }
	      gotoxy(4,row+1);
	      printf("Press any key to return");
	      if(flag==1)
	      {     clrscr();
		    gotoxy(26,11);
		    printf("*Author not found..!!");
		    gotoxy(26,24);
		    printf("press any key to return");
	      }
	      fclose(fb);
	      getch();
	      break;
	      case 0:
		      x=0;
		      break;
	      default :
	      gotoxy(26,21);
	      printf("* Invalid Choice *");
	      getch();
	    }
       }
       fcloseall();return;                             //Return to bookmenu()
  }
/*===================================================================*/
  void bookreport(void)                                //Function definition
  {
       int i,row=5;
       clrscr();

       fb=fopen("d:\\lbrary\\book.dat","rb+");
       clrscr();
       gotoxy(25,1);
       printf("*****-BOOK DISPLAY SCREEN-*****");
       gotoxy(4,3);
       printf("Book_code:");
       gotoxy(15,3);
       printf("Title:");
       gotoxy(40,3);
       printf("Author:");
       gotoxy(62,3);
       printf("Publisher:");
       while(fread(&b,bsize,1,fb)==1)
       {
	  gotoxy(4,row);printf("%s",b.bid);
	  gotoxy(15,row);printf("%s",b.bname);
	  gotoxy(40,row);printf("%s",b.auth);
	  gotoxy(62,row);printf("%s",b.publ);
	  row++;
	  if(row==21)
	  {
	     gotoxy(4,row+1);
	     printf("*Press any key to continue.....>>>>>>>");
	     getch();
	     row=5;
	     clrscr();
	     gotoxy(25,1);
	     printf("*****-BOOK DISPLAY SCREEN-*****");
	     gotoxy(4,3);
	     printf("Book_code:");
	     gotoxy(15,3);
	     printf("Title:");
	     gotoxy(40,3);
	     printf("Author:");
	     gotoxy(62,3);
	     printf("Publisher:");
	  }
       }
       fclose(fb);
       printf("\n\t* Press any key to return:");
       getch();
       return;                                         //Return to bookmenu()
  }
/*=====================BOOK MENU MAIN FUNCTION========================*/
  void bookmenu(void)                                 //Function definition
  {
       char reply='y';
       int ch=0;                                         //Function prototype
       void bookadd();                                   //      do
       void bookdel();                                   //      do
       void bookmod();                                   //      do
       void bookreport();                                //      do
       void bookquery();                                 //      do
       while(reply=='Y'||reply=='y')
       {
	     textbackground(8);
	     clrscr();
	     textcolor(13);
	     gotoxy(25,5);
	     cprintf(" ********_BOOK MENU_********");
	     textcolor(CYAN);
	     gotoxy(25,7);
	     cprintf(" 1. ENTER BOOK RECORDS......");
	     gotoxy(25,9);
	     cprintf(" 2. MODIFY BOOK RECORDS.....");
	     gotoxy(25,11);
	     cprintf(" 3. DELETE BOOK RECORDS.....");
	     gotoxy(25,13);
	     cprintf(" 4. BOOK REPORT.............");
	     gotoxy(25,15);
	     cprintf(" 5. BOOK QUERY..............");
	     gotoxy(25,17);
	     cprintf(" 0. RETURN TO MAIN MENU.... ");
	     gotoxy(25,19);
	     textcolor(13);
	     cprintf("_____________________________");
	     gotoxy(25,21);
	     textcolor(GREEN);

	     cprintf(" ENTER YOUR CHOICE(0-5):");
	     gotoxy(49,21);
	     textcolor(RED);
	     textbackground(WHITE);
	     cprintf("   ");
	     gotoxy(50,21);
	     fflush(stdin);
	     scanf("%d",&ch);
	     flushall();

	     switch(ch)
	     {
		   case 1:bookadd(); break;              //Function call
		   case 2:bookmod();break;               //      do
		   case 3 :bookdel();break;              //      do
		   case 4:bookreport();break;            //      do
		   case 5:bookquery();break;             //      do
		   case 0:return;                       //Return to main menu
		   default:
		   printf("\n WRONG OPERATOR...Press Any Key To Return ");
		   getch();

	      }
	  }
  }
/*============================THE END==================================*/