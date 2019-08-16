//Christian Rodas 11/12/18
//Program 6
//This Program is divided into two parts. 
//Part a will take a user's whole real number and will compute the total of n^2 + ...(n-1)^2 unti n = 1
//One function(rhs) will use recursion to compute the sequence and the other (lhs) will compute it using non-recursion
//Part b will create an array of size 5 (or more if user enters more than 5 numbers) 
//Then reverse that array using recursion

#include <vector>
#include <iostream>
#include <cmath>
#include <math.h>
#include <string>

using namespace std;

//Functions

//RHS using recursion 
int rhs_squares(int num, int total) {

	if (num > 1) {
		//cout << "This is n: " << num << " This is the total " << total << endl;

		total = num * num + total;
		cout << "Maths: " << total << " = " << num << " * " << num << " + " << total << endl;
		num = num - 1;

		rhs_squares(num, total);
	}

	else {
		int final_total;

		final_total = total;
		cout << final_total << endl << endl;
		cout << "The total is: " << total << endl;
		return final_total;
		
	}
}

//LHS not using recursion
int lhs_squares(int num, int total) {
	
	while (num > 1) {
		total = num* num + total;
		//cout << "Current number: " << num << " Current total: " << total << endl;
		num = num - 1;
	}

	return total;
}


//Part B's Functions

int array_reverse(int array[] , int size, int initializer) {
	int num_e = size - 1;	//This will start at the end
	int num_i = initializer;	//This will start at the beginning
	int temp_num;

	//Recursion stop case
	if (size < 1) {
		cout << "End of recursion: " << endl;
		return 0;
	}

	cout << "This is num_i at: " << num_i << " array number: " << array[num_i] << endl;
	cout << "This is num_e at: " << num_e << " arrray number: " << array[num_e] << endl;

	//Swapping numbers
	temp_num = array[num_i];
	array[num_i] = array[num_e];
	array[num_e] = temp_num;
	
	cout << "Swapped: " << array[num_i] << " with " << array[num_e] << endl;

	num_i = num_i + 1;
	size = size - 1;

	return array_reverse( array, size,num_i);
}



int main() {

	//Part a
	int n, total;
	total = 1;

	//Ask user for input
	cout << "Pick a number" << endl;
	cin >> n;

	//Calls functions
	int rhs;
	rhs = rhs_squares(n, 1);
	//cout << "This is rhs: " << x << endl;
	cout << endl;
	int lhs;
	lhs = lhs_squares(n, 1);
	//cout << "This is lhs:" << y << endl;

	//Compares the two function's ouput
	if (rhs == lhs) {
		cout << "Via induction, the left equals the right" << endl;
	}

	else {
		cout << "The left does not equal the right" << endl;
	}
	cout << endl;


	//Part b
	int user_num;

	//Set array size
	const int a_size = 5;

	//Creates the array
	int original_array[a_size];

	//Input the arrray's value
	cout << "Enter " << a_size << " numbers into the arrray" << endl;
	for (int i = 0; i < a_size; ++i) {
		cout << "Number: ";
		cin >> user_num;
		original_array[i] = user_num;
	}

	//Verifies that original array's values were correctly stored
	//for (int i = 0; i < a_size; ++i) {
		//cout << "Number at index: " << i << " is " << original_array[i] << endl;
	//}
	cout << endl;
	
	array_reverse(original_array, a_size,0);



	system("pause");

	return 0;

}
