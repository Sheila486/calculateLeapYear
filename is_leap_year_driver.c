#include <stdio.h>
#include <stdlib.h>

/*
 *Programmer: 		Sheila Li
 *Class and Semester:	CIS 1057 Section 004 Fall 2024
 *Date: 		Wednesday, October 23, 2024
 *Assignment:		Lab 5
 *Description:		The driver for is_a_leap_year; check whether the year
			inputted is a leap year or not.
*/


//driver for is_a_leap_year
//protoype function
int is_a_leap_year(int year);

int main()
{
	//Prompt the user to enter a year
	int prompt_year;
	printf("Enter a year:");
	scanf("%d", &prompt_year);
	if (is_a_leap_year(prompt_year)== 0){
		printf("the year %d is a leap year\n", prompt_year);
	}else{
		printf("the year %d is not a leap year\n", prompt_year);
	}
}


/*
 *Function: is_a_leap_year()
 *Preconditions:
 *		year - if the year inputted is equally divided by 4 and 400 to see if it is a leap year.
 *Postconditions: none
 *Globals:	none
 *Returns:	whether the calculated value is divided equally in true or false.
 *Description:  check whether the year inputted by the user is a leap year.
*/

int is_a_leap_year(int year)
{
	int end_of_century;
	if ((year%100)==0){
		if((year%400)==0)
		{
			return 0;
		}
		else{
			return 1;
		}
	}else if ((year%4)==0){
		return 0;
	}
}
