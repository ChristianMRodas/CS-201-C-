#include <iostream>
using namespace std;

#include "OfficeSupplies.h"

void OfficeSupplies::print() {
	cout << "Printing office supplies used";
}

void OfficeSupplies::SetSupplyCount(string SupplyToSet) {
	suppliesCount = SupplyToSet;
}

string OfficeSupplies::GetSupplyCount() {
	return suppliesCount;
}