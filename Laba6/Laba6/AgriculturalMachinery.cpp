#include "AgriculturalMachinery.h"

AgriculturalMachinery::AgriculturalMachinery()
{
	model_ = "";
	costOfProduction_ = 0;
}

AgriculturalMachinery::AgriculturalMachinery(std::string model, double costOfProduction)
{
	model_ = model;
	costOfProduction_ = costOfProduction;
}

std::string AgriculturalMachinery::getModel() const
{
	return model_;
}

double AgriculturalMachinery::getCostOfProduction() const
{
	return costOfProduction_;
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

std::unique_ptr<AgriculturalMachinery> AgriculturalMachinery::create(TypeMachinery type)
{
	switch (type) {
	case TypeMachinery::TRACTOR:
		return std::make_unique<Tractor>();
	case TypeMachinery::COMBINE:
		return std::make_unique<Combine>();
	case TypeMachinery::CORN_PLANE:
		return std::make_unique<CornPlane>();
	default:
		return nullptr;
	}
}

std::unique_ptr<AgriculturalMachinery> AgriculturalMachinery::create(TypeMachinery type, std::string model, double costOfProduction)
{
	switch (type) {
	case TypeMachinery::TRACTOR:
		return std::make_unique<Tractor>(model, costOfProduction);
	case TypeMachinery::COMBINE:
		return std::make_unique<Combine>(model, costOfProduction);
	case TypeMachinery::CORN_PLANE:
		return std::make_unique<CornPlane>(model, costOfProduction);
	default:
		return nullptr;
	}
}

std::ostream& operator<<(std::ostream& ous, const AgriculturalMachinery& mach)
{
	ous << "���: ";
	switch (mach.getType())
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

	switch (mach.getType()) {
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
	if (a.getType() == b.getType()) {
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
	if (a.getType() == b.getType()) {
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
	return a.model_ == b.model_ && a.getType() == b.getType() && a.costOfProduction_ == b.costOfProduction_;
}

Tractor::Tractor() : AgriculturalMachinery()
{
}

Tractor::Tractor(std::string model, double costOfProduction) : AgriculturalMachinery(model, costOfProduction)
{
}

std::unique_ptr<AgriculturalMachinery> Tractor::clone() const
{
	return std::make_unique<Tractor>(*this);
}

Combine::Combine() : AgriculturalMachinery()
{
}

Combine::Combine(std::string model, double costOfProduction) : AgriculturalMachinery(model, costOfProduction)
{
}

std::unique_ptr<AgriculturalMachinery> Combine::clone() const
{
	return std::make_unique<Combine>(*this);
}

CornPlane::CornPlane() : AgriculturalMachinery()
{
}

CornPlane::CornPlane(std::string model, double costOfProduction) : AgriculturalMachinery(model, costOfProduction)
{
}

std::unique_ptr<AgriculturalMachinery> CornPlane::clone() const
{
	return std::make_unique<CornPlane>(*this);
}

TypeMachinery Tractor::getType() const
{
	return TypeMachinery::TRACTOR;
}

TypeMachinery Combine::getType() const
{
	return TypeMachinery::COMBINE;
}

TypeMachinery CornPlane::getType() const
{
	return TypeMachinery::CORN_PLANE;
}
