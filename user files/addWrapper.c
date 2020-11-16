#include <stdio.h>
#include <unistd.h>
#include "addWrapper.h"
#define MY_SYSCALL 434

float addFloat(float num1,float num2)
{
	//Defining variables to store the integers
	int Inum1,Inum2,Ires;
	
	Inum1= *(int*)&num1;
	Inum2= *(int*)&num2;
	
	//declaring result variable storing -1 for errors
	float res=-1.0;
	
	//Storing NAN and INF IEEE representations
	int NaN1 = 0xFF800000;
	int NaN2 = 0xFFC00000;
	int INF = 0x7F800000;

	//if one of the numbers input is zero,print zero error
	if(Inum1==0||Inum2==0)
		printf("One of the inputs was zero\n");

	//if one of the numbers input is negetive, throw error
	else if(num1<0||num2<0)
		printf("Negative Inputs are not accepted\n");
	
	//Handling infinity inputs
	else if(Inum1==INF||Inum2==INF)
		printf("Overflow Error. Input number very Large.\n");

	//Handling NaN inputs
	else if(Inum1==NaN1|Inum2==NaN1|Inum1==NaN2|Inum2==NaN2)
		printf("One of the inputs was not a valid number\n");
		
	//The input is valid, calling syscall
	else
	{
		Ires = syscall(MY_SYSCALL,Inum1,Inum2);
		res = *(float*)&Ires;
	}
	
	//Checking for Overflow error 
	if(Ires==INF)
	{	printf("Overflow Error\n");
		res=-1.0;
	}
	
	
	return res;
}

