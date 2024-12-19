#pragma once
#include <iostream>
#include <fstream>

enum class TypeMachinery {
	NONE,
	TRACTOR,
	COMBINE,
	CORN_PLANE
};

class AgriculturalMachinery
{
public:
	AgriculturalMachinery();

	AgriculturalMachinery(std::string model, double costOfProduction);

	virtual std::unique_ptr<AgriculturalMachinery> clone() const = 0;


	virtual TypeMachinery getType() const = 0;
	std::string getModel() const;
	double getCostOfProduction() const;

	void setModel(std::string model);
	void setCostOfProduction(double cost);

	friend std::ostream& operator <<(std::ostream& ous, const AgriculturalMachinery& mach);
	friend std::ofstream& operator <<(std::ofstream& ous, const AgriculturalMachinery& mach);

	friend bool operator<(const AgriculturalMachinery& a, const AgriculturalMachinery& b);
	friend bool operator>(const AgriculturalMachinery& a, const AgriculturalMachinery& b);

	friend bool operator==(const AgriculturalMachinery& a, const AgriculturalMachinery& b);

	static std::unique_ptr<AgriculturalMachinery> create(TypeMachinery type);
	static std::unique_ptr<AgriculturalMachinery> create(TypeMachinery type, std::string model, double costOfProduction);

private:
	std::string model_;
	double costOfProduction_;

};

class Tractor : public AgriculturalMachinery {

public:

	Tractor();
	Tractor(std::string model, double costOfProduction);

	std::unique_ptr<AgriculturalMachinery> clone() const;

	TypeMachinery getType() const;
private:

};

class Combine : public AgriculturalMachinery {

public:

	Combine();
	Combine(std::string model, double costOfProduction);

	std::unique_ptr<AgriculturalMachinery> clone() const;

	TypeMachinery getType() const;
private:

};

class CornPlane : public AgriculturalMachinery {

public:

	CornPlane();
	CornPlane(std::string model, double costOfProduction);

	std::unique_ptr<AgriculturalMachinery> clone() const;

	TypeMachinery getType() const;
private:

};