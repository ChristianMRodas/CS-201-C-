#pragma once

#ifndef REGISTER_H
#define REGISTER_H

#include "PRODUCT.h"

class Register : public Product{
public:
	//Register::Register;

	//Array
	void print();

	void AddProduct();  //This will take an pointer

	//Splits the reciept into 3 parts. The first will printer the reciept header. The 2nd will print the products data. The 3rd will print the footer with a thank you.
	void PrintReceipt();
	void PrintReceipt2(int total_item_quantity, string total_item_size, string total_item_description, double total_item_price);
	void PrintReceipt3(int total_items, double total_prices);


private:



};









#endif