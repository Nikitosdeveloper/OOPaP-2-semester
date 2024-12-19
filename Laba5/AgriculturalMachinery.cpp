#include "AgriculturalMachinery.h"

AgriculturalMachinery::AgriculturalMachinery()
{
	type_ = TypeMachinery::NONE;
	model_ = "";
	costOfProduction_ = 0;
}

AgriculturalMachinery::AgriculturalMachinery(TypeMachinery type, std::string model, double costOfProduction)
{
	type_ = type;
	model_ = model;
	costOfProduction_ = costOfProduction;
}


TypeMachinery AgriculturalMachinery::getType()  const
{
	return type_;
}

std::string AgriculturalMachinery::getModel() const
{
	return model_;
}

double AgriculturalMachinery::getCostOfProduction() const
{
	return costOfProduction_;
}

void AgriculturalMachinery::setType(TypeMachinery type)
{
	type_ = type;
}

void AgriculturalMachinery::setModel(std::string model)
{
	model_ = model;
}

void AgriculturalMachinery::setCostOfProduction(double cost)
{
	if (cost < 0)
		std::cerr << "The cost cannot be negative" << std::endl;
	else
		costOfProduction_ = cost;
}

bool machineComparatorType(AgriculturalMachinery a, AgriculturalMachinery b)
{
	return a.getType() > b.getType();
}

bool machineComparatorModel(AgriculturalMachinery a, AgriculturalMachinery b)
{
	return a.getModel() > b.getModel();
}

bool machineComparatorCost(AgriculturalMachinery a, AgriculturalMachinery b)
{
	return a.getCostOfProduction() > b.getCostOfProduction();
}

std::ostream& operator<<(std::ostream& ous, const AgriculturalMachinery& mach)
{
	ous << "���: ";
	switch (mach.type_)
	{
	case TypeMachinery::TRACTOR:
		ous << "�������";
		break;
	case TypeMachinery::COMBINE:
		ous << "�������";
		break;
	case TypeMachinery::CORN_PLANE:
		ous << "���������";
		break;
	default:
		ous << "����������";
		break;
	}
	ous << std::endl;
	ous << "������: ";
	ous << mach.model_ << std::endl;
	ous << "��������� ������������: ";
	ous << mach.costOfProduction_ << std::endl;
	ous << std::endl;

	return ous;
}

std::ofstream& operator<<(std::ofstream& ous, const AgriculturalMachinery& mach) {
	ous << "���: ";

	switch (mach.type_) {
	case TypeMachinery::TRACTOR:
		ous << "�������";
		break;
	case TypeMachinery::COMBINE:
		ous << "�������";
		break;
	case TypeMachinery::CORN_PLANE:
		ous << "����������";
		break;
	default:
		ous << "�����������";
		break;
	}

	ous << std::endl;
	ous << "������: " << mach.model_ << std::endl;
	ous << "��������� ������������: " << mach.costOfProduction_ << std::endl;
	ous << std::endl;

	return ous;
}

bool operator<(const AgriculturalMachinery& a, const AgriculturalMachinery& b)
{
	if (a.type_ == b.type_) {
		if (a.model_ == b.model_) {
			return a.costOfProduction_ < b.costOfProduction_;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

bool operator>(const AgriculturalMachinery& a, const AgriculturalMachinery& b)
{
	if (a.type_ == b.type_) {
		if (a.model_ == b.model_) {
			return a.costOfProduction_ < b.costOfProduction_;
		}
		else {
			return true;
		}
	}
	else {
		return true;
	}
}

bool operator==(const AgriculturalMachinery& a, const AgriculturalMachinery& b)
{
	return a.model_ == b.model_ && a.type_ == b.type_ && a.costOfProduction_ == b.costOfProduction_;
}
