#pragma once
#include "AgriculturalMachinery.h"

class Deal
{
public:

	Deal();
	Deal(AgriculturalMachinery machin, double costOfSell = 0);

	AgriculturalMachinery getMachine() const;
	double getCostOfSell() const;

	void setMachine(AgriculturalMachinery machine);
	void setCostOfSell(double cost);

	double getProfit() const;

	friend std::ostream& operator <<(std::ostream& ous, const Deal& deal);

	friend bool operator<(const Deal& a, const Deal& b);
	friend bool operator>(const Deal& a, const Deal& b);

	friend bool operator==(const Deal& a, const Deal& b);

private:
	AgriculturalMachinery machine_;
	double costOfSell_;
};

