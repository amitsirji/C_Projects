#include<stdio.h>
#include<conio.h>

void newregister();
void registered1();
void pass();
void questions();
void loading();
char choice();
void randomize ( int arr[], int n );

void main()
{
	char x,a;
	clrscr();
	textcolor(CYAN+BLINK);
	cprintf("\n\n\n\n\n\n                               Welcome To The IT Quiz");
	textcolor(WHITE);
	printf("\n\n\n\n Cerated By----> Kandarp Dave & Dhrumit Fadadu");
	printf("\n\n Under the Guidance of Mr. Ashwin Dobariya");
	getch();
	clrscr();
	textcolor(LIGHTRED);
	cprintf("\n\n\n\n\n\n Are you Registered Player??");
	textcolor(WHITE);
	printf("\n\n Press Y or N : ");
	scanf("%c",&x);

	if(x=='y')
	{
		registered1();
		pass();
	}
	else
	{
		newregister();
		pass();
	}
	clrscr();
	a=choice();
	if(a=='y')
	{
		clrscr();
		loading();
		questions();
		getch();
	}
	else
	{
		clrscr();
		textcolor(MAGENTA);
		cprintf("\n\n\n\n\n\n\n\n\n\n\n                        Byee Byee........");
		textcolor(WHITE);
	}
	getch();
}

char choice()
{
	char a;
	textcolor(LIGHTBLUE);
	cprintf("\n\n\n\n\n\n\n\n\n\n\n                        Do you wanted To play Game ??");
	printf("\n\n\n                        Enter your choice :: ");
	textcolor(WHITE);
	fflush(stdin);
	scanf("%c",&a);
	return a;
}

void newregister()
{
	char name[20],surname[20],contact[15],mail[50],userid[20],pass[20];
	clrscr();
	textcolor(BROWN);
	cprintf("\n\n\n\n\nName : ");
	fflush(stdin);
	scanf("%s",name);
	textcolor(CYAN);
	cprintf("\nSurname : ");
	fflush(stdin);
	scanf("%s",surname);
	fflush(stdin);
	textcolor(GREEN);
	cprintf("\nContact No. : ");
	fflush(stdin);
	scanf("%s",contact);
	textcolor(BROWN);
	cprintf("\nE-mail id : ");
	fflush(stdin);
	scanf("%s",mail);
	textcolor(CYAN);
	cprintf("\nUser Id : ");
	fflush(stdin);
	scanf("%s",userid);
	textcolor(GREEN);
	cprintf("\nPassword : ");
	textcolor(WHITE);

}

void registered1()
{
	char userid[20],pass[20];
	clrscr();
	textcolor(MAGENTA);
	cprintf("\n\n\n\n\nUser Id : ");
	textcolor(WHITE);
	scanf("%s",userid);
	textcolor(MAGENTA);
	cprintf("\nPassword : ");
	textcolor(WHITE);
}

void pass()
{
	char ch,str[30];
	int i=0;

	while(1)
	{
		ch=getch();
		if(ch==13)
			break;
		str[i]=ch;
		printf("*");
		i++;
	}
}

void questions()
{
	char que[15][100] = {"Who is Founder of Google?",
			     "SMPS Means__________." ,
			     "Who is CEO Of Microsoft?",
				 "Who developed C Language?",
				 "Which of the following is developed Java?",
				 "Which of the following is the first version Of Android?",
				 "Who is Founder Of sixth seance Technology?",
				 "Which of the following OS is the free ware?",
				 "Who is Founder of Microsoft?",
				 "Generally Data transfer speed Of Hard disc________",
				 "Which generation's computers are based on Vacuum tubes?",
				 "First Supper computer is made by ________ in _______.",
				 "Which IT company's Nick name is The Big Blue??",
				 "Which below file extension is not a type of compressed file?",
				 "To move to the bottom of a document, press_______."};
	char a[15][30] = {"A. Larry Page and Sergey Brin" ,"A. Simple Mail Power Source" ,"A. Satya Nadella","A. Andrea Murphy",
			"A. Google","A. Froyo","A. Pranav Mistry","A. Windows","A. Steve Wozniak, Ronald Wayne","A. 1000 rpm",
			"A. Second","A. IBM , USA ","A. Microsoft","A. .zip","A. Auto Summarize"};
	char b[15][30] = {"B. Steve Jobs","B. Switched-mode power supply","B. Bill Gates","B. Russell Flannery",
			"B. Microsoft","B. Gingerbread","B. John Koppisch","B. RIM","B. Bill Gates, Paul Allen","B. 2500 rpm",
			"B. First","B. Microsoft , USA","B. Apple","B. .rar","B. Ctrl key + End key"};
	char c[15][30] = {"C. Larry Ellison","C. Standard Mode Power Source","C. Vishal Sikka","C. Dennis Ritchie",
			"C. Apple","C. Alpha","C. Ryan Mac","C. Linux","C. Satya Nadella","C. 9000 rpm",
			"C. Third","C. IBM , France","C. IBM","C. .tar","C. End key"};
	char d[15][30] = {"D. Edgar F. Codd","D. Switched Mail Power Supply","D. Natarajan Chandrasekaran","D. Tom Van Riper",
			"D. Oracle","D. Beta","D. Nathan Vardi","D. MAC","D. Arthur D. Levinson","D. 7200 rpm",
			"D. Fourth","D.  Microsoft , France","D. Oracle","D. .jpeg","D. Home key"};
	char correct[15][30] = {"A. Larry Page and Sergey Brin","B. Switched-mode power supply","A. Satya Nadella","C. Dennis Ritchie",
			"D. Oracle","C. Alpha","A. Pranav Mistry","C. Linux","B. Bill Gates, Paul Allen","D. 7200 rpm","B. First",
			"A. IBM , USA ","C. IBM","D. .jpeg","B. Ctrl key + End key"};

	char ans[15] = {'a','b','a','c','d','c','a','c','b','d','b','a','c','d','b'};
	char ch;
	int i;

	int questionSequence[] = {0 , 1, 2, 3, 4, 5, 6, 7, 8 ,9 ,10 ,11 ,12 ,13 ,14};
	randomize (questionSequence, 15);
	for(i=0;i<15;i++)
	{
		clrscr();
		textcolor(BROWN);
		printf("\n\n\n\n\n\n");
		cprintf("%d. %s", i, que[questionSequence[i]]);
		textcolor(WHITE);
		printf("\n\n");
		textcolor(YELLOW);
		cputs(a[questionSequence[i]]);
		printf("\n");
		cputs(b[questionSequence[i]]);
		printf("\n");
		cputs(c[questionSequence[i]]);
		printf("\n");
		cputs(d[questionSequence[i]]);
		printf("\n");
		textcolor(WHITE);

		printf("\n Enter your choice :");
		fflush(stdin);
		scanf("%c",&ch);

		if(ch == ans[questionSequence[i]])
		{
			textcolor(GREEN+BLINK);
			cprintf("\n                                   Correct answer ");
			textcolor(WHITE);
			getch();
		}
		else
		{
			textcolor(RED+BLINK);
			cprintf("\n                                   Incorrect answer\n\n");
			textcolor(CYAN);
			getch();
			printf("\nCorrect Answer Is  ");
			cputs(correct[questionSequence[i]]);
			textcolor(WHITE);
			getch();
			break;
		}
	}
	if(i==15)
	{
		clrscr();
		textcolor(GREEN+BLINK);
		cprintf("\n\n\n\n\n\n\n\n\n\n\n                   Congratulation You won the game");
	}
	else
	{
		clrscr();
		textcolor(RED);
		cprintf("\n\n\n\n\n\n\n\n\n\n\n                        Sorry You lost the game!!!");
	}
}

void loading()
{
	int c,d;
	for(c=0;c<=0;c++)
		{
			printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\tLoading\n\t\t\t");
			textcolor(WHITE);
			for(d=4;d<=27;d++)
			{
				textcolor(LIGHTGREEN);
				cprintf("*");
				textcolor(WHITE);
				delay(150);
			}

		}
}

void randomize ( int arr[], int n )
{
    int i;
    for (i=n-1;i>0;i--)
    {
	int j = rand() % (i);
	int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
		srand ( time(NULL) );
    }
}