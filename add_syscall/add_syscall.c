#include <linux/kernel.h>
#include <linux/types.h>
#include <linux/syscalls.h>
#include "add_syscall.h"

/*
System call routine to add positive Float numbers.
Uses IEEE 32-bit floating point addition.
*/

/*Pre-condition: num1 >=0 and num2 >=0*/
/*Postcondition: num1+num2*/

SYSCALL_DEFINE2(add_syscall, int, num1,int,num2)
{

	//defining return for overflow as INF in IEEE format
	int overflow_error = 0x7F800000;

	//extracting the exponent and mantissa of the two numbers via bit masking
	//The sign bit will be zero for positive numbers
	int exp1 = num1&(0x7F800000);
	int exp2 = num2&(0x7F800000);
	int mat1 = num1&(0x007FFFFF);
	int mat2 = num2&(0x007FFFFF);
	
	//Declaring variables to store the result
	int mat,exp;
	
	//If the exponents are equal, add the mantissae
	if(exp1==exp2)
	{
		//both have hidden bit = 1 which add to <10.mantissa>
		//Right shifting mantissa and incrementing exponent
		mat=((mat1+mat2)>>1)&(0x007FFFFF);
		exp=exp1+0x00800000;
		
		//returning the floating point number in IEEE format
		return exp|mat; 
	}

	//The exponents are not equal
	if(exp1>exp2)
	{
		//Ensure 2 is the bigger one
		int temp;
		temp = exp2;
		exp2 = exp1;
		exp1 = temp;
		temp = mat2;
		mat2 = mat1;
		mat1 = temp;
	}

	//matching the exponents by right shifting the smaller number
	int diff_exp=(exp2-exp1)>>23;
	
	
	//Also setting the MSB 1 to account for the hidden bit
	mat1=(mat1>>1)|0x400000; 
	mat1=mat1>>(diff_exp-1);
	
	//exponent is equal to larger amongst the two, and mantissa is the sum of the two
	exp=exp2; 
	mat = mat1+mat2;

	//if mat overflows, rightshift and reset the MSB of mat and increment exponent
	if(mat&0x00800000)
	{
		mat = mat>>1;
		mat = mat & 0x00BFFFFF; 
		exp = exp + 0x00800000;
	}

	//if exp overflows return overflow error
	if(exp&0x80000000)
		return overflow_error;

	//returning the floating point number in IEEE format
	return exp|mat; 

}



