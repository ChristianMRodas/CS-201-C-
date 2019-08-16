#pragma once

#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>

class Product {
public:
	//Product::Product();			//Constucotr			//FIXME
	//Product(const Product& Product);
	//~Product::Product();		//Destrucotr

	void PrintItemName() const;

	virtual void print() = 0;
	//virtual void CalculateTotal();  //Not needed in program

	void SetItemName(string NameToSet);
	string GetItemName();

	void SetItemPrice(double PriceToSet);
	double GetItemPrice();

	void SetItemQuantity(int QuantityToSet);
	int GetItemQuantity();

	void SetItemDescription(string DescriptionToSet);
	string GetItemDescription();


private:
	string itemName;
	string itemDescription;
	int itemQuantity;
	double itemPrice;



};


#endif