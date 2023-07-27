#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>

#define ESC 27
// escape key

void txt_ESC_fail();
void txt_default();
void txt_inverse();
void txt_success();

void encr_decr(int x);

int sign_in();
int sign_up();

int rec_add();
int rec_modify();
int rec_delete();
void rec_list();
int rec_search();
int bill_pay(int x);

int user_details();

void num_converter(int x);
int f_user_opener(int x);

typedef struct
{
	char id[14];
	char name[43];
	char ph_no[14];
	long int amount;
}customer;

customer cust;

typedef struct
{
	char fname[43];
	char address[65];
	char gender[3];
	long int age;
	char mobile[15];
	char uname[10];
	char pwd[35];
}usr;

usr user;

char in_age[5];
long int num_age[5];
char in_amount[8];
long int num_amount[8];

FILE *f_main,*f_main2,*f_user,*f_user2;

void main()
{
	int si,su;
	int *signin=0,*signup=0;
	int ch_case;

	char ch_st,ch_mn;
	char *choice_start,*choice_menu;

	signin=&si,signup=&su;
	choice_start=&ch_st,choice_menu=&ch_mn;

	fcloseall();

	encr_decr(1);

	sign_in_menu:

	clrscr();

	txt_ESC_fail();
	printf("\t\t\t\t\t\t\t   ");
	cprintf("Press ESC key to exit");
	printf("\n\n\n\n");

	txt_inverse();
	cprintf("                 ษออออออออออออออออออออออออออออออออออออออออออออป                 ");
	cprintf("                 *  Welcome to the telephone billing manager  *                 ");
	cprintf("                 ศออออออออออออออออออออออออออออออออออออออออออออผ                 ");

	txt_default();
	printf("\n\n\t\t Please choose any one by pressing the desired key.\n");

	printf("\n\t\t1 : Sign-in (If you are a registered tele-operator).");
	printf("\n\t\t2 : Sign-up (If you are a new tele-operator).");

	printf("\n\n\t\t\t      Enter your choice : ");

	choose_sign:

	gotoxy(51,16);
	*choice_start=getch();

	if(*choice_start=='1')
	{
		sign_in:
		*signin=sign_in();

		if((*signin)==0)
		{
			main_menu:
			fcloseall();

			clrscr();
			txt_ESC_fail();
			printf("\t\t\t\t");
			cprintf("Press ESC key to sign-out and go to sign-in menu");
			printf("\n\n\n\n");

			txt_inverse();
			cprintf("                                  ษอออออออออออป                                 ");
			cprintf("                                  * Main Menu *                                 ");
			cprintf("                                  ศอออออออออออผ                                 ");

			txt_default();
			printf("\n\n\t\t Please choose any one by pressing the desired key.\n");

			printf("\n\t\t\t 1. Add a new record.");
			printf("\n\t\t\t 2. Modify an existing record.");
			printf("\n\t\t\t 3. Delete a record.");
			printf("\n\t\t\t 4. List all records.");
			printf("\n\t\t\t 5. Search a specific record.");
			printf("\n\t\t\t 6. Make a bill.");
			printf("\n\t\t\t 7. Make a payment.\n");
			printf("\n\t\t\t 8. Your details.");

			printf("\n\n\n\t\t\t      Enter your choice : ");

			choose_main:

			gotoxy(51,24);
			*choice_menu=getch();

			switch(*choice_menu)
			{
				case '1':
					ch_case=rec_add();
					if(ch_case==2)
					{
						goto main_menu;
					}
				case '2':
					ch_case=rec_modify();
					if(ch_case==2)
					{
						goto main_menu;
					}
				case '3':
					ch_case=rec_delete();
					if(ch_case==2)
					{
						goto main_menu;
					}
				case '4':
					rec_list();
					goto main_menu;
				case '5':
					ch_case=rec_search();
					if(ch_case==2)
					{
						goto main_menu;
					}
				case '6':
					ch_case=bill_pay(1);
					if(ch_case==2)
					{
						goto main_menu;
					}
				case '7':
					ch_case=bill_pay(2);
					if(ch_case==2)
					{
						goto main_menu;
					}
				case '8':
					ch_case=user_details();
					if(ch_case==1)
					{
						goto sign_in_menu;
					}
					else
					{
						goto main_menu;
					}
				case ESC:
					goto sign_in_menu;
				default:
					goto choose_main;
			}
		}
		else if((*signin)==1)
		{
			goto end_of_prg;
		}
		else if((*signin)==2)
		{
			goto sign_in_menu;
		}
	}
	else if(*choice_start=='2')
	{
		*signup=sign_up();

		if(*signup==0)
			goto sign_in;
		else if(*signup==1)
			goto sign_in_menu;

		getch();
	}
	else if(*choice_start==ESC)
	{
		end_of_prg:
		clrscr();

		fcloseall();
		encr_decr(2);
		clrscr();

		txt_default();
		printf("\n\n\n\n");

		txt_inverse();
		cprintf("                         ษอออออออออออออออออออออออออออออป                        ");
		cprintf("                         *  Telephone billing manager  *                        ");
		cprintf("                         ศอออออออออออออออออออออออออออออผ                        ");

		txt_default();

		printf("\n\n\n");
		printf("\n\t\t\t       A software project\n");
		printf("\n\t\t\t\t  Created By :\n");
		printf("\n\t\t\t\t  Ravi Kavaiya");
		printf("\n\t\t\t\t Amar Kotadiya\n\n");
		printf("\n\t\t\t\t    Thank You");
		//delay(4000);
		getch();
	}
	else
	{
		goto choose_sign;
	}

}

void encr_decr(int x)
{
	FILE *f_ed,*f_ed2,*f_ed3;

	int i=0;
	int y=0,z=0;
	char ch,ch2;
	char s1[]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
	char s2[]="9876543210zyxwvutsrqponmlkjihgfedcbaZYXWVUTSRQPONMLKJIHGFEDCBA";
	clrscr();

	if(x==1)
	{
		gotoxy(30,14);
		printf("Preparing data for use");
		gotoxy(1,15);

		txt_inverse();
		for(i=0;i<80;i++)
		{
			cprintf(" ");
			delay(10);
		}
		txt_default();
		delay(500);

		goto enc_dec_main;
	}
	else if(x==2)
	{
		gotoxy(28,14);
		printf("Locking data for security");
		gotoxy(1,15);

		txt_inverse();
		for(i=0;i<80;i++)
		{
			cprintf(" ");
			delay(10);
		}
		txt_default();
		delay(500);

		goto enc_dec_user;
	}

	ret_enc_dec_main:
	ret_enc_dec_user:

	if(x==1 && y==0)
	{
		goto enc_dec_user;
	}
	else if(x==2 && z==0)
	{
		goto enc_dec_main;
	}
	goto no_main_end;

	enc_dec_user:
	f_ed=fopen("MAIN","rb");

	if(f_ed==NULL)
	{
		goto no_main_end;
	}

	fseek(f_ed,0,SEEK_SET);

	while(1)
	{
		fread(&user,sizeof(user),1,f_ed);

		if(feof(f_ed))
		{
			break;
		}

		f_ed2=fopen(user.uname,"rb");
		f_ed3=fopen("TEMP","wb+");

		if(f_ed2==NULL)
		{
			goto no_file;
		}

		fseek(f_ed2,0,SEEK_SET);

		ch=fgetc(f_ed2);

		while(ch!=EOF)
		{
			ch2=ch;

			for(i=0;i<62;i++)
			{
				if(ch==s1[i])
				{
					ch2=s2[i];
					break;
				}
			}
			fputc(ch2,f_ed3);
			ch=fgetc(f_ed2);
		}
		fclose(f_ed2);
		fclose(f_ed3);
		remove(user.uname);
		rename("TEMP",user.uname);

		no_file:
	}
	fcloseall();
	y=1;
	goto ret_enc_dec_user;

	enc_dec_main:

	f_ed=fopen("MAIN","rb");
	f_ed3=fopen("TEMP","wb+");

	if(f_ed==NULL)
	{
		goto no_main_end;
	}

	fseek(f_ed,0,SEEK_SET);

	ch=fgetc(f_ed);

	while(ch!=EOF)
	{
		ch2=ch;

		for(i=0;i<62;i++)
		{
			if(ch==s1[i])
			{
				ch2=s2[i];
				break;
			}
		}
		fputc(ch2,f_ed3);
		ch=fgetc(f_ed);
	}
	fcloseall();
	remove("MAIN");
	rename("TEMP","MAIN");
	z=1;
	goto ret_enc_dec_main;

	no_main_end:
}

void txt_ESC_fail()
{
	textcolor(14);
	textbackground(4);
}

void txt_default()
{
	textcolor(7);
	textbackground(0);
}

void txt_inverse()
{
	textcolor(0);
	textbackground(7);
}

void txt_success()
{
	textcolor(15);
	textbackground(2);
}

int sign_in()
{
	int i=0,l=0;
	int *loop,*atmpts;

	char chuname[10],chpwd[34];
	char *uname,*pwd;

	char *success="You are signed in";
	char *fail="Access denied";


	loop=&i,atmpts=&l;
	uname=chuname;
	pwd=chpwd;

	for((*atmpts)=0;(*atmpts)<3;(*atmpts)++)
	{
		clrscr();

		txt_ESC_fail();
		printf("\t\t\t\t\t   ");
		cprintf("Press ESC key at anytime to step back");
		printf("\n\n\n\n");

		txt_inverse();
		cprintf("                                   ษอออออออออป                                  ");
		cprintf("                                   * Sign-in *                                  ");
		cprintf("                                   ศอออออออออผ                                  ");

		txt_default();

		printf("\n\n\n\n\t\tEnter your username : ");
		input_uname:
		*loop=0;

		gotoxy(39,13);
		clreol();

		user.uname[*loop]='\0';

		user.uname[*loop]=toupper(getch());

		while(user.uname[*loop]!=13)
		{
			if((*loop)>=8)
			{
				user.uname[*loop]=toupper(getch());
			}
			if(user.uname[*loop]==8)
			{
				if(user.uname[0]==8)
				{
					goto input_uname;
				}
				(*loop)--;
				printf("%c%c%c",8,32,8);
				user.uname[*loop]=toupper(getch());
			}
			else if(user.uname[*loop]==ESC)
			{
				return 2;
			}
			else if(isupper(user.uname[*loop]) || isdigit(user.uname[*loop]))
			{
				if(*loop<8)
				{
					printf("%c",user.uname[*loop]);
					(*loop)++;
					user.uname[*loop]=toupper(getch());
				}
			}
			else
			{
				user.uname[*loop]=toupper(getch());
			}
		}

		if(user.uname[0]==13)
		{
			goto input_uname;
		}

		user.uname[*loop]='\0';

		printf("\n\t\tEnter your password : ");
		input_pwd:
		*loop=0;

		gotoxy(39,14);
		clreol();

		user.pwd[*loop]='\0';

		user.pwd[*loop]=getch();

		while(user.pwd[*loop]!=13)
		{
			if((*loop)>=32)
			{
				user.pwd[*loop]=getch();
			}
			if(user.pwd[*loop]==8)
			{
				if(user.pwd[0]==8)
				{
					goto input_pwd;
				}
				(*loop)--;
				printf("%c%c%c",8,32,8);
				user.pwd[*loop]=getch();
			}

			else if(user.pwd[*loop]==ESC)
			{
				gotoxy(1,14);
				clreol();
				goto input_uname;
			}

			else if(user.pwd[*loop]!=9)
			{
				if(*loop<32)
				{
					printf("*");
					(*loop)++;
					user.pwd[*loop]=getch();
				}
			}
			else
			{
				user.pwd[*loop]=getch();
			}
		}

		if(user.pwd[0]==13)
		{
			goto input_pwd;
		}

		user.pwd[*loop]='\0';

		printf("\n\n\n");
		txt_inverse();

		gotoxy(1,17);

		for(*loop=0;(*loop)<80;(*loop)++)
		{
			 delay(7);
			 cprintf(" ");
		}

		textcolor(BLINK);
		gotoxy(37,17);
		cprintf("Verifying");
		delay(1000);

		strcpy(uname,user.uname);
		strcpy(pwd,user.pwd);

		f_main=fopen("MAIN","rb");

		if(f_main==NULL)
		{
			goto fail;
		}

		while(1)
		{
			fread(&user,sizeof(user),1,f_main);

			if(feof(f_main))
				break;

			if(strcmp(uname,user.uname)==0 && strcmp(pwd,user.pwd)==0)
			{
				f_user=fopen(user.uname,"rb+");

				if(f_user==NULL)
				{
					goto fail;
				}

				txt_success();
				gotoxy(1,17);
				clreol();

				gotoxy(32,17);
				textcolor(BLINK);
				puts(success);

				delay(1000);

				txt_default();

				return 0;
			}
		}

		fail:
		if((*atmpts)!=2)
		{
			txt_inverse();

			gotoxy(22,17);
			cprintf("Incorrect username / password. Try again.");
			fcloseall();
			getch();

			txt_default();
		}
	}

	txt_ESC_fail();
	gotoxy(1,17);
	clreol();

	gotoxy(35,17);
	puts(fail);

	delay(1000);
	fcloseall();
	txt_default();
	return 1;
}

int sign_up()
{
	int i=0,j;
	int *loop,*loop2;

	int agelen=0;

	loop=&i,loop2=&j;

	clrscr();

	txt_ESC_fail();
	printf("\t\t\t\t\t   ");
	cprintf("Press ESC key at anytime to step back");
	printf("\n");

	txt_inverse();
	cprintf("                                   ษอออออออออป                                  ");
	cprintf("                                   * Sign-up *                                  ");
	cprintf("                                   ศอออออออออผ                                  ");

	txt_default();

	printf("\n\nEnter full name : ");
	input_user_fullname:
	*loop=0;

	gotoxy(19,8);
	clreol();

	user.fname[*loop]='\0';

	user.fname[*loop]=getch();

	while(user.fname[*loop]!=13)
	{
		if((*loop)>=40)
		{
			user.fname[*loop]=getch();
		}
		if(user.fname[*loop]==8)
		{
			if(user.fname[0]==8)
			{
				goto input_user_fullname;
			}
			(*loop)--;
			printf("%c%c%c",8,32,8);
			user.fname[*loop]=getch();
		}
		else if(user.fname[*loop]==ESC)
		{
			return 1;
		}
		else if(isupper(user.fname[*loop]) || islower(user.fname[*loop]) || isspace(user.fname[*loop]) && (user.fname[*loop]!=9))
		{
			if(*loop<40)
			{
				printf("%c",user.fname[*loop]);
				(*loop)++;
				user.fname[*loop]=getch();
			}
		}
		else
		{
			user.fname[*loop]=getch();
		}
	}

	if(user.fname[0]==13)
	{
		goto input_user_fullname;
	}

	user.fname[*loop]='\0';

	printf("\nEnter address   : ");
	input_user_address:
	*loop=0;

	gotoxy(19,9);
	clreol();

	user.address[*loop]='\0';

	user.address[*loop]=getch();

	while(user.address[*loop]!=13)
	{
		if((*loop)>=61)
		{
			user.address[*loop]=getch();
		}
		if(user.address[*loop]==8)
		{
			if(user.address[0]==8)
			{
				goto input_user_address;
			}
			(*loop)--;
			printf("%c%c%c",8,32,8);
			user.address[*loop]=getch();
		}
		else if(user.address[*loop]==ESC)
		{
			gotoxy(1,9);
			clreol();
			goto input_user_fullname;
		}
		else	if(*loop<61)
		{
			printf("%c",user.address[*loop]);
			(*loop)++;
			user.address[*loop]=getch();
		}
	}

	if(user.address[0]==13)
	{
		goto input_user_address;
	}

	user.address[*loop]='\0';

	printf("\nEnter gender (M / F) : ");
	input_user_gender:
	*loop=0;

	gotoxy(24,10);
	clreol();

	user.gender[*loop]='\0';

	user.gender[*loop]=toupper(getch());

	while(user.gender[*loop]!=13)
	{
		if((*loop)>=1 && user.gender[*loop]!=8)
		{
			user.gender[*loop]=toupper(getch());
		}
		if(user.gender[*loop]==8)
		{
			if(user.gender[0]==8)
			{
				goto input_user_gender;
			}
			(*loop)--;
			printf("%c%c%c",8,32,8);
			user.gender[*loop]=toupper(getch());
		}
		else if(user.gender[*loop]==ESC)
		{
			gotoxy(1,10);
			clreol();
			goto input_user_address;
		}
		else if(user.gender[*loop]=='M' || user.gender[*loop]=='F')
		{
			if(*loop<1)
			{
				printf("%c",user.gender[*loop]);
				(*loop)++;
				user.gender[*loop]=toupper(getch());
			}
		}
		else
		{
			user.gender[*loop]=toupper(getch());
		}
	}

	if(user.gender[0]==13)
	{
		goto input_user_gender;
	}

	user.gender[*loop]='\0';

	printf("\nEnter age (years) : ");
	input_user_age:
	*loop=0;

	gotoxy(21,11);
	clreol();

	in_age[*loop]='\0';

	in_age[*loop]=getch();

	while(in_age[*loop]!=13)
	{
		if((*loop)>=3 && in_age[*loop]!=8)
		{
			in_age[*loop]=getch();
		}
		if(in_age[*loop]==8)
		{
			if(in_age[0]==8)
			{
				goto input_user_age;
			}
			(*loop)--;
			printf("%c%c%c",8,32,8);
			in_age[*loop]=getch();
		}
		else if(in_age[*loop]==ESC)
		{
			gotoxy(1,11);
			clreol();
			goto input_user_gender;
		}
		else if(isdigit(in_age[*loop]))
		{
			if(*loop<3)
			{
				printf("%c",in_age[*loop]);
				(*loop)++;
				in_age[*loop]=getch();
			}
		}
		else
		{
			in_age[*loop]=getch();
		}
	}

	if(in_age[0]==13)
	{
		goto input_user_age;
	}

	in_age[*loop]='\0';

	num_converter(1);

	agelen=strlen(in_age);

	if(agelen==1)
		user.age=num_age[0];
	else if(agelen==2)
		user.age=(num_age[0]*10)+num_age[1];
	else if(agelen==3)
		user.age=(num_age[0]*100)+(num_age[1]*10)+num_age[2];

	if(user.age<18 || user.age>60)
	{
		if(user.age<18)
			printf("\nMinimum 18 years are compulsory.");
		else
			printf("\nMaximum 60 years are allowed.");

		getch();
		gotoxy(1,12);
		clreol();
		goto input_user_age;
	}

	printf("\nEnter mobile no : (+91) ");
	input_user_mbl:
	*loop=0;

	gotoxy(25,12);
	clreol();

	user.mobile[*loop]='\0';

	user.mobile[*loop]=getch();

	while(user.mobile[*loop]!=13)
	{
		if((*loop)>=10 && user.mobile[*loop]!=8)
		{
			user.mobile[*loop]=getch();
		}
		if(user.mobile[*loop]==8)
		{
			if(user.mobile[0]==8)
			{
				goto input_user_mbl;
			}
			(*loop)--;
			printf("%c%c%c",8,32,8);
			user.mobile[*loop]=getch();
		}
		else if(user.mobile[*loop]==ESC)
		{
			gotoxy(1,12);
			clreol();
			goto input_user_age;
		}
		else if(isdigit(user.mobile[*loop]))
		{
			if(*loop<10)
			{
				printf("%c",user.mobile[*loop]);
				(*loop)++;
				user.mobile[*loop]=getch();
			}
		}
		else
		{
			user.mobile[*loop]=getch();
		}
	}

	if(user.mobile[0]==13)
	{
		goto input_user_mbl;
	}

	user.mobile[*loop]='\0';

	if(strlen(user.mobile)<10)
	{
		printf("\nOnly 10 digits are allowed.");
		getch();
		gotoxy(1,13);
		clreol();
		goto input_user_mbl;

	}

	printf("\n\n\t\tNote : Username is not case sensitive.");
	printf("\n\t\tUsername can accept only alphabets and digits.");
	printf("\n\t\t(i.e., No special characters including space).");
	printf("\n\t\tPassword is case sensitive and can have any characters.");
	printf("\n\t\tMaximum length of username is 8 characters.");
	printf("\n\t\tMaximum length of password is 32 characters.");
	printf("\n\t\tThese username and password will be used to sign you in.");

	printf("\n\nEnter username : ");
	input_user_uname:
	*loop=0;

	gotoxy(18,22);
	clreol();

	user.uname[*loop]='\0';

	user.uname[*loop]=toupper(getch());

	while(user.uname[*loop]!=13)
	{
		if((*loop)>=8)
		{
			user.uname[*loop]=toupper(getch());
		}
		if(user.uname[*loop]==8)
		{
			if(user.uname[0]==8)
			{
				goto input_user_uname;
			}
			(*loop)--;
			printf("%c%c%c",8,32,8);
			user.uname[*loop]=toupper(getch());
		}
		else if(user.uname[*loop]==ESC)
		{
			for((*loop2=22);(*loop2)>12;(*loop2)--)
			{
				gotoxy(1,*loop2);
				clreol();
			}
			goto input_user_mbl;
		}
		else if(isupper(user.uname[*loop]) || isdigit(user.uname[*loop]))
		{
			if(*loop<8)
			{
				printf("%c",user.uname[*loop]);
				(*loop)++;
				user.uname[*loop]=toupper(getch());
			}
		}
		else
		{
			user.uname[*loop]=toupper(getch());
		}
	}

	if(user.uname[0]==13)
	{
		goto input_user_uname;
	}

	user.uname[*loop]='\0';

	if((strcmp(user.uname,"MAIN")==0) || (strcmp(user.uname,"TEMP")==0))
	{
		printf("\nSorry ! You cannot use this reserved username. Try a different one.");
		getch();
		gotoxy(1,23);
		clreol();
		goto input_user_uname;
	}
	f_user=fopen(user.uname,"rb");

	if(f_user!=NULL)
	{
		printf("\nSorry ! This user already exists. Try a different one.");
		getch();
		gotoxy(1,23);
		clreol();
		goto input_user_uname;
	}

	printf("\nEnter password : ");
	input_user_pwd:
	*loop=0;

	gotoxy(18,23);
	clreol();

	user.pwd[*loop]='\0';

	user.pwd[*loop]=getch();

	while(user.pwd[*loop]!=13)
	{
		if((*loop)>=32)
		{
			user.pwd[*loop]=getch();
		}
		if(user.pwd[*loop]==8)
		{
			if(user.pwd[0]==8)
			{
				goto input_user_pwd;
			}
			(*loop)--;
			printf("%c%c%c",8,32,8);
			user.pwd[*loop]=getch();
		}

		else if(user.pwd[*loop]==ESC)
		{
			gotoxy(1,23);
			clreol();
			goto input_user_uname;
		}

		else if(user.pwd[*loop]!=9)
		{
			if(*loop<32)
			{
				printf("*");
				(*loop)++;
				user.pwd[*loop]=getch();
			}
		}
		else
		{
			user.pwd[*loop]=getch();
		}
	}

	if(user.pwd[0]==13)
	{
		goto input_user_pwd;
	}

	user.pwd[*loop]='\0';

	f_main=fopen("MAIN","ab+");

	if(f_main==NULL)
	{
		printf("\nSorry ! The system cannot process. Please try again later.");
		getch();
		exit(1);
	}
	fseek(f_main,0,SEEK_END);
	fwrite(&user,sizeof(user),1,f_main);

	f_user=fopen(user.uname,"wb+");

	printf("\n\nYou are successfully signed-up. Please sign-in with your username and password.");
	fcloseall();
	getch();

	return 0;

}

void num_converter(int x)
{
	int i=0,j=48,k=0;
	if(x==1)
	{
		while(in_age[k]!='\0')
		{
			i=0,j=48;
			while(j<=57)
			{
				if(in_age[k]==j)
				{
					num_age[k]=i;
					break;
				}
				i++;
				j++;
			}
			k++;
		}
		num_age[k]='\0';
	}
	else if(x==2)
	{
		while(in_amount[k]!='\0')
		{
			i=0,j=48;
			while(j<=57)
			{
				if(in_amount[k]==j)
				{
					num_amount[k]=i;
					break;
				}
				i++;
				j++;
			}
			k++;
		}
		num_amount[k]='\0';
	}
}

int f_user_opener(int x)
{
	f_user=fopen(user.uname,"ab+");

	if(f_user==NULL)
	{
		printf("\n Sorry ! System can't process. Try again later.");
		getch();
		exit(1);
	}
	if(x==1)
	{
		fseek(f_user,0,SEEK_END);

		if(ftell(f_user)==0)
		{
			printf("\n\nNo records found in your account.");
			return 0;
		}
	}
	fseek(f_user,0,SEEK_SET);
	return 1;
}

int rec_add()
{
	int i,*loop;
	int amlen=0;

	char choice;
	char custid[14];

	loop=&i;

	rec_add:

	clrscr();

	txt_ESC_fail();
	printf("\t\t\t\t      ");
	cprintf("Press ESC key at anytime to goto main menu");
	printf("\n\n\n\n");

	txt_inverse();
	cprintf("                                 ษออออออออออออออป                               ");
	cprintf("                                 * Add a record *                               ");
	cprintf("                                 ศออออออออออออออผ                               ");

	txt_default();

	f_user_opener(0);

	printf("\n\nEnter customer ID        : ");
	input_cust_id:
	fseek(f_user,0,SEEK_SET);
	*loop=0;

	gotoxy(28,11);
	clreol();

	cust.id[*loop]='\0';

	cust.id[*loop]=toupper(getch());

	while(cust.id[*loop]!=13)
	{
		if((*loop)>=10)
		{
			cust.id[*loop]=toupper(getch());
		}
		if(cust.id[*loop]==8)
		{
			if(cust.id[0]==8)
			{
				goto input_cust_id;
			}
			(*loop)--;
			printf("%c%c%c",8,32,8);
			cust.id[*loop]=toupper(getch());
		}
		else if(cust.id[*loop]==ESC)
		{
			return 2;
		}
		else if(isupper(cust.id[*loop]) || isdigit(cust.id[*loop]))
		{
			if(*loop<10)
			{
				printf("%c",cust.id[*loop]);
				(*loop)++;
				cust.id[*loop]=toupper(getch());
			}
		}
		else
		{
			cust.id[*loop]=toupper(getch());
		}
	}

	if(cust.id[0]==13)
	{
		goto input_cust_id;
	}

	cust.id[*loop]='\0';

	strcpy(custid,cust.id);

	while(1)
	{

		fread(&cust,sizeof(cust),1,f_user);

		if(feof(f_user))
			break;

		if(strcmp(custid,cust.id)==0)
		{
			printf("\nThis customer ID already exists. Try a different one.");
			getch();
			gotoxy(1,12);
			clreol();
			goto input_cust_id;
		}
	}
	fseek(f_user,0,SEEK_END);
	strcpy(cust.id,custid);

	printf("\nEnter customer name      : ");
	input_cust_name:
	*loop=0;

	gotoxy(28,12);
	clreol();

	cust.name[*loop]='\0';

	cust.name[*loop]=getch();

	while(cust.name[*loop]!=13)
	{
		if((*loop)>=40)
		{
			cust.name[*loop]=getch();
		}
		if(cust.name[*loop]==8)
		{
			if(cust.name[0]==8)
			{
				goto input_cust_name;
			}
			(*loop)--;
			printf("%c%c%c",8,32,8);
			cust.name[*loop]=getch();
		}
		else if(cust.name[*loop]==ESC)
		{
			gotoxy(1,12);
			clreol();
			goto input_cust_id;
		}
		else if(isupper(cust.name[*loop]) || islower(cust.name[*loop]) || isspace(cust.name[*loop]) && (cust.name[*loop]!=9))
		{
			if(*loop<40)
			{
				printf("%c",cust.name[*loop]);
				(*loop)++;
				cust.name[*loop]=getch();
			}
		}
		else
		{
			cust.name[*loop]=getch();
		}
	}

	if(cust.name[0]==13)
	{
		goto input_cust_name;
	}

	cust.name[*loop]='\0';

	printf("\nEnter customer phone no. : (+91) ");
	input_cust_ph:
	*loop=0;

	gotoxy(34,13);
	clreol();

	cust.ph_no[*loop]='\0';

	cust.ph_no[*loop]=getch();

	while(cust.ph_no[*loop]!=13)
	{
		if((*loop)>=10 && cust.ph_no[*loop]!=8)
		{
			cust.ph_no[*loop]=getch();
		}
		if(cust.ph_no[*loop]==8)
		{
			if(cust.ph_no[0]==8)
			{
				goto input_cust_ph;
			}
			(*loop)--;
			printf("%c%c%c",8,32,8);
			cust.ph_no[*loop]=getch();
		}
		else if(cust.ph_no[*loop]==ESC)
		{
			gotoxy(1,13);
			clreol();
			goto input_cust_name;
		}
		else if(isdigit(cust.ph_no[*loop]))
		{
			if(*loop<10)
			{
				printf("%c",cust.ph_no[*loop]);
				(*loop)++;
				cust.ph_no[*loop]=getch();
			}
		}
		else
		{
			cust.ph_no[*loop]=getch();
		}
	}

	if(cust.ph_no[0]==13)
	{
		goto input_cust_ph;
	}

	cust.ph_no[*loop]='\0';

	if(strlen(cust.ph_no)<10)
	{
		printf("\nOnly 10 digits are allowed.");
		getch();
		gotoxy(1,14);
		clreol();
		goto input_cust_ph;

	}

	printf("\nEnter billing amount     : ");
	input_cust_am:
	*loop=0;

	gotoxy(28,14);
	clreol();

	in_amount[*loop]='\0';

	in_amount[*loop]=getch();

	while(in_amount[*loop]!=13)
	{
		if((*loop)>=6 && in_amount[*loop]!=8)
		{
			in_amount[*loop]=getch();
		}
		if(in_amount[*loop]==8)
		{
			if(in_amount[0]==8)
			{
				goto input_cust_am;
			}
			(*loop)--;
			printf("%c%c%c",8,32,8);
			in_amount[*loop]=getch();
		}
		else if(in_amount[*loop]==ESC)
		{
			gotoxy(1,14);
			clreol();
			goto input_cust_ph;
		}
		else if(isdigit(in_amount[*loop]))
		{
			if(*loop<6)
			{
				printf("%c",in_amount[*loop]);
				(*loop)++;
				in_amount[*loop]=getch();
			}
		}
		else
		{
			in_amount[*loop]=getch();
		}
	}

	if(in_amount[0]==13)
	{
		goto input_cust_am;
	}

	in_amount[*loop]='\0';

	num_converter(2);

	amlen=strlen(in_amount);

	if(amlen==1)
		cust.amount=num_amount[0];
	else if(amlen==2)
		cust.amount=(num_amount[0]*10)+num_amount[1];
	else if(amlen==3)
		cust.amount=(num_amount[0]*100)+(num_amount[1]*10)+num_amount[2];
	else if(amlen==4)
		cust.amount=(num_amount[0]*1000)+(num_amount[1]*100)+(num_amount[2]*10)+num_amount[3];
	else if(amlen==5)
		cust.amount=(num_amount[0]*10000)+(num_amount[1]*1000)+(num_amount[2]*100)+(num_amount[3]*10)+num_amount[4];
	else if(amlen==6)
		cust.amount=(num_amount[0]*100000)+(num_amount[1]*10000)+(num_amount[2]*1000)+(num_amount[3]*100)+(num_amount[4]*10)+num_amount[5];

	fwrite(&cust,sizeof(cust),1,f_user);

	printf("\n\nRecord successfully added.");
	printf("\nAdd more records ?");
	printf("\n(Press 'y' or 'Y' to add) : ");

	add_again:

	gotoxy(29,18);
	clreol();

	choice=getch();

	if(choice=='y' || choice =='Y')
	{
		fclose(f_user);
		goto rec_add;
	}
	else if(choice!=ESC)
	{
		goto add_again;
	}
	else if(choice==ESC)
	{
		return 2;
	}
	return 0;
}

int rec_modify()
{
	int amlen;
	int f=0;
	int i=0,j=0,*loop,*loop2;
	int x=0;
	char choice;
	char input[14];
	loop=&i;
	loop2=&j;

	rec_modify:

	clrscr();

	txt_ESC_fail();
	printf("\t\t\t\t      ");
	cprintf("Press ESC key at anytime to goto main menu");
	printf("\n\n\n");

	txt_inverse();
	cprintf("                               ษอออออออออออออออออป                              ");
	cprintf("                               * Modify a record *                              ");
	cprintf("                               ศอออออออออออออออออผ                              ");

	txt_default();

	x=f_user_opener(1);
	if(x==0)
		goto no_records;

	f_user2=fopen("TEMP","wb+");

	if(f_user2==NULL)
	{
		printf("\nSorry ! System can't process. Try again later.");
		getch();exit(1);
	}

	printf("\nEnter customer ID to modify : ");
	input_cust_id:
	fcloseall();

	f_user_opener(0);
	f_user2=fopen("TEMP","wb+");
	fseek(f_user,0,SEEK_SET);
	*loop=0;
	f=0;

	for((*loop2)=10;(*loop2)<=25;(*loop2)++)
	{
		gotoxy(1,(*loop2));
		clreol();
	}

	gotoxy(31,9);
	clreol();

	input[*loop]='\0';

	input[*loop]=toupper(getch());

	while(input[*loop]!=13)
	{
		if((*loop)>=10)
		{
			input[*loop]=toupper(getch());
		}
		if(input[*loop]==8)
		{
			if(input[0]==8)
			{
				goto input_cust_id;
			}
			(*loop)--;
			printf("%c%c%c",8,32,8);
			input[*loop]=toupper(getch());
		}
		else if(input[*loop]==ESC)
		{
			return 2;
		}
		else if(isupper(input[*loop]) || isdigit(input[*loop]))
		{
			if(*loop<10)
			{
				printf("%c",input[*loop]);
				(*loop)++;
				input[*loop]=toupper(getch());
			}
		}
		else
		{
			input[*loop]=toupper(getch());
		}
	}

	if(input[0]==13)
	{
		goto input_cust_id;
	}

	input[*loop]='\0';

	while(1)
	{
		fread(&cust,sizeof(cust),1,f_user);

		if(feof(f_user))
			break;

		if(strcmp(input,cust.id)==0)
		{
			f=1;
			printf("\n\nCurrent details are : ");
			printf("\n\nID\t      NAME\t\t\t\t\t  PHONE NO.      AMOUNT\n");

			for((*loop)=1;(*loop)<=79;(*loop)++)
				printf("-");

			printf("\n%-10s    %-40s    %-10s     %-6ld",cust.id,cust.name,cust.ph_no,cust.amount);
			printf("\n");
			for((*loop)=1;(*loop)<=79;(*loop)++)
				printf("-");

			printf("\n\nEnter new details : ");

			printf("\nEnter customer name      : ");
			input_cust_name:
			*loop=0;

			gotoxy(28,19);
			clreol();

			cust.name[*loop]='\0';

			cust.name[*loop]=getch();

			while(cust.name[*loop]!=13)
			{
				if((*loop)>=40)
				{
					cust.name[*loop]=getch();
				}
				if(cust.name[*loop]==8)
				{
					if(cust.name[0]==8)
					{
						goto input_cust_name;
					}
					(*loop)--;
					printf("%c%c%c",8,32,8);
					cust.name[*loop]=getch();
				}
				else if(cust.name[*loop]==ESC)
				{
					goto input_cust_id;
				}
				else if(isupper(cust.name[*loop]) || islower(cust.name[*loop]) || isspace(cust.name[*loop]) && (cust.name[*loop]!=9))
				{
					if(*loop<40)
					{
						printf("%c",cust.name[*loop]);
						(*loop)++;
						cust.name[*loop]=getch();
					}
				}
				else
				{
					cust.name[*loop]=getch();
				}
			}

			if(cust.name[0]==13)
			{
				goto input_cust_name;
			}

			cust.name[*loop]='\0';

			printf("\nEnter customer phone no. : (+91) ");
			input_cust_ph:
			*loop=0;

			gotoxy(34,20);
			clreol();

			cust.ph_no[*loop]='\0';

			cust.ph_no[*loop]=getch();

			while(cust.ph_no[*loop]!=13)
			{
				if((*loop)>=10 && cust.ph_no[*loop]!=8)
				{
					cust.ph_no[*loop]=getch();
				}
				if(cust.ph_no[*loop]==8)
				{
					if(cust.ph_no[0]==8)
					{
						goto input_cust_ph;
						}
					(*loop)--;
					printf("%c%c%c",8,32,8);
					cust.ph_no[*loop]=getch();
				}
				else if(cust.ph_no[*loop]==ESC)
				{
					gotoxy(1,20);
					clreol();
					goto input_cust_name;
				}
				else if(isdigit(cust.ph_no[*loop]))
				{
					if(*loop<10)
					{
						printf("%c",cust.ph_no[*loop]);
						(*loop)++;
						cust.ph_no[*loop]=getch();
					}
				}
				else
				{
					cust.ph_no[*loop]=getch();
				}
			}

			if(cust.ph_no[0]==13)
			{
				goto input_cust_ph;
			}

			cust.ph_no[*loop]='\0';

			if(strlen(cust.ph_no)<10)
			{
				printf("\nOnly 10 digits are allowed.");
				getch();
				gotoxy(1,21);
				clreol();
				goto input_cust_ph;

			}

			printf("\nEnter billing amount     : ");
			input_cust_am:
			*loop=0;

			gotoxy(28,21);
			clreol();

			in_amount[*loop]='\0';

			in_amount[*loop]=getch();

			while(in_amount[*loop]!=13)
			{
				if((*loop)>=6 && in_amount[*loop]!=8)
				{
					in_amount[*loop]=getch();
				}
				if(in_amount[*loop]==8)
				{
					if(in_amount[0]==8)
					{
						goto input_cust_am;
					}
					(*loop)--;
					printf("%c%c%c",8,32,8);
					in_amount[*loop]=getch();
				}
				else if(in_amount[*loop]==ESC)
				{
					gotoxy(1,21);
					clreol();
					goto input_cust_ph;
				}
				else if(isdigit(in_amount[*loop]))
				{
					if(*loop<6)
					{
						printf("%c",in_amount[*loop]);
						(*loop)++;
						in_amount[*loop]=getch();
					}
				}
				else
				{
					in_amount[*loop]=getch();
				}
			}

			if(in_amount[0]==13)
			{
				goto input_cust_am;
			}

			in_amount[*loop]='\0';

			num_converter(2);

			amlen=strlen(in_amount);

			if(amlen==1)
				cust.amount=num_amount[0];
			else if(amlen==2)
				cust.amount=(num_amount[0]*10)+num_amount[1];
			else if(amlen==3)
				cust.amount=(num_amount[0]*100)+(num_amount[1]*10)+num_amount[2];
			else if(amlen==4)
				cust.amount=(num_amount[0]*1000)+(num_amount[1]*100)+(num_amount[2]*10)+num_amount[3];
			else if(amlen==5)
				cust.amount=(num_amount[0]*10000)+(num_amount[1]*1000)+(num_amount[2]*100)+(num_amount[3]*10)+num_amount[4];
			else if(amlen==6)
				cust.amount=(num_amount[0]*100000)+(num_amount[1]*10000)+(num_amount[2]*1000)+(num_amount[3]*100)+(num_amount[4]*10)+num_amount[5];

			fwrite(&cust,sizeof(cust),1,f_user2);
		}
		else
		{
			fwrite(&cust,sizeof(cust),1,f_user2);
		}
	}
	if(f==0)
	{
		printf("\n\nRecord not found.");
	}
	fcloseall();
	remove(user.uname);
	rename("TEMP",user.uname);

	printf("\n\n\nModify more records ?");
	printf("\n(Press 'y' or 'Y' to modify) : ");

	modify_again:
	if(f==0)
		gotoxy(32,15);
	else
		gotoxy(32,25);
	clreol();

	choice=getch();

	fcloseall();
	if(choice=='y' || choice =='Y')
	{
		goto rec_modify;
	}
	else if(choice!=ESC)
	{
		goto modify_again;
	}
	else if(choice==ESC)
	{
		return 2;
	}
	no_records:
	fcloseall();
	getch();

	return 2;
}

int rec_delete()
{
	int f=0;
	int i=0,*loop;
	int x=0;

	char ch_dlt,ch_agn;
	char input[14];
	loop=&i;

	rec_delete:

	clrscr();

	txt_ESC_fail();
	printf("\t\t\t\t      ");
	cprintf("Press ESC key at anytime to goto main menu");
	printf("\n\n\n\n");

	txt_inverse();
	cprintf("                               ษอออออออออออออออออป                              ");
	cprintf("                               * Delete a record *                              ");
	cprintf("                               ศอออออออออออออออออผ                              ");

	txt_default();

	x=f_user_opener(1);
	if(x==0)
		goto no_records;

	f_user2=fopen("TEMP","wb+");

	if(f_user2==NULL)
	{
		printf("\nSorry ! system can't process. Try again later.");
		getch();exit(1);
	}

	printf("\n\nEnter customer ID to delete : ");
	input_cust_id:
	fcloseall();

	f_user_opener(0);
	f_user2=fopen("TEMP","wb+");

	fseek(f_user,0,SEEK_SET);
	*loop=0;
	f=0;

	gotoxy(31,11);
	clreol();

	input[*loop]='\0';

	input[*loop]=toupper(getch());

	while(input[*loop]!=13)
	{
		if((*loop)>=10)
		{
			input[*loop]=toupper(getch());
		}
		if(input[*loop]==8)
		{
			if(input[0]==8)
			{
				goto input_cust_id;
			}
			(*loop)--;
			printf("%c%c%c",8,32,8);
			input[*loop]=toupper(getch());
		}
		else if(input[*loop]==ESC)
		{
			return 2;
		}
		else if(isupper(input[*loop]) || isdigit(input[*loop]))
		{
			if(*loop<10)
			{
				printf("%c",input[*loop]);
				(*loop)++;
				input[*loop]=toupper(getch());
			}
		}
		else
		{
			input[*loop]=toupper(getch());
		}
	}

	if(input[0]==13)
	{
		goto input_cust_id;
	}

	input[*loop]='\0';

	while(1)
	{
		fread(&cust,sizeof(cust),1,f_user);

		if(feof(f_user))
			break;

		if(strcmp(input,cust.id)==0)
		{
			f=1;
			printf("\n\nThe following record will be deleted.");
			printf("\n\nID\t      NAME\t\t\t\t\t  PHONE NO.      AMOUNT\n");

			for((*loop)=1;(*loop)<=79;(*loop)++)
				printf("-");

			printf("\n%-10s    %-40s    %-10s     %-6ld",cust.id,cust.name,cust.ph_no,cust.amount);
			printf("\n");
			for((*loop)=1;(*loop)<=79;(*loop)++)
				printf("-");

			printf("\nAre you sure ? ('y' or 'Y') : ");
			confirm_dlt:

			gotoxy(31,19);
			clreol();
			ch_dlt=getch();

			if(ch_dlt=='y' || ch_dlt== 'Y')
			{
				printf("\nRecord is deleted.");
			}
			else if(ch_dlt!=ESC)
			{
				goto confirm_dlt;
			}
			else if(ch_dlt==ESC)
			{
				fwrite(&cust,sizeof(cust),1,f_user2);
			}
		}
		else
		{
			fwrite(&cust,sizeof(cust),1,f_user2);
		}
	}
	if(f==0)
	{
		printf("\n\nRecord not found.");
	}
	fcloseall();
	remove(user.uname);
	rename("TEMP",user.uname);

	printf("\n\n\nDelete more records ?");
	printf("\n(Press 'y' or 'Y' to accept) : ");

	delete_again:
	if(f==0)
	{
		gotoxy(32,17);
	}
	else
	{
		if(ch_dlt=='y' || ch_dlt=='Y')
		{
			gotoxy(32,24);
		}
		else
		{
			gotoxy(32,23);
		}
	}
	clreol();

	ch_agn=getch();

	fcloseall();
	if(ch_agn=='y' || ch_agn=='Y')
	{
		goto rec_delete;
	}
	else if(ch_agn!=ESC)
	{
		goto delete_again;
	}
	else if(ch_agn==ESC)
	{
		return 2;
	}
	no_records:
	fcloseall();
	getch();

	return 2;
}

void rec_list()
{
	int i=0,j=0;
	int x=0;
	char enter;

	clrscr();

	txt_ESC_fail();
	printf("\t\t\t\t      ");
	cprintf("Press ESC key at anytime to goto main menu");
	printf("\n\n\n\n");

	txt_inverse();
	cprintf("                              ษออออออออออออออออออป                              ");
	cprintf("                              * List all records *                              ");
	cprintf("                              ศออออออออออออออออออผ                              ");

	txt_default();

	x=f_user_opener(1);

	if(x==0)
		goto no_records;

	printf("\n\nID\t      NAME\t\t\t\t\t  PHONE NO.      AMOUNT\n");

	for(i=1;i<=79;i++)
		printf("-");

	while(1)
	{
		fread(&cust,sizeof(cust),1,f_user);

		if(feof(f_user))
			break;

		if(j>=12)
		{
			if(j%2==0)
			{
				printf("\nPress Enter to view more");
				gotoxy(1,1);
				clreol();

				txt_ESC_fail();
				printf("\t\t\t\t      ");
				cprintf("Press ESC key at anytime to goto main menu");
				txt_default();

				more:
				gotoxy(25,25);

				enter=getch();

				if(enter==13)
				{
					gotoxy(1,25);
					clreol();
					gotoxy(80,24);
				}
				else if(enter==ESC)
					goto end;
				else
					goto more;
			}
		}
		printf("\n%-10s    %-40s    %-10s     %-6ld",cust.id,cust.name,cust.ph_no,cust.amount);
		j++;
		delay(40);
	}
	printf("\n");
	for(i=1;i<=79;i++)
		printf("-");

	if(j<12)
		goto less;

	printf("\n\nPress ESC to continue");
	ent_cont:

	gotoxy(22,25);
	clreol();
	enter=getche();

	if(enter!=ESC)
		goto ent_cont;

	gotoxy(1,25);
	less:
	printf(" You have total %d record(s).",j);

	no_records:
	fcloseall();
	getch();
	end:
}

int rec_search()
{
	int f=0;
	int i=0,*loop;
	int x=0;
	char choice;
	char input[14];
	loop=&i;

	rec_search:
	clrscr();

	txt_ESC_fail();
	printf("\t\t\t\t      ");
	cprintf("Press ESC key at anytime to goto main menu");
	printf("\n\n\n\n");

	txt_inverse();
	cprintf("                               ษอออออออออออออออออป                              ");
	cprintf("                               * Search a record *                              ");
	cprintf("                               ศอออออออออออออออออผ                              ");

	txt_default();

	x=f_user_opener(1);

	if(x==0)
		goto no_records;

	printf("\n\nEnter customer ID to search : ");
	input_cust_id:
	fseek(f_user,0,SEEK_SET);
	*loop=0;
	f=0;

	gotoxy(31,11);
	clreol();

	input[*loop]='\0';

	input[*loop]=toupper(getch());

	while(input[*loop]!=13)
	{
		if((*loop)>=10)
		{
			input[*loop]=toupper(getch());
		}
		if(input[*loop]==8)
		{
			if(input[0]==8)
			{
				goto input_cust_id;
			}
			(*loop)--;
			printf("%c%c%c",8,32,8);
			input[*loop]=toupper(getch());
		}
		else if(input[*loop]==ESC)
		{
			return 2;
		}
		else if(isupper(input[*loop]) || isdigit(input[*loop]))
		{
			if(*loop<10)
			{
				printf("%c",input[*loop]);
				(*loop)++;
				input[*loop]=toupper(getch());
			}
		}
		else
		{
			input[*loop]=toupper(getch());
		}
	}

	if(input[0]==13)
	{
		goto input_cust_id;
	}

	input[*loop]='\0';

	while(1)
	{
		fread(&cust,sizeof(cust),1,f_user);

		if(feof(f_user))
			break;

		if(strcmp(input,cust.id)==0)
		{
			f=1;
			break;
		}
	}
	if(f==0)
	{
		printf("\n\nRecord not found.");
	}
	else
	{
		printf("\n\nID\t      NAME\t\t\t\t\t  PHONE NO.      AMOUNT\n");

		for((*loop)=1;(*loop)<=79;(*loop)++)
			printf("-");

		printf("\n%-10s    %-40s    %-10s     %-6ld",cust.id,cust.name,cust.ph_no,cust.amount);
		printf("\n");
		for((*loop)=1;(*loop)<=79;(*loop)++)
			printf("-");
	}

	printf("\n\n\nSearch more records ?");
	printf("\n(Press 'y' or 'Y' to search) : ");

	search_again:
	if(f==0)
		gotoxy(32,17);
	else
		gotoxy(32,20);
	clreol();

	choice=getch();

	if(choice=='y' || choice =='Y')
	{
		fclose(f_user);
		goto rec_search;
	}
	else if(choice!=ESC)
	{
		goto search_again;
	}
	else if(choice==ESC)
	{
		return 2;
	}
	no_records:
	fcloseall();
	getch();

	return 2;
}

int bill_pay(int x)
{
	long int old_amt;
	int amlen;
	int f=0;
	int i=0,j=0,*loop,*loop2;
	int y=0;

	char choice;
	char input[14];

	loop=&i;
	loop2=&j;

	rec_bill:

	clrscr();

	txt_ESC_fail();
	printf("\t\t\t\t      ");
	cprintf("Press ESC key at anytime to goto main menu");
	printf("\n\n\n\n");

	txt_inverse();

	if(x==1)
	{
		cprintf("                                 ษอออออออออออออป                                ");
		cprintf("                                 * Make a bill *                                ");
		cprintf("                                 ศอออออออออออออผ                                ");
	}
	else
	{
		cprintf("                               ษออออออออออออออออป                               ");
		cprintf("                               * Make a payment *                               ");
		cprintf("                               ศออออออออออออออออผ                               ");
	}

	txt_default();

	y=f_user_opener(1);

	if(y==0)
		goto no_records;

	f_user2=fopen("TEMP","wb+");

	if(f_user2==NULL)
	{
		printf("\nSorry ! System can't process. Try again later.");
		getch();exit(1);
	}

	printf("\nEnter customer ID : ");
	input_cust_id:
	fcloseall();

	f_user_opener(0);
	f_user2=fopen("TEMP","wb+");

	fseek(f_user,0,SEEK_SET);
	*loop=0;
	f=0;

	for((*loop2)=11;(*loop2)<=25;(*loop2)++)
	{
		gotoxy(1,(*loop2));
		clreol();
	}

	gotoxy(21,10);
	clreol();

	input[*loop]='\0';

	input[*loop]=toupper(getch());

	while(input[*loop]!=13)
	{
		if((*loop)>=10)
		{
			input[*loop]=toupper(getch());
		}
		if(input[*loop]==8)
		{
			if(input[0]==8)
			{
				goto input_cust_id;
			}
			(*loop)--;
			printf("%c%c%c",8,32,8);
			input[*loop]=toupper(getch());
		}
		else if(input[*loop]==ESC)
		{
			return 2;
		}
		else if(isupper(input[*loop]) || isdigit(input[*loop]))
		{
			if(*loop<10)
			{
				printf("%c",input[*loop]);
				(*loop)++;
				input[*loop]=toupper(getch());
			}
		}
		else
		{
			input[*loop]=toupper(getch());
		}
	}

	if(input[0]==13)
	{
		goto input_cust_id;
	}

	input[*loop]='\0';

	while(1)
	{
		fread(&cust,sizeof(cust),1,f_user);

		if(feof(f_user))
			break;

		if(strcmp(input,cust.id)==0)
		{
			f=1;
			printf("\n\nCurrent details are : ");
			printf("\n\nID\t      NAME\t\t\t\t\t  PHONE NO.      AMOUNT\n");

			for((*loop)=1;(*loop)<=79;(*loop)++)
				printf("-");

			printf("\n%-10s    %-40s    %-10s     %-6ld",cust.id,cust.name,cust.ph_no,cust.amount);
			printf("\n");
			for((*loop)=1;(*loop)<=79;(*loop)++)
				printf("-");

			old_amt=cust.amount;

			printf("\nEnter billing amount : ");
			input_cust_am:
			*loop=0;

			gotoxy(24,18);
			clreol();

			in_amount[*loop]='\0';

			in_amount[*loop]=getch();

			while(in_amount[*loop]!=13)
			{
				if((*loop)>=6 && in_amount[*loop]!=8)
				{
					in_amount[*loop]=getch();
				}
				if(in_amount[*loop]==8)
				{
					if(in_amount[0]==8)
					{
						goto input_cust_am;
					}
					(*loop)--;
					printf("%c%c%c",8,32,8);
					in_amount[*loop]=getch();
				}
				else if(in_amount[*loop]==ESC)
				{
					goto input_cust_id;
				}
				else if(isdigit(in_amount[*loop]))
				{
					if(*loop<6)
					{
						printf("%c",in_amount[*loop]);
						(*loop)++;
						in_amount[*loop]=getch();
					}
				}
				else
				{
					in_amount[*loop]=getch();
				}
			}

			if(in_amount[0]==13)
			{
				goto input_cust_am;
			}

			in_amount[*loop]='\0';

			num_converter(2);

			amlen=strlen(in_amount);

			if(amlen==1)
				cust.amount=num_amount[0];
			else if(amlen==2)
				cust.amount=(num_amount[0]*10)+num_amount[1];
			else if(amlen==3)
				cust.amount=(num_amount[0]*100)+(num_amount[1]*10)+num_amount[2];
			else if(amlen==4)
				cust.amount=(num_amount[0]*1000)+(num_amount[1]*100)+(num_amount[2]*10)+num_amount[3];
			else if(amlen==5)
				cust.amount=(num_amount[0]*10000)+(num_amount[1]*1000)+(num_amount[2]*100)+(num_amount[3]*10)+num_amount[4];
			else if(amlen==6)
				cust.amount=(num_amount[0]*100000)+(num_amount[1]*10000)+(num_amount[2]*1000)+(num_amount[3]*100)+(num_amount[4]*10)+num_amount[5];

			if(x==1)
			{
				cust.amount=old_amt+cust.amount;

				if(cust.amount>999999)
				{
					printf("\nSuch a large bill is not allowed. Please pay before proceeding.");
					getch();
					gotoxy(1,19);
					clreol();
					goto input_cust_am;
				}
			}
			else
			{
				cust.amount=old_amt-cust.amount;
			}

			fwrite(&cust,sizeof(cust),1,f_user2);
		}
		else
		{
			fwrite(&cust,sizeof(cust),1,f_user2);
		}
	}
	if(f==0)
	{
		printf("\n\nRecord not found.");
	}
	fcloseall();
	remove(user.uname);
	rename("TEMP",user.uname);

	if(x==1)
	{
		printf("\n\n\nMake more bills ?");
		printf("\n(Press 'y' or 'Y' to make) : ");
	}
	else
	{
		printf("\n\n\nPay more records ?");
		printf("\n(Press 'y' or 'Y' to pay) : ");
	}

	bill_again:
	if(f==0)
	{
		if(x==1)
		{
			gotoxy(30,16);
		}
		else
		{
			gotoxy(29,16);
		}
	}
	else
	{
		if(x==1)
		{
			gotoxy(30,22);
		}
		else
		{
			gotoxy(29,22);
		}
	}
	clreol();

	choice=getch();

	fcloseall();
	if(choice=='y' || choice =='Y')
	{
		goto rec_bill;
	}
	else if(choice!=ESC)
	{
		goto bill_again;
	}
	else if(choice==ESC)
	{
		return 2;
	}
	no_records:
	fcloseall();
	getch();

	return 2;
}

int user_details()
{
	int i,*loop;
	char choice;
	char old_pwd[35],*opwd;
	char new_pwd[35],*npwd;
	char new_pwd2[35],*npwd2;
	char username[10],*uname;

	loop=&i;
	opwd=old_pwd;
	npwd=new_pwd;
	npwd2=new_pwd2;
	uname=username;

	clrscr();

	*loop=0;
	txt_ESC_fail();
	printf("\t\t\t\t      ");
	cprintf("Press ESC key at anytime to goto main menu");
	printf("\n\n\n\n");

	txt_inverse();
	cprintf("                                ษออออออออออออออป                                ");
	cprintf("                                * Your details *                                ");
	cprintf("                                ศออออออออออออออผ                                ");

	txt_default();

	printf("\n");

	f_main=fopen("MAIN","rb");

	strcpy(uname,user.uname);

	while(1)
	{
		fread(&user,sizeof(user),1,f_main);

		if(feof(f_main))
			break;

		if(strcmp(uname,user.uname)==0)
		{
			printf("\nFullname  : %s",user.fname);
			printf("\nAddress   : %s",user.address);
			printf("\nGender    : %s",user.gender);
			printf("\nAge       : %ld",user.age);
			printf("\nMobile no : %s",user.mobile);
			printf("\nUsername  : %s",user.uname);
			break;
		}
	}
	printf("\n\nDo you want to change your password ? ");
	printf("\n(Press 'y' or 'Y' to change) : ");

	choose_chpwd:

	gotoxy(32,19);
	clreol();
	choice=getche();

	if(choice=='y' || choice=='Y')
	{
		printf("\n\nEnter your old password : ");

		input_old_pwd:
		*loop=0;

		gotoxy(27,21);
		clreol();

		opwd[*loop]='\0';

		opwd[*loop]=getch();

		while(opwd[*loop]!=13)
		{
			if((*loop)>=32)
			{
				opwd[*loop]=getch();
			}
			if(opwd[*loop]==8)
			{
				if(opwd[0]==8)
				{
					goto input_old_pwd;
				}
				(*loop)--;
				printf("%c%c%c",8,32,8);
				opwd[*loop]=getch();
			}

			else if(opwd[*loop]==ESC)
			{
				gotoxy(1,21);
				clreol();
				goto choose_chpwd;
			}

			else if(opwd[*loop]!=9)
			{
				if(*loop<32)
				{
					printf("*");
					(*loop)++;
					opwd[*loop]=getch();
				}
			}
			else
			{
				opwd[*loop]=getch();
			}
		}

		if(opwd[0]==13)
		{
			goto input_old_pwd;
		}
		opwd[*loop]='\0';

		if(strcmp(opwd,user.pwd)==0)
		{
			printf("\nEnter your new password : ");

			input_new_pwd:
			*loop=0;

			gotoxy(27,22);
			clreol();

			npwd[*loop]='\0';

			npwd[*loop]=getch();

			while(npwd[*loop]!=13)
			{
				if((*loop)>=32)
				{
					npwd[*loop]=getch();
				}
				if(npwd[*loop]==8)
				{
					if(npwd[0]==8)
					{
						goto input_new_pwd;
					}
					(*loop)--;
					printf("%c%c%c",8,32,8);
					npwd[*loop]=getch();
				}

				else if(npwd[*loop]==ESC)
				{
					gotoxy(1,22);
					clreol();
					goto input_old_pwd;
				}

				else if(npwd[*loop]!=9)
				{
					if(*loop<32)
					{
						printf("*");
						(*loop)++;
						npwd[*loop]=getch();
					}
				}
				else
				{
					npwd[*loop]=getch();
				}
			}

			if(npwd[0]==13)
			{
				goto input_new_pwd;
			}
			npwd[*loop]='\0';

			printf("\nConfirm new password    : ");

			input_new_pwd2:
			*loop=0;

			gotoxy(27,23);
			clreol();

			npwd2[*loop]='\0';

			npwd2[*loop]=getch();

			while(npwd2[*loop]!=13)
			{
				if((*loop)>=32)
				{
					npwd2[*loop]=getch();
				}
				if(npwd2[*loop]==8)
				{
					if(npwd2[0]==8)
					{
						goto input_new_pwd2;
					}
					(*loop)--;
					printf("%c%c%c",8,32,8);
					npwd2[*loop]=getch();
				}

				else if(npwd2[*loop]==ESC)
				{
					gotoxy(1,23);
					clreol();
					goto input_new_pwd;
				}

				else if(npwd2[*loop]!=9)
				{
					if(*loop<32)
					{
						printf("*");
						(*loop)++;
						npwd2[*loop]=getch();
					}
				}
				else
				{
					npwd2[*loop]=getch();
				}
			}

			if(npwd2[0]==13)
			{
				goto input_new_pwd2;
			}
			npwd2[*loop]='\0';

			if(strcmp(npwd,npwd2)==0)
			{
				fclose(f_main);
				f_main=fopen("MAIN","rb+");
				f_main2=fopen("TEMP","wb+");

				if(f_main==NULL || f_main2==NULL)
				{
					printf("\nSorry ! System cannot process. Try again later.");
					getch();
					exit(1);
				}

				while(1)
				{
					fread(&user,sizeof(user),1,f_main);

					if(feof(f_main))
						break;

					if(strcmp(uname,user.uname)==0)
					{
						strcpy(user.pwd,npwd);
						fwrite(&user,sizeof(user),1,f_main2);
					}
					else
					{
						fwrite(&user,sizeof(user),1,f_main2);
					}
				}
				fcloseall();
				remove("MAIN");
				rename("TEMP","MAIN");
				printf("\n\nPassword changed. Sign-in again to continue.");
				getch();
				return 1;
			}
			else
			{
				printf("\nPasswords do not match. Try again.");
				getch();
				gotoxy(1,24);
				clreol();
				gotoxy(1,23);
				clreol();
				goto input_new_pwd;
			}
		}
		else
		{
			printf("\nWrong password ! Try again.");
			getch();
			gotoxy(1,22);
			clreol();
			goto input_old_pwd;
		}
	}
	else if(choice!=ESC)
	{
		goto choose_chpwd;
	}
	else if(choice==ESC)
	{
		return 0;
	}
	return -1;
}