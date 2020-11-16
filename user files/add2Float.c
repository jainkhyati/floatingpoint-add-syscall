#include <stdio.h>
#include <unistd.h>
#include "addWrapper.c"

int main(int argc,char *argv[])
{
	//declaring variables to accept from user and store result
	float num1, num2, res;
	printf("Enter Number 1 and Number 2\n");
	scanf("%f %f", &num1, &num2);
	printf("Adding Numbers %f and %f \n",num1,num2);
	
	//Calling the Syscall Wrapper by passing the floats
	res=addFloat(num1,num2);
	
	//printing the result if no error (res = -1 if error)
	if(res!=-1)
		printf("The Result is %f\n",res);
	
	return 0;
}
