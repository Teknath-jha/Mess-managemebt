/// MESS MANAGEMENT SYSTEM.

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<process.h>
#include<dos.h>
#include<string.h>
#include<ctype.h>
#define ENTER 13
#define TAB 9
#define BKSPACE 8
#define SPACE 32
#define filename "Mess.txt"
int main_exit;

struct Customer
{
    int  id;
    char name[20];
    char contact[15];
    int amt_paid;
    int present;
} s,s1,t;

FILE *fp;
void update();                    ///1
void display();                       ///2
void input();                             ///3
void menu();                                  ///4
void del();                                       ///5
void sortbyid();                                      ///6
void dailyattendance();                                   ///7
void particular();
void fordelay(int );                                  ///8
void main_menu();
int main()
{
    int i;
	for(i=0; i<120; i++)
    {
        printf("\xdb");
    }
	 char pass[10],password[10]="Team11";
    
    printf("\n\n\t\tEnter the password to login:");
    i=0;
    char ch;
    while(1)
    {
    	ch=getch();
    	if(ch==ENTER)
    	{
    		pass[i]='\0';
    		break;
		}
		else if(ch==BKSPACE)
		{
			if(i>0)
			{
				i--;
				printf("\b \b");
			}
		}
		else if(ch==TAB || ch==SPACE)
		{
			continue;
		}
		else
		{
			pass[i]=ch;
			printf("*");
			i++;
		}
	}
    if (strcmp(pass,password)==0)
        {printf("\n\n\t\tYOU ARE IN !\n\t\tLOADING");
        for(i=0;i<=6;i++)
        {
            fordelay(100000000);
            printf("..");
        }
                system("cls");
            main_menu();
        }
    else
        {   printf("\n\n\t\tWrong password!!\a\a\a");
            login_try:
            printf("\n\t\tEnter 1 to try again and 0 to exit:");
            scanf("%d",&main_exit);
            if (main_exit==1)
                    {

                        system("cls");
                        main();
                    }

            else if (main_exit==0)
                    {
                    system("cls");
            }
            else
                    {printf("\nInvalid!");
                    fordelay(1000000000);
                    system("cls");
                    goto login_try;}

        }
    return 0;

}
void fordelay(int j)
{   int i,k;
    for(i=0;i<j;i++)
         k=i;
}
/// MAIN MENU
void main_menu()
{
	system("cls");
	system("color 6E");

	int op;
	printf("\t\t\t@@@@@@@   ASTER MESS MANAGEMENT SYSTEM @@@@@@@\n\n");
	printf("\t ***** WELCOME TO MENU *****\n\t ***** LET'S GET STARTED *****\n");
    while(1)
    {
        // system("cls");
        printf("\n\t* Choose any one option *\n ");
        printf("\n\t* 1.Add New Student *\n ");
        printf("\n\t* 2.Update Information Of Student *\n ");
        printf("\n\t* 3.Display Student List *\n ");
        printf("\n\t* 4.Display menu of mess *\n ");
        printf("\n\t* 5.Delete a particular *\n ");
        printf("\n\t* 6.Sort data by ID *\n ");
        printf("\n\t* 7.Daily Mess Attendence *\n ");
        printf("\n\t* 8.About particular information *\n ");
        printf("\n\t* 0.Exit *\n ");
        printf("\n\n\t Your Option : \n");
        printf("\t\t");
        scanf("%d",&op);
        switch(op)
        {
        case 1:
            input();
            break;
        case 2:
            update();
            break ;
        case 3:
            display();
            break ;
        case 4:
            menu();
            break ;
        case 5:
            del();
            break;
        case 6:
            sortbyid();
            break;
        case 7:
            dailyattendance();
            break;
        case 8:
            particular();
            break;
        case 0:
         exit(0);
            break;
        default:
            printf("\t\tInvalid choice... \n\n");
            break;
        }
    }
    system("cls");
    printf("\t Process completed... \n\n");
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
        main_menu();
    else if(main_exit==0)
        exit(0);
}
///   DATA PROCESSING ON FILE
/// CHECKING THE VALIDITY OF INPUTS ///
/// To check validity of id ///
int valid_id(int id)
{
    int i;
    for(i=0;id>0;i++)
        id/=10;
    if(i==0||i>4)
    {
        printf("\n\t\tInvalid id (id should be maximum 4 digit number and NO alphabets.)\n");
        return 0;
    }
    else
        return 1;
}
/// to check validity of name ///
int valid_name(char name[])
{
    int i;
    if(!strlen(name))
        return 0;
    for(i=0;i<strlen(name);i++)
    {
        if(!(name[i]>=65&&name[i]<=90||name[i]>=97&&name[i]<=122||name[i]==32))
        {
            printf("\n\t\tInvalid Customer name\n");
            return 0;
        }
    }
    return 1;
}
/// to check validity of contact ///
int valid_contact(char contact[])
{
    int i;
    if(strlen(contact)!=10)
    {
        printf("\n\t\tInvalid Contact no.\n");
        return 0;
    }
    for(i=0;i<strlen(contact);i++)
    {
        if(contact[i]<48||contact[i]>57)
        {
            printf("\n\t\tInvalid Contact no.\n");
            return 0;
        }
    }
    return 1;
}


/// INPUT DATA ///
void input()
{
    system("cls");
    system("COLOR 09");   //black-blue
    fp=fopen(filename,"ab");
    if (!fp)
    {
        printf(" File not found or unable to open the input file!!\n");

    }
    printf("\n\t\tEnter Customer id       : ");
    fflush(stdin);
    scanf("%d",&s.id);
    while(!valid_id(s.id))
    {
        printf("\n\t\tEnter Customer id       : ");
        fflush(stdin);
        scanf("%d",&s.id);
    }
    printf("\n\t\tEnter Customer name     : ");
    fflush(stdin);
    gets(s.name);
    while(!valid_name(s.name))
    {
        printf("\n\t\tEnter Customer name     : ");
        fflush(stdin);
        gets(s.name);
    }
    printf("\n\t\tEnter Customer contact  : ");
    fflush(stdin);
    gets(s.contact);
    while(!valid_contact(s.contact))
    {
        printf("\n\t\tEnter Customer contact  : ");
        fflush(stdin);
        gets(s.contact);
    }
    printf("\n\t\tEnter Customer amt_paid : ");
    fflush(stdin);
    scanf("%d",&s.amt_paid);
    s.present=0;
    fwrite(&s,sizeof(s),1,fp);
    //fprintf(fp,"\n");  // for file purpose only
    fclose(fp);
    system("COLOR 0A");//GREEN

    printf("\n\t\tData saved successfully... \n\n");
    
    
    //EXIT option to main menu or out to process
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
        main_menu();
    else if(main_exit==0)
        exit(0);
}

///   Sorting data as per id

void sortbyid()
{
    system("cls");
    system("COLOR E0");   //y-Blk
//clrscr();
    int c=0, i, j;
    struct Customer s1[50],t;
    system("cls");
    printf("\t\t\t<== Mess  Management ==>\n");
    printf("\t\t\t<== Sort By ID  ==>\n");
    fp = fopen(filename,"rb");
    while(fread(&s,sizeof(s),1,fp)==1)
        s1[c++]=s;

    for(i=0; i<c-1; i++)
    {
        for(j=i+1; j<c; j++)
        {
            int id1,id2;
            id1=(s1[i].id);
            id2=(s1[j].id);   ///atoi---->>>>   string to int directly
            if(id1>id2)
            {
                t = s1[i];
                s1[i]=s1[j];
                s1[j]=t;
            }
        }
    }
    printf("\t\t%-5s %-15s %-15s %-15s  %-5s\n\n","Id","Name","Contact","amt_paid","Attendance");

    for(i=0; i<c; i++)
        printf("\t\t%-5d %-15s %-15s %-15d %-5d\n\n",s1[i].id,s1[i].name,s1[i].contact,s1[i].amt_paid,s1[i].present);

	 //EXIT option to main menu or out to process
	printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
        main_menu();
    else if(main_exit==0)
        exit(0);


}



void display()
{
    system("cls");
    fp=fopen(filename,"rb");
    printf("\t\t%-5s %-15s %-15s %-15s %-5s\n","Id","Name","Contact","amt_paid","Attendance");
    while(fread(&s,sizeof(s),1,fp)==1)
    {
        printf("\t\t%-5d %-15s %-15s %-15d %-5d\n\n",s.id,s.name,s.contact,s.amt_paid,s.present);
    }
    fclose(fp);
   
   
   	 //EXIT option to main menu or out to process
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
        main_menu();
    else if(main_exit==0)
        exit(0);
}

/// Update  information
void update()
{
	system("cls");
    system("COLOR 5E");   //purple-yellow
    int  f=0;
    int id1=0;
    printf("\t\tEnter Id To Update: ");
    fflush(stdin);
    scanf("%d",&id1);
    while(!valid_id(id1))
    {
        printf("\t\tEnter Id To Update: ");
        fflush(stdin);
        scanf("%d",&id1);
    }
    fp=fopen(filename,"rb+");
    if (!fp)
    {
        system("COLOR 5C");   //purple-yellow
        printf(" File not found or unable to open the input file!!\n\n");

    }

    while(fread(&s,sizeof(s),1,fp)==1)
    {
        if(id1==s.id)
        {
            f=1;
            printf("\n\n\t\tEnter New Name    : ");
            fflush(stdin);
            gets(s.name);
            while(!valid_name(s.name))
            {
                printf("\n\n\t\tEnter New Name    : ");
                fflush(stdin);
                gets(s.name);
            }
            printf("\n\n\t\tEnter Contact     : ");
            scanf("%s",s.contact);
            while(!valid_contact(s.contact))
            {
                printf("\n\n\t\tEnter Contact     : ");
                scanf("%s",s.contact);
            }
            printf("\n\n\t\tEnter New amt_paid: ");
            scanf("%d",&s.amt_paid);
            s.present=0;
            fseek(fp,-sizeof(s),1);
            fwrite(&s,sizeof(s),1,fp);
            fclose(fp);
            break;
        }
    }
    if(f==0)
    {
        system("cls");
        system("COLOR 5C");   //purple-yellow
        printf("\n\n\t\tRecord Not Found...\n\n");
    }
    else
    {
        system("cls");
        printf("\n\n\t\tModified Successfully...\n\n");
    }
    
    
     //EXIT option to main menu or out to process
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
        main_menu();
    else if(main_exit==0)
        exit(0);

}

///  Delete information

void del()
{
	system("cls");
    int f=0;
    int  id1=0;
    system("COLOR B0");   //purple-yellow
    printf("\n\t\tEnter mess id  to delete: ");
    fflush(stdin);
    scanf("%d",&id1);

    FILE *ft;
    fp = fopen(filename,"rb");
    ft = fopen("temp.txt","ab");

    while(fread(&s,sizeof(s),1,fp)==1)
    {
        if(id1==s.id)
        {
            f=1;
        }
        else
        {
            fwrite(&s,sizeof(s),1,ft);
        }

    }
    fclose(fp);
    fclose(ft);
    remove(filename);
    rename("temp.txt",filename);

    if(f==0)
    {
        system("cls");
       system("COLOR BC");   //purple-yellow
        printf("\n\n\t\tRecord Not Found...\n\n");
    }
    else
    {
        system("cls");
        system("COLOR 5A");   //purple-yellow
        printf("\n\n\t\tRecord Deleted Successfully...\n\n");
    }
    
     //EXIT option to main menu or out to process
	printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
        main_menu();
    else if(main_exit==0)
        exit(0);
}

///  Mess Menu

void menu()
{
    system("cls");
    system("COLOR 30");   //purple-yellow

    printf("\n\t\t***************************************************************************");
    printf("\n\t\t***************************************************************************");
    printf("\n\t\t  W       W       W  EEEEEE L      CCCCCC OOOOOO  M               M  EEEEEE");
    printf("\n\t\t  W      W W      W  E      L      C      O    O  M M           M M  E");
    printf("\n\t\t  W     W   W     W  E      L      C      O    O  M  M         M  M  E");
    printf("\n\t\t  W    W     W    W  EEEEEE L      C      O    O  M   M       M   M  EEEEEE");
    printf("\n\t\t  W   W       W   W  E      L      C      O    O  M    M     M    M  E");
    printf("\n\t\t  W  W         W  W  E      L      C      O    O  M     M   M     M  E");
    printf("\n\t\t  W W           W W  E      L      C      O    O  M      M M      M  E");
    printf("\n\t\t  W               W  EEEEEE LLLLLL CCCCCC OOOOOO  M       M       M  EEEEEE");
    printf("\n\n\t\t**************************************************************************");
    printf("\n\t\t****************************************************************************");
    ///INFO- ASTER MESS
   system("COLOR 3E");  
    printf("\n\n\t\t\t **** MESS MENU **** \n\n");
    printf("\t\t***About Food ->\n");
    printf("\t\tSunday    : Non-veg and  Veg\n");
    printf("\t\tMonday    : Veg\n");
    printf("\t\tTuesday   : Veg\n");
    printf("\t\tWednesday : Non-Veg + Veg\n");
    printf("\t\tThursday  : Veg\n");
    printf("\t\tFriday    : Veg\n");
    printf("\t\tSaturday  : Veg\n");
    ///RULES

    printf("\n\t\t\t**** RULES ****\n\n");
    printf("\t\t 1 -> Students are instructed to come to mess within the alloted time.\n");
	printf("\t\t 2 -> Get your attendance marked at the counter daily.\n");
	printf("\t\t 3-> Inform 2 days before you go for holidays, otherwise payment would not be altered.\n");
	printf("\t\t 4-> Payment should be done before the due date.\n");         /// Write rules here
	printf("\t\t 5-> No one can take meal to the room. For the sick person, food will be brought to the room by a mess\n\t\t worker and the same worker will bring back those utensils.\n");
	printf("\t\t 6->DON'T WASTE FOOD,take the food according to your requirement.\n");
	
	 //EXIT option to main menu or out to process
	printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
        main_menu();
    else if(main_exit==0)
        exit(0);
}

///Daily Attendance

void dailyattendance()
{
	system("cls");
    printf("\n\t\tEnter id number it will be recorded or -1 to exit ...\n");
    int  id1;
    fflush(stdin);
    scanf("%d",&id1);

    while(id1!=-1)
    {

        fp=fopen(filename,"rb+");
        if (!fp)
        {
            printf(" File not found or unable to open the input file!!\n");

        }
        int f=0;

        while(fread(&s,sizeof(s),1,fp)==1)
        {
            system("cls");
            int id2=(s.id);
            if(id2==id1)
            {
                f=1;
                if(s.present==29){
                       system("COLOR 5C");   //purple-yellow
                    printf("\t\tHi %s today is your last day  of last renewal... \nPlease renew your  mess card ...  ",s.name);
                }
                if(s.present==30)
                {   system("COLOR 5E");   //purple-yellow
                    printf("\t\t%s today is your first day of renewal...  ",s.name);
                    s.present=0;
                    s.amt_paid=0;
                }
                s.present+=1;
                fseek(fp,-sizeof(s),1);
                fwrite(&s,sizeof(s),1,fp);
                fclose(fp);
            }
        }
        if(f==0)  {   system("COLOR 5C");   //purple-yellow
            printf("\n\n\t\tSorry ID does not found in Record Not Found...\n\n");}
        else{   system("COLOR 5A");   //purple-yellow
            printf("\n\n\t\tModified Successfully...in %s\n\n",s.name);
        }
           system("COLOR 5E");   //purple-yellow
        printf("\n\t\tEnter id number it will be recorded or -1 to exit to MENU\n");
        fflush(stdin);
        scanf("%d",&id1);
    }

    fclose(fp);
    system("cls");
    main_menu();
}



///    Information  about a particular

void particular()
{   
	system("cls");
    system("COLOR 5A");   //purple-yellow
    printf("\n\t\tEnter id of a particular ...\n");
    int  id1;
    fflush(stdin);
    scanf("%d",&id1);

    fp=fopen(filename,"rb");
    if (!fp)
    {
        printf(" File not found or unable to open the input file!!\n");

    }
    int f=0;

    while(fread(&s,sizeof(s),1,fp)==1)
    {
        system("cls");
        int id2=(s.id);
        if(id2==id1)
        {
            f=1;
            printf("\t\t%-5s %-15s %-15s %-15s  %-5s\n\n","Id","Name","Contact","amt_paid","Attendance");

            printf("\t\t%-5d %-15s %-15s %-15d %-5d\n\n",s.id,s.name,s.contact,s.amt_paid,s.present);

        }
        if(f==0)
            printf("\n\n\t\tSorry ID does not found in Record Not Found...\n\n");
        fclose(fp);
    }
    
     //EXIT option to main menu or out to process
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
        main_menu();
    else if(main_exit==0)
        exit(0);
}


