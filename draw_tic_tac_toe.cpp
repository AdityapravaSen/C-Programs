#include <stdio.h>
#include <conio.h>
#include<stdlib.h>

char square[10] = { 'o', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

void board()								//function to display board
{
	system("cls");
    printf("\n\n\tTic Tac Toe\n\n");

    printf("Player (X)  -  CPU (O)\n\n\n");


    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", square[1], square[2], square[3]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", square[4], square[5], square[6]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", square[7], square[8], square[9]);

    printf("     |     |     \n\n");
}

int input()					//function to input user choice
{
	int choice;
	printf("\nenter choice(1-9):\n");
	scanf("%d",&choice);
	if(choice>=1 && choice<=9)
		return choice;
	else
	{
		printf("wrong input.");
		input();
	}
}

void change_val(int ch,char mark)					//changes value of board
{
	if(ch==1)
		square[1]=mark;
	else if(ch==2)
		square[2]=mark;
	else if(ch==3)
		square[3]=mark;
	else if(ch==4)
		square[4]=mark;
	else if(ch==5)
		square[5]=mark;
	else if(ch==6)
		square[6]=mark;
	else if(ch==7)
		square[7]=mark;
	else if(ch==8)
		square[8]=mark;
	else if(ch==9)
		square[9]=mark;
}

int main()
{
	char mark;
	int choiceX, choiceO,check;
	board();
	choiceX=input();
	change_val(choiceX,'X');
	if(choiceX==5)
	{
		choiceO=9;
		change_val(choiceO,'O');
		board();
		choiceX=input();
		change_val(choiceX,'X');
		if(choiceX==1)
		{
			choiceO=7;
			change_val(choiceO,'O');
			board();
			choiceX=input();
			change_val(choiceX,'X');
			if(choiceX==8)
			{
				choiceO=2;
				change_val(choiceO,'O');
				board();
				choiceX=input();
				change_val(choiceX,'X');
				if(choiceX==4)
				{
					choiceO=6;
					change_val(choiceO,'O');
					board();
					choiceX=input();
					change_val(choiceX,'X');
					if(choiceX==2)
					{
						choiceO=3;
						change_val(choiceO,'O');
						board();
						printf("\ndraw\n");
					}
					else if(choiceX==3)
					{
						choiceO=2;
						change_val(choiceO,'O');
						board();
						printf("\ndraw\n");
					}
				}
				else if(choiceX==6)
				{
					choiceO=4;
					change_val(choiceO,'O');
					board();
					choiceX=input();
					change_val(choiceX,'X');
					if(choiceX==2)
					{
						choiceO=3;
						change_val(choiceO,'O');
						board();
						printf("\ndraw\n");
					}
					else if(choiceX==3)
					{
						choiceO=2;
						change_val(choiceO,'O');
						board();
						printf("\ndraw\n");
					}
				}
				else if(choiceX==1)
				{
					choiceO=3;
					change_val(choiceO,'O');
					board();
					choiceX=input();
					change_val(choiceX,'X');
					if(choiceX==4)
					{
						choiceO=6;
						change_val(choiceO,'O');
						board();
						printf("\ndraw\n");
					}
					else if(choiceX==6)
					{
						choiceO=4;
						change_val(choiceO,'O');
						board();
						printf("\ndraw\n");
					}
				}
				else if(choiceX==3)
				{
					choiceO=1;
					change_val(choiceO,'O');
					board();
					choiceX=input();
					change_val(choiceX,'X');
					if(choiceX==4)
					{
						choiceO=6;
						change_val(choiceO,'O');
						board();
						printf("\ndraw\n");
					}
					else if(choiceX==6)
					{
						choiceO=4;
						change_val(choiceO,'O');
						board();
						printf("\ndraw\n");
					}
				}
			}
			else if(choiceX==4)
			{
				choiceO=6;
				change_val(choiceO,'O');
				board();
				choiceX=input();
				change_val(choiceX,'X');
				if(choiceX==2)
				{
					choiceO=3;
					change_val(choiceO,'O');
					board();
					printf("\nCPU wins\n");
				}
				else if(choiceX==3)
				{
					choiceO=2;
					change_val(choiceO,'O');
					board();
					printf("\ndraw\n");
				}
				else if(choiceX==8)
				{
					choiceO=2;
					change_val(choiceO,'O');
					board();
					printf("\ndraw\n");
				}
			}
			else if(choiceX==6)
			{
				choiceO=4;
				change_val(choiceO,'O');
				board();
				choiceX=input();
				change_val(choiceX,'X');
				if(choiceX==2)
				{
					choiceO=8;
					change_val(choiceO,'O');
					board();
					printf("\nCPU wins\n");
				}
				else if(choiceX==3)
				{
					choiceO=2;
					change_val(choiceO,'O');
					board();
					printf("\ndraw\n");
				}
				else if(choiceX==8)
				{
					choiceO=2;
					change_val(choiceO,'O');
					board();
					printf("\ndraw\n");
				}
			}
			else if(choiceX==2)
			{
				choiceO=8;
				change_val(choiceO,'O');
				board();
				printf("\nCPU wins\n");
			}
			else if(choiceX==3)
			{
				choiceO=2;
				change_val(choiceO,'O');
				board();
				choiceX=input();
				change_val(choiceX,'X');
				if(choiceX==4)
				{
					choiceO=6;
					change_val(choiceO,'O');
					printf("\ndraw\n");
				}
				else if(choiceX==6)
				{
					choiceO=4;
					change_val(choiceO,'O');
					printf("\ndraw\n");
				}
				else if(choiceX==8)
				{
					choiceO=4;
					change_val(choiceO,'O');
					printf("\ndraw\n");
				}
			}
		}
		else if(choiceX==2)
		{
			choiceO=8;
			change_val(choiceO,'O');
			board();
			choiceX=input();
			change_val(choiceX,'X');
			if(choiceX==7)
			{
				choiceO=3;
				change_val(choiceO,'O');
				board();
				choiceX=input();
				change_val(choiceX,'X');
				if(choiceX==4)
				{
					choiceO=6;
					change_val(choiceO,'O');
					board();
					printf("\ndraw\n");
				}
				else if(choiceX==6)
				{
					choiceO=4;
					change_val(choiceO,'O');
					board();
					printf("\ndraw\n");
				}
				else if(choiceX==1)
				{
					choiceO=4;
					change_val(choiceO,'O');
					board();
					printf("\ndraw\n");
				}
			}
			else
			{
				choiceO=7;
				change_val(choiceO,'O');
				board();
				printf("CPU wins since in all the next cases possible in every case CPU wins no matter where you play\n");
			}
		}
		else if(choiceX==3)
		{
			choiceO=7;
			change_val(choiceO,'O');
			board();
			choiceX=input();
			change_val(choiceX,'X');
			if(choiceX==2)
			{
				choiceO=8;
				change_val(choiceO,'O');
				board();
				printf("\nCPU wins\n");
			}
			else if(choiceX==1)
			{
				choiceO=2;
				change_val(choiceO,'O');
				board();
				choiceX=input();
				change_val(choiceX,'X');
				if(choiceX==4)
				{
					choiceO=6;
					change_val(choiceO,'O');
					board();
					printf("\ndraw\n");
				}
				else if(choiceX==6)
				{
					choiceO=4;
					change_val(choiceO,'O');
					board();
					printf("\ndraw\n");
				}
				else if(choiceX==8)
				{
					choiceO=4;
					change_val(choiceO,'O');
					board();
					printf("\ndraw\n");
				}
			}
			else if(choiceX==8)
			{
				choiceO=2;
				change_val(choiceO,'O');
				board();
				choiceX=input();
				change_val(choiceX,'X');
				if(choiceX==4)
				{
					choiceO=6;
					change_val(choiceO,'O');
					board();
					printf("\ndraw\n");
				}
				else if(choiceX==6)
				{
					choiceO=4;
					change_val(choiceO,'O');
					board();
					printf("\ndraw\n");
				}
				else if(choiceX==1)
				{
					choiceO=4;
					change_val(choiceO,'O');
					board();
					printf("\ndraw\n");
				}
			}
			else if(choiceX==4)
			{
				choiceO=6;
				change_val(choiceO,'O');
				board();
				choiceX=input();
				change_val(choiceX,'X');
				if(choiceX==1)
				{
					choiceO=2;
					change_val(choiceO,'O');
					board();
					printf("\ndraw\n");
				}
				else if(choiceX==2)
				{
					choiceO=8;
					change_val(choiceO,'O');
					board();
					printf("\nCPU wins\n");
				}
				else if(choiceX==8)
				{
					choiceO=2;
					change_val(choiceO,'O');
					board();
					printf("\ndraw\n");
				}
			}
			else if(choiceX==6)
			{
				choiceO=4;
				change_val(choiceO,'O');
				board();
				choiceX=input();
				change_val(choiceX,'X');
				if(choiceX==1)
				{
					choiceO=2;
					change_val(choiceO,'O');
					board();
					printf("\ndraw\n");
				}
				else if(choiceX==2)
				{
					choiceO=8;
					change_val(choiceO,'O');
					board();
					printf("\nCPU wins\n");
				}
				else if(choiceX==8)
				{
					choiceO=2;
					change_val(choiceO,'O');
					board();
					printf("\ndraw\n");
				}
			}
		}
		else if(choiceX==4)
		{
			choiceO=6;
			change_val(choiceO,'O');
			board();
			choiceX=input();
			change_val(choiceX,'X');
			if(choiceX==3)
			{
				choiceO=7;
				change_val(choiceO,'O');
				board();
				choiceX=input();
				change_val(choiceX,'X');
				if(choiceX==8)
				{
					choiceO=2;
					change_val(choiceO,'O');
					board();
					printf("\ndraw\n");
				}
				else if(choiceX==2)
				{
					choiceO=8;
					change_val(choiceO,'O');
					board();
					printf("\nCPU wins\n");
				}
				else if(choiceX==1)
				{
					choiceO=2;
					change_val(choiceO,'O');
					board();
					printf("\ndraw\n");
				}
			}
			else if(choiceX==7 || choiceX==2)
			{
				choiceO=3;
				change_val(choiceO,'O');
				board();
				printf("\nCPU wins\n");
			}
			else if(choiceX==1)
			{
				choiceO=7;
				change_val(choiceO,'O');
				board();
				choiceX=input();
				change_val(choiceX,'X');
				if(choiceX==3)
				{
					choiceO=2;
					change_val(choiceO,'O');
					board();
					printf("\ndraw\n");
				}
				else if(choiceX==2)
				{
					choiceO=3;
					change_val(choiceO,'O');
					board();
					printf("\nCPU wins\n");
				}
				else if(choiceX==8)
				{
					choiceO=2;
					change_val(choiceO,'O');
					board();
					printf("\ndraw\n");
				}
			}
			else if(choiceX==8)
			{
				choiceO=2;
				change_val(choiceO,'O');
				board();
				choiceX=input();
				change_val(choiceX,'X');
				if(choiceX==3)
				{
					choiceO=7;
					change_val(choiceO,'O');
					board();
					printf("\ndraw\n");
				}
				else if(choiceX==1)
				{
					choiceO=7;
					change_val(choiceO,'O');
					board();
					printf("\ndraw\n");
				}
				else if(choiceX==7)
				{
					choiceO=3;
					change_val(choiceO,'O');
					board();
					printf("\nCPU wins\n");
				}
			}
		}
		else if(choiceX==6)
		{
			choiceO=4;
			change_val(choiceO,'O');
			board();
			choiceX=input();
			change_val(choiceX,'X');
			if(choiceX==3)
			{
				choiceO=7;
				change_val(choiceO,'O');
				board();
				choiceX=input();
				change_val(choiceX,'X');
				if(choiceX==8)
				{
					choiceO=2;
					change_val(choiceO,'O');
					board();
					printf("\ndraw\n");
				}
				else if(choiceX==2)
				{
					choiceO=8;
					change_val(choiceO,'O');
					board();
					printf("\nCPU wins\n");
				}
				else if(choiceX==1)
				{
					choiceO=2;
					change_val(choiceO,'O');
					board();
					printf("\ndraw\n");
				}
			}
			else if(choiceX==2)
			{
				choiceO=8;
				change_val(choiceO,'O');
				board();
				choiceX=input();
				change_val(choiceX,'X');
				if(choiceX==1)
				{
					choiceO=3;
					change_val(choiceO,'O');
					board();
					printf("\ndraw\n");
				}
				else if(choiceX==7)
				{
					choiceO=3;
					change_val(choiceO,'O');
					board();
					printf("\ndraw\n");
				}
				else if(choiceX==3)
				{
					choiceO=7;
					change_val(choiceO,'O');
					board();
					printf("\ndraw\n");
				}
			}
			else if(choiceX==1)
			{
				choiceO=2;
				change_val(choiceO,'O');
				board();
				choiceX=input();
				change_val(choiceX,'X');
				if(choiceX==3)
				{
					choiceO=7;
					change_val(choiceO,'O');
					board();
					printf("\ndraw\n");
				}
				else if(choiceX==7)
				{
					choiceO=3;
					change_val(choiceO,'O');
					board();
					printf("\ndraw\n");
				}
				else if(choiceX==8)
				{
					choiceO=7;
					change_val(choiceO,'O');
					board();
					printf("\ndraw\n");
				}
			}
			else if(choiceX==7)
			{
				choiceO=3;
				change_val(choiceO,'O');
				board();
				choiceX=input();
				change_val(choiceX,'X');
				if(choiceX==2)
				{
					choiceO=8;
					change_val(choiceO,'O');
					board();
					printf("\ndraw\n");
				}
				else if(choiceX==1)
				{
					choiceO=2;
					change_val(choiceO,'O');
					board();
					printf("\ndraw\n");
				}
				else if(choiceX==8)
				{
					choiceO=2;
					change_val(choiceO,'O');
					board();
					printf("\ndraw\n");
				}
			}
			else if(choiceX==8)
			{
				choiceO=2;
				change_val(choiceO,'O');
				board();
				choiceX=input();
				change_val(choiceX,'X');
				if(choiceX==7)
				{
					choiceO=3;
					change_val(choiceO,'O');
					board();
					printf("\ndraw\n");
				}
				else if(choiceX==3)
				{
					choiceO=7;
					change_val(choiceO,'O');
					board();
					printf("\ndraw\n");
				}
				else if(choiceX==1)
				{
					choiceO=7;
					change_val(choiceO,'O');
					board();
					printf("\ndraw\n");
				}
			}
		}
		else if(choiceX==7)
		{
			choiceO=3;
			change_val(choiceO,'O');
			board();
			choiceX=input();
			change_val(choiceX,'X');
			if(choiceX==6)
			{
				choiceO=4;
				change_val(choiceO,'O');
				board();
				choiceX=input();
				change_val(choiceX,'X');
				if(choiceX==8)
				{
					choiceO=2;
					change_val(choiceO,'O');
					board();
					printf("\ndraw\n");
				}
				else if(choiceX==2)
				{
					choiceO=8;
					change_val(choiceO,'O');
					board();
					printf("\ndraw\n");
				}
				else if(choiceX==1)
				{
					choiceO=2;
					change_val(choiceO,'O');
					board();
					printf("\ndraw\n");
				}
			}
			else if(choiceX==4)
			{
				choiceO=6;
				change_val(choiceO,'O');
				board();
				printf("\nCPU wins\n");
			}
			else if(choiceX==1)
			{
				choiceO=4;
				change_val(choiceO,'O');
				board();
				choiceX=input();
				change_val(choiceX,'X');
				if(choiceX==6)
				{
					choiceO=4;
					change_val(choiceO,'O');
					board();
					printf("\ndraw\n");
				}
				else if(choiceX==2)
				{
					choiceO=8;
					change_val(choiceO,'O');
					board();
					printf("\ndraw\n");
				}
				else if(choiceX==8)
				{
					choiceO=2;
					change_val(choiceO,'O');
					board();
					printf("\ndraw\n");
				}
			}
			else if(choiceX==2)
			{
				choiceO=8;
				change_val(choiceO,'O');
				board();
				choiceX=input();
				change_val(choiceX,'X');
				if(choiceX==4)
				{
					choiceO=6;
					change_val(choiceO,'O');
					board();
					printf("\nCPU wins\n");
				}
				else if(choiceX==6)
				{
					choiceO=4;
					change_val(choiceO,'O');
					board();
					printf("\ndraw\n");
				}
				else if(choiceX==1)
				{
					choiceO=4;
					change_val(choiceO,'O');
					board();
					printf("\ndraw\n");
				}
			}
			else if(choiceX==8)
			{
				choiceO=2;
				change_val(choiceO,'O');
				board();
				choiceX=input();
				change_val(choiceX,'X');
				if(choiceX==1)
				{
					choiceO=4;
					change_val(choiceO,'O');
					board();
					printf("\ndraw\n");
				}
				else if(choiceX==4)
				{
					choiceO=6;
					change_val(choiceO,'O');
					board();
					printf("\ndraw\n");
				}
				else if(choiceX==6)
				{
					choiceO=4;
					change_val(choiceO,'O');
					board();
					printf("\ndraw\n");
				}
			}
		}
		else if(choiceX==8)
		{
			choiceO=2;
			change_val(choiceO,'O');
			board();
			choiceX=input();
			change_val(choiceX,'X');
			if(choiceX==3)
			{
				choiceO=7;
				change_val(choiceO,'O');
				board();
				choiceX=input();
				change_val(choiceX,'X');
				if(choiceX==4)
				{
					choiceO=6;
					change_val(choiceO,'O');
					board();
					printf("\ndraw\n");
				}
				else if(choiceX==6)
				{
					choiceO=4;
					change_val(choiceO,'O');
					board();
					printf("\ndraw\n");
				}
				else if(choiceX==1)
				{
					choiceO=4;
					change_val(choiceO,'O');
					board();
					printf("\ndraw\n");
				}
			}
			else if(choiceX==1)
			{
				choiceO=4;
				change_val(choiceO,'O');
				board();
				choiceX=input();
				change_val(choiceX,'X');
				if(choiceX==3)
				{
					choiceO=7;
					change_val(choiceO,'O');
					board();
					printf("\ndraw\n");
				}
				else if(choiceX==7)
				{
					choiceO=3;
					change_val(choiceO,'O');
					board();
					printf("\ndraw\n");
				}
				else if(choiceX==6)
				{
					choiceO=7;
					change_val(choiceO,'O');
					board();
					printf("\ndraw\n");
				}
			}
			else if(choiceX==4)
			{
				choiceO=6;
				change_val(choiceO,'O');
				board();
				choiceX=input();
				change_val(choiceX,'X');
				if(choiceX==3)
				{
					choiceO=7;
					change_val(choiceO,'O');
					board();
					printf("\ndraw\n");
				}
				else if(choiceX==7)
				{
					choiceO=3;
					change_val(choiceO,'O');
					board();
					printf("\nCPU wins\n");
				}
				else if(choiceX==1)
				{
					choiceO=7;
					change_val(choiceO,'O');
					board();
					printf("\ndraw\n");
				}
			}
			else if(choiceX==6)
			{
				choiceO=4;
				change_val(choiceO,'O');
				board();
				choiceX=input();
				change_val(choiceX,'X');
				if(choiceX==7)
				{
					choiceO=3;
					change_val(choiceO,'O');
					board();
					printf("\ndraw\n");
				}
				else if(choiceX==3)
				{
					choiceO=7;
					change_val(choiceO,'O');
					board();
					printf("\ndraw\n");
				}
				else if(choiceX==1)
				{
					choiceO=3;
					change_val(choiceO,'O');
					board();
					printf("\ndraw\n");
				}
			}
			else if(choiceX==7)
			{
				choiceO=3;
				change_val(choiceO,'O');
				board();
				choiceX=input();
				change_val(choiceX,'X');
				if(choiceX==1)
				{
					choiceO=4;
					change_val(choiceO,'O');
					board();
					printf("\ndraw\n");
				}
				else if(choiceX==4)
				{
					choiceO=1;
					change_val(choiceO,'O');
					board();
					printf("\nCPU wins\n");
				}
				else if(choiceX==6)
				{
					choiceO=4;
					change_val(choiceO,'O');
					board();
					printf("\ndraw\n");
				}
			}
		}
	}
	//else if()	
}

