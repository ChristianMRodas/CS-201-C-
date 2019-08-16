//Christian Rodas 12/12/18
//Program 7
//
//This Program is divided into two menus (Main and Sub menus) and two lists. (Critically ill and "normally" ill)
//The Main Menu will show the 3 Departments (Heart Clinic, Lung Clinic, and Plastic Surgery) and an "exit program" option
//Once the user has selected a department, they will have 6 options. 
//
// "1: Add patient"		Which adds the patient's info into the "normally ill" queue lists
// "2: Add critically ill patient"	Which adds the patient's info into the "critically ill" queue lists
// "3: Take out patinet for operation"  Which will remove the first patient's info from the queue
// "4: Cancel patient"	Which will delete the user selected patient's info
// "5: List the queue of patients"	Which lists all the patients in order
// "6: Change department or exit"	Which sends user back the main menu
//
//The program will continue to loop until the user quits the program
//
//The maximum size for the two queue are 100 together

#include <vector>
#include <iostream>
#include <cmath> 
#include <math.h>
#include <string>
#include <queue> 


using namespace std;

//Functions

//This is the submenu function, which will process the user's selection

int sub_m() {
	string patient_fname;
	string patient_lname;
	int patient_ssn;
	int wait_list_size;
	int cwait_list_size;
	int total_wait_list_size;

	//Non critical patients
	queue<string> wait_list_fname;
	queue<string> wait_list_lname;
	queue<int> wait_list_ssn;

	//Critical patients
	queue<string> cwait_list_fname;
	queue<string> cwait_list_lname;
	queue<int> cwait_list_ssn;

	//Temp copy of a patient
	string scopy_wait_list;
	int icopy_wait_list;


	//Sets user choice to 0
	char choice = 0;
	while (choice != '6') {		//This asks the user to select which sub menu they would like to use
		cout << "Please enter your choice : " << endl;
		cout << "1: Add patient" << endl;
		cout << "2: Add critically ill patient" << endl;
		cout << "3: Take out patinet for operation" << endl;
		cout << "4: Cancel patient" << endl;
		cout << "5: List the queue of patients" << endl;
		cout << "6: Change department or exit" << endl;

		cin >> choice;

		switch (choice) {
		case '1':	//This will add the the normal patients into thier own "normal" wait list
			cout << "Adding patient." << endl;

			cwait_list_size = cwait_list_fname.size();
			wait_list_size = wait_list_fname.size();
			total_wait_list_size = cwait_list_size + wait_list_size;

			//Caps the amount of patients to 100
			if (total_wait_list_size > 100) {
				cout << "You have reached the Maximum size. " << endl;
				cout << "Patient was not added." << endl;
			}

			else {

				cout << "Please first enter the patient's first name: ";
				cin >> patient_fname;
				cout << "and thier last name: ";
				cin >> patient_lname;
				cout << "and thier SSN: ";
				cin >> patient_ssn;
				cout << endl;

				if (patient_ssn == NULL) {
					cout << "No SSN entered. Contact information not added" << endl;
				}

				else {
					cout << "Here is the information you added." << endl;
					cout << "First Name: " << patient_fname << " Last Name: " << patient_lname << " SSN: " << patient_ssn << endl;

					wait_list_fname.push(patient_fname);
					wait_list_lname.push(patient_lname);
					wait_list_ssn.push(patient_ssn);
				}
			}

			break;
		case '2': //Critically ill patients take priority, so two lists are used. 
			//The Critically Ill Patients's list will always be itereated/printed before the the normal patient's list is.
			//Essentially making them go first

			//Caps the total amount of patients to 100
			if (total_wait_list_size > 100) {
				cout << "You have reached the Maximum size. " << endl;
				cout << "Patient was not added." << endl;
			}

			else {
				cout << "Adding critically ill patient" << endl;

				cout << "Please first enter the patient's first name: ";
				cin >> patient_fname;
				cout << "Thier last name: ";
				cin >> patient_lname;
				cout << "Finally thier SSN: ";
				cin >> patient_ssn;
				cout << endl;

				if (patient_ssn == NULL) {
					cout << "No SSN entered. Contact information not added" << endl;
				}

				else {
					cout << "Here is the information you added." << endl;
					cout << "First Name: " << patient_fname << " Last Name: " << patient_lname << " SSN: " << patient_ssn << endl;

					cwait_list_fname.push(patient_fname);
					cwait_list_lname.push(patient_lname);
					cwait_list_ssn.push(patient_ssn);
				}
			} 
			break;

		case '3':
			cout << "Taking out patient for operation" << endl;
			cout << endl;

	
			wait_list_size = wait_list_fname.size();
			cwait_list_size = wait_list_fname.size();

			//Checks that there are patients in the wait list first
			if (wait_list_size <= 0 && cwait_list_size <= 0) {
				cout << "No more patints remaining" << endl;
			}

			else {
				//This will operate on critical patients first
				if (cwait_list_size > 0) {
					//Print critical patient contact info
					cout << "Critical patient " << cwait_list_fname.front() << " " << cwait_list_lname.front() << " SSN: " << cwait_list_ssn.front() << " has been operated on." << endl;

					//Then remove from queue
					cwait_list_fname.pop();
					cwait_list_lname.pop();
					cwait_list_ssn.pop();

				}
				//After all critical patients are operated on, the normal patients will be operated on
				else {
					//Print contact info
					cout << "Patient " << wait_list_fname.front() << " " << wait_list_lname.front() << " SSN: " << wait_list_ssn.front() << " has been operated on." << endl;

					//Then remove from queue
					wait_list_fname.pop();
					wait_list_lname.pop();
					wait_list_ssn.pop();
				}
			}

			break;

		case '4':
			cout << "Canceling patient" << endl;
			cout << endl;

			//Asks user for the patient's information so that they can be found
			cout << "Please enter the patients first name: ";
			cin >> patient_fname;
			cout << "Thier last name: ";
			cin >> patient_lname;
			cout << "Finally, thier SSN: ";
			cin >> patient_ssn;


			//Iterates through all the patients currently in the queue in order
			//This is done by adding both the critical and normal wait lists together and decrementing after each printed patient.
			//The printing is done by printing first element(.front() ), then saving that elemented to a temp variable
			//then deleting the original element( .pop() ) and then re-adding it back to the queue at the end (.push() ).
			//Once the patient is found, they wont be pushed back into the queue. Essentially removing them for the queue

			cwait_list_size = cwait_list_fname.size();
			wait_list_size = wait_list_fname.size();
			total_wait_list_size = cwait_list_size + wait_list_size;

			if (total_wait_list_size == 0) {
				cout << "Queue is empty." << endl;
			}

			while (total_wait_list_size > 0) {

				while (cwait_list_size > 0) {

					//Verifier: Shows all patients currently in the queue
					//cout << "Patient: " << cwait_list_fname.front() << " " << cwait_list_lname.front() << " SSN: " << cwait_list_ssn.front() << endl;

					if (patient_fname == cwait_list_fname.front() && patient_lname == cwait_list_lname.front() && patient_ssn == cwait_list_ssn.front()) {
						cout << "Patient Found" << endl;

						cwait_list_fname.pop();
						cwait_list_lname.pop();
						cwait_list_ssn.pop();

						cwait_list_size = cwait_list_size - 1;

						cout << "Patient has been removed" << endl;
					}

					scopy_wait_list = cwait_list_fname.front();
					cwait_list_fname.pop();
					cwait_list_fname.push(scopy_wait_list);

					scopy_wait_list = cwait_list_lname.front();
					cwait_list_lname.pop();
					cwait_list_lname.push(scopy_wait_list);

					icopy_wait_list = cwait_list_ssn.front();
					cwait_list_ssn.pop();
					cwait_list_ssn.push(icopy_wait_list);

					cwait_list_size = cwait_list_size - 1;

				}

				while (wait_list_size > 0) {

					//Verifier: Shows all patients currently in the queue
					//cout << "Patient: " << wait_list_fname.front() << " " << wait_list_lname.front() << " SSN: " << wait_list_ssn.front() << endl;

					if (patient_fname == wait_list_fname.front() && patient_lname == wait_list_lname.front() && patient_ssn == wait_list_ssn.front()) {
						cout << "Patient Found" << endl;

						wait_list_fname.pop();
						wait_list_lname.pop();
						wait_list_ssn.pop();

						wait_list_size = wait_list_size - 1;

						cout << "Patient has been removed" << endl;
					}

					scopy_wait_list = wait_list_fname.front();
					wait_list_fname.pop();
					wait_list_fname.push(scopy_wait_list);

					scopy_wait_list = wait_list_lname.front();
					wait_list_lname.pop();
					wait_list_lname.push(scopy_wait_list);

					icopy_wait_list = wait_list_ssn.front();
					wait_list_ssn.pop();
					wait_list_ssn.push(icopy_wait_list);

					wait_list_size = wait_list_size - 1;

				}

				total_wait_list_size = total_wait_list_size - 1;
			}


			break;

		case '5':
			cout << "Listing the queue of patients" << endl;
			cout << endl;

			//Print all the patients currently in the queue in order
			//This is done by adding both the critical and normal wait lists together and decrementing after each printed patient.
			//The printing is done by printing first element(.front() ), then saving that elemented to a temp variable
			//then deleting the original element( .pop() ) and then re-adding it back to the queue at the end (.push() )
			cwait_list_size = cwait_list_fname.size();
			wait_list_size = wait_list_fname.size();
			total_wait_list_size = cwait_list_size + wait_list_size;

			if (total_wait_list_size == 0) {
				cout << "Queue is empty." << endl;
			}

			while (total_wait_list_size > 0) {
				
				//Since critical patients have priority, they printed first
				while (cwait_list_size > 0) {

					cout << "Patient: " << cwait_list_fname.front() << " " << cwait_list_lname.front() << " SSN: " << cwait_list_ssn.front() << endl;
					scopy_wait_list = cwait_list_fname.front();
					cwait_list_fname.pop();
					cwait_list_fname.push(scopy_wait_list);

					scopy_wait_list = cwait_list_lname.front();
					cwait_list_lname.pop();
					cwait_list_lname.push(scopy_wait_list);

					icopy_wait_list = cwait_list_ssn.front();
					cwait_list_ssn.pop();
					cwait_list_ssn.push(icopy_wait_list);
					
					cwait_list_size = cwait_list_size - 1;

				}

				//After the critical wait list has been itereated through
				//the normal wait list is printed.
				while (wait_list_size > 0) {

					cout << "Patient: " << wait_list_fname.front() << " " << wait_list_lname.front() << " SSN: " << wait_list_ssn.front() << endl;
					scopy_wait_list = wait_list_fname.front();
					wait_list_fname.pop();
					wait_list_fname.push(scopy_wait_list);

					scopy_wait_list = wait_list_lname.front();
					wait_list_lname.pop();
					wait_list_lname.push(scopy_wait_list);

					icopy_wait_list = wait_list_ssn.front();
					wait_list_ssn.pop();
					wait_list_ssn.push(icopy_wait_list);

					wait_list_size = wait_list_size - 1;

				}
				total_wait_list_size = total_wait_list_size - 1;
			}





		case '6':	//Reverts back to Main Menu
			cout << "Changing depertment or exiting" << endl;

			break;

		default:	//Catches invalid input and reloops
			cout << "Invalid input. Try again" << endl;
		}

	}

	return 0;
}


int main() {
	

	//Part A: Asks user which menu they would like to access
	//Menu corresponds to its respective number
	char main_menu_value;

	main_menu_value = 0;
	
	while (main_menu_value != '4'){

		cout << "				Welcome to the Starling City Hospital" << endl;
		cout << "Which menu would you like to access?" << endl;
		cout << "1: Heart Clinic" << endl;
		cout << "2: Lung Clinic" << endl;
		cout << "3: Plastic Surgergy" << endl;
		cout << "4: Exit" << endl;
		cout << "Please press the number that cordinates with your desired selection. " << endl;
		cin >> main_menu_value;

		switch (main_menu_value) {
		case '1':
			cout << "Welcome to the Heart Clinic Department " << endl;
			sub_m();	//Calls the function
			cout << endl;
			break;

		case '2':
			cout << "Welcome to the Lung Clinic Department " << endl;
			sub_m();	//Calls the function
			cout << endl;
			break;


		case '3':
			cout << "Welcome to the Plastic Surgery Department " << endl;
			sub_m();	//Calls the function

			cout << endl;
			break;


		case '4':	//Exits the program
			cout << "Exiting the program." << endl;
			cout << endl;

			break;

		default:	//Catches invalid inputs 
			cout << "Invalid Selection. Please try again." << endl;

			break;
		};

	}
	
	cout << "You have left the program" << endl;

	system("pause");

	return 0;

}