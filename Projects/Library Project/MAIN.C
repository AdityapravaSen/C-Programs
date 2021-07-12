/* THIS IS A HIGHLY INTERACTIVE PROGRAM * AFTER EVERY STEP IF NECESSARY IT
   WILL ASK YOU FOR YOUR WISH PRESS 'Y' FOR YES AND 'N' FOR NO.*/
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<dos.h>
#include"d:\lbrary\member.h"
#include"d:\lbrary\book.h"
#include"d:\lbrary\transact.h"
#include"d:\lbrary\datediff.h"
#include"d:\lbrary\hungry.h"
void bookmenu();                //Function prototype
void membermenu();              //    do
void transmenu();               //    do
/*===================================================================*/
void main()
{
  char answer='y';
  int choice=0;
  while(answer=='y' || answer=='Y')
  {
  textbackground(8);
      clrscr();
      textcolor(13);
      gotoxy(25,5);
      cprintf("********_LIBRARY  MENU_********");
      textcolor(CYAN);
      gotoxy(25,7);
      cprintf(" 1. MEMBER RECORDS.............");
      gotoxy(25,9);
      cprintf(" 2. BOOK RECORDS...............");
      gotoxy(25,11);
      cprintf(" 3. TRANSACTION RECORDS........");
      gotoxy(25,13);
      cprintf(" 0. EXIT.......................");

      gotoxy(25,16);
      cprintf(" @@ NOW ENTER YOUR CHOICE @@ ");
      gotoxy(25,17);
      textcolor(13);
      cprintf("________________________________");
      gotoxy(25,19);
      textcolor(GREEN);

      cprintf(" ENTER YOUR CHOICE (0-3):");
      gotoxy(50,19);
      textcolor(WHITE);
      textbackground(RED);
      cprintf("   ");
      gotoxy(51,19);
      scanf("%d",&choice);
      flushall();
      switch(choice)
	  {
	  case 1:membermenu();break;              // Function call
	  case 2:bookmenu();break;                //    do
	  case 3:transmenu();break;               //    do
	  case 0:exit(0);break;
     default: printf("\n\n\n\t\t WRONG SELECTION...Press Any Key To Return ");
     getch();

	  }
    }
}
/*=============================THE END===============================*/