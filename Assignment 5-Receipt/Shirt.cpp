#include <iostream>
using namespace std;

#include "Shirt.h"

void Shirt::SetShirtSize(string SizeToSet) {
	shirtSize = SizeToSet;
}

string Shirt::GetShirtSize() {
	return shirtSize;
}

void Shirt::print() {
	cout << "Prints shirts (derived)" << endl;
}

void Shirt::CalculateTotal() {
	cout << " Some maths for shirt size: ";
}