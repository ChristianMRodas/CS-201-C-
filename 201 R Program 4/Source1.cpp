//Christian Rodas CS 201 R Program 4
//
//Program Summary
//The program will first create a base class named "Student". This class will hold the base functions and values
//The program sets up the setters and getters so that it can be used with the rest of the base and derived classes
//Next, the program creates a default destructor that will initialize the variables to 0 or empty (" ")
//In the main program, it will read the file (students.txt) and put the data into specified categories of (ID, First Name, Last Name, Item Quantity, Item Name
//Then for it will create a New Student based off the specified
//Afterwards, it will read the checkouts file and based off the ID, it will add the items to the Student.
//Next, it will read the checkins file, and remove the items based off whoever checked that item first
//Finally, using the Student Class' print function, it will output the final student data on an external file called UpdatedStudents2.txt

//Libraries
#include <iostream>
#include <fstream>
#include <istream>
#include <iomanip>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <string>
#include <typeinfo>

using namespace std;

//Class
class Student {
public:
	Student(string initID = "0", string initFirstName = "", string initLastName = "", string initItems ="0"); //Adds default constructor
	//~Student(); //For Destructer
	void setID(int student_ID);
	string getID() const;
	void setFirstName(string first_name);
	string getFirstName() const;
	void setLastName(string last_name);
	string getLastName() const;

	int CheckoutCount(int checked_out_items); //This function is to return how many items a student has checked out right now. DOES NOT change the amount tho

	//bool CheckOut(const string& item);  //This F() verifies item is still avaible(if so adds to student checked out items). True if added. Flase if cant.
	//if there is no dynamic array for the item being checked out, you create a dynamic array of 5

	//bool CheckIn(const string& item); //This F() verifies item is already on CHECKED OUT list and REMOVES it. 
	//IF this was the LAST ITEM, DElETE DYNAMIC ARRAY. IF check in works, return TRUE. else RETURN FALSE.

	//bool HasCheckOut(const string& item); //This F() return TRUE if ITEM is on students checkout LIST. else FALSE
	//DOES NOT CHANGE OBject's DATA

	//void Clear(); //Pretty much set names to EMPTY, ID to 0, all CHECKEDOUT data to DELETED and REMOVE all OBJECT's DATA

	void PrintStudent();


	private:
		string s_FN;
		string s_LN;
		string s_ID;
		string s_item_num;


};

//Default Constructor
Student::Student(string initID, string initFirstName, string initLastName, string initItems) {
	s_ID = initID;
	s_FN = initFirstName;
	s_LN = initLastName;
	s_item_num = initItems;
	

}
//Destructor
//Student::~Student() {
	//delete s_ID;
	//delete s_FN;   //this deletes pointer stuff
	//delete s_LN;
	//delete s_item_num;
//}

//My Functions
void Student::PrintStudent() {
	cout << " Student ID: " << this->s_ID << " Student name: " << this->s_FN << " " << this->s_LN << " Student Items Amount: " << this->s_item_num << endl;
}


int Student::CheckoutCount(int checked_out_items) {
	s_item_num = checked_out_items;
	return 0;
}

//Setters/Getters
void Student::setID(int student_ID) {
	s_ID = student_ID;
}
string Student::getID() const {
	return s_ID;
}

void Student::setFirstName(string first_name) {
	s_FN = first_name;
}
string Student::getFirstName() const{
	return s_FN;
}

void Student::setLastName(string last_name) {
	s_LN = last_name;
}
string Student::getLastName() const {
	return s_LN;
}

//This will print the entire student roster in a specified format
void PrintFullRoster(vector<Student*> StudentRoster) {
	int i;

	for (i = 0; i < StudentRoster.size(); ++i) {
		cout << "Iteration:  " << i << " Student Info: ";
		(*StudentRoster.at(i)).PrintStudent();
		cout << endl;
	}
}



//Starts program
int main() {

	//This creates a starting list for all students and thier names,id, item quantity and item names
	vector<Student*> StudentRoster;
	string student_name;
	string student_id;
	string items;
	string num_items;

	//This will setup the initial pointers 
	Student* newStudent = nullptr;
	Student* temp = nullptr;


	//Input file streams for each text file
	ifstream inST;
	ifstream inCO;
	ifstream inCI;

	//Tells user if a file was not found.
	inST.open("Students.txt"); //This file has the full student roster and what items they checked out(if any). USE DYNAMIC ARRAYS to STORE DATA
	if (!inST.is_open()) {
		cout << "Could not find the Students.txt file" << endl;
		return 1;
	}

	inCO.open("checkouts.txt"); //This file lists what ppl have checked out. MAKE SURE items are corresponed to the indicated items correctly
	if (!inCO.is_open()) {
		cout << "Could not find the checkouts.txt file" << endl;
		return 1;
	}

	inCI.open("checkins.txt"); //Check in items. SO first check who had the item first, then check that item in.
	if (!inCI.is_open()) {
		cout << "Could not find the checkins.txt file" << endl;
		return 1;
	}

	cout << "Reading in new files from inST" << endl;
	cout << "Reading in new files from inCO" << endl;
	cout << "Reading in new files from inCI" << endl;



	//students.txt

	//This creates the lists for each object
	vector<string> student_id_stuff(26);
	vector<string> student_first_name(25);
	vector<string> student_last_name(25);
	vector<string> student_items(25);
	vector<string> item_names(30);

	//Student stuff inserter and holder
	int i = 0;
	string s_stuff;
	int i_stuff;
	string id_students;
	string name_students;
	string items_students;

	//This will put the different datas, into specified lists
	while (inST >> s_stuff) {

		//cout << s_stuff << endl;
		id_students = s_stuff;
		student_id_stuff.at(i) = id_students;

		inST >> s_stuff;
		//cout << s_stuff << endl;
		name_students = s_stuff;
		student_first_name.at(i) = name_students;

		inST >> s_stuff;
		//cout << s_stuff << endl;
		name_students = s_stuff;
		student_last_name.at(i) = name_students;

		inST >> s_stuff;
		//cout << s_stuff << endl;
		items_students = s_stuff;
		student_items.at(i) = items_students;

		//If the student, has more than one item, it will add it to the item name array
		//Then it will attach that array into the Student's ID so that the program will know who(student's id) has what(items)
		if (s_stuff != "0") {
			int j;
			//cout << "More than one items: " << endl;
			if (s_stuff == "1") {
				inST >> s_stuff;
				//cout << "First item: " << s_stuff << endl;
				j = i + 1;
				items_students = s_stuff;
				student_items.at(j) = items_students;
			}
			else if (s_stuff == "2") {
				inST >> s_stuff;
				//cout << "First item: " << s_stuff << endl;
				j = i + 1;
				items_students = s_stuff;
				student_items.at(j) = items_students;

				inST >> s_stuff;
				//cout << "Second item: " << s_stuff << endl;
				j = j + 1;
				items_students = s_stuff;
				student_items.at(j) = items_students;
			}
			else if (s_stuff == "3") {
				inST >> s_stuff;
				//cout << "First item: " << s_stuff << endl;
				j = i + 1;
				items_students = s_stuff;
				student_items.at(j) = items_students;

				inST >> s_stuff;
				//cout << "Second item: " << s_stuff << endl;
				j = j + 1;
				items_students = s_stuff;
				student_items.at(j) = items_students;

				inST >> s_stuff;
				//cout << "Third item: " << s_stuff << endl;
				j = j + 1;
				items_students = s_stuff;
				student_items.at(j) = items_students;
			}
			else if (s_stuff == "4") {
				inST >> s_stuff;
				//cout << "First item: " << s_stuff << endl;
				j = i + 1;
				items_students = s_stuff;
				student_items.at(j) = items_students;

				inST >> s_stuff;
				//cout << "Second item: " << s_stuff << endl;
				j = j + 1;
				items_students = s_stuff;
				student_items.at(j) = items_students;

				inST >> s_stuff;
				//cout << "Third item: " << s_stuff << endl;
				j = j + 1;
				items_students = s_stuff;
				student_items.at(j) = items_students;

				inST >> s_stuff;
				//cout << "Fourth item: " << s_stuff << endl;
				j = j + 1;
				items_students = s_stuff;
				student_items.at(j) = items_students;
			}
			else if (s_stuff == "5") {
				inST >> s_stuff;
				//cout << "First item: " << s_stuff << endl;
				j = i + 1;
				items_students = s_stuff;
				student_items.at(j) = items_students;

				inST >> s_stuff;
				//cout << "Second item: " << s_stuff << endl;
				j = j + 1;
				items_students = s_stuff;
				student_items.at(j) = items_students;

				inST >> s_stuff;
				//cout << "Third item: " << s_stuff << endl;
				j = j + 1;
				items_students = s_stuff;
				student_items.at(j) = items_students;

				inST >> s_stuff;
				//cout << "Fourth item: " << s_stuff << endl;
				j = j + 1;
				items_students = s_stuff;
				student_items.at(j) = items_students;

				inST >> s_stuff;
				//cout << "Fifth item: " << s_stuff << endl;
				j = j + 1;
				items_students = s_stuff;
				student_items.at(j) = items_students;
			}
			else if (s_stuff == "6") {
				inST >> s_stuff;
				//cout << "First item: " << s_stuff << endl;
				j = i + 1;
				items_students = s_stuff;
				student_items.at(j) = items_students;

				inST >> s_stuff;
				//cout << "Second item: " << s_stuff << endl;
				j = j + 1;
				items_students = s_stuff;
				student_items.at(j) = items_students;

				inST >> s_stuff;
				//cout << "Third item: " << s_stuff << endl;
				j = j + 1;
				items_students = s_stuff;
				student_items.at(j) = items_students;

				inST >> s_stuff;
				//cout << "Fourth item: " << s_stuff << endl;
				j = j + 1;
				items_students = s_stuff;
				student_items.at(j) = items_students;

				inST >> s_stuff;
				//cout << "Fifth item: " << s_stuff << endl;
				j = j + 1;
				items_students = s_stuff;
				student_items.at(j) = items_students;

				inST >> s_stuff;
				//cout << "Sixth item: " << s_stuff << endl;
				j = j + 1;
				items_students = s_stuff;
				student_items.at(j) = items_students;
			}
			else if (s_stuff == "7") {
				inST >> s_stuff;
				//cout << "First item: " << s_stuff << endl;
				j = i + 1;
				items_students = s_stuff;
				student_items.at(j) = items_students;

				inST >> s_stuff;
				//cout << "Second item: " << s_stuff << endl;
				j = j + 1;
				items_students = s_stuff;
				student_items.at(j) = items_students;

				inST >> s_stuff;
				//cout << "Third item: " << s_stuff << endl;
				j = j + 1;
				items_students = s_stuff;
				student_items.at(j) = items_students;

				inST >> s_stuff;
				//cout << "Fourth item: " << s_stuff << endl;
				j = j + 1;
				items_students = s_stuff;
				student_items.at(j) = items_students;

				inST >> s_stuff;
				//cout << "Fifth item: " << s_stuff << endl;
				j = j + 1;
				items_students = s_stuff;
				student_items.at(j) = items_students;

				inST >> s_stuff;
				//cout << "Sixth item: " << s_stuff << endl;
				j = j + 1;
				items_students = s_stuff;
				student_items.at(j) = items_students;

				inST >> s_stuff;
				//cout << "Seventh item: " << s_stuff << endl;
				j = j + 1;
				items_students = s_stuff;
				student_items.at(j) = items_students;
			}

			else if (s_stuff == "8") {
				inST >> s_stuff;
				//cout << "First item: " << s_stuff << endl;
				j = i + 1;
				items_students = s_stuff;
				student_items.at(j) = items_students;

				inST >> s_stuff;
				//cout << "Second item: " << s_stuff << endl;
				j = j + 1;
				items_students = s_stuff;
				student_items.at(j) = items_students;

				inST >> s_stuff;
				//cout << "Third item: " << s_stuff << endl;
				j = j + 1;
				items_students = s_stuff;
				student_items.at(j) = items_students;

				inST >> s_stuff;
				//cout << "Fourth item: " << s_stuff << endl;
				j = j + 1;
				items_students = s_stuff;
				student_items.at(j) = items_students;

				inST >> s_stuff;
				//cout << "Fifth item: " << s_stuff << endl;
				j = j + 1;
				items_students = s_stuff;
				student_items.at(j) = items_students;

				inST >> s_stuff;
				//cout << "Sixth item: " << s_stuff << endl;
				j = j + 1;
				items_students = s_stuff;
				student_items.at(j) = items_students;

				inST >> s_stuff;
				//cout << "Seventh item: " << s_stuff << endl;
				j = j + 1;
				items_students = s_stuff;
				student_items.at(j) = items_students;

				inST >> s_stuff;
				//cout << "Eighth item: " << s_stuff << endl;
				j = j + 1;
				items_students = s_stuff;
				student_items.at(j) = items_students;
			}

			else if (s_stuff == "9") {
				inST >> s_stuff;
				//cout << "First item: " << s_stuff << endl;
				j = i + 1;
				items_students = s_stuff;
				student_items.at(j) = items_students;

				inST >> s_stuff;
				//cout << "Second item: " << s_stuff << endl;
				j = j + 1;
				items_students = s_stuff;
				student_items.at(j) = items_students;

				inST >> s_stuff;
				//cout << "Third item: " << s_stuff << endl;
				j = j + 1;
				items_students = s_stuff;
				student_items.at(j) = items_students;

				inST >> s_stuff;
				//cout << "Fourth item: " << s_stuff << endl;
				j = j + 1;
				items_students = s_stuff;
				student_items.at(j) = items_students;

				inST >> s_stuff;
				//cout << "Fifth item: " << s_stuff << endl;
				j = j + 1;
				items_students = s_stuff;
				student_items.at(j) = items_students;

				inST >> s_stuff;
				//cout << "Sixth item: " << s_stuff << endl;
				j = j + 1;
				items_students = s_stuff;
				student_items.at(j) = items_students;

				inST >> s_stuff;
				//cout << "Seventh item: " << s_stuff << endl;
				j = j + 1;
				items_students = s_stuff;
				student_items.at(j) = items_students;

				inST >> s_stuff;
				//cout << "Eighth item: " << s_stuff << endl;
				j = j + 1;
				items_students = s_stuff;
				student_items.at(j) = items_students;

				inST >> s_stuff;
				//cout << "Ninth item: " << s_stuff << endl;
				j = j + 1;
				items_students = s_stuff;
				student_items.at(j) = items_students;

			}

		}

		i = i + 1;
		//cout << "This is i " << i << endl;
	}

	//This will organize students data so that it can be inserted into the new Students functions
	for (i = 0; i < student_first_name.size(); ++i) {
		string id;
		string fn;
		string ln;
		string items;

		id = student_id_stuff.at(i);
		//cout << "i: " << i << " Current Student ID: " << id << endl;

		fn = student_first_name.at(i);
		//cout << "i: " << i << " Current Student Frist Name Info: " << fn << endl;

		ln = student_last_name.at(i);
		//cout << "i: " << i << " Current Student Last Name Info: " << ln << endl;

		items = student_items.at(i);
		//cout << "i: " << i << " Current Student Items: " << items << endl;

		//This will create a new Student and add it to the dynamic array
		newStudent = new Student(id, fn, ln, items);
		StudentRoster.push_back(newStudent);
	}

	//This will save the student's id into an ID array
	//Then it will save the item checked out into another array
	unsigned int gym_students_id;
	vector<int> list_students_id(30);

	string gym_items;
	vector<string> list_gym_items(30);

	i = 0;
	while (!inCO.eof()) {

		inCO >> gym_students_id;
		list_students_id.at(i) = gym_students_id;
		//cout << "This is what is being stored into the id array: " << gym_students_id << endl;

		inCO >> gym_items;
		list_gym_items.at(i) = gym_items;
		//cout << "This is what is being stored into gym items array: " << gym_items << endl;

		i = i + 1;

	}


	//This will read the checkins File
	string stuff3;
	inCI >> stuff3;
	//cout << "inCI's stuff3: " << stuff3 << endl;


	ofstream fout("UpdatedStudents2.txt");

	//Prints the Students info onto UpdatedStudents2.txt file
	//fout << "Printing Student Roster" << endl << PrintFullRoster(StudentRoster);  FIXME: Unable to print the roster to the output file due to function being void.


	// Delete Students
	for (int i = 0; i < StudentRoster.size(); i++) {
	delete StudentRoster.at(i);
	}

	//This will close all opened files
	//cout << "Closing the file Students.txt file" << endl;
	inST.close(); 
	//cout << "Closing the file checkout.txt" << endl;
	inCO.close();
	//cout << "Closing the file checkins.txt file" << endl;
	inCI.close();

	fout.close();


	//system("pause");

	return 0;
}