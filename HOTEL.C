#include<stdio.h>
#include<conio.h>


struct customer
{
	int id;
	char fname[100];
	char lname[100];
	char ph_no[15];
	char proof[100];
	char gender[6];
	char roomt[20];
	int rno;
	int day;
	int charge;

};

void add_customer();
void search_customer();
void update_customer();
void delete_customer();
void display_customer();
void generate_bills();

void main()
{

	int option,jump,i,choice;
	char *user,*pas,ch;



	clrscr();
	lab:
	printf("*******************************************************************************	");


	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");

	printf("\n\n \t \t  ***Welcome to The Atomium Hotel***");

	printf("\n");
	printf("\n");
	printf("\n");

	printf("\n\t \t \t  -:Select the Login:-");
	printf("\n");
	printf("\n\t\t\t 1.Admin Login");
	printf("\n\t\t\t 2.Customer Login");
	printf("\n\t\t\t 3.Exit");

	printf("\n");

	printf("\n\t\t\t\ Enter Your Choice:");
	scanf("%d",&option);

	clrscr();


	switch(option)
	{

		case 1://admin login
		main_menu:
		printf("*******************************************************************************	");


		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");

		printf("\n\n \t \t \t *Welcome to The Atomium Hotel*");

		printf("\n");
		printf("\n");
		printf("\n");


		printf("\n\n \t \t\t\t-:Admin Login:-");
		printf("\n");
		printf("\n\t\tUsername:");
		fflush(stdin);
		gets(user);
		fflush(stdin);
		printf("\n\t\tPassword:");


		for(i=0;i<5;i++)
		{
			ch=getch();
			pas[i]=ch;
			ch='*';
			printf("%c",ch);
		}
		pas[i]='\0';

		if(strcmp(user,"admin")==0)
		{

				if(strcmp(pas,"admin")==0)
				{
					clrscr();
					printf("*******************************************************************************	");

					printf("\n");

					printf("\n\n \t \t \t *Welcome to The Atomium Hotel*");

					printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\tLogin Successfully...");

					getch();



				}
				else
				{

					printf("\n\n\n Error!! Please Input valid Username or Password.");						getch();
					clrscr();
					goto main_menu;
					exit(1);
				}

			}

			else
			{
				printf("\n Error! Password is incorect");

				exit(0);

			}


		clrscr();

		printf("*******************************************************************************	");


		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		admin_login:
		printf("\n\n \t \t \t *Welcome to The Atomium Hotel*");
		printf("\n\n \t \t\t\t-:Admin Login:-");

		printf("\n\t\t1.Add Customer.");
		printf("\n\t\t2.Search Customer.");
		printf("\n\t\t3.Update Customer.");
		printf("\n\t\t4.Display Customers.");
		printf("\n\t\t5.Delete Customers.");
		printf("\n\t\t6.Generate Bills.");
		printf("\n\t\t0.Exit.");


		printf("\n Enter your choice:");
		fflush(stdin);
		scanf("%d",&choice);

		if(choice==1) // add customer
		{
			clrscr();
			add_customer();
			printf("\n Enter 1 for main menu or 2 for one step back:");
			scanf("%d",&jump);

			if(jump==1)
			{
				clrscr();
				goto main_menu;
			}
			else
			{
				clrscr();
				goto admin_login;
			}

		}

		if(choice==2)//search customer
		{
			clrscr();
			search_customer();
			printf("\n");
			printf("\n Enter 1 for main menu or 2 for one step back:");
			scanf("%d",&jump);

			if(jump==1)
			{
				clrscr();
				goto main_menu;
			}
			else
			{
				clrscr();
				goto admin_login;
			}

		}

		if(choice==3)//update_customer
		{
			clrscr();
			update_customer();
			printf("\n Enter 1 for main menu or 2 for one step back:");
			scanf("%d",&jump);

			if(jump==1)
			{
				clrscr();
				goto main_menu;
			}
			else
			{
				clrscr();
				goto admin_login;
			}

		}
		if(choice==4) //display customer
		{
			clrscr();
			display_customer();
			printf("\n Enter 1 for main menu or 2 for one step back:");
			scanf("%d",&jump);

			if(jump==1)
			{
				clrscr();
				goto main_menu;
			}
			else
			{
				clrscr();
				goto admin_login;
			}

		}

		if(choice==5) //delete_customer
		{
			clrscr();
			delete_customer();
			printf("\n Enter 1 for main menu or 2 for one step back:");
			scanf("%d",&jump);

			if(jump==1)
			{
				clrscr();
				goto main_menu;
			}
			else
			{
				clrscr();
				goto admin_login;
			}
		}

		if(choice==6)    //generate_bills
		{
			clrscr();
			generate_bills();
			printf("\n\n\n Enter 1 for main menu or 2 for one step back:");
			scanf("%d",&jump);

			if(jump==1)
			{
				clrscr();
				goto main_menu;
			}
			else
			{
				clrscr();
				goto admin_login;
			}

		}
			break;


		case 2://customer login
			clrscr();
			search_customer();
			printf("\n\n\n Enter 1 for main menu:");
			scanf("%d",&jump);

			if(jump==1)
			{
				clrscr();
				goto main_menu;
			}

	}


	getch();


}

void add_customer()
{
		int room;
		struct customer a;
		FILE *fp;
		char ext[50];


		fp=fopen("mi.txt","a");


		if(fp==NULL)
		{
			printf("\n File Openin Error..!!");
		}


		printf("*******************************************************************************	");

		printf("\n");

		printf("\n\n \t \t \t *Welcome to The Atomium Hotel*");
		printf("\n");
		printf("\n\t\t\t\t -:Add Customer Details:-");


		printf("\n Enter Customer ID:");
		scanf("%d",&a.id);

		printf("\n Enter Customer First Name:");
		fflush(stdin);
		gets(a.fname);

		printf("\n Enter Customer Last Name:");
		fflush(stdin);
		gets(a.lname);

		printf("\n Enter Customer Phone Number:");
		fflush(stdin);
		gets(a.ph_no);

		printf("\n Enter Customer Proof:");
		fflush(stdin);
		gets(a.proof);

		printf("\n Enter Customer Gender:");
		fflush(stdin);
		gets(a.gender);

		printf("\n----------------------------------");
		printf("\n\t--:TYPE OF ROOMS:-- ");

		printf("\n\n 1. A/C Single Bed(Rs.499):");

		printf("\n\n 2. Non-A/C Single Bed(Rs.399)");

		printf("\n\n 3. A/C Double bed(Rs.799)");

		printf("\n\n 4. Non-A/C Double bed(Rs.699)");

		printf("\n\n--------------------------------");
		printf("\n  Enter Customer Room Type:");
		scanf("%d",&room);

		if(room==1)
		{
			strcpy(ext,"Single_Bed");
			strcpy(a.roomt,ext);
//			a.roomt=ext;
		}

		else if(room==2)
		{
			strcpy(ext,"Non_A/C_Single_Bed");
			strcpy(a.roomt,ext);
		}

		else if(room==3)
		{

			strcpy(ext,"A/C_Double_bed");
			strcpy (a.roomt,ext);

		}

		else if(room==4)
		{
			 strcpy(ext,"Non_A/C_Double_bed");
			 strcpy(a.roomt,ext);


		}
		printf("\n Enter Total number of Rooms:");
		scanf("%d",&a.rno);

		printf("\n Enter Total number of days to Stay:");
		scanf("%d",&a.day);

		printf("\n Total Charge:");
		scanf("%d",&a.charge);

		fprintf(fp,"\n%d\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%d\t%d",a.id,a.fname,a.lname,a.ph_no,a.proof,a.gender,a.roomt,a.rno,a.day,a.charge);

		fclose(fp);

}

void search_customer()
{
	FILE *fp;
	struct customer a;
	int found=0,mo;

	fp=fopen("mi.txt","r");
	if(fp==NULL)
	{
		printf("\n File opening Error");
		exit(1);
	}
		printf("*******************************************************************************	");

		printf("\n");

		printf("\n\n \t \t \t *Welcome to The Atomium Hotel*");
		printf("\n");
		printf("\n\t\t\t\t -:Search Customer Details:-");

	printf("\n Enter the Customer id to view its detail:");
	scanf("%d",&mo);


	while(1)
	{
		fscanf(fp,"\n%d\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%d\t%d",&a.id,a.fname,a.lname,a.ph_no,a.proof,a.gender,a.roomt,&a.rno,&a.day,&a.charge);

		if(a.id==mo)
		{
			found=1;
			printf("\n Customr Id : %d",a.id);
			printf("\n Customer First Name:%s",a.fname);
			printf("\n Customer Last Name:%s",a.lname);
			printf("\n Customer Phone Number:%s",a.ph_no);
			printf("\n Customer Proof Document:%s",a.proof);
			printf("\n Customer Gender:%s",a.gender);
			printf("\n Customer Room type:%s",a.roomt);
			printf("\n Total number of Rooms:%d",a.rno);
			printf("\n Total number of days to stay:%d",a.day);
			printf("\n Total Room Charge:%d",a.charge);
		}

		if(feof(fp))
		{
			break;
		}

	}

		if(found==0)
		{
			printf("\n Record not found");
		}


		fclose(fp);

}
void update_customer()
{
	FILE *fp, *fp2;
	struct customer a;
	int found=0,mo,room;
	char ext[50];

	fp=fopen("mi.txt","r");

	if(fp==NULL)
	{
		printf("\n Error opening file");
		exit(1);
	}

	fp2=fopen("temp.txt","w");

	if(fp2==NULL)
	{
		printf("\n File opening Error..!!");
		exit(1);
	}
	printf("*******************************************************************************	");

	printf("\n");

	printf("\n\n \t \t \t *Welcome to The Atomium Hotel*");
	printf("\n");
	printf("\n\t\t\t\t -:Update Customer Details:-");


	printf("\n Enter the CUSTOMER ID to Edit their Detail:");
	scanf("%d",&mo);

	while(1)
	{
		fscanf(fp,"\n%d\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%d\t%d",&a.id,a.fname,a.lname,a.ph_no,a.proof,a.gender,a.roomt,&a.rno,&a.day,&a.charge);

		if(a.id==mo)
		{
			found=1;

			printf("\n The details are as follows:");
			printf("\n Customr Id : %d",a.id);
			printf("\n Customer First Name:%s",a.fname);
			printf("\n Customer Last Name:%s",a.lname);
			printf("\n Customer Phone Number:%s",a.ph_no);
			printf("\n Customer Proof Document:%s",a.proof);
			printf("\n Customer Gender:%s",a.gender);
			printf("\n Customer Room type:%s",a.roomt);
			printf("\n Total number of Rooms:%d",a.rno);
			printf("\n Total number of days to stay:%d",a.day);
			printf("\n Total Room Charge:%d",a.charge);
			printf("\n\n\n");
			printf("\n\t\t --:Enter The MODIFIED Data:--");
			printf("\n Enter Customer First Name:");
			fflush(stdin);
			gets(a.fname);

			printf("\n Enter Customer Last Name:");
			fflush(stdin);
			gets(a.lname);

			printf("\n Enter Customer Phone Number:");
			fflush(stdin);
			gets(a.ph_no);

			printf("\n Enter Customer Proof:");
			fflush(stdin);
			gets(a.proof);

			printf("\n Enter Customer Gender:");
			fflush(stdin);
			gets(a.gender);

			printf("\n----------------------------------");
			printf("\n\t--:TYPE OF ROOMS:-- ");

			printf("\n\n 1. A/C Single Bed(Rs.499):");

			printf("\n\n 2. Non-A/C Single Bed(Rs.399)");

			printf("\n\n 3. A/C Double bed(Rs.799)");

			printf("\n\n 4. Non-A/C Double bed(Rs.699)");

			printf("\n\n--------------------------------");
			printf("\n  Enter Customer Room Type:");
			scanf("%d",&room);

			if(room==1)
			{
				strcpy(ext,"SingleBed");
				strcpy(a.roomt,ext);

			}

			else if(room==2)
			{
				strcpy(ext,"Non_A/C_Single_Bed");
				strcpy(a.roomt,ext);
			}

			else if(room==3)
			{

				strcpy(ext,"A/C_Double_bed");
				strcpy (a.roomt,ext);

			}

			else if(room==4)
			{
				 strcpy(ext,"Non_A/C_Double_bed");
				 strcpy(a.roomt,ext);


			}
			printf("\n Enter Total number of Rooms:");
			scanf("%d",&a.rno);

			printf("\n Enter Total number of days to Stay:");
			scanf("%d",&a.day);

			printf("\n Total Charge:");
			scanf("%d",&a.charge);


			fprintf(fp2,"\n%d\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%d\t%d",a.id,a.fname,a.lname,a.ph_no,a.proof,a.gender,a.roomt,a.rno,a.day,a.charge);
		}
		else
		{
			fprintf(fp2,"\n%d\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%d\t%d",a.id,a.fname,a.lname,a.ph_no,a.proof,a.gender,a.roomt,a.rno,a.day,a.charge);

		}

		if(feof(fp))
		{
			break;
		}

	}
	fclose(fp);
	fclose(fp2);

	remove("mi.txt");
	rename("temp.txt","mi.txt");

	if(found==0)
	{
		printf("\n The Record With Customer ID %d was not found .. Please input valid Customer ID..!!",mo);
	}

	printf("\n Record Succeesfullly Updated..!");
	getch();

}
void delete_customer()
{

	FILE *fp, *fp2;
	struct customer a;
	int found=0,mo,room;
	char ext[50];

	fp=fopen("mi.txt","r");

	if(fp==NULL)
	{
		printf("\n Error opening file");
		exit(1);
	}

	fp2=fopen("temp.txt","w");

	if(fp2==NULL)
	{
		printf("\n File opening Error..!!");
		exit(1);
	}
	printf("*******************************************************************************	");

	printf("\n");

	printf("\n\n \t \t \t *Welcome to The Atomium Hotel*");
	printf("\n");
	printf("\n\t\t\t\t -:Delete Customer Details:-");


	printf("\n Enter the CUSTOMER ID to Delete their Detail:");
	scanf("%d",&mo);

	while(1)
	{
		fscanf(fp,"\n%d\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%d\t%d",&a.id,a.fname,a.lname,a.ph_no,a.proof,a.gender,a.roomt,&a.rno,&a.day,&a.charge);

		if(a.id==mo)
		{
			found=1;

			printf("\n The details are as follows:");
			printf("\n Customr Id : %d",a.id);
			printf("\n Customer First Name:%s",a.fname);
			printf("\n Customer Last Name:%s",a.lname);
			printf("\n Customer Phone Number:%s",a.ph_no);
			printf("\n Customer Proof Document:%s",a.proof);
			printf("\n Customer Gender:%s",a.gender);
			printf("\n Customer Room type:%s",a.roomt);
			printf("\n Total number of Rooms:%d",a.rno);
			printf("\n Total number of days to stay:%d",a.day);
			printf("\n Total Room Charge:%d",a.charge);

		}
		else
		{
			fprintf(fp2,"\n%d\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%d\t%d",a.id,a.fname,a.lname,a.ph_no,a.proof,a.gender,a.roomt,a.rno,a.day,a.charge);

		}

		if(feof(fp))
		{
			break;
		}

	}
	fclose(fp);
	fclose(fp2);

	remove("mi.txt");
	rename("temp.txt","mi.txt");

	if(found==0)
	{
		printf("\n The Record With Customer ID %d was not found .. Please input valid Customer ID..!!",mo);
	}

	printf("\n Record Succeesfullly Deleted..!");
	getch();
}
void display_customer()
{
       FILE *fp;
       struct customer a;

       fp=fopen("mi.txt","r");

       if(fp==NULL)
       {
		printf("\n File Opening Error..!!");
		exit(1);
       }
	printf("*******************************************************************************	");

	printf("\n");

	printf("\n\n \t \t \t *Welcome to The Atomium Hotel*");
	printf("\n");
	printf("\n\t\t\t\t -:Customer Details:-");


	while(1)
	{
	fscanf(fp,"\n%d\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%d\t%d",&a.id,a.fname,a.lname,a.ph_no,a.proof,a.gender,a.roomt,&a.rno,&a.day,&a.charge);
			printf("\n Customr Id : %d",a.id);
			printf("\n Customer First Name:%s",a.fname);
			printf("\n Customer Last Name:%s",a.lname);
			printf("\n Customer Phone Number:%s",a.ph_no);
			printf("\n Customer Proof Document:%s",a.proof);
			printf("\n Customer Gender:%s",a.gender);
			printf("\n Customer Room type:%s",a.roomt);
			printf("\n Total number of Rooms:%d",a.rno);
			printf("\n Total number of days to stay:%d",a.day);
			printf("\n Total Room Charge:%d",a.charge);
			printf("\n");

			getch();
	if(feof(fp))
	{
		break;
	}
	}
	fclose(fp);


}

void generate_bills()
{
	FILE *fp;
	struct customer a;
	int found=0,mo,sum;

	fp=fopen("mi.txt","r");

	if(fp==NULL)
	{
		printf("\n Error File Opening ..!!");
		exit(1);
	}
	printf("*******************************************************************************	");

	printf("\n");

	printf("\n\n \t \t \t *Welcome to The Atomium Hotel*");
	printf("\n");
	printf("\n\t\t -:Generate Bills:-");



	printf("\n Enter the Customer ID to generate Bill:");
	scanf("%d",&mo);

	while(1)
	{
		fscanf(fp,"\n%d\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%d\t%d",&a.id,a.fname,a.lname,a.ph_no,a.proof,a.gender,a.roomt,&a.rno,&a.day,&a.charge);

		if(a.id==mo)
		{
			found=1;
			sum=a.charge*a.day;
		}
		if(feof(fp))
		{
			break;
		}

	}
	fclose(fp);

	printf("\n\n\n The Room Charges Of Customer ID %d is:%d",mo,sum);



	if(found==1)
	{
		printf("\n\n\n Bill Successfully generated..!!");
	}
	else
	{
		printf("\n\n The Customer Id %d is not Valid .. Please input Valid Customer Id..",mo);
	}

	getch();

}