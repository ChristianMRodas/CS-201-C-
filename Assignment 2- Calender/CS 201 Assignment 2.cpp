#include <iostream>
#include <cmath>
#include <cassert>
#include <iomanip>
#include <string>
using namespace std;

// Functions for taking in a user-specified date and prints a properly formatted month

// This asks user for a valid year. If invalid, it will ask the user again until a valid year is entered
int GetYear() {
	int year;
	year = 0;

	cout << "Enter a year that is between 1000 and 9999" << endl;
	cin >> year;
	cout << endl;

	// Checks for valid input
	if (year >= 1000 && year <= 9999) {
		//Test: Verifies for valid years
		//cout << "The year " << year << " is valid" << endl;
		year = year;
	}

	// If invalid input detected, then asks user again.
	else {
		cout << "You entered an invalid year. The year must be between 1000 and 9999. Try again." << endl;
		GetYear();
	}

	return year;
}

// Gets the starting day and converts it to a number so that the PrintOneMonth function knows where to start print days
int GetStartDay() {
	string starting_week_day;
	int start_day;

	starting_week_day = "Sun";
	start_day = 0;

	// Asks user for starting day
	cout << "What day does this month start with?" << endl;
	cin >> starting_week_day;
	cout << endl;

	//Convert starting day to int
	if (starting_week_day == "Sunday" or starting_week_day == "Sun") {
		start_day = 0;
	}
	else if (starting_week_day == "Monday" or starting_week_day == "Mon") {
		start_day = 1;
	}
	else if (starting_week_day == "Tuesday" or starting_week_day == "Tues") {
		start_day = 2;
	}
	else if (starting_week_day == "Wednesday" or starting_week_day == "Wed") {
		start_day = 3;
	}
	else if (starting_week_day == "Thursday" or starting_week_day == "Thu") {
		start_day = 4;
	}
	else if (starting_week_day == "Friday" or starting_week_day == "Fri") {
		start_day = 5;
	}
	else if (starting_week_day == "Saturday" or starting_week_day == "Sat") {
		start_day = 6;
	}
	// If user enters invalid input, it will ask user again
	else {
		cout << "Invalid starting day entered. Try again. (Ex: Sat, Friday). " << endl;
		GetStartDay();
	}
	// Test: Verifies that correct output was dectected
	//cout << "This is the int for start_day: " << start_day << endl;
	return start_day;
}

// Asks user for month and assigns it an integer for the DaysPerMonth function
int GetMonth() {
	string month;
	int monthNumber;

	month = "Jan";
	monthNumber = 0;

	cout << "What month is it?" << endl;
	cin >> month;
	cout << endl;

if (month == "January" or month == "Jan") {
	monthNumber = 0;
}
else if (month == "February" or month == "Feb") {
	monthNumber = 1;
}
else if (month == "March" or month == "Mar") {
	monthNumber = 2;
}
else if (month == "April" or month == "Apr") {
	monthNumber = 3;
}
else if (month == "May") {
	monthNumber = 4;
}
else if (month == "June" or month == "Jun") {
	monthNumber = 5;
}
else if (month == "July" or month == "Jul") {
	monthNumber = 6;
}
else if (month == "August" or month == "Aug") {
	monthNumber = 7;
}
else if (month == "September" or month == "Sep") {
	monthNumber = 8;
}
else if (month == "October" or month == "Oct") {
	monthNumber = 9;
}
else if (month == "November" or month == "Nov") {
	monthNumber = 10;
}
else if (month == "December" or month == "Dec") {
	monthNumber = 11;
}
// If invalid input dected, asks user to try again.
else {
	cout << "You entered an invalid month. Try again. (Ex: December, Sep)." << endl;
	GetMonth();
}

return monthNumber;
}


// Finds how many days each month has and adds an extra day for Feb if it is a leap year.
int DaysPerMonth(int monthNumber, int year) {
	int days_in_month;

	days_in_month = 0;

	// Assigns 31 days to months that will always have 31 days.
	if (monthNumber == 0 or monthNumber == 2 or monthNumber == 4 or monthNumber == 6 or monthNumber == 7 or monthNumber == 9 or monthNumber == 11) {
		//Test: Verifies that correct months will be assigned 31 days.
		//cout << "This month has 31 days" << endl;
		days_in_month = 31;
	}
	// Assings the number of days to the rest of the months that wont have 31 days
	else {
		//Test: Verifies months that dont have 31 days
		//cout << "This month doesnt have 31 days" << endl;
		// Computes February's day changes depending on leap years
		if (monthNumber == 1) {
			days_in_month = 28;
			if (year % 4 == 0) {
				if (year % 100 == 0) {
					if (year % 400 == 0) {
						//Test: Verifies that Leap year dectection was successful
						//cout << "Leap year Dected" << endl;
						days_in_month = 29;
					}
					else {
						days_in_month = 28;
					}
				}
				else {
					//Test: Verifies that a Leap Year was dected successfully
					//cout << "Leap year Dected" << endl;
					days_in_month = 29;
				}
			}
			else {
				days_in_month = 28;
			}
			//Test: Verifies correct days for the month
			//cout << "This month has " << days_in_month << " days." << endl;
		}
		// Assings 30 days to remainding months
		if (monthNumber == 3 or monthNumber == 5 or monthNumber == 8 or monthNumber == 10) {
			days_in_month = 30;
			//Test: Verifies 30 days for months with 30 days
			//cout << "This month has " << days_in_month << " days." << endl;
		}
	}

	return days_in_month;
}




// This function will print the month for the given year in a formatted way.
void PrintOneMonth(string month, int year, int days, int start_d) {
	int moving_day;
	int i;

	//Tests for valid starting day formatting
	//start_d = 1;
	cout << "Printing the Monthly Calender for you." << endl;

	//Centers the Month and Year
	std::cout << std::setw(40);
	std::cout << month << " " << year << std::endl;

	//Prints weeklys days in header format
	cout << "Sunday    Monday    Tuesday    Wednesday    Thursday    Friday    Saturday" << endl;

	//Starts days at 1
	i = 1;

	//Test: Outputs integer value of starting day for verification
	//cout << "This is the starting day " << start_d << endl;

	//These if statements start the first day and begins initial formatting
	if (start_d == 0) {
		i = 1;
		cout << i;
	}
	else if (start_d == 1) {
		cout << "          " << i;
		i = i + 1;
	}
	else if (start_d == 2) {
		cout << "                    " << i;
		i = i + 1;
	}
	else if (start_d == 3) {
		cout << "                               " << i;
		i = i + 1;
	}
	else if (start_d == 4) {
		cout << "                                            " << i;
		i = i + 1;
	}
	else if (start_d == 5) {
		cout << "                                                        " << i;
		i = i + 1;
	}
	else if (start_d == 6) {
		cout << "                                                                  " << i;
		i = i + 1;
	}

	//This begins the process of moving the days to the valid formatting
	moving_day = start_d + 1;

	//This prints all the days in integers with proper formatting
	for ( i = 2; i <= days; ++i) {
		if (moving_day == 0) {
			cout << setw(0) << i;
		}
		else if (moving_day == 1) {
			if (i <= 10) {
				cout << "         " << i;
			}
			else {
				cout << "        " << i;
			}
		}
		else if (moving_day == 2) {
			if (i <= 10) {
				cout << "         " << i;
			}
			else {
				cout << "        " << i;
			}
		}
		else if (moving_day == 3) {
			if (i <= 10) {
				cout << "          " << i;
			}
			else {
				cout << "         " << i;
			}
		}
		else if (moving_day == 4) {
			if (i <= 10) {
				cout << "            " << i;
			}
			else {
				cout << "           " << i;
			}
		}
		else if (moving_day == 5) {
			if (i <= 10) {
				cout << "           " << i;
			}
			else {
				cout << "          " << i;
			}
		}
		else if (moving_day == 6) {
			if (i <= 10) {
				cout << "         " << i;
			}
			else {
				cout << "        " << i;
			}
		}
		//This restarts the format to the left once the day reaches saturday
		else if (moving_day == 7) {
			i = i - 1;
			moving_day = -1;

			cout << endl;
		}

		//This moves to the next formatting day
		moving_day = moving_day + 1;
	}
}




int main () 
{
	int month;
	string month_string;
	int day;
	int year;
	int monthly_days;
	char keep_going;
	int starting_day;

	keep_going = 'Y';

	while (keep_going == 'Y') {

		month = GetMonth();
		year = GetYear();
		monthly_days = DaysPerMonth(month, year);
		starting_day = GetStartDay();

		// Convers month (int) into month_string (string)
		if (month == 0) {
			month_string = "JANUARY";
		}
		else if (month == 1) {
			month_string = "FEBRUARY";
		}
		else if (month == 2) {
			month_string = "MARCH";
		}
		else if (month == 3) {
			month_string = "APRIL";
		}
		else if (month == 4) {
			month_string = "MAY";
		}
		else if (month == 6) {
			month_string = "JUNE";
		}
		else if (month == 7) {
			month_string = "JULY";
		}
		else if (month == 8) {
			month_string = "AUGUST";
		}
		else if (month == 9) {
			month_string = "SEPTEMBER";
		}
		else if (month == 10) {
			month_string = "OCTOBER";
		}
		else if (month == 11) {
			month_string = "NOVEMBER";
		}
		else if (month == 12) {
			month_string = "DECEMBER";
		}

		//Test: Verifies that output was correct
		//cout << "This is the month int" << month << endl;
		//cout << "This is the month string" << month_string << endl;


		PrintOneMonth(month_string, year, monthly_days, starting_day);

		cout << endl;

		cout << "Would you like to find the calender for anther month? (Press Y)." << endl;
		cin >> keep_going;
	}

	system("pause");
	return 0;
}
