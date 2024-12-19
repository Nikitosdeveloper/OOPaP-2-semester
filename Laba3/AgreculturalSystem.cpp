#include "AgreculturalSystem.h"

void AgreculturalSystem::menu()
{
	while (true)
	{
		std::cout << "Выберете действие" << std::endl;
		std::cout << "1 - добавить сельхозмашину на склад" << std::endl;
		std::cout << "2 - вывести список машин на складе" << std::endl;
		std::cout << "3 - напечатать список машина на складе в файл" << std::endl;
		std::cout << "4 - найти сельхозмашину по модели" << std::endl;
		std::cout << "5 - вывести машины определённого типа" << std::endl;
		std::cout << "6 - отсортировать список машин на складе" << std::endl;
		std::cout << "7 - продать сельхозмашину" << std::endl;
		std::cout << "8 - вывести список сделок" << std::endl;
		std::cout << "9 - напечатать список сделок в файл" << std::endl;
		std::cout << "10 - вывести 5 самых удачных сделок" << std::endl;
		std::cout << "0 - выйти" << std::endl;
		std::cout << "Ваш выбор: " << std::endl;
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
	std::cout << "Выберете тип сельхозмашины" << std::endl;
	std::cout << "1 - Трактор" << std::endl;
	std::cout << "2 - Комбайн" << std::endl;
	std::cout << "3 - кукурузник" << std::endl;

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
	std::cout << "Введите название модели" << std::endl;
	std::cin >> model;

	double cost;
	std::cout << "Введите стоимость производства" << std::endl;
	std::cin >> cost;

	AgriculturalMachinery machine(type, model, cost);

	machines_.push_back(machine);
}

void AgreculturalSystem::printMachinesInConsole_()
{
	if (machines_.size() == 0) {
		std::cout << "Список сельхозмашин на складе пуст" << std::endl;
		return;
	}
	for (std::vector<AgriculturalMachinery>::iterator it = machines_.begin(); it != machines_.end(); it++) {
		std::cout << *it;
	}
}

void AgreculturalSystem::printMachinesInFile_()
{
	std::string fileName;
	std::cout << "Введите имя файла" <<std::endl;
	std::cin >> fileName;

	std::ofstream file(fileName, std::ios::out);

	if (machines_.size() == 0) {
		file << "Список сельхозмашин на складе пуст" << std::endl;
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
	std::cout << "Введите модель, которую хотите найти" << std::endl;
	std::string model;
	std::cin >> model;

	std::vector<AgriculturalMachinery>::iterator it = std::find_if(machines_.begin(), machines_.end(), [model](AgriculturalMachinery x) {
		return x.getModel() == model;
		});

	if (it == machines_.end())
		std::cout << "Искомая сельхозмашина не найдена" << std::endl;
	else
		std::cout << *it;
}

void AgreculturalSystem::printMachineInConsoleByType_()
{
	TypeMachinery type = TypeMachinery::NONE;
	std::cout << "Выберете тип сельхозмашины" << std::endl;
	std::cout << "1 - Трактор" << std::endl;
	std::cout << "2 - Комбайн" << std::endl;
	std::cout << "3 - кукурузник" << std::endl;

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
		std::cout << "На складе нет сельхозмашин данного типа" << std::endl;
	
}

void AgreculturalSystem::sortMachine_()
{
	std::cout << "Выберете параметр по которому можно сортировать сельхозмашины" << std::endl;
	std::cout << "1 - тип" << std::endl;
	std::cout << "2 - модель" << std::endl;
	std::cout << "3 - стоимость производства" << std::endl;

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

	std::cout << "Сортировка прошла успешно" << std::endl;
}

void AgreculturalSystem::sellMachine_()
{
	std::cout << "Введите модель, которую хотите продать" << std::endl;
	std::string model;
	std::cin >> model;

	std::vector<AgriculturalMachinery>::iterator it = std::find_if(machines_.begin(), machines_.end(), [model](AgriculturalMachinery x) {
		return x.getModel() == model;
		});

	if (it == machines_.end()) {
		std::cout << "Данная модель не найдена" << std::endl;
		return;
	}

	std::cout << "Введите стоимость по которой хотите продать" << std::endl;
	int cost;
	std::cin >> cost;

	
	deals_.push_back(Deal(*it, cost));
	machines_.erase(it);
	std::cout << "Сельхозмашнина успешно продана" << std::endl;
	std::cout << "Информацию о продаже можете посмотреть в списке продаж" << std::endl;
}

void AgreculturalSystem::printDealsInConsole_()
{
	if (deals_.size() == 0) {
		std::cout << "Список сделок пуст" << std::endl;
		return;
	}
	for (std::list<Deal>::iterator it = deals_.begin(); it != deals_.end(); it++) {
		std::cout << *it;
	}
}

void AgreculturalSystem::printDealsInFile_()
{
	std::string fileName;
	std::cout << "Введите имя файла" << std::endl;
	std::cin >> fileName;

	std::ofstream file(fileName, std::ios::out);

	if (deals_.size() == 0) {
		file << "Список сделок пуст" << std::endl;
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
		std::cout << "Список сделок пуст" << std::endl;
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
