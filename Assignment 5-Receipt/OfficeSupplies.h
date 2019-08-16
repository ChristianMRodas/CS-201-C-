#pragma once

#ifndef OFFICESUPPLIES_H
#define OFFICESUPPLIES_H

#include "PRODUCT.h"

class OfficeSupplies : public Product {
public:
	void print();

	void SetSupplyCount(string SupplyToSet);
	string GetSupplyCount();

private:
	string suppliesCount;


};









#endif
