#pragma once
#include <queue>
#include <stack>
#include <deque>
#include "AgriculturalMachinery.h"
#include "SparesSets.h"

class AgreculturalSystemV3 {
public:

	void menu();
private:

	void addOrders_();
	void addSpaersSets_();
	void makeOrder_();
	void pritnOrdersInConsole_();
	void pritnSparesSetsInConsole_();
	void printOrdersInFile_();
	void refuseOrders_();
	void utilizeSparesSets_();
	void printFirstOrder_();

	std::queue<AgriculturalMachinery*> orders_;
	std::deque<SparesSets> spaersSetsList_;
};