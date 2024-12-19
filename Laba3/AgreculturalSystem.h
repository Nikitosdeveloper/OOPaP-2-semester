#pragma once
#include <list>
#include <vector>
#include <array>
#include <algorithm>
#include <iterator>
#include "AgriculturalMachinery.h"
#include "Deal.h"

const unsigned COUNT_OF_MOST_PROFIT_DEALS = 5;

class AgreculturalSystem
{
public:
	void menu();

private:

	void addMachine_();
	void printMachinesInConsole_();
	void printMachinesInFile_();
	void findMachineByModel_();
	void printMachineInConsoleByType_();
	void sortMachine_();
	void sellMachine_();
	void printDealsInConsole_();
	void printDealsInFile_();
	void printFiveMostProfitDeals_();

	void updateMostProfitDeals_();

	std::list<Deal> deals_;
	std::vector<AgriculturalMachinery> machines_;
	std::array<Deal, COUNT_OF_MOST_PROFIT_DEALS> mostProfiDeals_;
	int sizeOfmostProfiDeals_ = 0;
};

