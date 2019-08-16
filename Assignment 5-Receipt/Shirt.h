#pragma once

#ifndef SHIRT_H
#define SHIRT_H

#include "PRODUCT.h"

class Shirt : public Product {
public:
	//Shirt::Shirt();

	void SetShirtSize(string SizeToSet);
	string GetShirtSize();

	void print();

	void CalculateTotal();

private:
	string shirtSize;


};


#endif