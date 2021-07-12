/*TRANSACT.H */
/*ALL TRANSACTION RELATED FUNCTIONS ARE IN THIS FILE*/
		struct dt
		{
		   int day;
		   int mon;
		   int year;
		};

	 struct tran
	 {
	     char tid[8];
	  char tmcode[8];
	  char tbcode[8];
	 struct dt idate;
	 struct dt rdate;
		int fine;
	     char remark;
	 };
	 struct mdoc     //To store the cancellation date of membership
	 {
	    int dd;
	    int mm;
	    int yy;
	 }mdoc1;
struct tran t;
struct member m1;
struct book b1;
struct date d1,d2;
long int tsize=sizeof(t);
FILE *tr,*fb1,*fm1;
/*====================================================================*/
   void issue(void)                                    //Function declaration
   {
	char ans='Y',reply;
	char tmcode1[8],tbcode1[8],tcode[8];
	int bflag1,bflag2,mflag1,mflag2,mcd,j=1,k=0;  //Mcd is also a flag
	fcloseall();
/*                                                                        */
	while(ans=='y'|| ans=='Y')
	{
	     clrscr();
	     fm1=fopen("d:\\lbrary\\member.dat","rb");
	     fb1=fopen("d:\\lbrary\\book.dat","rb");
	     bflag1=0,bflag2=0,mflag1=0,mflag2=0,mcd=0;
	     clrscr();
	     gotoxy(2,3);
	     printf("Do Confirm The Membership Cancellation Date Before");
	     printf(" Issueing Book To Any Member");
	     gotoxy(2,4);
	     printf("__________________________________________________");
	     printf("____________________________");
	     gotoxy(26,7);
	     printf("*****_BOOK ISSUE SCREEN_*****");
	     gotoxy(26,9);
	     printf("Enter Member_code:  ");
	     fflush(stdin);
	     gets(tmcode1);
	     while(fread(&m1,sizeof(m1),1,fm1)==1)  //Checking member id is
	     {                                      //valid or invalid by
		  if(strcmpi(m1.mid,tmcode1)==0)    //reading member.dat
		  {                                 //      AND
			mdoc1.dd=m1.doc1.dd;        //Storing membership
			mdoc1.mm=m1.doc1.mm;        //cancellation date
			mdoc1.yy=m1.doc1.yy;
			mflag1=1;
			break;
		  }
	     }

	     if(mflag1==0)
	     {
		    clrscr();
		    gotoxy(26,11);
		    printf("*Sorry, Invalid Member-Id*");
	     }
	     if(mflag1==1)  //Asking for user's confirmation after displaying
	     {                                 //membership cancellation date.
		  gotoxy(26,11);
		  printf("Membership cancellation date:%d.%d.%d",mdoc1.dd,
						       mdoc1.mm,mdoc1.yy);
		  gotoxy(26,13);
		  printf("Want to issue to the member[Y/N]:");
		  scanf("%c",&reply);
		  if(reply=='y'||reply=='Y')
		  mcd=1;
	     }

	     if(mcd==1)
	     {                                      //Checking book id is
		  gotoxy(26,15);                    //valid or invalid by
		  printf("Enter  Book_code:  ");    //reading book.dat.
		  fflush(stdin);
		  gets(tbcode1);
		  while(fread(&b1,sizeof(b1),1,fb1)==1)
		  {
		       if(strcmpi(b1.bid,tbcode1)==0)
		       {
				bflag1=1;
		       }
		  }
	     }
	     fcloseall();
	     if(mcd==1 && bflag1==0)
	     {
		       clrscr();
		       gotoxy(26,11);
		       printf("*Sorry, Invalid Book-Id*");
	     }
	     if(mcd==1 && bflag1==1 )               //Checking in trans.dat
	     {
		 if((tr=fopen("d:\\lbrary\\trans.dat","rb"))==NULL)
		 {
			 mflag2=0;
			 bflag2=0;
			 fclose(tr);
		 }
		 else
		 {
			 while(fread(&t,tsize,1,tr)==1)
			 {
			       if(strcmpi(t.tmcode,tmcode1)==0)
			       {
				   if(t.remark=='I')
				   mflag2=1;
			       }
			 }
			 if(mflag2==1)
			 {
			       clrscr();
			       gotoxy(21,9);
			       printf("*Member has a book can't be issue*");
			 }
			 if(mflag2==0)       //Checking if the book is already
			 {                   //issued to any other member.
			      rewind(tr);
			      while(fread(&t,tsize,1,tr)==1)
			      {
				    if(strcmpi(t.tbcode,tbcode1)==0)
				    {
					if(t.remark=='I')
					bflag2=1;
				    }
			      }
			 }
			 if(bflag2==1)
			 {
			      clrscr();
			      gotoxy(21,9);
			      printf("*Book is already issued can't be issue*");
			 }
			 fcloseall();
		 }                    //closing else
		 if(mflag2==0 && bflag2==0)
		 {
		    if((tr=fopen("d:\\lbrary\\trans.dat","rb+"))==NULL)
		    {
			fflush(stdin);
			strcpy(t.tid,"T10001");
		    }
		    else
		    {
			 rewind(tr);
			 k=0;
			 while(fread(&t,tsize,1,tr)==1);
			 for(j=1;t.tid[j]!='\0';j++,k++)
			 {
			      tcode[k]=t.tid[j];
			 }
			 tcode[k]='\0';
			 j=atoi(tcode);
			 j++;
			 itoa(j,tcode,10);
			 fflush(stdin);
			 strcpy(t.tid,"T");
			 fflush(stdin);
			 strcat(t.tid,tcode);
			 flushall();
		     }
		     fclose(tr);
		     fflush(stdin);
		     strcpy(t.tmcode,tmcode1);
		     fflush(stdin);
		     strcpy(t.tbcode,tbcode1);
		     getdate(&d1);
		     t.idate.day=d1.da_day;
		     t.idate.mon=d1.da_mon;
		     t.idate.year=d1.da_year;
		     t.rdate.day=0;
		     t.rdate.mon=0;
		     t.rdate.year=0;
		     clrscr();
		     gotoxy(26,7);
		     printf("*****_BOOK ISSUE SCREEN_*****");
		     gotoxy(26,9);
		     printf("Trans code:  %s",t.tid);
		     gotoxy(26,11);
		     printf("Mem_cancel_date:%d.%d.%d",mdoc1.dd,mdoc1.mm,
							  mdoc1.yy);
		     gotoxy(26,13);
		     printf("Date of Issue	: %d-%d-%d",t.idate.day,
						t.idate.mon,t.idate.year);
		     t.fine=0;
		     t.remark='I';
		     flushall();
		     tr=fopen("d:\\lbrary\\trans.dat","ab+");
		     fwrite(&t,tsize,1,tr);
		     gotoxy(26,15);
		     printf("One Book Issued....");
		     gotoxy(26,17);
		     printf("+++++++++++++++++++++++++++++++");
		     flushall();
		     fclose(tr);
		 }
	     }
	    gotoxy(26,23);
	    printf("Want to continue [Y/N]:");
	    fflush(stdin);
	    scanf("%c",&ans);
	}
	fcloseall();
	return;                                        //Return to transmenu()
  }
/*===================================================================*/
  void b_return(void)                             //Function declaration
  {
     int day=0,i=0;
     char tcode[8];
     char ans1='y';
     while(ans1=='y'|| ans1=='Y')
     {
	  clrscr();
	  gotoxy(25,5);
	  printf("*****_BOOK RETURN SCREEN_*****");
	  gotoxy(25,7);
	  printf("Enter transaction code:");
	  fflush(stdin);
	  scanf("%s",tcode);
	  tr=fopen("d:\\lbrary\\trans.dat","rb+");
	  while(fread(&t,tsize,1,tr)==1)
	  {
	       if(strcmpi(t.tid,tcode)==0)      //Checking if the given trans
	       {                                //code is existing in
		    if(t.remark=='I')           //trans.dat and has an'I'
		    {                           //means issue against it.
		    i=1;
		    clrscr();                   //Performing return.
		    gotoxy(25,7);
		    printf("*****_BOOK RETURN SCREEN_*****");
		    gotoxy(25,19);
		    printf("_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_");
		    getdate(&d2);
		    t.rdate.day=d2.da_day;
		    t.rdate.mon=d2.da_mon;
		    t.rdate.year=d2.da_year;
		    gotoxy(25,9);
		    printf("Transaction code: %s",t.tid);
		    gotoxy(25,11);
		    printf("Date of issue:    %d-%d-%d",t.idate.day,
					    t.idate.mon,t.idate.year);
		    gotoxy(25,13);
		    printf("Date of return:   %d-%d-%d",t.rdate.day,
					    t.rdate.mon,t.rdate.year);
		    day=datediff(t.idate.day,t.idate.mon,t.idate.year,
		     t.rdate.day,t.rdate.mon,t.rdate.year);//calling datediff
		    if(day > 7)                            //function to
		    {                                      //calculate the
		       fflush(stdin);                      //difference
		       t.fine=(day-7)*5;                   //between issue &
		    }                                      //return date.
		    gotoxy(25,15);
		    printf("Fine amount:  %d",t.fine);
		    t.remark='R';
		    fseek(tr,-tsize,1);
		    fwrite(&t,tsize,1,tr);
		    gotoxy(25,17);
		    printf("Book is returned");
		    }
	       }
	  }

	  if(i==0)
	  {
	    gotoxy(25,11);
	    printf("# Transaction code is unavailable #");
	  }
	    fclose(tr);
	  gotoxy(26,21);
	  printf("Want to continue [Y/N]: ");
	  fflush(stdin);
	  ans1=getchar();
	  flushall();
     }
     return;                                      //Return to transmenu()
  }
/*===================================================================*/
  void transdel()                                //Function declaration
  {
       char ans='y',reply;
       char tcode[8];
       int flag;
       FILE *ft;
       while(ans=='y'||ans=='Y')
       {
	      textbackground(8);
	      textcolor(CYAN);
	      flag=0;
	      clrscr();
	      gotoxy(25,2);
	      printf(" ^^^^^^^^TRANS DELETION^^^^^^^^^ ");
	      gotoxy(32,3);
	      printf("==================");
	      gotoxy(25,16);
	      printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
	      gotoxy(27,6);
	      printf("ENTER TRANS CODE: ");
	      fflush(stdin);
	      gets(tcode);
	      flushall();
	      tr=fopen("d:\\lbrary\\trans.dat","rb+");
	      while(fread(&t,tsize,1,tr)==1)
	      {
		   if(strcmpi(tcode,t.tid)==0)
		   flag=1;
	      }
	      if(flag==1)
	      {
		 rewind(tr);
		 ft=fopen("d:\\lbrary\\temp.dat","wb+");
		 while(fread(&t,tsize,1,tr)==1)
		 {
		   if(strcmpi(tcode,t.tid)!=0)
		   {
			 fwrite(&t,tsize,1,ft);
		   }
		   else
		   {
			gotoxy(27,8);
			printf("THE MEMBER CODE:%s", t.tmcode);
			gotoxy(27,10);
			printf("THE BOOK CODE  : %s",t.tbcode);
			gotoxy(27,12);
			printf("THE REMARK     : %c",t.remark);
			if(t.remark=='I')
			{
			  gotoxy(27,14);
			  printf("REMARK IS 'I' STILL WISH TO DELETE?(Y/N):");
			}
			else
			{
			  gotoxy(27,14);
			  printf("WISH TO DELETE?(Y/N):");
			}
			scanf("%c",&reply);
			flushall();
			if(reply=='n'||reply=='N')
			{
			  fwrite(&t,tsize,1,ft);
			}
		     }
		  }

		  fclose(tr);
		  fclose(ft);
		  remove("d:\\lbrary\\trans.dat");
		  rename("d:\\lbrary\\temp.dat","d:\\lbrary\\trans.dat");
	       }
	    if(flag==1)
	    {
		 gotoxy(27,18);
		 printf(" ANY MORE?(Y/N):");
		 scanf("%c",&ans);
		 flushall();
	    }
	    if(flag==0)
	    {
		 fclose(tr);
		 gotoxy(27,18);
		 printf("*Invalid code!! ANY MORE?[Y/N]:");
		 fflush(stdin);
		 scanf("%c",&ans);
	    }
	 }
  return;                                        //Return to transmenu()
  }
/*===================================================================*/
    void transquery(void)                       //Function declaration
    {
       int flag,d,x=1,row=5;                    //It is a menu based query,
       char tcode[8];                           //it will search by code,
       clrscr();                                //issue,return.During the
       while(x)                                 //issue or return records
       {                                        //it will show you upto
	    flag=1;                             //21 rows at a time and
	    clrscr();                           //ask you to press any key
	    gotoxy(25,5);                       //to continue for next screen
	    printf("*****_TRANS QUERY SCREEN_*****");      //full of records.
	    gotoxy(29,9);
	    printf("1.SEARCH BY TRANS CODE");
	    gotoxy(29,11);
	    printf("2.SEARCH BY ISSUE");
	    gotoxy(29,13);
	    printf("3.SEARCH BY RETURN");
	    gotoxy(29,15);
	    printf("0.BACK TO MENU");
	    gotoxy(29,17);
	    printf("Enter your choice   : ");
	    scanf("%d",&d);
	    switch(d)
	    {
	      case 1:                /*====searching by code=============*/
	      clrscr();
	      tr=fopen("d:\\lbrary\\trans.dat","rb+");
	      gotoxy(26,11);
	      printf("Enter the trans_code to search:");
	      fflush(stdin);
	      gets(tcode);
	      while(fread(&t,tsize,1,tr)==1)
	      {
		   if(strcmpi(tcode,t.tid)==0)
		   {
			flag=0;
			break;
		   }
	      }
	      if(flag==0)
	      {
			clrscr();
			gotoxy(26,5);
			printf("*******QUERY BY CODE********");
			gotoxy(26,7);
			printf("Trans_code : %s",t.tid);
			gotoxy(26,9);
			printf("Member code: %s",t.tmcode);
			gotoxy(26,11);
			printf("Book code  : %s",t.tbcode);
			gotoxy(26,13);
			printf("Date of issue : %d-%d-%d",t.idate.day,t.idate.mon
							     ,t.idate.year);
			gotoxy(26,15);
			printf("Date of return:  %d-%d-%d",t.rdate.day,t.rdate.mon
							     ,t.rdate.year);
			gotoxy(26,17);
			printf("Fine  : Rs %d",t.fine);
			gotoxy(26,19);
			printf("Remark  :  %c",t.remark);
			gotoxy(26,21);
			printf("::::::::::THANK YOU::::::::::");
			gotoxy(26,23);
			printf("Press any key to return:");
	      }
	      else
	      {
			clrscr();
			gotoxy(26,11);
			printf("Trans_code not found ......");
	      }
	      fclose(tr);
	      getch();
	      break;

	      case 2:                 /*=======SEARCHING BY ISSUE=========*/
	      clrscr();
	      tr=fopen("d:\\lbrary\\trans.dat","rb+");
	      clrscr();
	      gotoxy(26,2);printf("* TRANS ISSUE QUERY *");
	      gotoxy(12,4);printf("Trans_code:");
	      gotoxy(28,4);printf("Mem_code:");
	      gotoxy(43,4);printf("Book code:");
	      gotoxy(58,4);printf("Issue date:");
	      while(fread(&t,tsize,1,tr)==1)
	      {
		    if(t.remark=='I')
		    {
			  flag=0;
			  gotoxy(12,row);printf("%s",t.tid);
			  gotoxy(28,row);printf("%s",t.tmcode);
			  gotoxy(43,row);printf("%s",t.tbcode);
			  gotoxy(58,row);printf("%d-%d-%d",
				     t.idate.day,t.idate.mon,t.idate.year);
			  row++;
			  if(row==7)
			  {
			     gotoxy(12,row+1);
			     printf("*Press any key to continue------->>>>");
			     getch();
			     row=5;
			     clrscr();
			     gotoxy(26,2);printf("* TRANS ISSUE QUERY *");
			     gotoxy(12,4);printf("Trans_code:");
			     gotoxy(28,4);printf("Mem_code:");
			     gotoxy(43,4);printf("Book code:");
			     gotoxy(58,4);printf("Issue date:");
			  }
		    }
	      }
	      gotoxy(12,row+1);
	      printf("Press any key to return");
	      if(flag==1)
	      {
	      clrscr();
	      gotoxy(26,11);
	      printf("Record not found.......");
	      gotoxy(26,23);
	      printf("Press any key to return:");
	      }
	      fclose(tr);
	      getch();
	      break;

	      case 3:           /*==========SEARCHING BY RETURN=========*/
	      clrscr();
	      tr=fopen("d:\\lbrary\\trans.dat","rb+");
	      clrscr();
	      gotoxy(26,2);printf("* TRANS RETURN QUERY *");
	      gotoxy(10,4);printf("Trans_code:");
	      gotoxy(24,4);printf("Mem_code:");
	      gotoxy(37,4);printf("Book code:");
	      gotoxy(50,4);printf("Return date:");
	      gotoxy(65,4);printf("Fine:");
	      while(fread(&t,tsize,1,tr)==1)
	      {
		    if(t.remark=='R')
		    {
			  flag=0;
			  gotoxy(10,row);printf("%s",t.tid);
			  gotoxy(24,row);printf("%s",t.tmcode);
			  gotoxy(37,row);printf("%s",t.tbcode);
			  gotoxy(50,row);printf("%d-%d-%d",
				 t.rdate.day,t.rdate.mon,t.rdate.year);
			  gotoxy(65,row);printf("%d",t.fine);
			  row++;
			  if(row==6)
			  {
			     gotoxy(10,row+1);
			     printf("*Press any key to continue------>>>>>");
			     getch();
			     row=5;
			     clrscr();
			     gotoxy(26,2);printf("* TRANS RETURN QUERY *");
			     gotoxy(10,4);printf("Trans_code:");
			     gotoxy(24,4);printf("Mem_code:");
			     gotoxy(37,4);printf("Book code:");
			     gotoxy(50,4);printf("Return date:");
			     gotoxy(65,4);printf("Fine:");
			  }
		    }
	      }
	      gotoxy(10,row+1);
	      printf("Press any key to return");
	      if(flag==1)
	      {
	      clrscr();
	      gotoxy(26,11);
	      printf("Record not found.......");
	      gotoxy(26,23);
	      printf("Press ny key to return");
	      }
	      fclose(tr);
	      getch();
	      break;
	      case 0:
		      x=0;
		      break;
	      default :
	      gotoxy(26,21);
	      printf("Invalid Choice....");
	      getch();
	    }
       }
       fcloseall();return;                     //Return to transmenu()
  }
/*====================================================================*/
 void treport(void)                           //Function declaration
  {
    int i,row=5;                              //It will also show you 21
    clrscr();                                 //rows at a time and ask you
					      //to press any key for continue.
    tr=fopen("d:\\lbrary\\trans.dat","rb");
    clrscr();
    gotoxy(23,1);
    printf("*****-TRANSACTION DISPLAY SCREEN-*****");
    gotoxy(1,3);
    printf("T_code:");
    gotoxy(12,3);
    printf("M_code:");
    gotoxy(24,3);
    printf("B_code:");
    gotoxy(36,3);
    printf("Issue date:");
    gotoxy(50,3);
    printf("Return date:");
    gotoxy(64,3);
    printf("Fine");
    gotoxy(72,3);
    printf("Remark");
    while(fread(&t,tsize,1,tr)==1)
    {
	  gotoxy(1,row);printf("%s",t.tid);
	  gotoxy(12,row);printf("%s",t.tmcode);
	  gotoxy(24,row);printf("%s",t.tbcode);
	  gotoxy(36,row);printf("%d.%d.%d",t.idate.day,t.idate.mon,t.idate.year);
	  gotoxy(50,row);printf("%d.%d.%d",t.rdate.day,t.rdate.mon,t.rdate.year);
	  gotoxy(64,row);printf("%d",t.fine);
	  gotoxy(72,row);printf("%c",t.remark);
	  row++;
	  if(row==23)
	  {
	     printf("\n* Press any key to continue.....");
	     getch();
	     row=5;
	     clrscr();
	     gotoxy(23,1);
	      printf("*****-TRANSACTION DISPLAY SCREEN-*****");
	      gotoxy(1,3);
	      printf("T_code:");
	      gotoxy(12,3);
	      printf("M_code:");
	      gotoxy(24,3);
	      printf("B_code:");
	      gotoxy(36,3);
	      printf("Issue date:");
	      gotoxy(50,3);
	      printf("Return date:");
	      gotoxy(64,3);
	      printf("Fine");
	      gotoxy(72,3);
	      printf("Remark");
	  }
    }
	  fclose(tr);
	  printf("\nPress any key to return:");
	  getch();
	  return;
  }

/*=====================Transaction main menu function==================*/
  void transmenu (void)                       //Function declaration
  {
  char answer='y';
  int choice=0;
  void issue(void);                           //Function prototype
  void b_return(void);                        //      do
  void transdel(void);                        //      do
  void treport(void);                         //      do
  void transquery(void);                      //      do
  while(answer=='y' || answer=='Y')
  {
  textbackground(8);
      clrscr();
      textcolor(13);
      gotoxy(25,5);
      cprintf(" *****_TRANSACTION  MENU_*****");
      textcolor(CYAN);
      gotoxy(25,7);
      cprintf(" 1.BOOK ISSUE.................");
      gotoxy(25,9);
      cprintf(" 2.BOOK RETURN................");
      gotoxy(25,11);
      cprintf(" 3.TRANSACTION DELETION.......");
      gotoxy(25,13);
      cprintf(" 4.TRANSACTION REPORT.........");
      gotoxy(25,15);
      cprintf(" 5.TRANSACTION QUERY..........");
      gotoxy(25,17);
      cprintf(" 0.RETURN TO MAIN MENU........");
      gotoxy(25,19);
      cprintf(" @@ NOW ENTER YOUR CHOICE @@ ");
      gotoxy(25,20);
      textcolor(13);
      cprintf(" ------------------------------");
      gotoxy(25,22);
      textcolor(GREEN);

      cprintf(" ENTER YOUR CHOICE(0-5):");
      gotoxy(49,22);
      textcolor(RED);
      textbackground(WHITE);
      cprintf("   ");
       gotoxy(50,22);
       scanf("%d",&choice);
      flushall();
      switch(choice)
	  {
	  case 1:issue();break;                         //Function call
	  case 2:b_return();break;                      //      do
	  case 3:transdel();break;                      //      do
	  case 4:treport();break;                       //      do
	  case 5:transquery();break;                    //      do
	  case 0:return;                         //Return to main function

  default: cprintf("\n\n\n\t\t WRONG SELECTION...Press Any Key To Return ");
      getch();

      }
}
}
/*===============================THE END====================================*/
