#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#include<string.h>                  //contains strcmp(),strcpy(),strlen(),etc

//#include<ctype.h>                   //contains toupper(), tolower(),etc
//#include<dos.h>                     //contains _dos_getdate
//#include<time.h>

COORD cursor = {0,0};

void gotopoint(int x,int y)
{
    cursor.X = x;
    cursor.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),cursor);
}
void Password();
int main()
{
    Password();
    getche();
    return 0;
}

void mainmenu()
{
    FILE *fp, *ftp, *fpr;
    char another, choice;

    struct emp
    {   char id[40];
        char name[40];
        int age;
        float basic;
        char address[100];
        int dd,mm,yy;
        char peradd[100];
        double salary;
        double present;

    };
    struct emp e;
    char empid[40];
    char ch;
    int j,i=0,k,p;
    int cas=0,cnt,dt=0,bon,modi,search=0,l,idlen=0,modilen1=0,modilen2=0,correct;
    char design1[40]={"Employee Record System"};
    char design2[10000]={"   *************************EMPLOYEE RECORD LIST*************************"};
    char xt[100]={"---\aThank You---"};
    char catg;
    char mnth[100];
    char rafi[100]={"1.   DEVELOPERS :"};
    char dev1[100]={"i.   Rafiqul Islam Rafi"};
    char dev2[100]={"ii.  Mohammad Yeasin Arafat"};
    char dev3[100]={"iii. Syeda Farhana Aziz"};
    char dev4[100]={"iv.  Fazley Rabbi Ripon"};
    char dev5[100]={"v.   Marjia Akter Mita"};
    char bubt[200]={"-----> Bangladesh University of Business and Technology(BUBT)"};
    char about[100]={"2.Details :"};
    char details[1000]={"The project is made to record employee details.\nIts also used to search recorded employee and calculate\n salary and bonus.The project is made by using c language..."};
    long int size;
    int day,month,year;

    fp = fopen("EMP.DAT","rb+");
    if(fp == NULL)
    {
        fp = fopen("EMP.DAT","wb+");
        if(fp == NULL)
        {
            printf("Can't open file");
            exit(1);
        }
    }
    size = sizeof(e);

    while(1)
    {
        system("cls");
        gotopoint(6,1);
for(k=0;k<21;k++)
{
Sleep(40);
if(k%2==0)
printf("-");
else
    printf("-");
}
for(k=0;k<strlen(design1);k++)
{
    Sleep(40);
    printf("%c",design1[k]);
}
 for(k=0;k<21;k++)
{
Sleep(40);
if(k%2==0)
printf("-");
else
    printf("-");
}
gotopoint(30,3);
printf("1. Add New Records");
gotopoint(30,5);
printf("2. View Records");
gotopoint(30,7);
printf("3. Search employee");
gotopoint(30,9);
printf("4. Modify or Edit or Update Records");
gotopoint(30,11);
printf("5. Delete or Remove Records");
gotopoint(30,13);
printf("6. Calculate  salary");
gotopoint(30,15);
printf("7. Calculate bonus");
gotopoint(30,17);
printf("8. About");
gotopoint(30,19);
printf("0. Exit");
printf("\n");
gotopoint(20,21);

gotopoint(20,25);
printf("Please Enter Your Choice: ");

fflush(stdin); // flush the input buffer
choice  = getche();

switch(choice)
{
case '1':
    system("cls");
    fseek(fp,0,SEEK_END);

    another = 'y';
    while(another == 'y')
{
    printf("\n  Enter employee id: ");
    again:
    scanf("%s",&e.id);

    idlen=strlen(e.id);
    for(p=0;p<idlen;p++)
    {
     if((e.id[p]>='0'&&e.id[p]<='9'))
        {
          continue;
        }
            else
            { printf("You Entered wrong keyword!\n\nPlease again Enter id :");
                        goto again;


                        break;

                        }
    }
    printf("\n  Enter Name: ");
     again1:
    scanf("%s",e.name);



                 l=strlen(e.name);
                for(i=0;i<l;i++)
                {
                if((e.name[i]>='a'&&e.name[i]<='z')||(e.name[i]>='A'&&e.name[i]<='Z')||(e.name[i]==' '))
                        {
                        continue;
                        }
                        else
                        { printf("You Entered wrong keyword!\n\nPlease again Enter name :");
                        goto again1;


                        break;

                        }
                       }

    printf("\n  Enter Age: ");
    scanf("%d", &e.age);
    if(e.age<=19||e.age>=89||(e.age>='a'&&e.age<='z')||(e.age>='A'&&e.age<='Z'))
    {printf("Invalid age\n");
     printf("\n\nPress any key to go Main Menu\n");
     getch();
     break;
    }
    printf("\n  Enter Basic Salary: ");
    scanf("%f", &e.basic);
    printf("\n  Enter Address: ");
    scanf("%s",e.address);
    printf("\n  Enter Permanent Address: ");
    scanf("%s",e.peradd);
    printf("\n  Enter Joining Date format (day month year): ");

    scanf("%d%d%d",&e.dd,&e.mm,&e.yy);
    if((e.dd>=1&&e.dd<=31)&&(e.mm>=1&&e.mm<=12))
    {

    printf("\n\n\nSuccessfully  added\n\n");
    }
    else

    {
    printf("Invalid date or month\n");
    printf("\n\nPress any key to go Main Menu\n");
    getch();
    break;
    }




    fwrite(&e,size,1,fp);

    printf("\nAdd another record(y/n) ");
    fflush(stdin);
    another = getche();
}
break;

case '2':
    system("cls");
    rewind(fp);
   // gotopoint(5,5);

        printf("%s",design2);

    gotopoint(0,3);
     printf("Name");
     gotopoint(15,3);
     printf("id");
      gotopoint(25,3);
    printf("Age");
 gotopoint(35,3);
    printf("Salary");
 gotopoint(45,3);
    printf("Address");
 gotopoint(60,3);
    printf("Permanent Address");
    gotopoint(85,3);
    printf("Joining Date");
    cas=3;
while(fread(&e,size,1,fp)==1)
{
    cas+=2;
    gotopoint(0,cas);
     printf("%s",e.name);
     gotopoint(15,cas);
     printf("%s",e.id);
      gotopoint(25,cas);
    printf("%d",e.age);
 gotopoint(35,cas);
    printf("%0.2lf",e.basic);
 gotopoint(45,cas);
    printf("%s",e.address);
 gotopoint(60,cas);
    printf("%s",e.peradd);
    gotopoint(85,cas);
    printf("%d-%d-%d",e.dd,e.mm,e.yy);
}
    printf("\n\n\n\nDo u want to Calculate Salary ?(y/n)\n");
    another=getche();
    getche();
while(another=='y')
{
    double temp=0,d,present;

    printf("\nEnter id of Employee to Calculate Salary: ");
    scanf("%s",empid);

    fpr = fopen("Temp2.dat","wb");
    rewind(fp);
    //if(strcmp(e.id,empid) != 0)

while(fread(&e,size,1,fp) == 1)
{
    if(strcmp(e.id,empid) == 0){


    printf("\n Enter present month(january...december)\n");
    scanf("%s",mnth);
    cnt=1;
    if(strcmp(mnth,"january")==0 || strcmp(mnth,"January")==0 || strcmp(mnth,"JANUARY")==0 || strcmp(mnth,"march")==0 || strcmp(mnth,"March")==0 || strcmp(mnth,"MARCH")==0 || strcmp(mnth,"may")==0 || strcmp(mnth,"May")==0 || strcmp(mnth,"MAY")==0 || strcmp(mnth,"august")==0 || strcmp(mnth,"August")==0 || strcmp(mnth,"AUGUST")==0 || strcmp(mnth,"july")==0 || strcmp(mnth,"July")==0 || strcmp(mnth,"JULY")==0 || strcmp(mnth,"october")==0 || strcmp(mnth,"October")==0 || strcmp(mnth,"OCTOBER")==0 || strcmp(mnth,"december")==0 || strcmp(mnth,"December")==0 || strcmp(mnth,"DECEMBER")==0){
    printf("\nEnter his/her attendence of this month:\n");
    scanf("%lf",&present);
    if(present>31 || present<0)
    {
        printf("\ninvalid day\n");
        cnt=1;
        break;
    }

    temp=(e.basic/31);
    printf("\n%s will get %0.2lf taka of this month",e.name,temp*present);
    cnt=1;
     break;
    }
    else if(strcmp(mnth,"february")==0 || strcmp(mnth,"February")==0 || strcmp(mnth,"FEBRUARY")==0){
                printf("\nEnter his/her attendence of this month:\n");
    scanf("%lf",&present);
    if(present>28 || present<0)
    {
        printf("\ninvalid day\n");
        cnt=1;
        break;
    }

    temp=(e.basic/28);
    printf("\n%s will get %0.2lf taka of this month",e.name,temp*present);
    cnt=1;
     break;
    }

       else if(strcmp(mnth,"april")==0 || strcmp(mnth,"April")==0 || strcmp(mnth,"APRIL")==0 || strcmp(mnth,"june")==0 || strcmp(mnth,"June")==0 || strcmp(mnth,"JUNE")==0 || strcmp(mnth,"september")==0 || strcmp(mnth,"September")==0 || strcmp(mnth,"SEPTEMBER")==0 || strcmp(mnth,"november")==0 || strcmp(mnth,"November")==0 || strcmp(mnth,"NOVEMBER")==0){
                printf("\nEnter his/her attendence of this month:\n");
    scanf("%lf",&present);
    if(present>30 || present<0)
    {
        printf("\ninvalid day\n");
        cnt=1;
        break;
    }

    temp=(e.basic/30);
    printf("\n%s will get %0.2lf taka of this month",e.name,temp*present);
    cnt=1;
     break;
    }

}
else
{
    cnt=0;
    continue;
}

    }
    if(cnt==0){
    printf("\nIncorrect id....\n");
    }

    fclose(fpr);
    printf("\nCalculate Another Employee Salary(y/n)");
    fflush(stdin);
    another = getche();
}

    printf("\n\nPress any key to go Main Menu\n");
    getch();
break;


case '3':
    system("cls");
    another = 'y';
    cas=3;
while(another == 'y')
{
    printf("\nEnter id of Employee to search: ");
    again3:
    scanf("%s",empid);
    for(p=0;p<strlen(empid);p++)
    {
     if((empid[p]>='0'&&empid[p]<='9'))
        {
          continue;
        }
            else
            { printf("You Entered wrong keyword!\n\nPlease again Enter id :");
                        goto again3;


                        break;

                        }
    }


    cas+=3;
    rewind(fp);
while(fread(&e,size,1,fp) == 1)
{
    if(strcmp(e.id,empid) == 0)
{    gotopoint(0,cas);
     printf("Name");
     gotopoint(15,cas);
     printf("id");
      gotopoint(25,cas);
    printf("Age");
 gotopoint(35,cas);
    printf("Salary");
 gotopoint(45,cas);
    printf("Address");
 gotopoint(60,cas);
    printf("Permanent Address");
    gotopoint(85,cas);
    printf("Joining Date");

    cas+=2;

     gotopoint(0,cas);
     printf("%s",e.name);
     gotopoint(15,cas);
     printf("%s",e.id);
      gotopoint(25,cas);
    printf("%d",e.age);
 gotopoint(35,cas);
    printf("%0.2lf",e.basic);
 gotopoint(45,cas);
    printf("%s",e.address);
 gotopoint(60,cas);
    printf("%s",e.peradd);
    gotopoint(85,cas);
    printf("%d-%d-%d",e.dd,e.mm,e.yy);

    search=1;
    break;
}
if(strcmp(e.id,empid)!=0)
{
    search=0;
}

}

if(search==0)
{
    printf("\n\nSorry! The record not found\n");
    cas+=3;

}
search=0;

printf("\n\ndo u want to search another record (y/n) ? : ");



    another = getche();
    getche();
    cas+=3;
    if(another=='n')
    {
        printf("\n\n\n\n\nenter any key for main menu\n");
        getche();
    }

}
break;

case '4':
    system("cls");
    another = 'y';
while(another == 'y')
{
    printf("Enter the Employee id to Modify: ");
    again4:
    scanf("%s", empid);

    for(p=0;p<strlen(empid);p++)
    {
     if((empid[p]>='0'&&empid[p]<='9'))
        {
          continue;
        }
            else
            { printf("You Entered wrong keyword!\n\nPlease again Enter id :");
                        goto again4;


                        break;

                        }
    }
    rewind(fp);

while(fread(&e,size,1,fp)==1)
{
    if(strcmp(e.id,empid) == 0){
            printf("\n\nRecord found and Able to modify\n\n");

    printf("\n  Enter new id : ");
    idmodi:
    scanf("%s",e.id);

    modilen2=strlen(e.id);
    for(p=0;p<modilen2;p++)
    {
     if((e.id[p]>='0'&&e.id[p]<='9'))
        {
          continue;
        }
            else
            { printf("You Entered wrong keyword!\n\nPlease again Enter id :");
                        goto idmodi;


                        break;

                        }
    }
     printf("\n  Enter Name : ");
     namemodi:
    scanf("%s",e.name);

    modilen1=strlen(e.name);
                for(i=0;i<modilen1;i++)
                {
                if((e.name[i]>='a'&&e.name[i]<='z')||(e.name[i]>='A'&&e.name[i]<='Z')||(e.name[i]==' '))
                        {
                        continue;
                        }
                        else
                        { printf("You Entered wrong keyword!\n\nPlease again Enter name :");
                        goto namemodi;


                        break;

                        }}
    printf("\n  Enter Age: ");
    scanf("%d", &e.age);
    if(e.age<=19||e.age>=89||(e.age>='a'&&e.age<='z')||(e.age>='A'&&e.age<='Z'))
    {printf("Invalid age\n");
     printf("\n\nPress any key to go Main Menu\n");
     getch();
     break;
    }

    printf("\n  Enter Basic Salary: ");
    scanf("%f", &e.basic);
    printf("\n  Enter Address: ");
    scanf("%s",e.address);
    printf("\n  Enter Permanent Address: ");
    scanf("%s",e.peradd);
    printf("\n  Enter Joining Date format (day month year): ");

    scanf("%d%d%d",&e.dd,&e.mm,&e.yy);
    if((e.dd>=1&&e.dd<=31)&&(e.mm>=1&&e.mm<=12))
    {
    correct=0;
    }
    else

    {
    printf("Invalid date or month\n");
    printf("\n\nPress any key to go Main Menu\n");
    getch();
    break;
    }



    fseek(fp,-size,SEEK_CUR);
    fwrite(&e,size,1,fp);
    printf("\n\n successfully  modified.....\n");
    modi=1;
break;

}
else
    modi==0;
    }
    if((strcmp(e.id,empid)!=0) && modi!=1)
{
    printf("\aSorry ! Record not Found");

    printf("\n\nPRESS ANY KEY FOR MAIN MENU\n");
}


    if(strcmp(e.id,empid) == 0)
    printf("\nModify another record(y/n)");

    fflush(stdin);
    another = getche();
}
break;
case '5':
    system("cls");
    another = 'y';
    dt=0;
while(another == 'y')
{
    printf("\nEnter id of Employee to Delete: ");
    delid:
    scanf("%s",empid);

    for(p=0;p<strlen(empid);p++)
    {
     if((empid[p]>='0'&&empid[p]<='9'))
        {
          continue;
        }
            else
            { printf("You Entered wrong keyword!\n\nPlease again Enter id :");
                        goto delid;


                        break;

                        }
    }



    ftp = fopen("Temp.dat","wb");
    rewind(fp);
while(fread(&e,size,1,fp) == 1)
{
    if(strcmp(e.id,empid) != 0)
{
    fwrite(&e,size,1,ftp);
}
if(strcmp(e.id,empid)==0)
{
    printf("\n\n\nThe record is successfully deleted\n\n\n");
    dt=1;
}

}



    fclose(fp);
    fclose(ftp);
    remove("EMP.DAT");
    rename("Temp.dat","EMP.DAT");
    fp = fopen("EMP.DAT", "rb+");

if(dt==0)
{
    printf("\n\n\aThe record not found\n\n\n");

}
dt=0;
    printf("\nDelete another record(y/n)");
    fflush(stdin);
    another = getche();


}
break;

case '6':
    system("cls");
    another='y';
while(another=='y')
{
    double temp=0,d,present;

    printf("\nEnter id of Employee to Calculate Salary: ");
    salid:
    scanf("%s",empid);

    for(p=0;p<strlen(empid);p++)
    {
     if((empid[p]>='0'&&empid[p]<='9'))
        {
          continue;
        }
            else
            { printf("You Entered wrong keyword!\n\nPlease again Enter id :");
                        goto salid;


                        break;

                        }
    }



    fpr = fopen("Temp2.dat","wb");
    rewind(fp);
    //if(strcmp(e.id,empid) != 0)

while(fread(&e,size,1,fp) == 1)
{
    if(strcmp(e.id,empid) == 0){


    printf("\n Enter present month(january...december)\n");
    scanf("%s",mnth);
    cnt=1;

    if(strcmp(mnth,"january")==0 || strcmp(mnth,"January")==0 || strcmp(mnth,"JANUARY")==0){
    printf("\nEnter his/her attendence of this month:\n");
    scanf("%lf",&present);
    if(present>31 || present<0)
    {
        printf("\ninvalid day\n");
        cnt=1;
        break;
    }

    temp=(e.basic/31);
    printf("\n%s will get %0.2lf taka of this month",e.name,temp*present);
    cnt=1;
     break;
    }
    else if(strcmp(mnth,"february")==0 || strcmp(mnth,"February")==0 || strcmp(mnth,"FEBRUARY")==0){
                printf("\nEnter his/her attendence of this month:\n");
    scanf("%lf",&present);
    if(present>28 || present<0)
    {
        printf("\ninvalid day\n");
        cnt=1;
        break;
    }

    temp=(e.basic/28);
    printf("\n%s will get %0.2lf taka of this month",e.name,temp*present);
    cnt=1;
     break;
    }

    else if(strcmp(mnth,"march")==0 || strcmp(mnth,"March")==0 || strcmp(mnth,"MARCH")==0){
                printf("\nEnter his/her attendence of this month:\n");
    scanf("%lf",&present);
    if(present>31 || present<0)
    {
        printf("\ninvalid day\n");
        cnt=1;
        break;
    }

    temp=(e.basic/31);
    printf("\n%s will get %0.2lf taka of this month",e.name,temp*present);
    cnt=1;
     break;
    }
       else if(strcmp(mnth,"april")==0 || strcmp(mnth,"April")==0 || strcmp(mnth,"APRIL")==0){
                printf("\nEnter his/her attendence of this month:\n");
    scanf("%lf",&present);
    if(present>30 || present<0)
    {
        printf("\ninvalid day\n");
        cnt=1;
        break;
    }

    temp=(e.basic/30);
    printf("\n%s will get %0.2lf taka of this month",e.name,temp*present);
    cnt=1;
     break;
    }
           else if(strcmp(mnth,"may")==0 || strcmp(mnth,"May")==0 || strcmp(mnth,"MAY")==0){
                    printf("\nEnter his/her attendence of this month:\n");
    scanf("%lf",&present);
    if(present>31 || present<0)
    {
        printf("\ninvalid day\n");
        cnt=1;
        break;
    }

    temp=(e.basic/31);
    printf("\n%s will get %0.2lf taka of this month",e.name,temp*present);
    cnt=1;
     break;
    }

          else if(strcmp(mnth,"june")==0 || strcmp(mnth,"June")==0 || strcmp(mnth,"JUNE")==0){
                    printf("\nEnter his/her attendence of this month:\n");
    scanf("%lf",&present);
    if(present>30 || present<0)
    {
        printf("\ninvalid day\n");
        cnt=1;
        break;
    }

    temp=(e.basic/30);
    printf("\n%s will get %0.2lf taka of this month",e.name,temp*present);
    cnt=1;
     break;
    }
          else if(strcmp(mnth,"july")==0 || strcmp(mnth,"July")==0 || strcmp(mnth,"JULY")==0){
                    printf("\nEnter his/her attendence of this month:\n");
    scanf("%lf",&present);
    if(present>31 || present<0)
    {
        printf("\ninvalid day\n");
        cnt=1;
        break;
    }

    temp=(e.basic/31);
    printf("\n%s will get %0.2lf taka of this month",e.name,temp*present);
    cnt=1;
     break;
    }
          else if(strcmp(mnth,"august")==0 || strcmp(mnth,"August")==0 || strcmp(mnth,"AUGUST")==0){
                    printf("\nEnter his/her attendence of this month:\n");
    scanf("%lf",&present);
    if(present>31 || present<0)
    {
        printf("\ninvalid day\n");
        cnt=1;
        break;
    }

    temp=(e.basic/31);
    printf("\n%s will get %0.2lf taka of this month",e.name,temp*present);
    cnt=1;
     break;
    }
          else if(strcmp(mnth,"september")==0 || strcmp(mnth,"September")==0 || strcmp(mnth,"SEPTEMBER")==0){
                    printf("\nEnter his/her attendence of this month:\n");
    scanf("%lf",&present);
    if(present>30 || present<0)
    {
        printf("\ninvalid day\n");
        cnt=1;
        break;
    }

    temp=(e.basic/30);
    printf("\n%s will get %0.2lf taka of this month",e.name,temp*present);
    cnt=1;
     break;
    }
          else if(strcmp(mnth,"october")==0 || strcmp(mnth,"October")==0 || strcmp(mnth,"OCTOBER")==0){
                    printf("\nEnter his/her attendence of this month:\n");
    scanf("%lf",&present);
    if(present>31 || present<0)
    {
        printf("\ninvalid day\n");
        cnt=1;
        break;
    }

    temp=(e.basic/31);
    printf("\n%s will get %0.2lf taka of this month",e.name,temp*present);
    cnt=1;
     break;
    }
          else if(strcmp(mnth,"november")==0 || strcmp(mnth,"November")==0 || strcmp(mnth,"NOVEMBER")==0){
                    printf("\nEnter his/her attendence of this month:\n");
    scanf("%lf",&present);
    if(present>30 || present<0)
    {
        printf("\ninvalid day\n");
        cnt=1;
        break;
    }

    temp=(e.basic/30);
    printf("\n%s will get %0.2lf taka of this month",e.name,temp*present);
    cnt=1;
     break;
    }
          else if(strcmp(mnth,"december")==0 || strcmp(mnth,"December")==0 || strcmp(mnth,"DECEMBER")==0){
                    printf("\nEnter his/her attendence of this month:\n");
    scanf("%lf",&present);
    if(present>31 || present<0)
    {
        printf("\ninvalid day\n");
        cnt=1;
        break;
    }

    temp=(e.basic/31);
    printf("\n%s will get %0.2lf taka of this month",e.name,temp*present);
    cnt=1;
     break;
    }
    else
    {
        printf("\ninvalid month\n");
        break;
    }




}
else
{
    cnt=0;
    continue;
}

    }
    if(cnt==0){
    printf("\nIncorrect id....\n");
    }

    fclose(fpr);
    printf("\nCalculate Another Employee Salary(y/n)");
    fflush(stdin);
    another = getche();
}
    printf("\n\n\nPress any key to go Main Menu\n");
    getch();
break;

case '7':
    system("cls");
    another='y';
while(another=='y')
{

    printf("\n\nEnter id of Employee to Calculate bonus: ");

    bonusid:
    scanf("%s",empid);

    for(p=0;p<strlen(empid);p++)
    {
     if((empid[p]>='0'&&empid[p]<='9'))
        {
          continue;
        }
            else
            { printf("You Entered wrong keyword!\n\nPlease again Enter id :");
                        goto bonusid;


                        break;

                        }
    }


    printf("\nEnter the Category of this Employee(A/B/C/D)\n: ");
    catg=getche();
    getche();
    fpr = fopen("Temp2.dat","wb");
    rewind(fp);


while(fread(&e,size,1,fp) == 1)
{
    if(strcmp(e.id,empid) == 0){


    printf("\nEnter Present date :\n");
    scanf("%d",&day);

    if(day>=32)
    {printf("Invalid date\n");
     printf("\n\nPress any key to go Main Menu\n");
     getch();
     break;
    }

    printf("\nEnter Present month :\n");
    scanf("%d",&month);

    if(month>=13)
    {printf("Invalid month\n");
     printf("\n\nPress any key to go Main Menu\n");
     getch();
     break;
    }
    printf("\nEnter Present year :\n");
    scanf("%d",&year);
    if(e.yy==year)
    {
        printf("\n%s will not get bonus in year %d\n",e.name,year);
        break;
    }
    else if(year-e.yy==1)
    {
        if(month>=e.mm)
        {
            if(day>=e.dd&&catg=='A')
                printf("\n%s will get  =%0.2f taka as  bonus in year %d\n",e.name,0.5*e.basic,year);
                if(day>=e.dd&&catg=='B')
                printf("\n%s will get  =%0.2f taka as  bonus in year %d\n",e.name,0.25*e.basic,year);
                if(day>=e.dd&&catg=='C')
                printf("\n%s will get  =%0.2f taka as  bonus in year %d\n",e.name,0.10*e.basic,year);

                if(day<e.dd&&catg=='D')
                printf("\n%s will not get bonus in year %d\n",e.name,year);
        }
        if(month<e.mm)
        printf("\n%s will not get bonus in year %d\n",e.name,year);

    }

    else if(year-e.yy>1){
        if(catg=='A')
                printf("\n%s will get  =%0.2f taka as  bonus in year %d\n",e.name,0.5*e.basic,year);
                if(catg=='B')
                printf("\n%s will get  =%0.2f taka as  bonus in year %d\n",e.name,0.25*e.basic,year);
                if(catg=='C')
                printf("\n%s will get  =%0.2f taka as  bonus in year %d\n",e.name,0.10*e.basic,year);

                if(catg=='D')
                printf("\n%s will not get bonus in year %d\n",e.name,year);
    }


        else
    {
             printf("\n%s will not get bonus in year %d\n",e.name,year);
    }
        bon=1;
        break;
    }
    else
    {
        bon=0;
        continue;
    }

}

   if(bon==0)
        printf("\nIncorrect employee id\n");
    fclose(fpr);
    printf("\nCalculate Another Employee bonus(y/n)\n");
    fflush(stdin);
    another = getche();
}
    printf("\n\n\nPress any key to go Main Menu\n");
    getch();
break;
case '8':
   system("cls");

   printf("%s",rafi);
   gotopoint(6,1);
   printf("%s",dev1);
   gotopoint(6,3);
   printf("%s",dev2);
   gotopoint(6,5);
   printf("%s",dev3);
   gotopoint(6,7);
   printf("%s",dev4);
   gotopoint(6,9);
   printf("%s",dev5);
   gotopoint(12,11);
   printf("%s",bubt);
   gotopoint(0,15);
   printf("%s",about);
   gotopoint(1,17);
   printf("%s",details);



   printf("\n\n\nPress any key to go Main Menu\n");
    getch();
    break;

case '0':
    fclose(fp);
    gotopoint(20,30);
    for(i=0;i<strlen(xt);i++)
    {
        Sleep(40);
        printf("%c",xt[i]);
    }
    gotopoint(20,40);
    exit(0);
}
}
}
void Password(void)
{
    system("cls");
    int i=0,j;
    char ch;
    char pass[1000];
    char head1[50]={" System is Password Protected "};
    char head2[50]={"Please Enter Password 3-8 character: "};
    gotopoint(10,2);
for(j=0;j<20;j++)
{
Sleep(30);
if(j%2==0)
printf(">");
else
    printf(">");
}
for(j=0;j<strlen(head1);j++)
{
    Sleep(20);
    printf("%c",head1[j]);
}
 for(j=0;j<20;j++)
{
Sleep(30);
if(j%2==0)
printf("<");
else
    printf("<");
}
gotopoint(16,7);
for(j=0;j<strlen(head2);j++)
{
    Sleep(30);
    printf("%c",head2[j]);
}
while(ch!=13)   //ASCII value of enter is 13
{
ch=getch();

if(ch!=13 && ch!=8){
putch('*');
pass[i] = ch;
i++;
}
}
pass[i] = '\0';
if(strcmp(pass,"bubt293")==0)
{

gotopoint(15,10);
printf("Welcome !Password match....");
gotopoint(15,13);
printf("Press any key to continue....");
getch();
mainmenu();

}
else
{
gotopoint(15,16);
printf("\a Sorry! You Entered Wrong Password....");
gotopoint(15,18);
printf("try again.....");
getch();
Password();
}
}
