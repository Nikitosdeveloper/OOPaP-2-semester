#include "AgreculturalSystem.h"

void AgreculturalSystem::menu()
{
	while (true)
	{
		std::cout << "�������� ��������" << std::endl;
		std::cout << "1 - �������� ������������� �� �����" << std::endl;
		std::cout << "2 - ������� ������ ����� �� ������" << std::endl;
		std::cout << "3 - ���������� ������ ������ �� ������ � ����" << std::endl;
		std::cout << "4 - ����� ������������� �� ������" << std::endl;
		std::cout << "5 - ������� ������ ������������ ����" << std::endl;
		std::cout << "6 - ������������� ������ ����� �� ������" << std::endl;
		std::cout << "7 - ������� �������������" << std::endl;
		std::cout << "8 - ������� ������ ������" << std::endl;
		std::cout << "9 - ���������� ������ ������ � ����" << std::endl;
		std::cout << "10 - ������� 5 ����� ������� ������" << std::endl;
		std::cout << "0 - �����" << std::endl;
		std::cout << "��� �����: " << std::endl;
		int choice;
		std::cin >> choice;

		switch (choice)
		{
		case 1:
			addMachine_();
			break;
		case 2:
			printMachinesInConsole_();
			break;
		case 3:
			printMachinesInFile_();
			break;
		case 4:
			findMachineByModel_();
			break;
		case 5:
			printMachineInConsoleByType_();
			break;
		case 6:
			sortMachine_();
			break;
		case 7:
			sellMachine_();
			break;
		case 8:
			printDealsInConsole_();
			break;
		case 9:
			printDealsInFile_();
			break;
		case 10:
			printFiveMostProfitDeals_();
			break;
		case 0:
			exit(0);
			break;
		default:
			break;
		}
	}	
}

void AgreculturalSystem::addMachine_()
{

	TypeMachinery type = TypeMachinery::NONE;
	std::cout << "�������� ��� �������������" << std::endl;
	std::cout << "1 - �������" << std::endl;
	std::cout << "2 - �������" << std::endl;
	std::cout << "3 - ����������" << std::endl;

	int choise;
	std::cin >> choise;

	switch (choise)
	{
	case 1:
		type = TypeMachinery::TRACTOR;
		break;
	case 2:
		type = TypeMachinery::COMBINE;
		break;
	case 3:
		type = TypeMachinery::CORN_PLANE;
		break;
	default:
		break;
	}

	std::string model;
	std::cout << "������� �������� ������" << std::endl;
	std::cin >> model;

	double cost;
	std::cout << "������� ��������� ������������" << std::endl;
	std::cin >> cost;

	AgriculturalMachinery machine(type, model, cost);

	machines_.push_back(machine);
}

void AgreculturalSystem::printMachinesInConsole_()
{
	if (machines_.size() == 0) {
		std::cout << "������ ������������ �� ������ ����" << std::endl;
		return;
	}
	for (std::vector<AgriculturalMachinery>::iterator it = machines_.begin(); it != machines_.end(); it++) {
		std::cout << *it;
	}
}

void AgreculturalSystem::printMachinesInFile_()
{
	std::string fileName;
	std::cout << "������� ��� �����" <<std::endl;
	std::cin >> fileName;

	std::ofstream file(fileName, std::ios::out);

	if (machines_.size() == 0) {
		file << "������ ������������ �� ������ ����" << std::endl;
		file.close();
		return;
	}

	for (std::vector<AgriculturalMachinery>::iterator it = machines_.begin(); it != machines_.end(); it++) {
		file << *it;
	}

	file.close();
}

void AgreculturalSystem::findMachineByModel_()
{
	std::cout << "������� ������, ������� ������ �����" << std::endl;
	std::string model;
	std::cin >> model;

	std::vector<AgriculturalMachinery>::iterator it = std::find_if(machines_.begin(), machines_.end(), [model](AgriculturalMachinery x) {
		return x.getModel() == model;
		});

	if (it == machines_.end())
		std::cout << "������� ������������� �� �������" << std::endl;
	else
		std::cout << *it;
}

void AgreculturalSystem::printMachineInConsoleByType_()
{
	TypeMachinery type = TypeMachinery::NONE;
	std::cout << "�������� ��� �������������" << std::endl;
	std::cout << "1 - �������" << std::endl;
	std::cout << "2 - �������" << std::endl;
	std::cout << "3 - ����������" << std::endl;

	int choise;
	std::cin >> choise;

	switch (choise)
	{
	case 1:
		type = TypeMachinery::TRACTOR;
		break;
	case 2:
		type = TypeMachinery::COMBINE;
		break;
	case 3:
		type = TypeMachinery::CORN_PLANE;
		break;
	default:
		break;
	}
	bool isHaveMachine = false;
	for (std::vector<AgriculturalMachinery>::iterator it = machines_.begin(); it != machines_.end(); it++) {
		if (it->getType() == type) {
			std::cout << *it;
			isHaveMachine = true;
		}
	}
	if (!isHaveMachine)
		std::cout << "�� ������ ��� ������������ ������� ����" << std::endl;
	
}

void AgreculturalSystem::sortMachine_()
{
	std::cout << "�������� �������� �� �������� ����� ����������� �������������" << std::endl;
	std::cout << "1 - ���" << std::endl;
	std::cout << "2 - ������" << std::endl;
	std::cout << "3 - ��������� ������������" << std::endl;

	int choise;
	std::cin >> choise;

	switch (choise)
	{
	case 1:
		std::sort(machines_.begin(), machines_.end(), machineComparatorType);
		break;
	case 2:
		std::sort(machines_.begin(), machines_.end(), machineComparatorModel);
		break;
	case 3:
		std::sort(machines_.begin(), machines_.end(), machineComparatorCost);
		break;
	default:
		break;
	}

	std::cout << "���������� ������ �������" << std::endl;
}

void AgreculturalSystem::sellMachine_()
{
	std::cout << "������� ������, ������� ������ �������" << std::endl;
	std::string model;
	std::cin >> model;

	std::vector<AgriculturalMachinery>::iterator it = std::find_if(machines_.begin(), machines_.end(), [model](AgriculturalMachinery x) {
		return x.getModel() == model;
		});

	if (it == machines_.end()) {
		std::cout << "������ ������ �� �������" << std::endl;
		return;
	}

	std::cout << "������� ��������� �� ������� ������ �������" << std::endl;
	int cost;
	std::cin >> cost;

	
	deals_.push_back(Deal(*it, cost));
	machines_.erase(it);
	std::cout << "�������������� ������� �������" << std::endl;
	std::cout << "���������� � ������� ������ ���������� � ������ ������" << std::endl;
}

void AgreculturalSystem::printDealsInConsole_()
{
	if (deals_.size() == 0) {
		std::cout << "������ ������ ����" << std::endl;
		return;
	}
	for (std::list<Deal>::iterator it = deals_.begin(); it != deals_.end(); it++) {
		std::cout << *it;
	}
}

void AgreculturalSystem::printDealsInFile_()
{
	std::string fileName;
	std::cout << "������� ��� �����" << std::endl;
	std::cin >> fileName;

	std::ofstream file(fileName, std::ios::out);

	if (deals_.size() == 0) {
		file << "������ ������ ����" << std::endl;
		file.close();
		return;
	}
	for (std::list<Deal>::iterator it = deals_.begin(); it != deals_.end(); it++) {
		file << *it;
	}

	file.close();
}

void AgreculturalSystem::printFiveMostProfitDeals_()
{
	if (sizeOfmostProfiDeals_ == 0) {
		std::cout << "������ ������ ����" << std::endl;
		return;
	}
	updateMostProfitDeals_();
	for (int i = 0; i < sizeOfmostProfiDeals_; i++) {
		std::cout << mostProfiDeals_[i];
	}
}

void AgreculturalSystem::updateMostProfitDeals_()
{
	int count = COUNT_OF_MOST_PROFIT_DEALS;
	
	std::list<Deal> sortDeals = deals_;

	sortDeals.sort([](Deal x, Deal y) {
		return x.getProfit() > y.getProfit();
		});

 	for (std::list<Deal>::iterator it = sortDeals.begin(); it != sortDeals.end() && count; it++, count--) {
		mostProfiDeals_[COUNT_OF_MOST_PROFIT_DEALS - count] = *it;
	}

	sizeOfmostProfiDeals_ = COUNT_OF_MOST_PROFIT_DEALS - count;
}
