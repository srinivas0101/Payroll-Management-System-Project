#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
#include<ctime>
#include<iomanip>
#include<ctype.h>
#define max 50
using namespace std;

int num=0;
void Cdelay(int);
void intro();
void login();
void menu();
void insert();
void edit();
void editmenu();
void editname(int);
void editcode(int);
void editdes(int);
void editexp(int);
void editage(int);
void editsalary(int);
void list();
void deletes();
void search();
void setWindowSize(int,int);
void saverecords();
void getrecords();
bool isFilePresent();
void displayPayslip();


class employee
{
public:
	char name[20];
	char mob[10];
	char mail[100];
	int code;
	char designation[20];
	int exp;
	int age;
	int salary;
	char AnyLoan;
	int HRA;
	int PF;
	int tax;
	int MealAllowance;
	int TransportAllowance;
	int MedicalAllowance;
	int LoanBalance;
	int LoanDebit;
	int grosspay;
	int workingHours;
	int DA;

};
employee emp[max],tempemp[max];


void getrecords()
{
	FILE *fp;
	fp = fopen("Records.txt","r");
	int c=0;
	if(fp!=NULL)
	{
		while(feof(fp)==0)
		{
			fscanf(fp,"%s\t%d\t%s\t%d\t%d\t%d\t%c\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%s\t%s\n",&emp[c].name,&emp[c].code,&emp[c].designation,&emp[c].exp,&emp[c].age,&emp[c].salary,&emp[c].AnyLoan,&emp[c].HRA,&emp[c].PF,&emp[c].tax,&emp[c].MealAllowance,&emp[c].TransportAllowance,&emp[c].MedicalAllowance,&emp[c].LoanBalance,&emp[c].LoanDebit,&emp[c].grosspay,&emp[c].workingHours,&emp[c].DA,&emp[c].mail,&emp[c].mob);
			c++;
		}
		num=c;
	}
	fclose(fp);
}

void saverecords()
{
	if(num==0)
	{
		system("del Records.txt");
	}
	else
	{
		FILE *fp;
		fp = fopen("Records.txt","w");
		for(int i=0;i<num;i++)
		{
			fprintf(fp,"%s\t%d\t%s\t%d\t%d\t%d\t%c\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%s\t%s\n",emp[i].name,emp[i].code,emp[i].designation,emp[i].exp,emp[i].age,emp[i].salary,emp[i].AnyLoan,emp[i].HRA,emp[i].PF,emp[i].tax,emp[i].MealAllowance,emp[i].TransportAllowance,emp[i].MedicalAllowance,emp[i].LoanBalance,emp[i].LoanDebit,emp[i].grosspay,emp[i].workingHours,emp[i].DA,emp[i].mail,emp[i].mob);
		}
		fclose(fp);
	}
}

void Cdelay(int msec)
{
    long goal = msec + (clock());
    while (goal > (clock()));
}

bool isFilePresent()
{
	FILE *fp;
	fp = fopen("Records.txt","r");
	if(fp==NULL)
		return false;
	else
		return true;
}

void login()
{

	char UserName[30],Password[30],ch;int i=0;
	cout<<"\t\t\t-----------------------------------------------";
	cout<<"\n\t\t\t\t WELCOME TO SRM PAYROLL MANAGEMENT\n";
	cout<<"\t\t\t-----------------------------------------------";
    printf("\n\n\n\t\t\tEnter UserName : ");
    cin>>UserName;
    cout<<"\n\t\t\tEnter Password : ";
    while(1)
    {
    	ch = getch();
    	if(ch==13)
    		break;
    	if(ch==32||ch==9)
    		continue;
    	else
    	{
			cout<<"*";
			Password[i]=ch;
			i++;
    	}
	}
	Password[i] = '\0';
    if(strcmp(UserName,"admin")==0 && strcmp(Password,"SRM123")==0)
    {
    	system("cls");
    	
    	cout<<"\n\n\n\t\t\t\t Login Success!!!"; 
		time_t now = time(0); 
        char* dt = ctime(&now);  
        cout << "\n\n\n\t\t\tLogin at: " <<dt; 
    	cout<<"\n\n\t\t\tWill be redirected in 3 Seconds...";
    	Cdelay(1000);
    	cout<<"\b \b2";
    	Cdelay(1000);
    	cout<<"\b \b1";
    	Cdelay(1000);
	}
	else
	{
		system("cls");
		printf("Access Denied!!!\a");
    	cout<<"\nWill be redirected in 3 Seconds...";
    	Cdelay(1000);
    	cout<<"\b \b2";
    	Cdelay(1000);
    	cout<<"\b \b1";
    	Cdelay(1000);
    	system("cls");
    	login();
	}
}


void insert()
{

	
	int i=num;
	int sal,PF,TAX,HRA,MealA,MedicalA,TransportA,LoanBal,LoanDeb,h,DA;
	char loan;
	num+=1;
	system("cls");
	cout<<"\n\t\t\t------------------------";
	printf("\n\t\t\tInsert New Record");
	cout<<"\n\t\t\t------------------------";
	cout<<"\n\t\t\tName : ";
	cin>>emp[i].name;
	cout<<"\n\t\tCode : ";
	cin>>emp[i].code;
	cout<<"\n\t\tDesignation : ";
	cin>>emp[i].designation;
	cout<<"\n\t\tYears of Experience : ";
	cin>>emp[i].exp;
	cout<<"\n\t\tEnter mail Id : ";
	cin>>emp[i].mail;
	cout<<"\n\t\tEnter Mobile Number: ";
	cin>>emp[i].mob;
	cout<<"\n\t\tAge : ";
	cin>>emp[i].age;
	cout<<"\n\t\tEnter Working Hours : ";
	cin>>h;
	sal = h*300;
	emp[i].workingHours = h;
	do
	{
		
		cout<<"\t\tAny Loan (Y/N) ?: \b \b";
		loan=getch();
		if(loan=='Y'|| loan == 'y' || loan =='n' || loan == 'N')
			break;
	}while(1);
	if(loan=='y'|| loan=='Y')
	{
	cout<<"\n\t\tEnter Loan Balance : ";
	cin>>LoanBal;
	}
	else
	{
		LoanBal=0;
	}
	cout<<"\n\tRecorded Succesfully...!!!";

	TAX =  0.04 * sal;
	DA = 1.20 * sal;
	PF = 0.12 * sal;
	HRA = sal * 0.27;
	MealA = 300;
	MedicalA = 300;
	TransportA = 300;
	LoanDeb = sal * 0.09;
	if(LoanDeb > LoanBal)
	{
		LoanBal = 0;
		LoanDeb = LoanBal;
	}
	emp[i].salary = sal;
	emp[i].DA = DA;
	emp[i].tax=TAX;
	emp[i].PF = PF;
	emp[i].HRA = HRA;
	emp[i].MealAllowance = MealA;
	emp[i].MedicalAllowance = MedicalA;
	emp[i].TransportAllowance = TransportA;
	emp[i].LoanBalance = LoanBal-LoanDeb;
	emp[i].AnyLoan = loan;
	emp[i].LoanDebit = LoanDeb;
	emp[i].grosspay = (sal+MealA+MedicalA+TransportA+HRA+DA)-(PF+TAX+LoanDeb) ;
	getch();
}



void  list()
{
	system("cls");
	cout<<" ================== List of the Employees ==================="<<endl;
	cout<<" Name\t\tCode\tDesignation\tYears(EXP)\tAge\tSalary "<<endl;
	cout<<"------------------------------------------------------------------------"<<endl;
	for(int i=0;i<=num-1;i++)
	{
		cout<<" "<<emp[i].name<<"\t\t";
		cout<<emp[i].code<<"\t";
		cout<<"  "<<emp[i].designation<<"\t";
		cout<<"  "<<emp[i].exp<<"\t\t";
		cout<<" "<<emp[i].age<<"\t";
		cout<<" "<<emp[i].grosspay<<"\t"<<endl<<endl;
	}
	getch();
}

void loading()
{
	system("cls");
    printf("\n\n\n\n\n\n\n\n\t\t\t\t\tLoading...");
    for(int i = 0; i<20; i++)
    {
        Cdelay(200);
        printf("%c",254);
    }
}
void menu()
{
	system("cls");
	cout<<"\t\t------------------------------------------------------------------------";
	cout<<"\n\t\t\t============  Welcome To Payroll Management System ================ "<<endl;
	cout<<"\t\t------------------------------------------------------------------------";
	cout<<"\n\t\tPress  1 - Record.";
	cout<<"\n\t\tPress  2 - List The Employee Table.";
	cout<<"\n\t\tPress  3 - Delete a Record.";
	cout<<"\n\t\tPress  4 - Edit a Record.";
	cout<<"\n\t\tPress  5 - Search a Record.";
	cout<<"\n\t\tPress  6 - Print Employee PaySlip.";
	cout<<"\n\t\tPress  7 - Quit Program.";
	cout<<"\n\t\tEnter Your Option ";
}

void deletes()
{
	for(int i=0;i<num;i++)
	{
		tempemp[i]=emp[i];
	}
	int code;
	int check=-1;
	cout<<"\n------------Delete a Record-----------------";
	cout<<"\nEnter the JobCode To Delete That Record  :";
	cin>>code;
	int i,j;
	for(i=0;i<=num-1;i++)
	{
	 	if(emp[i].code==code)
		{
			check=i;
		}
	}
	if(check!=-1)
	{
		for(i=0,j=0;i<=num-1;i++,j++)
		{
			if(i==check)
			{
				i++;
			}
			emp[j]=tempemp[i];
		}
		num--;
	}
}

void search()
{
	
	int jobcode;
	bool found = false;
	cout<<"\nYou can Search only through the Jobcode of an Employee"<<endl;
	cout<<"Enter Code Of the Employee : ";
	cin>>jobcode;
	for(int i=0;i<=num-1;i++)
	{
		if(emp[i].code==jobcode)
		{
			cout<<"Name\tCode\tDesignation\tYears(EXP)\tAge\tSalary "<<endl;
			cout<<"------------------------------------------------------------------"<<endl;
			cout<<emp[i].name<<"\t";
			cout<<emp[i].code<<"\t";
			cout<<emp[i].designation<<"\t";
			cout<<emp[i].exp<<"\t";
			cout<<emp[i].age<<"\t";
			cout<<emp[i].grosspay<<"\t";
			found = true;
		}
		
	}
	if(!found)
	{
		
		cout<<"\nNo records Found...!!!\a";
	}
	getch();
}



void editmenu()
{
	system("cls");
	cout<<"\nEdit An Entry";
	cout<<"\nWhat Do You Want To edit"<<"\n";
	cout<<"n -------> Name \n";
	cout<<"c -------> Code \n";
	cout<<"d -------> Designation\n";
	cout<<"e -------> Experience\n";
	cout<<"a -------> Age\n";
	cout<<"s -------> Salary\n";
	cout<<"q -------> QUIT\n";
	cout<<"Enter Choice ---->>>  ";
}

void editname(int i)
{
	cout<<"\nEnter New Name----->  ";
	cin>>emp[i].name;
}

void editcode(int i)
{
	cout<<"\nEnter New Job Code----->  ";
	cin>>emp[i].code;
}
void editdes(int i)
{
	cout<<"\nEnter new designation----->  ";
	cin>>emp[i].designation;
}

void editexp(int i)
{
	cout<<"\nEnter new Years of Experience";
	cin>>emp[i].exp;
}
void editage(int i)
{
	cout<<"\nEnter new Age ";
	cin>>emp[i].age;
}

void editsalary(int i)
{
	int sal,PF,TAX,HRA,MealA,MedicalA,TransportA,LoanBal=emp[i].LoanBalance,LoanDeb,DA;
	char loan;
	cout<<"\nEnter new Salary ";
	cin>>sal;
	DA = 1.20 * sal;
	TAX =  0.04 * sal;
	PF = 0.12 * sal;
	HRA = 4000;
	MealA = 300;
	MedicalA = 300;
	TransportA = 300;
	LoanDeb = sal * 0.09;
	if(LoanDeb > LoanBal)
	{
		LoanBal = 0;
		LoanDeb = LoanBal;
	}
	emp[i].salary = sal;
	emp[i].tax=TAX;
	emp[i].PF = PF;
	emp[i].HRA = HRA;
	emp[i].MealAllowance = MealA;
	emp[i].MedicalAllowance = MedicalA;
	emp[i].TransportAllowance = TransportA;
	emp[i].LoanBalance = LoanBal;
	emp[i].AnyLoan = loan;
	emp[i].LoanDebit = LoanDeb;
	emp[i].grosspay = (sal+MealA+MedicalA+TransportA+HRA+DA)-(PF+TAX+LoanDeb) ;
}

void edit()
{
	system("cls");
	int jobcode;
	printf("\n---------------Edit a Record-----------------");
	int i;
	char option;
	cout<<"\nEnter the jobcode To Edit : ";
	cin>>jobcode;
	editmenu();
	for(i=0;i<=num-1;i++)
	{
		if(emp[i].code==jobcode)
		{
			while((option=cin.get())!='q')
			{
				switch(option)
				{
					case 'n':
						editname(i);
						break;
					case 'c':
						editcode(i);
						break;
					case 'd':
						editdes(i);
						break;
					case 'e':
						editexp(i);
						break;
					case 'a':
						editage(i);
						break;
					case 's':
						editsalary(i);
						break;
				}
   				editmenu();
			}
		}
	}
}


void displayPayslip()
{
	system("cls");
	int code,i;
	cout<<"\nEnter Employee Job Code :";
	cin>>code;
    cout<<"\n";
	for(i=0;i<=num-1;i++)
	{
		if(emp[i].code==code)
		{
			cout<<"\t\t------------------------------------------------"<<endl;
			cout<<"\t\t\t\t Employee Pay Slip "<<endl;
			cout<<"\t\t------------------------------------------------"<<endl;
			cout<<"\n\t\tName : "<<emp[i].name<<endl;
			cout<<"\n\t\tMaild id:"<<emp[i].mail<<endl;
			cout<<"\n\t\tWorking Hours : "<<emp[i].workingHours<<" Hrs"<<endl;
			cout<<"\n\t\tEarnings :-"<<endl;
			cout<<"\n\t\t\tBasic Pay : "<<emp[i].salary<<endl;
			cout<<"\n\t\t\tHRA(27% of Basic): "<<emp[i].HRA<<endl;
			cout<<"\n\t\t\tDA (120% of Basic):"<<emp[i].DA<<endl;
			cout<<"\n\t\t\tMeal Allowance : "<<emp[i].MealAllowance<<endl;
			cout<<"\n\t\t\tMedical Alowance : "<<emp[i].MedicalAllowance<<endl;
			cout<<"\n\t\t\tTransport Allowance : "<<emp[i].TransportAllowance<<endl;
			cout<<"\n\t\tDeductions :- "<<endl;
			cout<<"\n\t\t\tPF : "<<emp[i].PF<<endl;
			cout<<"\n\t\t\tTax : "<<emp[i].tax<<endl;
			int l = emp[i].AnyLoan;
			char l2 = toupper(l);
			cout<<"\n\t\t\tLoan Status : "<<l2<<endl;
			cout<<"\n\t\t\tLoan Debit This Month : "<<emp[i].LoanDebit<<endl;
			cout<<"\n\t\t\tLoan Balance : "<<emp[i].LoanBalance<<endl;
			cout<<"\n\t\tTotal Gross Pay : "<<emp[i].grosspay<<endl;
			cout<<"\n***************************************************************************"<<endl;
		}
	}
	getch();
}


int main()
{
    login();
    menu();
    getrecords();
    int option;
    if(emp[0].code==0 && isFilePresent())
    	num--;
	while(1)
	{
		cin>>option;
		switch(option)
		{
			case 2:
				list();
				break;
			case 1:
				insert();
				break;
			case 3:
				deletes();
				break;
			case 4:
				edit();
				break;
			case 5:
				search();
				break;
			case 6:
				displayPayslip();
				break;
			case 7:
				saverecords();
				exit(0);
		}
		menu();
	}
	return 0;
}