#include <stdio.h>
#include <math.h>

//function is 3x^5+5x^4+7x^3+9x^2+7x+1
//derivative is 15x^4+20x^3+21x^2+18x+7

#define THRESHOLD 0.001 //define how accurate the root should be

int a1,a2,a3,a4,a5,a6;  //coefictients of polynominal

void createPolynominal(int b1,int b2,int b3,int b4,int b5,int b6){
    a1 = b1;
    a2 = b2;
    a3 = b3;
    a4 = b4;
    a5 = b5;
    a6 = b6;
}

double f_x(double x){   //calculate value of f(x)
    double value = 0; // value of f(x)

     //calculate and add terms separately

    value += a1*x*x*x*x*x;     //3x^5
    value += a2*x*x*x*x;       //5x^4
    value += a3*x*x*x;         //7x^3
    value += a4*x*x;           //9x^2
    value += a5*x;             //7x
    value += a6;

    return value;
}

double df_x(double x){            //calculates value of derivative of f(x) at x
    double value = 0; // value of f(x)

     //calculate and add terms separately

    value += 5*a1*x*x*x*x;      //15x^4
    value += 4*a2*x*x*x;        //20x^3
    value += 3*a3*x*x;          //21x^2
    value += 2*a4*x;            //18x
    value += a5;

    return value;
}

void printPolynominal(){
    if(a1!= 0)
        printf("%dx^5",a1);
    if(a2>0)
        printf("+%dx^4",a2);
    else if(a2<0)
        printf("%dx^4",a2);
    if(a3>0)
        printf("+%dx^3",a3);
    else if(a3<0)
        printf("%dx^3",a3);
    if(a4>0)
        printf("+%dx^2",a4);
    else if(a4<0)
        printf("%dx^2",a4);
    if(a5>0)
        printf("+%dx",a5);
    else if(a5<0)
        printf("%dx",a5);
    if(a6>0)
        printf("+%d",a6);
    else if(a6<0)
        printf("%d",a6);
    printf("\n");
}

void printGuessRootPair(float guess){  //prints initial guess, iteration number and root
    double last,current=guess;    //temporarily holds root guesses
    int numIter=0;    //number of iterations

    printf("%13.2f ",guess);

    do{
    if(fabs(df_x(last)) < 0.00001){     //invalid value
        printf("Can't calculate root\n");
        return;
    }
    last = current;
    current = last-(f_x(last)/df_x(last));              //newthons-rapson algorythm
    numIter++;
    }while(fabs(current-last)>THRESHOLD && numIter < 10000);

    printf("%20d \t %4.3f\n",numIter,current);
}

void printSinGuessRootPair(float guess){  //prints initial guess, iteration number and root
    double last,current=guess;    //temporarily holds root guesses
    int numIter=0;    //number of iterations

    printf("%13.2f ",guess);

    do{
    last = current;         //save guess for future approximation
    if(fabs(df_x(last)) < 0.00001){     //invalid value
        printf("Can't calculate root\n");
        return 0;
    }
    current = last-(last*last+sin(1/last))/(2*last-cos(1/last)*(1/(2*last)));              //newthons-rapson algorythm x^2+sin(1/x) with derivative  2x-cos(1/x)*(1/2x)
    numIter++;
    }while(fabs(current-last)>THRESHOLD && numIter < 10000);

    printf("%20d \t %4.3f\n",numIter,current);
}

int main()
{
    //polynomial function with given coefficients
    createPolynominal(36,-330,960,-1170,624,-120);
    printPolynominal();
    printf("With roots: %.2f %.2f %.2f %.2f %.2f\n",0.5,0.66,1.0,2.0,5.0);
    printf("Initial guess \t number of iterations \t Root\n");
    printf("_____________________________________________\n");
    for(double guess=0;guess<5.2;guess+=0.3){
        printGuessRootPair(guess);
    }
    printf("\n");

    //sine function
    printf("x^2+sin(1/x)\n");
    printf("Too many roots and all of them can't be found using newton-raphson method\n");
    printf("Initial guess \t number of iterations \t Root\n");
    printf("_____________________________________________\n");
    for(double guess=-1;guess<1;guess+=0.3){
        printSinGuessRootPair(guess);
    }
    printf("\n");

    //polynomial function
    createPolynominal(1,22,-6613,-75178,7823256,-72367200);
    printPolynominal();
    printf("With roots: -76 -50 12 23 69\n");
    printf("Initial guess \t number of iterations \t Root\n");
    printf("_____________________________________________\n");
    printGuessRootPair(-80);
    printGuessRootPair(-55);
    printGuessRootPair(5);
    printf("\n");

    //root of this function can't be found using newton's method if initial guess is 0
    createPolynominal(0,0,0,-1,0,1);
    printPolynominal();
    printf("Initial guess \t number of iterations \t Root\n");
    printf("_____________________________________________\n");
    printGuessRootPair(0.5);
    printGuessRootPair(-0.5);
    printGuessRootPair(0);
    printf("\n");

    //redId polynomial has only one real root, other are complex roots, which can't be found by newton's method without some adjustments
    createPolynominal(3,5,7,9,7,1);
    printPolynominal();
    printf("With root: -0.178\n");
    printf("_____________________________________________\n");
    printGuessRootPair(-10);
    printf("\n");

    //similar to redid polynomial
    createPolynominal(17,5,3,6,7,23);
    printPolynominal();
    printf("With root: -1.085\n");
    printf("_____________________________________________\n");
    printGuessRootPair(-10);
    printf("\n");

    createPolynominal(3,20,-10,-240,-250,200);
    printPolynominal();
    printf("With roots: -4.672 -3.588 -2.256 0.530 3.320\n");
    printf("_____________________________________________\n");
    printGuessRootPair(-10);
    printGuessRootPair(-4);
    printGuessRootPair(-1);
    printGuessRootPair(0);
    printGuessRootPair(10);
    printf("\n");

    createPolynominal(1,19,-21,40,-199,-59);
    printPolynominal();
    printf("With roots: -20.164 -0.278 2.248\n");
    printf("_____________________________________________\n");
    printGuessRootPair(-30);
    printGuessRootPair(-4);
    printGuessRootPair(5);
    printf("\n");

    createPolynominal(1,19,21,40,199,59);
    printPolynominal();
    printf("With roots: -17.918 -2.240 -0.314\n");
    printf("_____________________________________________\n");
    printGuessRootPair(-20);
    printGuessRootPair(-4);
    printGuessRootPair(-1);
    printf("\n");

    return 0;
}
