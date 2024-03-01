/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h> /*This is where the Random Function is defined*/
#include <time.h>

/*dice art function*/
int dice1(void)
{
     printf("\n    _______");
     printf("\n   /\\ o o o\\");
     printf("\n  /o \\ o o o\\_______");
     printf("\n <    >------>   o /|");
     printf("\n  \\ o/  o   /_____/o|");
     printf("\n   \\/______/     |oo|");
     printf("\n         |   o   |o/");
     printf("\n         |_______|/\n");
}

/*Generating a 'try again' message function*/
int errormessage(void)
{
    printf("\n _____  ___ __   __       ___   ___  ___  ___  _  _ ");
    printf("\n|_   _|| _ \\\\ \\ / /      /   \\ / __|/   \\|_ _|| \\| |");
    printf("\n  | |  |   / \\   /       | - || (_ || - | | | | .  |");
    printf("\n  |_|  |_|_\\  |_|        |_|_| \\___||_|_||___||_|\\_|\n");

}
int main()

{
    /*Defining the variables we'll be using*/
    int faces, throws, a,b, i, count, x;
    float occurence;
    
    /*ASCII dice art*/
    dice1();
    
  
    /*Asking the user to input the number of faces on the dice*/
    printf("\nEnter number of faces:");
    scanf("%d", &faces);
    
    
    /*Printing an error message if the input of the user is inferior to 1 or superior to 25, and asking to input again*/
    while (faces<1 || faces > 25)
	{
	    errormessage();
		printf("\nInvalid parameter");
		printf("\nEnter number of faces:");
    	scanf("%d", &faces);
	};
	
	
	/*Asking the user to input the number of throws*/
    printf("Enter number of throws:");
    scanf("%d", &throws);
    
    
    /*Printing an error message if the input is inferior to 1 or superior to 500, and asking to input again*/
	while (throws < 1 || throws > 500)
	{
	    errormessage();
		printf("\nInvalid parameter");
		printf("\nEnter number of throws:");
    	scanf("%d", &throws);
	};
	
	
	/*Defining the array where we'll store the random numbers for the dice*/
	int dice[throws]; 
	
	
	/*Generating the throws:*/
	printf("\nGenerating throws:");
	srand(time(NULL)); /*randomize seed*/ 
    for (i=1; i<=throws; i=i+1)	/*Repeating this part of the program for a given number of throws*/
    {
	    dice[i]= (rand() % (faces + 1 - 1))+1; /*Asking the system to generate random numbers in a given range*/
    };
    for(i=1;i<throws+1;i++) /*Printing the random numbers one at the time, which are stored in the array*/
    {
        printf("\n%d",dice[i]);
    };
    
    /*Evaluating the occurence of each random number*/
    dice1();
    a=faces-1; 
	for (b=1; b<=faces;  b++) /*Repeating this operation for all the faces*/
	{ 
	    count=0; 
	    occurence=0; 
	    i=1;
	    /*Checking for each element of the array, if they are equal to the faces (one at the time for the faces) */
	    while (i<=throws+1) 
	    {
	        if(dice[i]==faces-a)
	        {
	            count=count+1;
	            occurence=((float)count/(float)throws)*100;
	        }
	        i++;
	    };
	    printf("\n Occurences of %d=%.2f%%", faces-a, occurence); /*Printing the occurence of each face of the dice*/
	    a=a-1; /*Subtracting a by 1 so that for the next loop: faces-a=(faces-a)+1*/
	};
    return 0;
};
   





