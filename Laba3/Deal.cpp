#include "Deal.h"

Deal::Deal()
{
	machine_ = AgriculturalMachinery();
	costOfSell_ = 0;
}

Deal::Deal(AgriculturalMachinery machine = AgriculturalMachinery(), double costOfSell)
{
	machine_ = machine;
	costOfSell_ = costOfSell;
}

AgriculturalMachinery Deal::getMachine() const
{
	return machine_;
}

double Deal::getCostOfSell() const
{
	return costOfSell_;
}

void Deal::setMachine(AgriculturalMachinery machine)
{
	machine_ = machine;
}

void Deal::setCostOfSell(double cost)
{

	if (cost < 0)
		std::cerr << "The cost cannot be negative" << std::endl;
	else
		costOfSell_ = cost;
}

double Deal::getProfit() const
{
	return costOfSell_ - machine_.getCostOfProduction();
}

std::ostream& operator<<(std::ostream& ous,const Deal& deal)
{
	ous << "Модель: " << deal.machine_.getModel() << std::endl;
	ous << "Стоимость продажи: " << deal.costOfSell_ << std::endl;
	ous << "Прибыль: " << deal.getProfit() << std::endl;
	ous << std::endl;
	return ous;
}

bool operator<(const Deal& a, const Deal& b)
{
	if (a.machine_ == b.machine_)
		return a.costOfSell_ < b.costOfSell_;
	return a.machine_ < b.machine_;
}

bool operator>(const Deal& a, const Deal& b)
{
	if (a.machine_ == b.machine_)
		return a.costOfSell_ < b.costOfSell_;
	return a.machine_ < b.machine_;
}

bool operator==(const Deal& a, const Deal& b)
{
	return (a.machine_ == b.machine_) && (a.costOfSell_ == b.costOfSell_);
}
