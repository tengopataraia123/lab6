#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <curses.h>
#include <time.h>

void show_top_score();
void reset_points();
void edit_score(double , char []);

void show_record()
    {system("cls");
	char* name[15];
	double top_score;
	FILE *f;
	f=fopen("score.txt","r");
	fscanf(f,"%s%lf",(char*)&name,&top_score);
	printf("\n\n\t\t*************************************************************");
	printf("\n\n\t\t %s has secured the Highest Score %0.2lf",*name,top_score);
	printf("\n\n\t\t*************************************************************");
	fclose(f);
	getch();}

void reset_score()
    {system("cls");
    double res_scr;
	char* nm[15];
	FILE *f;
	f=fopen("score.txt","r+");
	fscanf(f,"%s%lf",(char*)&nm,&res_scr);
	res_scr=0;
	fprintf(f,"%s,%.2lf",*nm,res_scr);
    fclose(f);}


void edit_score(double score, char a[40])
	{system("cls");
	double sc;
	char* nm[15];
	FILE *f;
	f=fopen("score.txt","r");
	fscanf(f,"%s%lf",(char*)&nm,&sc);
	if (score>=sc)
	  { sc=score;
	    fclose(f);
	    f=fopen("score.txt","w");
	    fprintf(f,"%s\n%.2lf",a,sc);
	    fclose(f);}}

void write_statistic(char a[40], int b)
{
    FILE *f;
    f=fopen("stat.txt","a");
    fprintf(f, "%s \t\t %d\n", a, b);
    fclose(f);
}

int main()
     {
     srand(time(NULL));
     int m1,count1,m2,count2,i;
     int myRedId[9] = {8, 2, 0, 3, 7, 6, 9, 1, 6};
     int previousQuestions=0;
     double score;
     char option;
     char player[15];
     mainpage:
     system("cls");
     printf("\t\t\tDAMPLURI TAMASHEBI\n");
     printf("\n\t\t***************************************");
     printf("\n\t\t\t   HERZLICH WILLKOMMEN ");
     printf("\n\t\t\t      TO THE QUIZ ");
     printf("\n\t\t\t   DAMPLURI TAMASHEBI ");
     printf("\n\t\t***************************************");
     printf("\n\t\t Click S to begin the quiz");
     printf("\n\t\t Click T to access the top score");
     printf("\n\t\t Click R to reset your points");
     printf("\n\t\t Click Q to quit");
     printf("\n\t\t***************************************\n\n");
     option=toupper(getch());
     if (option=='T')
	{
	show_record();
	goto mainpage;
	}
	else if (option=='R')
	{reset_score();
	getch();
	goto mainpage;}
	else if (option=='Q')
	exit(1);
    else if(option=='S')
    {
     system("cls");

    printf("\n\n\n\n\n\n\n\n\n\n\t\t\tWrite your name:");
     gets(player);

    system("cls");
    printf("\n\t\t\t\t Welcome %s to the DAMPLURI TAMASHEBI",player);
    printf("\n\n\t\t\t QUIZ INFORMATION");
    printf("\n In the quiz DAMPLURI TAMASHEBI there are 2 rounds");
    printf("\n You will be able to play the game if you will give least 2 CORRECT ANSWERS in the first round");
    printf("\n You will be given 4 options and you have to choose A, B ,C or D for the right option");
    printf("\n You will be asked questions furtherly if you will be giving the RIGHT ANSWERS");
    printf("\n There are no minus points for the wrong responses");
    printf("\n\n\tWISH YOU GOOD LUCK");
    printf("\n\n\n Click S to start the quiz!\n");
    printf("\n Click any other key to return to the main menu!");
    if (toupper(getch())=='S')
		{
		    goto home;
        }
	else
		{
        goto mainpage;
       system("cls");
       }

     home:
     system("cls");
     count1=0;
     for(i=1;i<=10;i++)
     {
    system("cls");
    m1 = rand() %10;
    if(m1 == previousQuestions)
        m1 = rand()%10;
     switch(m1)
		{
		case 1:
		    previousQuestions = 1;
		printf("\n\nWhere is Bengali language spoken?");
		printf("\n\nA.India\t\tB.Saudi Arabia\n\nC.Bangladesh\t\tD.Georgia");
		if (toupper(getch())=='C')
			{
			    printf("\n\nCorrect!");count1++;
			    getch();
			    break;
}
		else
		       {
		           printf("\n\nWrong! The correct answer is C.Bangladesh");
		           getch();
		       break;
		       }

        case 2:
            previousQuestions = 2;
		printf("\n\nIn which country was Sandwich invented?");
		printf("\n\nA.Armenia\t\tB.Denmark\n\nC.Great Britain\t\tD.France");
		if (toupper(getch())=='C')
			{printf("\n\nCorrect!");count1++;
			getch();
			break;}
		else
		       {printf("\n\nWrong! The correct answer is C.Great Britain");
		       getch();
		       break;}

        case 3:
            previousQuestions = 3;
		printf("\n\nWhich Georgian Basketballer plays in NBA?");
		printf("\n\nA.Burjanadze\t\tB.Pachulia\n\nC.Shermadini\t\tD.Cincadze");
		if (toupper(getch())=='B')
			{printf("\n\nCorrect!");count1++;
			getch();
			break;}
		else
		       {printf("\n\nWrong! The correct answer is B.Pachulia");
		       getch();
		       break;}

        case 4:
            previousQuestions = 4;
		printf("\n\nWhich vitamin can we get from the sunlight?");
		printf("\n\nA.D\t\tB.B12\n\nC.A\t\tD.K");
		if (toupper(getch())=='A')
			{printf("\n\nCorrect!");count1++;
			getch();
			 break;}
		else
		       {printf("\n\nWrong! The correct answer is A.D");
		       getch();
		       break;}

        case 5:
            previousQuestions = 5;
        printf("\n\nWhich is the lowest point in the world?");
        printf("\n\nA.Turpan Pendi\t\tB.Death valley\n\nC.The Dead Sea\t\tD.Sebkhet Tah");
        if (toupper(getch())=='C')
               {printf("\n\nCorrect!");count1++;
               getch();
                break;}
        else
		       {printf("\n\nWrong! The correct answer is C.The Dead Sea");
		       getch();
		       break;}

        case 6:
            previousQuestions = 6;
		printf("\n\nWho has painted the starry night?");
		printf("\n\nA.Gaugin\t\tB.Leonardo Da Vinci\n\nC.Dali\t\tD.Vincent van Gogh");
		if (toupper(getch())=='D' )
			{printf("\n\nCorrect!");count1++;
			getch();
			break;}
		else
		       {printf("\n\nWrong! The correct answer is D.Vincent van Gogh");
		       getch();
		       break;}
		case 7:
		    previousQuestions = 7;
		printf("\n\nWho wrote the Divine Comedy?");
		printf("\n\nA.Ovid\t\tB.Kafka\n\nC.Rustaveli\t\tD.Dante");
		if (toupper(getch())=='D' )
			{printf("\n\nCorrect!");count1++;
			getch();
			break;}
		else
		       {printf("\n\nWrong! The correct answer is D.Dante");
		       getch();
		       break;}
        case 8:
            previousQuestions = 8;
		printf("\n\nWhich countries possession is Greenland?");
		printf("\n\nA.Denmark\t\tB.Canada\n\nC.Norway\t\tD.Sweden");
		if (toupper(getch())=='A' )
			{printf("\n\nCorrect!");count1++;
			getch();
			break;}
		else
		       {printf("\n\nWrong! The correct answer is A.Denmark");
		       getch();
		       break;}
        case 9:
            previousQuestions = 9;
		printf("\n\nIn which music group was Freddie Mercury singing?");
		printf("\n\nA.The Beatles\t\tB.The Loudspeakers\n\nC.The Queen\t\tD.The King");
		if (toupper(getch())=='C')
			{printf("\n\nCorrect!");count1++; getch();
			break;}
		else
		       {printf("\n\nWrong! The correct answer is C.The Queen");getch();goto score;
		       break;}

		case 10:
		    previousQuestions = 10;
		printf("\n\nWhich country won Eurovision 2019?");
		printf("\n\nA.The Netherlands\t\tB.Australia\n\nC.Italy\t\tD.Germany");
		if (toupper(getch())=='A')
			{printf("\n\nCorrect!");count1++; getch();
			break;}
		else
		       {printf("\n\nWrong!! The correct answer is A.The Netherlands");getch();goto score;
		       break;}
            }}
		       }

	if(count1>=3)
	{goto test;}
	else
	{
	system("cls");
	printf("\nSORRY YOU LOST, WISH YOU GOOD LUCK IN THE FUTURE");
	getch();
	goto mainpage;
	}
     test:
     system("cls");
     printf("\n\nFELICITATIONS %s you can play the second round",player);
     printf("\n\n\tClick any key to Start the second round");
     if(toupper(getch())=='p')
		{goto game;}
game:
     count2=0;
     for(i=1;i<=10;i++)
     {system("cls");
     m2 = rand() %10;
    if(m2 == previousQuestions)
        m2 = rand()%10;

     switch(m2)
		{
		case 1:
		    previousQuestions = 1;
		printf("\n\nWho invented the light bulb?");
		printf("\n\nA.Tesla\t\tB.Einstein\n\nC.Fibonacci\t\tD.Euler");
		if (toupper(getch())=='A')
			{printf("\n\nCorrect!");count2++;getch();
			 break;getch();}
		else
		       {printf("\n\nWrong! The correct answer is A.Tesla");getch();
		       goto score;
		       break;}

		case 2:
		    previousQuestions =2;
		printf("\n\nWhat is the study of lakes called?");
		printf("\n\nA.Ecology\t\tB.Hydrobiology\n\nC.Limnology\t\tD.Geology");
		if (toupper(getch())=='C')
			{printf("\n\nCorrect!");count2++;getch();
			 break;}
		else
		       {printf("\n\nWrong! The correct answer is C.Limnology");getch();
		      goto score;
		       break;
		       }

        case 3:
            previousQuestions = 3;
		printf("\n\nWhich avengers character is green and big?");
		printf("\n\nA.Hulk\t\tB.Thor\n\nC.Spiderman\t\tD.Iron man");
		if (toupper(getch())=='A')
			{printf("\n\nCorrect!");count2++;getch();
			 break;}
		else
		       {printf("\n\nWrong! The correct answer is A.Hulk");getch();
		       goto score;
		       break;}

        case 4:
            previousQuestions = 4;
		printf("\n\nWho played main role in Pasion de Gavilanes?");
		printf("\n\nA.Rios\t\tB.Cimarro\n\nC.Urrego\t\tD.Pernia");
		if (toupper(getch())=='B')
			{printf("\n\nCorrect!");count2++;getch();
			 break;}
		else
		       {
                printf("\n\nWrong! The correct answer is B.Cimarro");getch();
		       goto score;
		       break;
		       }

        case 5:
            previousQuestions = 5;
		printf("\n\nWho wrote The Queen of Spades?");
		printf("\n\nA.Pushkin\t\tB.Chekhov\n\nC.Javakhishvili\t\tD.Ioseliani");
		if (toupper(getch())=='A')
			{printf("\n\nCorrect!");count2++;getch(); break;}
		else
		       {
		           printf("\n\nWrong! The correct answer is A.Pushkin");
		       getch();
		       goto score;
		       break;
		       }

		case 6:
		    previousQuestions = 6;
		printf("\n\nWhich is the capital city of Vietnam?");
		printf("\n\nA.Pkhenyan\t\tB.Seoul\n\nC.Phnom Penh\t\tD.Hanoi");
		if (toupper(getch())=='D' )
			{printf("\n\nCorrect!!!");count2++;getch();
			 break;}
		else
		       {printf("\n\nWrong!!! The correct answer is D.Hanoi");goto score;
		       getch();
		       break;}

        case 7:
            previousQuestions = 7;
		printf("\n\nHow is Estonian language called in Estonian?");
		printf("\n\nA.Estonian\t\tB.Eesti\n\nC.Ugric\t\tD.Saaremaa");
		if (toupper(getch())=='B')
			{printf("\n\nCorrect!");count2++;getch();
			 break;}
		else
		       {printf("\n\nWrong! The correct answer is B.Eesti");getch();
		       goto score;
		       break;}

        case 8:
            previousQuestions = 8;
		printf("\n\nWhich language is the most spoken in Africa?");
		printf("\n\nA.Swahili\t\tB.Arabic\n\nC.Indian\t\tD.Russian");
		if (toupper(getch())=='A')
			{printf("\n\nCorrect!");count2++;getch(); break;}
		else
		       {printf("\n\nWrong! The correct answer is A.Swahili");getch();
		       goto score;
		       break;}

        case 9:
            previousQuestions = 9;
		printf("\n\nWhat was Moses nationality?");
		printf("\n\nA.Arab\t\tB.Georgian\n\nC.Hyksos\t\tD.Jewish");
		if (toupper(getch())=='D')
			{printf("\n\nCorrect!");count2++; getch();
			break;}
		else
		       {printf("\n\nWrong! The correct answer is D.Jewish");getch();
		       goto score;
		       break;}

        case 10:
            previousQuestions = 10;
		printf("\n\n\nBy mixing which colors can you get green?");
		printf("\n\nA.Yellow and Blue\t\tB.Yellow and Purple\n\nC.Red and Blue\t\tD.Brown and Orange");
		if (toupper(getch())=='A')
			{printf("\n\nCorrect!!!");count2++;getch(); break;}
		else
		       {printf("\n\nWrong!!! The correct answer is A.Yellow and Blue");getch();break;goto score;}

        case 11:
            previousQuestions = 11;
		printf("\n\n\nAll roads lead to...");
		printf("\n\nA.Madrid\t\tB.Barcelona\n\nC.Rome\t\tD.Paris");
		if (toupper(getch())=='C')
			{printf("\n\nCorrect!");count2++;getch();
			 break;}
		else
              {printf("\n\nWrong! The correct answer is C.Rome");getch();
              break;goto score;}

        case 12:
            previousQuestions = 12;
		printf("\n\nWhich company was created by Steve Jobs?");
		printf("\n\nA.Samsung\t\tB.Huawei\n\nC.Apple\t\tD.Motorolla");
		if (toupper(getch())=='C')
			  {printf("\n\nCorrect!");count2++;getch();
			   break;}
		else
              {printf("\n\nWrong! The correct answer is C.Apple");getch();
              break;goto score;}

		case 13:
		    previousQuestions = 13;
		printf("\n\nIn which country is another small country, San-Marino located??");
		printf("\n\nA.Andorra\t\tB.Italy\n\nC.Spain\t\tD.France");
		if (toupper(getch())=='B')
			{printf("\n\nCorrect!");count2++;getch();
			break;}
		else
		       {printf("\n\nWrong! The correct answer is B.Italy");getch();
		       break;goto score;}

        case 14:
            previousQuestions = 14;
		printf("\n\nWhich insects can spread malaria?");
		printf("\n\nA.Mosquitoes\t\tB.Butterflies\n\nC.B.Worms\t\tD.Flies");
		if (toupper(getch())=='A')
			{printf("\n\nCorrect!");count2++;getch();
			 break;}
		else
		       {printf("\n\nWrong! The correct answer is A.Mosquitoes");getch();
		       break;goto score;}

		case 15:
		    previousQuestions = 15;
		printf("\n\nWho wrote Macbeth?");
		printf("\n\nA.Shakespeare\t\tB.Byron\n\nC.Wordsworth\t\tD.Kafka");
		if (toupper(getch())=='A')
			{printf("\n\nCorrect!");count2++;getch();
			 break;}
		else
		       {printf("\n\nWrong! The correct answer is A.Shakespeare");getch();
		       goto score;
		       break;}

		case 16:
		    previousQuestions = 16;
		printf("\n\nHow many dialects are there in Arabic?");
		printf("\n\nA.2-3\t\tB.5-7\n\nC.10-20\t\tD.30+");
		if (toupper(getch())=='D')
			{printf("\n\nCorrect!");count2++; getch();
			break;
			}
		else
		       {printf("\n\nWrong! The correct answer is D.30+");getch();
		       goto score;
		       break;}


		case 17:
		    previousQuestions = 17;
		printf("\n\n\nThe origin country of Capoeira is...");
		printf("\n\nA.Brazil\t\tB.Venezuela\n\nC.Mexico\t\tD.Colombia");
		if (toupper(getch())=='A')
			{printf("\n\nCorrect!");count2++; getch();
			break;}
		else
		       {printf("\n\nWrong! The correct answer is A.Brazil");getch();goto score;
		       break;}

		case 18:
		    previousQuestions = 18;
		printf("\n\n\nHow many stomaches does the cow have?");
		printf("\n\nA.1\t\tB.4\n\nC.3\t\tD.2\n\n");
		if (toupper(getch())=='B')
			{printf("\n\nCorrect!");count2++; getch();
			break;}
		else
		       {printf("\n\nWrong! The correct answer is B.4");getch();goto score;
		       break;}

		case 19:
		    previousQuestions = 19;
		printf("\n\n\nBy lack of what is Albinism caused?");
		printf("\n\nA.D Vitamin\t\tB.Chromosome\n\nC.Melanin\t\tD.Sparkles\n\n");
		if (toupper(getch())=='C')
			{printf("\n\nCorrect!");count2++; getch();
			break;}
		else
		       {printf("\n\nWrong! The correct answer is C.Melanin");getch();goto score;
		       break;}

		case 20:
		    previousQuestions = 20;
		printf("\n\nHow many crusades were there?");
		printf("\n\nA.9\t\tB.8\n\nC.7\t\tD.6");
		if (toupper(getch())=='A')
			{printf("\n\nCorrect!");count2++; getch();
			break;}
		else
		       {printf("\n\nWrong! The correct answer is A.9");getch();goto score;
		       break;}

		case 21:
		    previousQuestions = 21;
		printf("\n\nSkype was created in...");
		printf("\n\nA.Russia\t\tB.Finland\n\nC.Lithuania\t\tD.Estonia");
		if (toupper(getch())=='D')
			{printf("\n\nCorrect!");count2++; getch();
			break;}
		else
		       {printf("\n\nWrong! The correct answer is D. C.F.C");getch();goto score;
		       break;}
        case 22:
            previousQuestions = 22;
        printf("\n\nRed Id is: ");
        for (int i = 0; i < 9; i++){
           printf("%d", myRedId[i]);
        }
        printf("\n\nWhat is the median of this number?");
        printf("\n\nA.2\t\tB.7\n\nC.9\t\tD.0");
        if (toupper(getch())=='B')
            {printf("\n\nCorrect!");count1++; getch();
            break;}
            else
             {printf("\n\nWrong!! The correct answer is B.7");getch();goto score;
		       break;}}}
	score:
    system("cls");
	score=(double)count2*125;
	if(score>0.00 && score<1250.00)
	{
	   printf("\n\n\t\tFELICITATIONS");
	     printf("\n\t You won $%.2lf",score);
	     goto go;}

	 else if(score==1250.00)
	{
	    printf("\n\n\n \t\tFELICITATIONS");
	    printf("\n\t\t\t\t YOU ARE A WINNER");
	    printf("\n\t\t You won $%.2lf",score);
	    printf("\t\t Thank You!!");
	}
	 else
{
	 printf("\n\n\tUNFORTUNATELY YOU LOST");
	    printf("\n\t\t WE ENCOURAGE YOU TO TRY AGAIN");
	    goto go;}

	go:
	puts("\n\nIf you enjoyed the quiz click A, if you didn't click B");
	puts("\n\n Click N if you want to play next game");
	puts(" Click any key if you want to go main menu");
	if (toupper(getch())=='N')
		goto home;
    else if (toupper(getch())=='A'){
        write_statistic(player, 1);
        edit_score(score,player);
        goto mainpage;
    }
    else if (toupper(getch())=='B'){
        write_statistic(player, 0);
        edit_score(score,player);
        goto mainpage;
    }
	else
		{
		edit_score(score,player);
		goto mainpage;}}

