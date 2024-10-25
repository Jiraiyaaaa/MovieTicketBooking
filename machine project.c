#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include <time.h>
#include"C:\Users\Public\moviedetails.c"
#include"C:\Users\Public\decleration.c"
#include<strings.h>

struct moviedetails person[300];
int count=0;
int id2=1000;
int main()
{
	int **seat,choice,price=10,slection,i;
	seat=(int **)calloc(101,sizeof(int *));
	for (i=0;i<6;i++)
		*(seat+i)=(int *)calloc(101,sizeof(int ));
	int x;
	char movies[1000];
	while(x!=6)
	{
		choice=choice1();
		switch(choice)
		{
			case 1:
				price=changeprize(price);
				break;
			case 2:
				details();
				break;
			case 3:
				slection=movie();
				reservation(seat[slection-1],price,slection);
				count++;
				break;
			case 4:
				slection=cmovie();
				cancel(seat[slection-1]);
				break;
			case 5:
				slection=loadsched();
				break;
			case 6:
                x=5;
				break;
			default:
				printf("Choice not available\n");
				break;

		}
	int loadsched(void)
{
    system("cls");
    FILE *fp1;
    char str[1000];
    char* filename = "MovieSched.txt";

    fp1 = fopen(filename, "r");
    if (fp1 == NULL)
        {
        printf("Could not open file %s",filename);
        return 1;
        }
    while (fgets(str, 1000, fp1) != NULL)
        printf("%s\n", str);
    fclose(fp1);
    return 0;
}
	}
}
int loadsched(void)
{
    system("cls");
    FILE *fp1;
    char str1[1000];
    char* filename1 = "MovieSched_1.txt";

    fp1 = fopen(filename1, "r");
    if (fp1 == NULL)
        {
        printf("Could not open file %s",filename1);
        return 1;
        }
         while (fgets(str1, 1000, fp1) != NULL)
        printf("%s\n", str1);
    fclose(fp1);

        FILE *fp2;
    char str2[1000];
    char* filename2 = "MovieSched_2.txt";

    fp2 = fopen(filename2, "r");
    if (fp2 == NULL)
        {
        printf("Could not open file %s",filename2);
        return 1;
        }
         while (fgets(str2, 1000, fp2) != NULL)
        printf("%s\n", str2);
    fclose(fp2);

        FILE *fp3;
    char str3[1000];
    char* filename3 = "MovieSched_3.txt";

    fp3 = fopen(filename3, "r");
    if (fp3 == NULL)
        {
        printf("Could not open file %s",filename3);
        return 1;
        }
         while (fgets(str3, 1000, fp3) != NULL)
        printf("%s\n", str3);
    fclose(fp3);

        FILE *fp4;
    char str4[1000];
    char* filename4 = "MovieSched_4.txt";

    fp4 = fopen(filename4, "r");
    if (fp4 == NULL)
        {
        printf("Could not open file %s",filename4);
        return 1;
        }
         while (fgets(str4, 1000, fp4) != NULL)
        printf("%s\n", str4);
    fclose(fp4);

        FILE *fp5;
    char str5[1000];
    char* filename5 = "MovieSched_5.txt";

    fp5 = fopen(filename5, "r");
    if (fp5 == NULL)
        {
        printf("Could not open file %s",filename5);
        return 1;
        }
         while (fgets(str5, 1000, fp5) != NULL)
        printf("%s\n", str5);
    fclose(fp5);

        FILE *fp6;
    char str6[1000];
    char* filename6 = "MovieSched_6.txt";

    fp6 = fopen(filename6, "r");
    if (fp6 == NULL)
        {
        printf("Could not open file %s",filename6);
        return 1;
        }
   while (fgets(str6, 1000, fp6) != NULL)
        printf("%s\n", str6);
    fclose(fp6);

}
int choice1(void)
{
	int choice;
	printf("             Machine Project Movie Ticket Booking System\n");
	printf(" ==================================================================\n");
	printf("||             1- To edit price of ticket (only admin):           ||\n");
	printf("||             2- To view reserved tickets (only admin):          ||\n");
	printf("||             3- To purchase ticket:                             ||\n");
	printf("||             4- To cancel the seat:                             ||\n");
	printf("||             5- To load/view Movie Schedule:                    ||\n");
	printf("||             6- Exit system:                                    ||\n");
	printf("||================================================================||\n");
	printf("  Enter your choice: ");
	scanf("%d",&choice);
	return choice;
}
int changeprize(int prize)
{
	char pass[10],pak[10]="pass";
	printf("Enter the password to change price of ticket: ");
	scanf("%s",&pass);
	if (strcmp(pass,pak)==0)
	{
		printf("Please enter new price: ");
		scanf("%d",&prize);
		system("PAUSE");
		system("CLS");
	}
	else
		printf("The entered password is wrong! ");
	return prize;
}
void cancel(int *array)
{
      int Cseat,i,stop;
	  printf("Please enter ID number of ticket: ");
	  scanf("%d",&Cseat);
	  for (i=0;i<300;i++)
	  {
	  		if(Cseat==person[i].id)
	  		{
					 stop=5;
					 system("cls");
					 printf("%s your seat is %d cancelled",person[i].name,person[i].seat);
					 array[person[i].seat]=0;
					 i=300;
	  		}
	  }
	  if (stop!=5)
	  		printf("Ticket ID number is incorrect please enter right one to cancel ticket: \n");

}
int cmovie(void)
{
	int i;
	printf("\t\t\twhich movie ticket you want to cancel\n");
	printf("\t\t\t-------------------------------------\n");
	printf("\t\t\tpress 1 for Avengers: EndGame\n\n");
	printf("\t\t\tpress 2 for Captain Marvel\n\n");
	printf("\t\t\tpress 3 for Spider-Man: Far From Home\n");
	scanf("%d",&i);
	return i;
}
void details(void)
{
	int i;
	char pass[10],pak[10]="pass";
	printf("Enter the password to see details: ");
	scanf("%s",&pass);
	if (strcmp(pass,pak)==0)
	{
		for (i=0;i<count;i++)
		{
			printf("seat no: %d is booked by %s booking id is %d\n",person[i].seat,person[i].name,person[i].id);
		}
	}
	else
		printf("Entered password is wrong \n");
		system("PAUSE");
		system("CLS");

}
int movie(void)
{
	int i;
	system("cls");
int loadsched(void)
{
    system("cls");
    FILE *fp1;
    char str1[1000];
    char* filename1 = "MovieSched_1.txt";

    fp1 = fopen(filename1, "r");
    if (fp1 == NULL)
        {
        printf("Could not open file %s",filename1);
        return 1;
        }
         while (fgets(str1, 1000, fp1) != NULL)
        printf("%s\n", str1);
    fclose(fp1);

        FILE *fp2;
    char str2[1000];
    char* filename2 = "MovieSched_2.txt";

    fp2 = fopen(filename2, "r");
    if (fp2 == NULL)
        {
        printf("Could not open file %s",filename2);
        return 1;
        }
         while (fgets(str2, 1000, fp2) != NULL)
        printf("%s\n", str2);
    fclose(fp2);

        FILE *fp3;
    char str3[1000];
    char* filename3 = "MovieSched_3.txt";

    fp3 = fopen(filename3, "r");
    if (fp3 == NULL)
        {
        printf("Could not open file %s",filename3);
        return 1;
        }
         while (fgets(str3, 1000, fp3) != NULL)
        printf("%s\n", str3);
    fclose(fp3);

        FILE *fp4;
    char str4[1000];
    char* filename4 = "MovieSched_4.txt";

    fp4 = fopen(filename4, "r");
    if (fp4 == NULL)
        {
        printf("Could not open file %s",filename4);
        return 1;
        }
         while (fgets(str4, 1000, fp4) != NULL)
        printf("%s\n", str4);
    fclose(fp4);

        FILE *fp5;
    char str5[1000];
    char* filename5 = "MovieSched_5.txt";

    fp5 = fopen(filename5, "r");
    if (fp5 == NULL)
        {
        printf("Could not open file %s",filename5);
        return 1;
        }
         while (fgets(str5, 1000, fp5) != NULL)
        printf("%s\n", str5);
    fclose(fp5);

        FILE *fp6;
    char str6[1000];
    char* filename6 = "MovieSched_6.txt";

    fp6 = fopen(filename6, "r");
    if (fp6 == NULL)
        {
        printf("Could not open file %s",filename6);
        return 1;
        }
   while (fgets(str6, 1000, fp6) != NULL)
        printf("%s\n", str6);
    fclose(fp6);
}
 FILE *fp1;
    char str1[1000];
    char* filename1 = "MovieSched_1.txt";

    fp1 = fopen(filename1, "r");
    if (fp1 == NULL)
        {
        printf("Could not open file %s",filename1);
        return 1;
        }
         while (fgets(str1, 1000, fp1) != NULL)
        printf("%s\n", str1);
    fclose(fp1);

        FILE *fp2;
    char str2[1000];
    char* filename2 = "MovieSched_2.txt";

    fp2 = fopen(filename2, "r");
    if (fp2 == NULL)
        {
        printf("Could not open file %s",filename2);
        return 1;
        }
         while (fgets(str2, 1000, fp2) != NULL)
        printf("%s\n", str2);
    fclose(fp2);

        FILE *fp3;
    char str3[1000];
    char* filename3 = "MovieSched_3.txt";

    fp3 = fopen(filename3, "r");
    if (fp3 == NULL)
        {
        printf("Could not open file %s",filename3);
        return 1;
        }
         while (fgets(str3, 1000, fp3) != NULL)
        printf("%s\n", str3);
    fclose(fp3);

        FILE *fp4;
    char str4[1000];
    char* filename4 = "MovieSched_4.txt";

    fp4 = fopen(filename4, "r");
    if (fp4 == NULL)
        {
        printf("Could not open file %s",filename4);
        return 1;
        }
         while (fgets(str4, 1000, fp4) != NULL)
        printf("%s\n", str4);
    fclose(fp4);

        FILE *fp5;
    char str5[1000];
    char* filename5 = "MovieSched_5.txt";

    fp5 = fopen(filename5, "r");
    if (fp5 == NULL)
        {
        printf("Could not open file %s",filename5);
        return 1;
        }
         while (fgets(str5, 1000, fp5) != NULL)
        printf("%s\n", str5);
    fclose(fp5);

        FILE *fp6;
    char str6[1000];
    char* filename6 = "MovieSched_6.txt";

    fp6 = fopen(filename6, "r");
    if (fp6 == NULL)
        {
        printf("Could not open file %s",filename6);
        return 1;
        }
   while (fgets(str6, 1000, fp6) != NULL)
        printf("%s\n", str6);
    fclose(fp6);
    printf("\nPLEASE MAKE A VALID MOVIE INDEX SELECTION\n\n");

	scanf("%d",&i);

	return i;
}
void reservation(int *array,int price,int slection)
{
		int i,j,t;
		printf("\n                                SCREEN\n\n\n");
		for (i=1;i<=50;i++)
		{
			if (array[i]==0)
				printf("%d\t",i);
			else
				printf("*\t",i);
			if(i%10==0)
				printf("\n\n");
		}
		printf("Please enter your name: ");
		scanf(" %19[^\n]%*[^\n]",&person[count].name);
		printf("Please enter your phone number: ");
		scanf("%u",&person[count].phone);
		printf("Please enter seat numbers you want [UPTO 4 SEATS] ");
		printf("PLEASE ENTER 1ST SEAT - ");
		scanf("%d",&j);
		if (j>50||j<1)
			{
				printf("seat1 number is unavailable in this theater\n");
				printf("Please re-enter seat number: ");
				scanf("%d",&j);
			}
		if (array[j]==1)
			{
				printf("Sorry, this ticket is already booked! Please choose another seat.\n");
				scanf("%d",&j);
			}
		else
			array[j]=1;
		person[count].seat=j;
		if (slection==1)
			ticket1(j,person[count].name,id2,price);
    else if (slection==2)
			ticket2(j,person[count].name,id2,price);
    else if (slection==3)
			ticket3(j,person[count].name,id2,price);
    else if (slection==4)
			ticket4(j,person[count].name,id2,price);
    else if (slection==5)
			ticket5(j,person[count].name,id2,price);
                else
                ticket6(j,person[count].name,id2,price);
		id2++;
        printf("PLEASE ENTER 2ND SEAT ");
        printf("[PLEASE ENTER '0' IF YOU DONT WANT TO BOOK ANYMORE] - \n");
		scanf("%d",&j);
		if (j==0)
		{
		    return ;
		}
        else
		{
		if (j>50||j<1)
			{
				printf("seat1 number is unavailable in this theater\n");
				printf("Please re-enter seat number: ");
				scanf("%d",&j);
			}
		if (array[j]==1)
			{
				printf("Sorry, this ticket is already booked! Please choose another seat.\n");
				scanf("%d",&j);
			}
		else
			array[j]=1;
		person[count].seat=j;
		 if (slection==1)
			ticket1(j,person[count].name,id2,price);
    else if (slection==2)
			ticket2(j,person[count].name,id2,price);
    else if (slection==3)
			ticket3(j,person[count].name,id2,price);
    else if (slection==4)
			ticket4(j,person[count].name,id2,price);
    else if (slection==5)
			ticket5(j,person[count].name,id2,price);
                else
                ticket6(j,person[count].name,id2,price);
		id2++;
		printf("PLEASE ENTER 3RD SEAT ");
		printf("[PLEASE ENTER '0' IF YOU DONT WANT TO BOOK ANYMORE] -\n");
		scanf("%d",&j);
		if (j==0)
		{
		    return ;
		}
        else
        {

		if (j>50||j<1)
			{
				printf("seat1 number is unavailable in this theater\n");
				printf("Please re-enter seat number: ");
				scanf("%d",&j);
			}
		if (array[j]==1)
			{
				printf("Sorry, this ticket is already booked! Please choose another seat.\n");
				scanf("%d",&j);
			}
		else
			array[j]=1;
		person[count].seat=j;
		if (slection==1)
			ticket1(j,person[count].name,id2,price);
    else if (slection==2)
			ticket2(j,person[count].name,id2,price);
    else if (slection==3)
			ticket3(j,person[count].name,id2,price);
    else if (slection==4)
			ticket4(j,person[count].name,id2,price);
    else if (slection==5)
			ticket5(j,person[count].name,id2,price);
                else
                ticket6(j,person[count].name,id2,price);
		id2++;printf("PLEASE ENTER 4TH SEAT - ");
		printf("[PLEASE ENTER '0' IF YOU DONT WANT TO BOOK ANYMORE] -\n");
		scanf("%d",&j);
		if (j==0)
		{
		    return ;
		}
        else
        {

		if (j>50||j<1)
			{
				printf("seat1 number is unavailable in this theater\n");
				printf("Please re-enter seat number: ");
				scanf("%d",&j);
			}
		if (array[j]==1)
			{
				printf("Sorry, this ticket is already booked! Please choose another seat.\n");
				scanf("%d",&j);
			}
		else
			array[j]=1;
		person[count].seat=j;
		if (slection==1)
			ticket1(j,person[count].name,id2,price);
    else if (slection==2)
			ticket2(j,person[count].name,id2,price);
    else if (slection==3)
			ticket3(j,person[count].name,id2,price);
    else if (slection==4)
			ticket4(j,person[count].name,id2,price);
    else if (slection==5)
			ticket5(j,person[count].name,id2,price);
                else
                ticket6(j,person[count].name,id2,price);
		id2++;


		}
        }
		}
}

void ticket1(int choice,char name[10],int id2,int price)
{
SYSTEMTIME stime;
GetSystemTime(&stime);
        FILE *fp;
        FILE *fp1;
    char str1[1000];
    char* filename1 = "MovieSched_1.txt";

    fp1 = fopen(filename1, "r");
         while (fgets(str1, 1000, fp1) != NULL)
         {
        fp=fopen("ticket.txt", "a");
        fprintf(fp, "\t-----------------THEATER BOOKING TICKET----------------\n");
        fprintf(fp, "\t============================================================\n");
        fprintf(fp, "\t               \t\t\tShow Name : %s\n", str1);
        fgets(str1, 1000, fp1);
        fgets(str1, 1000, fp1);
        fprintf(fp, "\t               \t\t\tShow time : %s\n", str1);
        fprintf(fp, "\t Booking ID : %d \t\t\t                              \n", id2);
        fprintf(fp, "\t Customer  : %s\n",name);
        fprintf(fp, "\t\t\t                              Date      : %d / %d / %d \n", stime.wDay,stime.wMonth,stime.wYear);
        fprintf(fp, "\t                                                        \n");
        fprintf(fp, "\t                                              Hall      : 02\n");
        fprintf(fp, "\t                                              seats No. : %d \n",choice);
        fprintf(fp, "\t                                              price . : %d  \n\n",price);
        fprintf(fp, "\t============================================================\n");
        fclose(fp);
        FILE *fp10;
        fp10 = fopen("Reservation Data_1.txt", "a");
        fscanf(fp1, "%[^\n]", str1);
        fprintf(fp10,"Show time : %s\n", str1);
        fprintf(fp10,"seats No. : %d \n",choice);
        fclose(fp10);

		printf("\n\n");
        printf("\t-----------------THEATER BOOKING TICKET----------------\n");
        printf("\t============================================================\n");
        fgets(str1, 1000, fp1);
        printf("\t                       \t\t\tShow Time : %s\n", str1);
        printf("\t Booking ID : %d \t\t\t                              \n", id2);
        printf("\t Customer  : %s\n",name);
        printf("\t\t\t                              Date      : %d / %d / %d \n", stime.wDay,stime.wMonth,stime.wYear);
        printf("\t                                                        \n");
        printf("\t                                              Hall      : 02\n");
        printf("\t                                              seats No. : %d  \n",choice);
        printf("\t                                              price . : %d  \n\n",price);
		person[count].id=id2;
        printf("\t============================================================\n");
        printf("\t please collect the ticket from ticket text file \n");
        return;
        }
}
void ticket2(int choice,char name[10],int id2,int price)
{
        SYSTEMTIME stime;
        GetSystemTime(&stime);
        FILE *fp2;
    char str2[1000];
    char* filename2 = "MovieSched_2.txt";

    fp2 = fopen(filename2, "r");
         while (fgets(str2, 1000, fp2) != NULL)
         {
        FILE *fp;
        fp=fopen("ticket.txt", "a");
        fprintf(fp, "\n\n");
        fprintf(fp, "\t-----------------THEATER BOOKING TICKET----------------\n");
        fprintf(fp, "\t============================================================\n");
        fprintf(fp, "\t               \t\t\tShow Name : %s\n", str2);
        fgets(str2, 1000, fp2);
        fgets(str2, 1000, fp2);
        fprintf(fp, "\t               \t\t\tShow time : %s\n", str2);
        fprintf(fp, "\t Booking ID : %d \t\t\t                     \n",id2);
        fprintf(fp, "\t Customer  : %s\n",name);
        fprintf(fp, "\t\t\t                              Date      : %d / %d / %d \n", stime.wDay,stime.wMonth,stime.wYear);
        fprintf(fp, "\t                                                         \n");
        fprintf(fp, "\t                                              Hall      : 03\n");
        fprintf(fp, "\t                                              seats No. : %d  \n",choice);
        fprintf(fp, "\t                                              price . : %d  \n\n",price);
        fprintf(fp, "\t============================================================\n");
        fclose(fp);
        FILE *fp20;
        fp20 = fopen("Reservation Data_2.txt", "a");
        fscanf(fp2, "%[^\n]", str2);
        fprintf(fp20,"Show time : %s\n", str2);
        fprintf(fp20,"seats No. : %d \n",choice);
        fclose(fp20);

		printf("\n\n");
        printf("\t-----------------THEATER BOOKING TICKET----------------\n");
        printf("\t============================================================\n");
        fgets(str2, 1000, fp2);
        printf("\t                               \t\t\tShow Time : %s\n",str2);
        printf("\t Booking ID : %d \t\t\t                            \n",id2);
        printf("\t Customer  : %s\n",name);
        printf("\t\t\t                              Date      : %d / %d / %d \n", stime.wDay,stime.wMonth,stime.wYear);
        printf("\t                                                        \n");
        printf("\t                                              Hall      : 03\n");
        printf("\t                                              seats No. : %d  \n",choice);
        printf("\t                                              price . : %d  \n\n",price);
        person[count].id=id2;
        printf("\t============================================================\n");
        printf("\t please collect the ticket from ticket text file \n");
        return;
         }
}
void ticket3(int choice,char name[10],int id2,int price)
{
        SYSTEMTIME stime;
        GetSystemTime(&stime);
        FILE *fp3;
    char str3[1000];
    char* filename3 = "MovieSched_3.txt";

    fp3 = fopen(filename3, "r");
         while (fgets(str3, 1000, fp3) != NULL)
         {
        FILE *fp;
        fp=fopen("ticket.txt", "a");
        fprintf(fp, "\n\n");
        fprintf(fp, "\t-----------------THEATER BOOKING TICKET----------------\n");
        fprintf(fp, "\t============================================================\n");
        fprintf(fp, "\t               \t\t\tShow Name : %s\n", str3);
        fgets(str3, 1000, fp3);
        fgets(str3, 1000, fp3);
        fprintf(fp, "\t               \t\t\tShow Time : %s\n", str3);
        fprintf(fp, "\t Booking ID : %d \t\t\t                     \n",id2);
        fprintf(fp, "\t Customer  : %s\n",name);
        fprintf(fp, "\t\t\t                              Date      : %d / %d / %d \n", stime.wDay,stime.wMonth,stime.wYear);
        fprintf(fp, "\t                                                         \n");
        fprintf(fp, "\t                                              Hall      : 04\n");
        fprintf(fp, "\t                                              seats No. : %d  \n",choice);
        fprintf(fp, "\t                                              price . : %d  \n\n",price);
        fprintf(fp, "\t============================================================\n");
        fclose(fp);
        FILE *fp30;
        fp30 = fopen("Reservation Data_6.txt", "a");
        fscanf(fp3, "%[^\n]", str3);
        fprintf(fp30,"Show time : %s\n", str3);
        fprintf(fp30,"seats No. : %d \n",choice);
        fclose(fp30);


		printf("\n\n");
        printf("\t-----------------THEATER BOOKING TICKET----------------\n");
        printf("\t============================================================\n");
        fgets(str3, 1000, fp3);
        printf("\t                       \t\t\tShow Time : %s\n", str3);
        printf("\t Booking ID : %d \t\t\t                              \n", id2);
        printf("\t Customer  : %s\n",name);
        printf("\t\t\t                              Date      : %d / %d / %d \n", stime.wDay,stime.wMonth,stime.wYear);
        printf("\t                                                        \n");
        printf("\t                                              Hall      : 04\n");
        printf("\t                                              seats No. : %d  \n",choice);
        printf("\t                                              price . : %d  \n\n",price);
        person[count].id=id2;
        printf("\t============================================================\n");
        printf("\t please collect the ticket from ticket text file \n");
        return ;
         }
}
void ticket4(int choice,char name[10],int id2,int price)
{
        SYSTEMTIME stime;
        GetSystemTime(&stime);
        FILE *fp4;
    char str4[1000];
    char* filename4 = "MovieSched_4.txt";

    fp4 = fopen(filename4, "r");
         while (fgets(str4, 1000, fp4) != NULL)
         {
		FILE *fp;
        fp=fopen("ticket.txt", "a");
        fprintf(fp, "\t-----------------THEATER BOOKING TICKET----------------\n");
        fprintf(fp, "\t============================================================\n");
        fprintf(fp, "\t               \t\t\tShow Name : %s\n", str4);
        fgets(str4, 1000, fp4);
        fgets(str4, 1000, fp4);
        fprintf(fp, "\t               \t\t\tShow Time : %s\n", str4);
        fprintf(fp, "\t Booking ID : %d \t\t\t                     \n",id2);
        fprintf(fp, "\t Customer  : %s\n",name);
        fprintf(fp, "\t\t\t                              Date      : %d / %d / %d \n", stime.wDay,stime.wMonth,stime.wYear);
        fprintf(fp, "\t                                                         \n");
        fprintf(fp, "\t                                              Hall      : 02\n");
        fprintf(fp, "\t                                              seats No. : %d \n",choice);
        fprintf(fp, "\t                                              price . : %d  \n\n",price);
        fprintf(fp, "\t============================================================\n");
        fclose(fp);
        FILE *fp40;
        fp40 = fopen("Reservation Data_4.txt", "a");
        fscanf(fp4, "%[^\n]", str4);
        fprintf(fp40,"Show time : %s\n", str4);
        fprintf(fp40,"seats No. : %d \n",choice);
        fclose(fp40);


		printf("\n\n");
        printf("\t-----------------THEATER BOOKING TICKET----------------\n");
        printf("\t============================================================\n");
        fgets(str4, 1000, fp4);
        printf("\t                       \t\t\tShow Time : %s\n", str4);
        printf("\t Booking ID : %d \t\t\t                              \n", id2);
        printf("\t Customer  : %s\n",name);
        printf("\t\t\t                              Date      : %d / %d / %d \n", stime.wDay,stime.wMonth,stime.wYear);
        printf("\t                                                        \n");
        printf("\t                                              Hall      : 02\n");
        printf("\t                                              seats No. : %d  \n",choice);
        printf("\t                                              price . : %d  \n\n",price);
		person[count].id=id2;
        printf("\t============================================================\n");
        printf("\t please collect the ticket from ticket text file \n");
        return;
}
}
void ticket5(int choice,char name[10],int id2,int price)
{
        SYSTEMTIME stime;
        GetSystemTime(&stime);
        FILE *fp5;
    char str5[1000];
    char* filename5 = "MovieSched_5.txt";

    fp5 = fopen(filename5, "r");
         while (fgets(str5, 1000, fp5) != NULL)
         {
		FILE *fp;
        fp=fopen("ticket.txt", "a");
        fprintf(fp, "\t-----------------THEATER BOOKING TICKET----------------\n");
        fprintf(fp, "\t============================================================\n");
        fprintf(fp, "\t               \t\t\tShow Name : %s\n", str5);
        fgets(str5, 1000, fp5);
        fgets(str5, 1000, fp5);
        fprintf(fp, "\t               \t\t\tShow time : %s\n", str5);
        fprintf(fp, "\t Booking ID : %d \t\t\t                     \n",id2);
        fprintf(fp, "\t Customer  : %s\n",name);
        fprintf(fp, "\t\t\t                              Date      : %d / %d / %d \n", stime.wDay,stime.wMonth,stime.wYear);
        fprintf(fp, "\t                                                        \n");
        fprintf(fp, "\t                                              Hall      : 02\n");
        fprintf(fp, "\t                                              seats No. : %d \n",choice);
        fprintf(fp, "\t                                              price . : %d  \n\n",price);
        fprintf(fp, "\t============================================================\n");
        fclose(fp);
        FILE *fp50;
        fp50 = fopen("Reservation Data_5.txt", "a");
        fscanf(fp5, "%[^\n]", str5);
        fprintf(fp50,"Show time : %s\n", str5);
        fprintf(fp50,"seats No. : %d \n",choice);
        fclose(fp50);


		printf("\n\n");
        printf("\t-----------------THEATER BOOKING TICKET----------------\n");
        printf("\t============================================================\n");
        fgets(str5, 1000, fp5);
        printf("\t                       \t\t\tShow Time : %s\n", str5);
        printf("\t Booking ID : %d \t\t\t                              \n", id2);
        printf("\t Customer  : %s\n",name);
        printf("\t\t\t                              Date      : %d / %d / %d \n", stime.wDay,stime.wMonth,stime.wYear);
        printf("\t                                                        \n");
        printf("\t                                              Hall      : 02\n");
        printf("\t                                              seats No. : %d  \n",choice);
        printf("\t                                              price . : %d  \n\n",price);
		person[count].id=id2;
        printf("\t============================================================\n");
        printf("\t please collect the ticket from ticket text file \n");
        return;
         }
}
void ticket6(int choice,char name[10],int id2,int price)
{
        SYSTEMTIME stime;
        GetSystemTime(&stime);
        FILE *fp6;
    char str6[1000];
    char* filename6 = "MovieSched_6.txt";

    fp6 = fopen(filename6, "r");
         while (fgets(str6, 1000, fp6) != NULL)
         {
		FILE *fp;
        fp=fopen("ticket.txt", "a");
        fprintf(fp, "\t-----------------THEATER BOOKING TICKET----------------\n");
        fprintf(fp, "\t============================================================\n");
        fprintf(fp, "\t               \t\t\tShow Name : %s\n", str6);
        fscanf(fp6, "%[^\n]", str6);
        fprintf(fp, "\t               \t\t\tShow time : %s\n", str6);
        fprintf(fp, "\t Booking ID : %d \t\t\t                     \n", id2);
        fprintf(fp, "\t Customer  : %s\n",name);
        fprintf(fp, "\t\t\t                              Date      : %d / %d / %d \n", stime.wDay,stime.wMonth,stime.wYear);
        fprintf(fp, "\t                                                        \n");
        fprintf(fp, "\t                                              Hall      : 02\n");
        fprintf(fp, "\t                                              seats No. : %d \n",choice);
        fprintf(fp, "\t                                              price . : %d  \n\n",price);
        fprintf(fp, "\t============================================================\n");
        fclose(fp);
        FILE *fp60;
        fp60 = fopen("Reservation Data_6.txt", "a");
        fscanf(fp6, "%[^\n]", str6);
        fprintf(fp60,"Show time : %s\n", str6);
        fprintf(fp60,"seats No. : %d \n",choice);
        fclose(fp60);



		printf("\n\n");
        printf("\t-----------------THEATER BOOKING TICKET----------------\n");
        printf("\t============================================================\n");
        fscanf(fp6, "%[^\n]", str6);
        printf("\t                       \t\t\tShow time : %s\n", str6);
        printf("\t Booking ID : %d \t\t\t                              \n", id2);
        printf("\t Customer  : %s\n",name);
        printf("\t\t\t                              Date      : %d / %d / %d \n", stime.wDay,stime.wMonth,stime.wYear);
        printf("\t                                                            \n");
        printf("\t                                              Hall      : 02\n");
        printf("\t                                              seats No. : %d  \n",choice);
        printf("\t                                              price . : %d  \n\n",price);
		person[count].id=id2;
        printf("\t============================================================\n");
        printf("\t please collect the ticket from ticket text file \n");
        return;
}
}
