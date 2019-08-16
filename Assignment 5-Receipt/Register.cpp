#include <iostream>
using namespace std;

#include "Register.h"

void Register::print() {
	//cout << "Printing the full receipt" << endl;
}

void Register::AddProduct() {
	//cout << "adding products" << endl;


}

void Register::PrintReceipt() {
	cout << "****************************************" << endl;
	cout << "*            UMKC BOOKSTORE            *" << endl;
	cout << "****************************************" << endl;
	cout << endl;
	cout << "Qty Description                Total   *" << endl;
	cout << "___ __________________________ _________" << endl;
	//This is where we will print the items off the array using setw() Remember is wierd so from right spaces


}

void Register::PrintReceipt2(int total_item_quantity, string total_item_size, string total_item_description, double total_item_price) {

	cout << "  " << total_item_quantity << " " << total_item_description << total_item_size << " "  << "          " << total_item_price << endl;

}

void Register::PrintReceipt3(int total_items, double total_prices) {
	cout << endl;
	cout << "Grand total: $" << total_prices << endl;   //Add Total Price here
	cout << "Items sold:  " << total_items << endl;    //Add all items bought here
	cout << endl;
	cout << "* Thank you for shopping at our store! *" << endl;
}
