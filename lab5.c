#include <stdio.h>
#include <stdlib.h>

/*
 *Programmer Name: Sheila Li
 *Class and Semester: CIS 1057 Section 004 Fall 2024
 *Date: Wednesday,October 23, 2024
 *Assignment: Lab 5
 *Description: Takes in a date from the user, checks if it is a validate date
	and then outputs the caculated julianized date. 
*/

//function prototypes
int is_a_leap_year(int year);
int is_a_validate_date(int month2, int day2, int year2);
int get_date(int month, int day, int year);
int ordinal_date(int month3, int day3, int year3);
int print_US_date(int mm, int dd, int yyyy);
int print_ordinal_date(int yyyy, int ddd);

int main()
{
	int prompt_month, prompt_day, prompt_year;
	printf("Enter a month: ");
	scanf("%d", &prompt_month);

	printf("\nEnter a day: ");
	scanf("%d", &prompt_day);

	printf("\nEnter a year: ");
	scanf("%d", &prompt_year);

	int month = prompt_month;
	int day = prompt_day;
	int year = prompt_year;

	is_a_validate_date(month, day, year);
	print_US_date(month, day, year);
	print_ordinal_date(year, ordinal_date(month, day, year));
}


/*
 *Functions: 	is_a_leap_year()
 *Preconditions:
		year - takes the prompted year from the user.
 *Post Conditions:NONE
 *Globals: NONE
 *Returns: 0(true) or (false)
 *Description: calculates if the user inputted year is a leap year or not.
*/
int is_a_leap_year(int year)
{
	if ((year%100)==0){
		if((year%400)==0)
		{
			return 0;
		}
		else{
			return 1;
		}
	}else if ((year%4)==0){
		return  0;
	}
}

/*
 *Functions: is_a_validate_date()
 *Preconditions:
		year2 - takes the prompted year from the user.
		month2 -takes the prompted month from the user.
		day2 - takes the prompted day from the user.
 *Post Conditions: NONE
 *Globals:NONE
 *Returns: return 0 is it is true and will print a statement if the date is invalid.
 *Description: Checks if the user inputted date is valid or invalid.
*/
int is_a_validate_date(int month2, int day2, int year2)
{
	if ((1<=month2 && month2<=12) && (1<=day2 && day2<=31) && (1900<=year2 && year2<=2200))
	{
		return 0;
	}else{
		printf("\nthe date is not a validate date");
		exit(0);
	}
}

/*
 *Functions: ordinal_date()
 *Preconditions:
		year3 - takes the prompted year from the user.
		month3 -takes the prompted month from the user.
		day2 - takes the prompted day from the user.
 *Post Conditions:
		day_of_year - adds days in the month.
 *Globals:NONE
 *Returns:
		days_of_year - the calculated days from the start of the year to the user inputted month and day.
 *Description: calculates the number of the day of the year from the user inputted day and month.
*/
int ordinal_date(int month3, int day3, int year3)
{
	int day_of_year = 0;
	int days_in_month []={31,28,31,30,31,30,31,31,30,31,30,31};

	if(is_a_leap_year(year3) == 0)
	{
		days_in_month[1] = 29;
	}

	for (int i=0; i<month3 -1; i++){
                day_of_year += days_in_month[i];
        }

	return day_of_year + day3;
}

/*
 *Functions: print_US_date()
 *Preconditions:
		yyyy - takes the prompted year from the user.
		mm -takes the prompted month from the user.
		dd - takes the prompted day from the user.
 *Post Conditions:NONE
 *Globals:NONE
 *Returns:NONE
 *Description: prints the date.
*/
int print_US_date(int mm, int dd, int yyyy)
{
	printf("%d/%d/%d\n", mm, dd, yyyy);

}

/*
 *Functions: print_ordinal_date()
 *Preconditions:
		 yyyy - takes the prompted year from the user.
		 ddd - takes the prompted day from the user.
 *Post Conditions: NONE
 *Globals:NONE
 *Returns:NONE
 *Description: prints the ordinal date.
*/
int print_ordinal_date(int yyyy, int ddd)
{
	if (ddd >= 100 && ddd <= 999){
		 printf("%d%d\n", yyyy, ddd);
	}else{
		for(int i=0; i<=3; i++)
		{
			i++;
			if(i = 3){
				printf("%d0%d\n", yyyy, ddd);
			}else{
				printf("%d%d\n", yyyy, ddd);
			}
		}
	  }
}

