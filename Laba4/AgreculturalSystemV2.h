#pragma once
#include "D:\”нивер\3 семестр\ќќѕиѕ\OOPaP 2 semester\Laba3\AgriculturalMachinery.h"
#include "D:\”нивер\3 семестр\ќќѕиѕ\OOPaP 2 semester\Laba3\Deal.h"
#include <map>
#include <set>

const unsigned COUNT_OF_MOST_PROFIT_DEALS = 5;

class AgreculturalSystemV2
{
public:
	void menu();

private:

	void addMachine_();
	void printMachinesInConsole_();
	void printMachinesInFile_();
	void findMachineByModel_();
	void printMachineInConsoleByType_();
	void sellMachine_();
	void printDealsInConsole_();
	void printDealsInFile_();
	void printFiveMostProfitDeals_();

    std::map<AgriculturalMachinery, int> machines_;
    std::multiset<Deal> deals_;
	std::set<Deal> mostProfiDeals_;
};

