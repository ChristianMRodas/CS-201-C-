// Christian Rodas 201R  Program #3 
//
//This program reads from a file with values: Transaction ID, thier first name and last name, and how much they spent.
//The program then reads the file and saves the values into thier own respective arrays
//Then the program gives the user a menu which will give them 4 options
//The 1st option prints all the customers data, the 2nd prints all the customers first and last name, and the 3rd option prints thier total before and after discount
//The last option ends the program, which the program can press 4,q, or Q.
//The program will catch invalid input and ask the user to try again
//The program we continue to run unitl the user quits the program
//
//
//



#include <string>
#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include <iomanip>
#include <stdexcept>

using namespace std;

//My functions

//Prints all customers data in a formatted way
void printCustomersData (int transaction_ID[], string first_name[], string last_name[], double total_spent[], int size) {

	cout << left << setw(12) << "Trans_ID   " << "First      " << "Last           " << "Before Discount" << endl;
	for (int i=0; i < size; ++i) {
		cout << left << setw(12) << transaction_ID[i];
		cout << left << setw(11) << first_name[i];
		cout << left << setw(15) << last_name[i];
		cout << fixed << setprecision(2) << total_spent[i]; //Prints price into standard currency format with 2 decimals.
		cout << endl;
	}



}

//This function prints the customers transaction ID and the first and last name in a formatted way.
void printNames(int transaction_ID[], string first_name[], string last_name[], int size) {

	cout << left << setw(12) << "Trans_ID   " << "First      " << "Last" << endl;
	for (int i=0; i < size; ++i) {

		cout << left << setw(12) << transaction_ID[i];
		cout << left << setw(11) << first_name[i];
		cout << last_name[i];
		cout << endl;
	}




}
//Prints customers receipt with discount applied
void printTotal(int transaction_ID[], double total_spent[], int size) {

	cout << left << setw(12) << "Trans_ID   " << "Before Discount     " << "After Discount" << endl;
	for (int i = 0; i < size; ++i) {

		cout << left << setw(12) << transaction_ID[i];
		cout << left << setw(19) << fixed << setprecision(2) << total_spent[i] << " ";
		
		//Maths to take 40% off the purchase
		double some_maths;
		double after_discount;

		some_maths = total_spent[i];
		some_maths = some_maths * .40;
		after_discount = total_spent[i] - some_maths;
		cout << fixed << setprecision(1) << after_discount; //Sets amount into a standard currency format

		cout << i << " ";
		cout << endl;
	}

}


int main() {

	//Sets size of the arrary and used to limit the size of the iterations for the 4 different arrarys
	const int array_size = 10;

	char user_choice;
	bool keep_going = true; //Continues to show the menu until user quits


	//4 arrarys to store the customer's 4 different data types
	int transaction_ID[array_size];
	string first_name[array_size];
	string last_name[array_size];
	double total_spent[array_size];

	ifstream c_data;  //This names the file

	//Opens file
	c_data.open("input.txt");
	if (!c_data.is_open()) {
		cout << "Could not open file" << endl;
		return 1;  //This will indicate an error if something went wrong
	}

	//Variables to input into thier respective arrays.
	int transactionID; 
	string firstName;
	string lastName;
	double totalSpent;

	//This saves all the values into thier respective arrays.
	for (int i = 0; i < array_size; ++i) {

		c_data >> transactionID;
		c_data >> firstName;
		c_data >> lastName;
		c_data >> totalSpent;

		//cout << transactionID << " ";
		transaction_ID[i] = transactionID;

		//cout << firstName << " ";
		first_name[i] = firstName;

		//cout << lastName << " ";
		last_name[i] = lastName;

		//cout << totalSpent << " " << endl;
		total_spent[i] = totalSpent;
	}


	//This closes the file
	//cout << "Closing the file" << endl;
	c_data.close(); //This is the syntax to close the file


	//This begins the program which will continue to run until the user quits the program.
	while (!keep_going == false) {

		cout << "1 .Print all customers data" << endl;
		cout << "2. Print names and Transaction ID" << endl;
		cout << "3. Print total before and after discount applied" << endl;
		cout << "4. Enter q/Q to quit" << endl;
		cout << endl;
		cout << "Enter your choice or 'q' to quit: " << endl;

		//Try's to get user input but if the user enters somwthing invalid it will catch that error
		try {
			cin >> user_choice;
			//cout << "You chose the option, " << user_choice << endl;

			if (user_choice == '0' ) {
				throw runtime_error("Wrong input. Please Try again...");
				cout << endl;
			}
		}
		catch (runtime_error& excpt) {
			cout << excpt.what() << endl;
			cout << "Wrong Input. You must choose a number between 1-4 or 'q' or 'Q'" << endl;
		}

		//User Menu
		switch (user_choice) {
		case '1':
			cout << "Here is all of the customers data" << endl;
			printCustomersData(transaction_ID, first_name, last_name, total_spent, array_size);
			cout << endl;
			break;

		case '2':
			cout << "Here's the customers names and Transaction ID" << endl;
			printNames(transaction_ID, first_name, last_name, array_size);
			cout << endl;
			break;

		case '3':
			cout << "Here's the total before and after discount application" << endl;
			// This is where we are gonna to take the 40% discount. Probs use a for loop , save to temp, apply 40, then cout
			printTotal(transaction_ID, total_spent, array_size);
			cout << endl;
			break;

		case '4':
			cout << "Thanks for using my program. Goodbye! " << endl;
			keep_going = false;
			break;

		case 'q':
			cout << "Thanks for using my program. Goodbye! " << endl;
			keep_going = false;
			break;

		case 'Q':
			cout << "Thanks for using my program. Goodbye! " << endl;
			keep_going = false;
			break;

		default:
			cout << endl <<  "Wrong input. Please Try again..." << endl;
			break;
		}
		
	}


	//system("pause");

	return 0;


}