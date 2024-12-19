#pragma once
#include <iostream>
#include <fstream>

enum class TypeMachinery{
	NONE,
	TRACTOR,
	COMBINE,
	CORN_PLANE
};

class AgriculturalMachinery
{
public:
	AgriculturalMachinery();

	AgriculturalMachinery(TypeMachinery type, std::string model, double costOfProduction);


	TypeMachinery getType() const;
	std::string getModel() const;
	double getCostOfProduction() const;

	void setType(TypeMachinery type);
	void setModel(std::string model);
	void setCostOfProduction(double cost);

	friend std::ostream& operator <<(std::ostream& ous, const AgriculturalMachinery& mach);
	friend std::ofstream& operator <<(std::ofstream& ous, const AgriculturalMachinery& mach);

	friend bool operator<(const AgriculturalMachinery& a, const AgriculturalMachinery& b);
	friend bool operator>(const AgriculturalMachinery& a, const AgriculturalMachinery& b);

	friend bool operator==(const AgriculturalMachinery& a, const AgriculturalMachinery& b);

private:
	TypeMachinery type_;
	std::string model_;
	double costOfProduction_;

};

bool machineComparatorType(AgriculturalMachinery a, AgriculturalMachinery b);
bool machineComparatorModel(AgriculturalMachinery a, AgriculturalMachinery b);
bool machineComparatorCost(AgriculturalMachinery a, AgriculturalMachinery b);


