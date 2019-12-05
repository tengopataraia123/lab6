#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct question {
	char content[200];
	char answers[4][50];
	int correct;
} Question;

Question * questions;

void skipNlines(FILE * f,int n){
	while(n){
		char t = fgetc(f);
		if(t == '\n')
			n--;
	}
}

int load_questions(){
	FILE * fp;
	int qNum;
	fp = fopen("round1.txt","r");
	fscanf(fp,"%d",&qNum);
	questions = (Question*)malloc(sizeof(Question) * qNum);
	skipNlines(fp,2);
	for(int i=0;i<qNum;i++){
		do{
			fgets(questions[i].content,100,fp);
		}while(strlen(questions[i].content) <= 10);
		fgets(questions[i].answers[0],50,fp);
		fgets(questions[i].answers[1],50,fp);
		fgets(questions[i].answers[2],50,fp);
		fgets(questions[i].answers[3],50,fp);
		fscanf(fp,"%d",&questions[i].correct);
		
		printf("%s",questions[i].content);
		printf("%s",questions[i].answers[0]);
		printf("%s",questions[i].answers[1]);
		printf("%s",questions[i].answers[2]);
		printf("%s",questions[i].answers[3]);
		printf("%d\n",questions[i].correct);
		
	}
	return qNum;
}

int main(){
	int numOfQuestions=0;
	system("clear");
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

	numOfQuestions = load_questions();
	
//	for(int i=0;i<numOfQuestions;i++)
//		puts(questions[i].content);
	return 0;
}
