
	struct member
	{
	      char mid[8];
	   char mname[25];
	   struct address
	   {
	     char pin[10];
	      char rd[25];
	   }a;
	   struct doa            //Date Of Addmission
	   {
		  int day;
		  int mon;
		 int year;
	   } doa1;
	   struct doc            //Date Of Cancelation
	   {
		  int dd;
		  int mm;
		  int yy;
	   }doc1;
	}m;
  struct date d;
  long int msize=sizeof(m);
  FILE *fm;
/*======================================================*/
  void memadd()             //Addition of records
  {
  void valid1(char *);      //Function prototype
  void valid2(char *);     //      do
  void valid3(char *);                           //      do
  void valid4(char *);                           //      do
  void valid5(char *);                           //      do
  char temp[25],temp1[25],temp2[10],ans='y',id[8];
  int tmm,tyy,i,j;
  while(ans=='y'||ans=='Y')
  {
   textbackground(8);
   i=1;
   j=0;
   clrscr();
   if((fm=fopen("d:\\lbrary\\member.dat","rb+"))==NULL)
   {
    strcpy(m.mid,"M10001");              //To auto generate
   }                                         //purpose for member
   else                                      //code
   {
    rewind(fm);
    while(fread(&m,msize,1,fm)==1);
    for(i=1;m.mid[i]!='\0';i++,j++)           //Auto generating member
    {                                         //code
    id[j]=m.mid[i];
    }
    id[j]='\0';
    i=atoi(id);
    i++;
    itoa(i,id,10);
    strcpy(m.mid,"M");
    strcat(m.mid,id);
    }                                               //Member entry
       gotoxy(30,4);                                        //recording
       textcolor(YELLOW);
       cprintf("MEMBER ENTRY FORM");
       gotoxy(29,5);
       cprintf("===================");

       textcolor(BLUE);
       gotoxy(15,10);
       cprintf("THE MEMBER CODE:");
       gotoxy(47,10);
       textbackground(CYAN);
       cprintf("           ");
       gotoxy(48,10);
       cprintf("%s",m.mid);

       gotoxy(15,12);
       textbackground(8);
       cprintf("ENTER MEMBER NAME:");
       gotoxy(47,12);
       textbackground(CYAN);
       cprintf("                     ");
       gotoxy(48,12);
       fflush(stdin);
       gets(temp);
       valid1(temp);                                        //Validation call
       valid4(temp);                                        //       do
       valid2(temp);                                        //       do
       strcpy(m.mname,temp);
       flushall();

       gotoxy(15,14);
       textbackground(8);
       cprintf("ENTER PIN CODE:");
       gotoxy(47,14);
       textbackground(CYAN);
       cprintf("          ");
       gotoxy(48,14);
       fflush(stdin);
       gets(temp2);
       valid5(temp2);                                       //Validation call
       strcpy(m.a.pin,temp2);
       flushall();

       gotoxy(15,16);
       textbackground(8);
       cprintf("ENTER ROAD NAME:");
       gotoxy(47,16);
       textbackground(CYAN);
       cprintf("                       ");
       gotoxy(48,16);
       fflush(stdin);
       gets(temp1);
       valid1(temp1);                                       //Validation call
       valid3(temp1);                                       //       do
       valid4(temp1);
       fflush(stdin);                                       //       do
       strcpy(m.a.rd,temp1);
       flushall();

       gotoxy(15,18);
       textbackground(8);
       cprintf("ADDMISSION DATE [dd.mm.yy]:");
       gotoxy(47,18);
       textbackground(CYAN);
       cprintf("               ");
       gotoxy(48,18);
       getdate(&d);
       m.doa1.day=d.da_day; m.doa1.mon=d.da_mon; m.doa1.year=d.da_year;
       printf("%d.%d.%d",m.doa1.day,m.doa1.mon,m.doa1.year);
       flushall();
	       tyy=m.doa1.year;
	       if(m.doa1.mon<7)
	       {
		 if(m.doa1.day==31&&m.doa1.mon==3||m.doa1.day==31&&m.doa1.mon==5)
		 {
		    m.doc1.mm=m.doa1.mon+7;
		    m.doc1.dd=1;
		    m.doc1.yy=m.doa1.year;
		 }
		 else
		 {
		m.doc1.mm=m.doa1.mon+6;
		 m.doc1.dd=m.doa1.day;
		m.doc1.yy=m.doa1.year;
		 }
	       }
	       else
	       {
		 if(m.doa1.day==31&&m.doa1.mon==10||m.doa1.day==31&&m.doa1.mon==12)
		 {
		   tmm=m.doa1.mon+7;
		   m.doc1.yy=m.doa1.year+1;
		   m.doc1.dd=1;
		   if(tmm==17)m.doc1.mm=5;
		   if(tmm==19)m.doc1.mm=7;
		 }
		 if(m.doa1.day<31&&m.doa1.mon==10||m.doa1.day<31&&m.doa1.mon==12)
		 {
		   tmm=m.doa1.mon+6;
		   m.doc1.yy=m.doa1.year+1;
		   m.doc1.dd=m.doa1.day;
		   if(tmm==16)m.doc1.mm=4;
		   if(tmm==18)m.doc1.mm=6;
		 }
		 if(m.doa1.mon==8)
		 {
		    if(tyy%400==0||(tyy%100!=0&&tyy%4==0))
		    {
		      if(m.doa1.day==29)
		      {
			m.doc1.dd=29;
			m.doc1.mm=2;
			m.doc1.yy=m.doa1.year+1;
		      }
		      if(m.doa1.day==30)
		      {
			 m.doc1.dd=1;
			 m.doc1.mm=3;
			 m.doc1.yy=m.doa1.year+1;
		      }
		      if(m.doa1.day==31)
		      {
			 m.doc1.dd=2;
			m.doc1.mm=3;
			m.doc1.yy=m.doa1.year+1;
		      }
		      if(m.doa1.day<=28)
		      {
			 m.doc1.dd=m.doa1.day;
			m.doc1.mm=2;
			m.doc1.yy=m.doa1.year+1;
		      }
		    }
		    else
		    {
		      if(m.doa1.day==29)
		      {
			 m.doc1.dd=1;
			 m.doc1.mm=3;
			 m.doc1.yy=m.doa1.year+1;
		      }
		      if(m.doa1.day==30)
		      {
			 m.doc1.dd=2;
			 m.doc1.mm=3;
			 m.doc1.yy=m.doa1.year+1;
		      }
		      if(m.doa1.day==31)
		      {
			 m.doc1.dd=3;
			 m.doc1.mm=3;
			 m.doc1.yy=m.doa1.year+1;
		      }
		      if(m.doa1.day<=28)
		      {
			m.doc1.dd=m.doa1.day;
			m.doc1.mm=2;
			m.doc1.yy=m.doa1.year+1;
		      }
		    }

		 }
		 if(m.doa1.mon==7||m.doa1.mon==9||m.doa1.mon==11)
		 {
		    tmm=m.doa1.mon+6;
		    m.doc1.yy=m.doa1.year+1;
		    m.doc1.dd=m.doa1.day;
		    if(tmm==13)m.doc1.mm=1;
		    if(tmm==15)m.doc1.mm=3;
		    if(tmm==17)m.doc1.mm=5;
		 }
	       }
       gotoxy(15,20);
       textbackground(8);
       cprintf("CANCELLATION DATE [dd.mm.yy]:");
       gotoxy(47,20);
       textbackground(CYAN);
       cprintf("               ");
       gotoxy(48,20);
       printf("%d.%d.%d",m.doc1.dd,m.doc1.mm,m.doc1.yy);
       flushall();

       fclose(fm);
       fm=fopen("d:\\lbrary\\member.dat","ab+");
       fwrite(&m,msize,1,fm);
       fclose(fm);

       gotoxy(29,22);
       textbackground(8);
       textcolor(RED);
       cprintf(" Any more?(Y/N): ");
       gotoxy(45,22);
       textbackground(WHITE);
       cprintf("    ");
       gotoxy(46,22);
       fflush(stdin);
       scanf("%c",&ans);
       flushall();
       }
  return;                                             //Return to membermenu()
  }
/*===================================================================*/
  void memdel()                                       //Function definition
  {
       char ans='y',reply;
       char did[8];
       int flag;
       FILE *ft;
       while(ans=='y'||ans=='Y')
       {
	      textbackground(8);
	      textcolor(CYAN);
	      flag=0;
	      clrscr();
	      gotoxy(25,2);
	      printf(" ^^^^^^^^MEMBER DELETION^^^^^^^^^ ");
	      gotoxy(32,3);
	      printf("==================");
	      gotoxy(25,18);
	      printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
	      gotoxy(27,6);
	      printf("ENTER MEMBER CODE: ");
	      fflush(stdin);
	      gets(did);
	      flushall();
	      fm=fopen("d:\\lbrary\\member.dat","rb+");
	      while(fread(&m,msize,1,fm)==1)
	      {
		   if(strcmpi(did,m.mid)==0)
		   flag=1;
	      }
	      if(flag==1)
	      {
		 rewind(fm);
		 ft=fopen("d:\\lbrary\\temp.dat","wb+");
		 while(fread(&m,msize,1,fm)==1)
		 {
		   if(strcmpi(did,m.mid)!=0)
		   {
			 fwrite(&m,msize,1,ft);
		   }
		   else
		   {
			gotoxy(27,8);
			printf("THE MEMBER CODE:%s",m.mid);
			gotoxy(27,10);
			printf("THE MEMBER NAME:%s",m.mname);
			gotoxy(27,12);
			printf("ADDMISSION DATE:%d.%d.%d",m.doa1.day,
					    m.doa1.mon,m.doa1.year );
			gotoxy(27,14);
			printf("CANCELLATION DATE:%d.%d.%d",m.doc1.dd,
						m.doc1.mm,m.doc1.yy);
			gotoxy(27,16);
			printf("WISH TO DELETE?(Y/N):");
			scanf("%c",&reply);
			flushall();
			if(reply=='n'||reply=='N')
			{
			  fwrite(&m,msize,1,ft);
			}
		   }
		 }

		  fclose(fm);
		  fclose(ft);
		  remove("d:\\lbrary\\member.dat");
		  rename("d:\\lbrary\\temp.dat","d:\\lbrary\\member.dat");
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
		 fclose(fm);
		 gotoxy(27,20);
		 printf("*Invalid code!! ANY MORE?[Y/N]:");
		 fflush(stdin);
		 scanf("%c",&ans);
	    }
	 }
  return;                                             //Return to membermenu()
  }
/*===================================================================*/
  void memmod()                                       //Function definition
  {
       void valid1(char *);                           //Function prototype
       void valid3(char *);                           //       do
       void valid4(char *);                           //       do
       void valid5(char *);                           //       do
       char temp[25],temp1[10],did[10],ans='y';int f=0;
       while(ans=='y'||ans=='Y')
       {
	     clrscr();
	     gotoxy(23,2);
	     printf("*****_MEMBER MODIFICATION SCREEN_*****");
	     gotoxy(28,11);
	     printf(" ENTER MEMBER CODE: ");
	     scanf("%s",did);
	     flushall();
	     clrscr();
	     fm=fopen("d:\\lbrary\\member.dat","rb+");
	     while(fread(&m,msize,1,fm)==1)
	     {
		  if(strcmpi(did,m.mid)==0)
		  {   f=1;
		      gotoxy(23,7);
		      printf("*****_MEMBER MODIFICATION SCREEN_*****");
		      gotoxy(26,19);
		      printf("=================================");
		      gotoxy(26,9);
		      printf(" NAME:%s",m.mname);
		      gotoxy(26,11);
		      printf(" ROAD NAME:%s",m.a.rd);
		      gotoxy(26,13);
		      printf(" PIN CODE:%s",m.a.pin);
		      gotoxy(26,15);
		      printf(" ENTER NEW ROAD NAME: ");
		      gets(temp);
		      valid1(temp);                   //Validation call
		      valid3(temp);                   //       do
		      valid4(temp);                   //       do
		      strcpy(m.a.rd,temp);
		      gotoxy(26,17);
		      printf(" ENTER NEW PIN CODE: ");
		      fflush(stdin);
		      gets(temp1);
		      valid5(temp1);                  //Validation call
		      strcpy(m.a.pin,temp1);
		      flushall();

		      fseek(fm,-msize,SEEK_CUR);
		      fwrite(&m,msize,1,fm);
		  }

	     }
	     fclose(fm);
	     if(f==0)
	     {
		  gotoxy(26,11);
		  printf("* Record not found *");
	     }
	     gotoxy(26,21);
	     printf(" ANY MORE?(Y/N):");
	     scanf("%c",&ans);
	     flushall();
	}
	fcloseall();
  return;                                             //Return to membermenu()
  }
/*===================================================================*/
  void memquery(void)                                 //Function definition
  {                                                   //search by code
       char did[10];int f=0;
       clrscr();
       fm=fopen("d:\\lbrary\\member.dat","rb+");
       gotoxy(26,2);
       printf("*****-MEMBER QUERY SCREEN-*****");
       gotoxy(32,3);
       printf("-------------------");
       gotoxy(28,11);
       printf(" Enter member code: ");
       fflush(stdin);
       scanf("%s",&did);
       clrscr();
       while(fread(&m,msize,1,fm)==1)
       {
	     if(strcmp(did,m.mid)==0)
	     {
		f=1;
		gotoxy(26,7);
		printf("*****-MEMBER QUERY SCREEN-*****");
		gotoxy(26,21);
		printf("=================================");
		gotoxy(26,9);
		printf("Member code: %s",m.mid);
		gotoxy(26,11);
		printf("Name: %s",m.mname);
		gotoxy(26,13);
		printf("Pin code: %s",m.a.pin);
		gotoxy(26,15);
		printf("Road name: %s",m.a.rd);
		gotoxy(26,17);
		printf("Date of addmission: %d.%d.%d",m.doa1.day,
				     m.doa1.mon,m.doa1.year);
		gotoxy(26,19);
		printf("Date of cancellation:%d.%d.%d",m.doc1.dd,
					m.doc1.mm,m.doc1.yy);
	     }

	  }
	  if(f==0)
	     {
		clrscr();
		gotoxy(31,11);
		printf("* Record not found *");
	     }
  fcloseall();
  gotoxy(28,23);
  printf(" Press any key to return:");
  getch();
  return;                                             //Return to membermenu()
  }
/*===================================================================*/
  void memreport(void)                                //Function definition
  {                                                   //This function will
       int i,row=5;                                   //shows 21 rows of
       clrscr();                                      //records at a time
						      //and ask you to press
    fm=fopen("d:\\lbrary\\member.dat","rb+");         //any key for continue
    clrscr();
    gotoxy(25,1);
    printf("*****-MEMBER DISPLAY SCREEN-*****");
    gotoxy(2,3);
    printf("I_code:");
    gotoxy(10,3);
    printf("Name:");
    gotoxy(27,3);
    printf("Pin:");
    gotoxy(35,3);
    printf("Road:");
    gotoxy(56,3);
    printf("Addm.date:");
    gotoxy(68,3);
    printf("Cancel_date:");
    while(fread(&m,msize,1,fm))
    {

	  gotoxy(2,row);printf("%s",m.mid);
	  gotoxy(10,row);printf("%s",m.mname);
	  gotoxy(27,row);printf("%s",m.a.pin);
	  gotoxy(35,row);printf("%s",m.a.rd);
	  gotoxy(56,row);printf("%d.%d.%d",m.doa1.day,m.doa1.mon,m.doa1.year);
	  gotoxy(68,row);printf("%d.%d.%d",m.doc1.dd,m.doc1.mm,m.doc1.yy);
	  row++;
	  if(row==21)
	  {
	    gotoxy(4,row+1);
	    printf("*Press any key to continue....>>>>>>");
	    getch();
	    row=5;
	    clrscr();
	    gotoxy(25,1);
	    printf("*****-MEMBER DISPLAY SCREEN-*****");
	    gotoxy(2,3);
	    printf("I_code:");
	    gotoxy(10,3);
	    printf("Name:");
	    gotoxy(27,3);
	    printf("Pin:");
	    gotoxy(35,3);
	    printf("Road:");
	    gotoxy(56,3);
	    printf("Addm.date:");
	    gotoxy(68,3);
	    printf("Cancel_date:");
	  }
    }
	  fclose(fm);
	  gotoxy(2,row+1);
	  printf("Press any key to return:");
	  getch();
	  return;                                   //Return to membermenu()
  }
/*===================================================================*/
  void membermenu()
  {
       char reply='y';
       int ch=0;
       void memadd();
       void memdel();
       void memmod();
       void memreport();
       void memquery();
       while(reply=='Y'||reply=='y')
       {
	     textbackground(8);
	     clrscr();
	     textcolor(13);
	     gotoxy(25,5);
	     cprintf(" ********_MEMBER MENU_********");
	     textcolor(CYAN);
	     gotoxy(25,7);
	     cprintf(" 1. ENTER MEMBER  RECORDS.....");
	     gotoxy(25,9);
	     cprintf(" 2. MODIFY MEMBER RECORDS.....");
	     gotoxy(25,11);
	     cprintf(" 3. DELETE MEMBER RECORDS.....");
	     gotoxy(25,13);
	     cprintf(" 4. MEMBER REPORT.............");
	     gotoxy(25,15);
	     cprintf(" 5. MEMBER QUERY..............");
	     gotoxy(25,17);
	     cprintf(" 0. RETURN TO MAIN MENU.......");
	     gotoxy(25,19);
	     textcolor(13);
	     cprintf("------------------------------");
	     gotoxy(25,21);
	     textcolor(GREEN);

	     cprintf(" ENTER YOUR CHOICE(0-5):");
	     gotoxy(49,21);
	     textcolor(RED);
	     textbackground(WHITE);
	     cprintf("   ");
	     gotoxy(50,21);
	     scanf("%d",&ch);
	     flushall();

	     switch(ch)
	     {
		      case 1:memadd();break;
		      case 2:memmod();break;
		      case 3:memdel();break;
		      case 4:memreport();break;
		      case 5:memquery();break;
		      case 0:return;
	      default: printf("\n WRONG OPERATOR...Press Any Key To Return ");
	      getch();
	      continue;
	     }
       }
  }