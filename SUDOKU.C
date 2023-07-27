#include<stdio.h>
#include<conio.h>
#include<dos.h>
int a[9][9];
int b[9][9];
int c[9][9];
int d[9][9];
int i,j;
void registration();
void easy();
void medium();
void hard();
void displayeasy(int a[9][9]);
void displaymedium(int b[9][9]);
void displayhard(int c[9][9]);
void check();
void main()
{
	int choice;
	clrscr();
	registration();
	choose:
	printf("Enter your choice of difficulty:");
	printf("\n\tEnter '1' for easy\n\tEnter '2' for medium\n\tEnter '3' for hard\n\t");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:   clrscr();
			  easy();
			  break;
		case 2:   clrscr();
			  medium();
			  break;
		case 3:   clrscr();
			  hard();
			  break;
		default:  printf("\nInvalid choice\nEnter your choice again:");
			  goto choose;
	}
	getch();
	clrscr();
	printf("\n\n\n\n\n\t\tThank you for playing.... Have a wonderful day^_^");
	printf("\n\n\t\t\t\tGood-Bye^_^");
	getch();
}

void registration()
{
	int age,contact,i,j,k;
	char name[25],ch,str[12],gender,username[10];
	clrscr();

	printf("\n\n\n\t\t\t Welcome to Sudoku Solver");
	printf("\n\n\t\t\tRegistration Form\n");
	printf("\n\nEnter the player's name: ");
	fflush(stdin);
	scanf("%s",&name);
	printf("\nEnter the palyer's age: ");
	fflush(stdin);
	scanf("%d",&age);
	printf("\nEnter the palyer's gender: ");
	fflush(stdin);
	scanf("%c",&gender);
	printf("\nEnter the palyer's contact number: ");
	scanf("%d",&contact);
	clrscr();
	for(j=0;j<1;j++)
	{
		printf("\n\n\n\n\n\n\n\t\t\t\tLoading.. Please wait\n\t\t\t");
		for(k=0;k<=35;k++)
		{
			printf(".");
			delay(250);
		}
		clrscr();
	}
       printf("\n\t\t\tRegistration Form");
	printf("\nUsername: ");
	fflush(stdin);
	scanf("%s",username);
	printf("\nPassword: ");
	while(1)
	{
		ch=getch();
		if(ch==13)
			break;
		str[i]=ch;
		printf("*");
		i++;
	}
	str[i]='\0';
	printf("\n\n\nCongratulations you have successfully got your registration done\n\n");
	clrscr();
	printf("\n\n\t\tRULES OF SUDOKU GAME");
	printf("\n\n\n1.Sudoku game begins with some of the grid cells already filled with numbers");
	printf("\n2.The object of Sudoku is to fill the other empty cells with numbers between 1 and 9");
	printf("\n   -->Number can appear only once on each row");
	printf("\n   -->Number can appear only once on each column");
	printf("\n   -->Number can appear only once on each region");
	getch();
	clrscr();
	printf("\n\n\t\t\tHOW TO ENTER ELEMENTS\n");
	printf("\n\n1.Enter the elements by specifying the row and column number of\n  corresponding location");
	printf("\n\n2.Each row and column start from 1 and end at 9 (not from 0 to 8)");
	printf("\n\n3.After finishing entering the elements or if you want to quit the game, enter zeroes (0)\n  for row or column");
	getch();
	clrscr();
}

void easy()
{
	clrscr();
	a[0][0]=1; a[0][1]=0; a[0][2]=3; a[0][3]=4; a[0][4]=0; a[0][5]=0; a[0][6]=7; a[0][7]=0; a[0][8]=9;
	a[1][0]=0; a[1][1]=5; a[1][2]=6; a[1][3]=0; a[1][4]=8; a[1][5]=9; a[1][6]=0; a[1][7]=2; a[1][8]=3;
	a[2][0]=0; a[2][1]=8; a[2][2]=9; a[2][3]=1; a[2][4]=0; a[2][5]=3; a[2][6]=4; a[2][7]=0; a[2][8]=6;
	a[3][0]=2; a[3][1]=1; a[3][2]=4; a[3][3]=0; a[3][4]=6; a[3][5]=5; a[3][6]=0; a[3][7]=9; a[3][8]=7;
	a[4][0]=3; a[4][1]=0; a[4][2]=0; a[4][3]=8; a[4][4]=0; a[4][5]=7; a[4][6]=0; a[4][7]=1; a[4][8]=4;
	a[5][0]=8; a[5][1]=0; a[5][2]=7; a[5][3]=0; a[5][4]=1; a[5][5]=4; a[5][6]=0; a[5][7]=6; a[5][8]=5;
	a[6][0]=0; a[6][1]=3; a[6][2]=1; a[6][3]=0; a[6][4]=4; a[6][5]=0; a[6][6]=9; a[6][7]=7; a[6][8]=8;
	a[7][0]=6; a[7][1]=4; a[7][2]=0; a[7][3]=9; a[7][4]=7; a[7][5]=0; a[7][6]=5; a[7][7]=3; a[7][8]=1;
	a[8][0]=0; a[8][1]=7; a[8][2]=8; a[8][3]=0; a[8][4]=0; a[8][5]=1; a[8][6]=0; a[8][7]=4; a[8][8]=2;
	printf("\n\n\t\t\t\tEASY\n");
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			printf("%d  ",a[i][j]);
		}
		printf("\n");
	}
	solve:
	printf("\nEnter the positions:");
	scanf("%d%d",&i,&j);
	if(i==0 || j==0)
	{
		displayeasy(a);
	}
	else
	{
		if(a[i-1][j-1]==0)
		{
			printf("\nEnter the corresponding number:");
			scanf("%d",&a[i-1][j-1]);
			clrscr();
			for(i=0;i<9;i++)
			{
				for(j=0;j<9;j++)
				{
					printf("%d  ",a[i][j]);
				}
				printf("\n");
			}
			goto solve;
		}
		else
		{
			printf("\nThe number is fixed...\nRe-Enter the positions");
			goto solve;
		}
	}
}


void displayeasy(int a[9][9])
{
	int flag=0;
	char choice;
	clrscr();
	b[0][0]=1; b[0][1]=2; b[0][2]=3; b[0][3]=4; b[0][4]=5; b[0][5]=6; b[0][6]=7; b[0][7]=8; b[0][8]=9;
	b[1][0]=4; b[1][1]=5; b[1][2]=6; b[1][3]=7; b[1][4]=8; b[1][5]=9; b[1][6]=1; b[1][7]=2; b[1][8]=3;
	b[2][0]=7; b[2][1]=8; b[2][2]=9; b[2][3]=1; b[2][4]=2; b[2][5]=3; b[2][6]=4; b[2][7]=5; b[2][8]=6;
	b[3][0]=2; b[3][1]=1; b[3][2]=4; b[3][3]=3; b[3][4]=6; b[3][5]=5; b[3][6]=8; b[3][7]=9; b[3][8]=7;
	b[4][0]=3; b[4][1]=6; b[4][2]=5; b[4][3]=8; b[4][4]=9; b[4][5]=7; b[4][6]=2; b[4][7]=1; b[4][8]=4;
	b[5][0]=8; b[5][1]=9; b[5][2]=7; b[5][3]=2; b[5][4]=1; b[5][5]=4; b[5][6]=3; b[5][7]=6; b[5][8]=5;
	b[6][0]=5; b[6][1]=3; b[6][2]=1; b[6][3]=6; b[6][4]=4; b[6][5]=2; b[6][6]=9; b[6][7]=7; b[6][8]=8;
	b[7][0]=6; b[7][1]=4; b[7][2]=2; b[7][3]=9; b[7][4]=7; b[7][5]=8; b[7][6]=5; b[7][7]=3; b[7][8]=1;
	b[8][0]=9; b[8][1]=7; b[8][2]=8; b[8][3]=5; b[8][4]=3; b[8][5]=1; b[8][6]=6; b[8][7]=4; b[8][8]=2;
	printf("\nHave you solved the Sudoku?\n\n");
	printf("Enter 'y' for yes and enter 'n' for no\n");
	fflush(stdin);
	scanf("%c",&choice);
	clrscr();
	if(choice=='y' || choice=='Y')
	{
		printf("\n\nYour solved Sudoku is\n\n");
		for(i=0;i<9;i++)
		{
			for(j=0;j<9;j++)
			{
				printf("%d  ",a[i][j]);
			}
			printf("\n");
		}
		for(i=0;i<9;i++)
		{
			for(j=0;j<9;j++)
			{
				if(a[i][j]==b[i][j])
				{
					flag=1;
				}
				else
				{
					flag=0;
					break;
				}
			}
		}

		if(flag==1)
			printf("\n\n\tCongratulations!!!!! You have won the game");
		else
			printf("\n\n\tSorry.... You lost.... Better luck next time");
	}
	else
	{
		clrscr();
		printf("\nThe solution is\n");
		for(i=0;i<9;i++)
		{
			for(j=0;j<9;j++)
			{
				printf("%d  ",b[i][j]);
			}
			printf("\n");
		}
	}
}


void medium()
{
	clrscr();
	a[0][0]=0; a[0][1]=0; a[0][2]=0; a[0][3]=0; a[0][4]=0; a[0][5]=0; a[0][6]=0; a[0][7]=0; a[0][8]=0;
	a[1][0]=5; a[1][1]=0; a[1][2]=0; a[1][3]=0; a[1][4]=0; a[1][5]=4; a[1][6]=8; a[1][7]=0; a[1][8]=0;
	a[2][0]=0; a[2][1]=0; a[2][2]=1; a[2][3]=0; a[2][4]=0; a[2][5]=0; a[2][6]=0; a[2][7]=3; a[2][8]=4;
	a[3][0]=8; a[3][1]=0; a[3][2]=7; a[3][3]=0; a[3][4]=5; a[3][5]=3; a[3][6]=0; a[3][7]=4; a[3][8]=2;
	a[4][0]=0; a[4][1]=0; a[4][2]=3; a[4][3]=0; a[4][4]=2; a[4][5]=0; a[4][6]=6; a[4][7]=0; a[4][8]=0;
	a[5][0]=0; a[5][1]=0; a[5][2]=4; a[5][3]=0; a[5][4]=9; a[5][5]=0; a[5][6]=5; a[5][7]=0; a[5][8]=0;
	a[6][0]=6; a[6][1]=0; a[6][2]=0; a[6][3]=0; a[6][4]=0; a[6][5]=5; a[6][6]=9; a[6][7]=0; a[6][8]=8;
	a[7][0]=0; a[7][1]=0; a[7][2]=0; a[7][3]=0; a[7][4]=0; a[7][5]=9; a[7][6]=0; a[7][7]=0; a[7][8]=0;
	a[8][0]=0; a[8][1]=0; a[8][2]=0; a[8][3]=0; a[8][4]=3; a[8][5]=8; a[8][6]=4; a[8][7]=6; a[8][8]=5;
	printf("\n\n\t\t\t\tMEDIUM\n");
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			printf("%d  ",a[i][j]);
		}
		printf("\n");
	}
	solve1:
	printf("\nEnter the positions:");
	scanf("%d%d",&i,&j);
	if(i==0 || j==0)
	{
		displaymedium(b);
	}
	else
	{
		if(a[i-1][j-1]==0)
		{
			printf("\nEnter the corresponding number:");
			scanf("%d",&a[i-1][j-1]);
			clrscr();
			for(i=0;i<9;i++)
			{
				for(j=0;j<9;j++)
				{
					printf("%d  ",a[i][j]);
				}
				printf("\n");
			}
			goto solve1;
		}
		else
		{
			printf("\nThe number is fixed...\nRe-Enter the positions");
			goto solve1;
		}
	}
}


void displaymedium()
{
	int flag=0;
	char choice;
	clrscr();
	c[0][0]=3; c[0][1]=4; c[0][2]=8; c[0][3]=9; c[0][4]=1; c[0][5]=2; c[0][6]=7; c[0][7]=5; c[0][8]=6;
	c[1][0]=5; c[1][1]=2; c[1][2]=6; c[1][3]=3; c[1][4]=7; c[1][5]=4; c[1][6]=8; c[1][7]=9; c[1][8]=1;
	c[2][0]=9; c[2][1]=7; c[2][2]=1; c[2][3]=5; c[2][4]=8; c[2][5]=6; c[2][6]=2; c[2][7]=3; c[2][8]=4;
	c[3][0]=8; c[3][1]=9; c[3][2]=7; c[3][3]=6; c[3][4]=5; c[3][5]=3; c[3][6]=1; c[3][7]=4; c[3][8]=2;
	c[4][0]=1; c[4][1]=5; c[4][2]=3; c[4][3]=4; c[4][4]=2; c[4][5]=7; c[4][6]=6; c[4][7]=8; c[4][8]=9;
	c[5][0]=2; c[5][1]=6; c[5][2]=4; c[5][3]=8; c[5][4]=9; c[5][5]=1; c[5][6]=5; c[5][7]=7; c[5][8]=3;
	c[6][0]=6; c[6][1]=3; c[6][2]=2; c[6][3]=7; c[6][4]=4; c[6][5]=5; c[6][6]=9; c[6][7]=1; c[6][8]=8;
	c[7][0]=4; c[7][1]=8; c[7][2]=5; c[7][3]=1; c[7][4]=6; c[7][5]=9; c[7][6]=3; c[7][7]=2; c[7][8]=5;
	c[8][0]=7; c[8][1]=1; c[8][2]=9; c[8][3]=2; c[8][4]=3; c[8][5]=8; c[8][6]=4; c[8][7]=6; c[8][8]=5;
	printf("\nHave you solved the Sudoku?\n\n");
	printf("Enter 'y' for yes and enter 'n' for no\n");
	fflush(stdin);
	scanf("%c",&choice);
	clrscr();
	if(choice=='y' || choice=='Y')
	{
		printf("\n\nYour solved Sudoku is\n\n");
		for(i=0;i<9;i++)
		{
			for(j=0;j<9;j++)
			{
				printf("%d  ",a[i][j]);
			}
			printf("\n");
		}
		for(i=0;i<9;i++)
		{
			for(j=0;j<9;j++)
			{
				if(a[i][j]==c[i][j])
				{
					flag=1;
				}
				else
				{
					flag=0;
					break;
				}
			}
		}

		if(flag==1)
			printf("\n\n\tCongratulations!!!!! You have won the game");
		else
			printf("\n\n\tSorry.... You lost.... Better luck next time");
	}
	else
	{
		clrscr();
		printf("\nThe solution is\n");
		for(i=0;i<9;i++)
		{
			for(j=0;j<9;j++)
			{
				printf("%d  ",c[i][j]);
			}
			printf("\n");
		}
	}
}


void hard()
{
	clrscr();
	a[0][0]=0; a[0][1]=0; a[0][2]=0; a[0][3]=9; a[0][4]=3; a[0][5]=6; a[0][6]=4; a[0][7]=0; a[0][8]=0;
	a[1][0]=0; a[1][1]=0; a[1][2]=0; a[1][3]=0; a[1][4]=1; a[1][5]=0; a[1][6]=0; a[1][7]=9; a[1][8]=2;
	a[2][0]=0; a[2][1]=0; a[2][2]=0; a[2][3]=0; a[2][4]=0; a[2][5]=0; a[2][6]=0; a[2][7]=0; a[2][8]=0;
	a[3][0]=0; a[3][1]=0; a[3][2]=0; a[3][3]=2; a[3][4]=8; a[3][5]=0; a[3][6]=0; a[3][7]=0; a[3][8]=7;
	a[4][0]=0; a[4][1]=4; a[4][2]=0; a[4][3]=0; a[4][4]=0; a[4][5]=7; a[4][6]=0; a[4][7]=0; a[4][8]=3;
	a[5][0]=0; a[5][1]=0; a[5][2]=0; a[5][3]=0; a[5][4]=0; a[5][5]=3; a[5][6]=0; a[5][7]=0; a[5][8]=5;
	a[6][0]=8; a[6][1]=9; a[6][2]=0; a[6][3]=0; a[6][4]=0; a[6][5]=0; a[6][6]=0; a[6][7]=5; a[6][8]=0;
	a[7][0]=5; a[7][1]=1; a[7][2]=0; a[7][3]=3; a[7][4]=4; a[7][5]=0; a[7][6]=7; a[7][7]=0; a[7][8]=0;
	a[8][0]=6; a[8][1]=0; a[8][2]=0; a[8][3]=0; a[8][4]=0; a[8][5]=5; a[8][6]=0; a[8][7]=8; a[8][8]=0;
	printf("\n\n\t\t\t\tHARD\n");
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			printf("%d  ",a[i][j]);
		}
		printf("\n");
	}
	solve2:
	printf("\nEnter the positions:");
	scanf("%d%d",&i,&j);
	if(i==0 || j==0)
	{
		displayhard(c);
	}
	else
	{
		if(a[i-1][j-1]==0)
		{
			printf("\nEnter the corresponding number:");
			scanf("%d",&a[i-1][j-1]);
			clrscr();
			for(i=0;i<9;i++)
			{
				for(j=0;j<9;j++)
				{
					printf("%d  ",a[i][j]);
				}
				printf("\n");
			}
			goto solve2;
		}
		else
		{
			printf("\nThe number is fixed...\nRe-Enter the positions");
			goto solve2;
		}
	}
}


void displayhard()
{
	int flag=0;
	char choice;
	clrscr();
	d[0][0]=1; d[0][1]=2; d[0][2]=5; d[0][3]=9; d[0][4]=3; d[0][5]=6; d[0][6]=4; d[0][7]=7; d[0][8]=8;
	d[1][0]=7; d[1][1]=6; d[1][2]=3; d[1][3]=8; d[1][4]=1; d[1][5]=4; d[1][6]=5; d[1][7]=9; d[1][8]=2;
	d[2][0]=4; d[2][1]=8; d[2][2]=9; d[2][3]=5; d[2][4]=7; d[2][5]=2; d[2][6]=1; d[2][7]=3; d[2][8]=6;
	d[3][0]=3; d[3][1]=5; d[3][2]=1; d[3][3]=2; d[3][4]=8; d[3][5]=9; d[3][6]=6; d[3][7]=4; d[3][8]=7;
	d[4][0]=9; d[4][1]=4; d[4][2]=6; d[4][3]=1; d[4][4]=5; d[4][5]=7; d[4][6]=8; d[4][7]=2; d[4][8]=3;
	d[5][0]=2; d[5][1]=7; d[5][2]=8; d[5][3]=4; d[5][4]=6; d[5][5]=3; d[5][6]=9; d[5][7]=1; d[5][8]=5;
	d[6][0]=8; d[6][1]=9; d[6][2]=7; d[6][3]=6; d[6][4]=2; d[6][5]=1; d[6][6]=3; d[6][7]=5; d[6][8]=4;
	d[7][0]=5; d[7][1]=1; d[7][2]=2; d[7][3]=3; d[7][4]=4; d[7][5]=8; d[7][6]=7; d[7][7]=6; d[7][8]=9;
	d[8][0]=6; d[8][1]=3; d[8][2]=4; d[8][3]=7; d[8][4]=9; d[8][5]=5; d[8][6]=2; d[8][7]=8; d[8][8]=1;
	printf("\nHave you solved the Sudoku?\n\n");
	printf("Enter 'y' for yes and enter 'n' for no\n");
	fflush(stdin);
	scanf("%c",&choice);
	clrscr();
	if(choice=='y' || choice=='Y')
	{
		printf("\n\nYour solved Sudoku is\n\n");
		for(i=0;i<9;i++)
		{
			for(j=0;j<9;j++)
			{
				printf("%d  ",a[i][j]);
			}
			printf("\n");
		}
		for(i=0;i<9;i++)
		{
			for(j=0;j<9;j++)
			{
				if(a[i][j]==d[i][j])
				{
					flag=1;
				}
				else
				{
					flag=0;
					break;
				}
			}
		}

		if(flag==1)
			printf("\n\n\tCongratulations!!!!! You have won the game");
		else
			printf("\n\n\tSorry.... You lost.... Better luck next time");
	}
	else
	{
		clrscr();
		printf("\nThe solution is\n");
		for(i=0;i<9;i++)
		{
			for(j=0;j<9;j++)
			{
				printf("%d  ",d[i][j]);
			}
			printf("\n");
		}
	}
}
