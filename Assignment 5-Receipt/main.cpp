//11/8/2018
//Christian Rodas
//This functions takes data given from a text file and prints a receipt for the items purchased
//This is done by creating a base class that creates the starting prototype functions
//Then the derived class define the functions for their own specific use
//Then the classes are imported into the main program and the text file input is read and saved into arrays 
//These arrays will then be used to store the values iterativly so that it can printed on the reciept in order
//This program uses classes to help streamline the process and to prevent too much code being inside the main
//


#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <fstream>
#include <istream>
#include <stdexcept>
#include <sstream>

using namespace std;
//Takes the functions from class to be used in the main program
#include "PRODUCT.h"
#include "SHIRT.h"
#include "OFFICESUPPLIES.h"
#include "REGISTER.h"


//These are the new instances of objects


int main() {

	ifstream ipdt;		//Input file stream for products.txt
	ofstream opdt;		//Outputs to a new file

	//cout << "Opening products.txt" << endl;
	ipdt.open("products.txt");

	if (!ipdt.is_open()) {
		cout << "Could not open the file products.txt" << endl;			//Tells user if there is an error in opening the file
		return 1;
	}



	string item_data;
	int int_item_data;
	double double_item_data;
	int i = 0;
	double total_price = 00.00;

	//Arrays for respective data
	int *dA_quantities;
	dA_quantities = new int[50];
	string *dA_description;
	dA_description = new string[50];
	string *dA_size_count;
	dA_size_count = new string[50];
	double *dA_items_price;
	dA_items_price = new double[50];




	while (!ipdt.eof()) {
		ipdt >> item_data;

		//cout << "This is the data: " << item_data << endl;


		if (item_data == "SHIRT") {
			i = i + 1;
			//cout << "This is a shirt item" << endl;

			//This will create a new object that will use the Product's(base) virtual function
			//And override using the Shirt(derived) function.
			Product *p;
			Shirt shirt1;
			p = &shirt1;


			//Sets Shirt object's description
			string full_description;
			getline(ipdt, full_description);
			getline(ipdt, full_description);

			dA_description[i] = full_description;

			p->SetItemDescription(full_description);
			//cout << "This is the Shirt's description: " << shirt1.GetItemDescription() << endl;

			//Sets Shirt object's size
			ipdt >> item_data;

			dA_size_count[i] = item_data;

			shirt1.SetShirtSize(item_data);
			//cout << "This is the Shirt's size: " << shirt1.GetShirtSize() << endl;

			//Sets Shirt object's Quantity
			ipdt >> int_item_data;

			dA_quantities[i] = int_item_data;

			p->SetItemQuantity(int_item_data);
			//cout << "This is the Shirt's Quanitity: " << shirt1.GetItemQuantity() << endl;

			//Sets Shirt's object's Price
			ipdt >> double_item_data;

			double total_item_price;
			total_item_price = (int_item_data * double_item_data);
			dA_items_price[i] = total_item_price;

			total_price = total_price + (int_item_data * double_item_data);

			p->SetItemPrice(double_item_data);
			//cout << "This is the Shirt's Price: " << shirt1.GetItemPrice() << endl;

			cout << endl;

																	//FIXME Add an array to keep all shirts
		}

		else if (item_data == "SUPPLIES") {
			i = i + 1;
			//cout << "these are supplies" << endl;

			//This will create a new object that will use the Product's(base) virtual function
			//And override using the Shirt(derived) function.
			Product *p;
			OfficeSupplies supply1;
			p = &supply1;


			//Sets The Supplies' object's description
			string full_description;
			getline(ipdt, full_description);
			getline(ipdt, full_description);

			dA_description[i] = full_description;

			p->SetItemDescription(full_description);
			//cout << "This is the Shirt's description: " << supply1.GetItemDescription() << endl;

			//Sets The Size(count) of each Package
													//int int_item_data;
			ipdt >> item_data;

			dA_size_count[i] = item_data;

			supply1.SetSupplyCount(item_data);
			//cout << "This is the size of each Package: " << supply1.GetSupplyCount() << endl;


			//Sets Shirt object's Quantity
			ipdt >> int_item_data;
			//Saves from file and inserts into its respective array
			dA_quantities[i] = int_item_data;

			p->SetItemQuantity(int_item_data);
			//cout << "This is the Shirt's Quanitity: " << supply1.GetItemQuantity() << endl;

			//Sets Shirt's object's Price
			double double_item_data;
			ipdt >> double_item_data;

			//Saves the item's price with quanitity
			double total_item_price;
			total_item_price = (int_item_data * double_item_data);
			dA_items_price[i] = total_item_price;

			//Adds the total price
			total_price = total_price + (int_item_data * double_item_data);

			p->SetItemPrice(double_item_data);
			//cout << "This is the Supplies' Price: " << supply1.GetItemPrice() << endl;

			cout << endl;


		}

		else {
			cout << "Neither shirt or supplies" << endl;	//Tells user of odd input products
		}
	}

	//Prints the Receipt from the Register Derived class using Register's functions
	Product *pointer;
	Register Reciept1;
	pointer = &Reciept1;
	Reciept1.PrintReceipt();


	int j = 1;  //Change to 0 if i changes in while loop
	while (j <= i) {

		//Verifiers: Checks that values are correct
		//cout << "This is the " << j << " quantity: " << dA_quantities[j] << endl;
		//cout << "This is the " << j << " description: " << dA_description[j] << endl;			
		//cout << "This is the " << j << " size/count: " << dA_size_count[j] << endl;
		//cout << "This is the " << j << " total item price: " << dA_items_price[j] << endl;

		Reciept1.PrintReceipt2(dA_quantities[j], dA_size_count[j], dA_description[j],  dA_items_price[j]);

		j = j + 1;
	}

	Reciept1.PrintReceipt3(i, total_price); //Prints the total price and number of items purchased. Then prints a thank you at very end.



	ipdt.close();
	system("pause");
	return 0;
}
