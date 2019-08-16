#include <iostream>
using namespace std;

//The base class sets up the prototype functions that the derived class will use.

#include "Product.h"
#include <string>

void Product::PrintItemName() const {
}


void Product::SetItemName(string NameToSet) {
	itemName = NameToSet;
}													//Item Name
string Product::GetItemName() {
	return itemName;
}

void Product::SetItemPrice(double PriceToSet) {
	itemPrice = PriceToSet;
}													//Item Price
double Product::GetItemPrice() {
	return itemPrice;
}

void Product::SetItemQuantity(int QuantityToSet) {
	itemQuantity = QuantityToSet;
}													//Item Quantity
int Product::GetItemQuantity() {
	return itemQuantity;
}

void Product::SetItemDescription(string DescriptionToSet) {
	itemDescription = DescriptionToSet;
}													//Item Name
string Product::GetItemDescription() {
	return itemDescription;
}