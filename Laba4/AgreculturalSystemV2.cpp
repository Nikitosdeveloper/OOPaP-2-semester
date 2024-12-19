#include "AgreculturalSystemV2.h"

void AgreculturalSystemV2::menu()
{
	while (true)
	{
		std::cout << "Выберете действие" << std::endl;
		std::cout << "1 - добавить сельхозмашину на склад" << std::endl;
		std::cout << "2 - вывести список машин на складе" << std::endl;
		std::cout << "3 - напечатать список машина на складе в файл" << std::endl;
		std::cout << "4 - найти сельхозмашину по модели" << std::endl;
		std::cout << "5 - вывести машины определённого типа" << std::endl;
		std::cout << "6 - продать сельхозмашину" << std::endl;
		std::cout << "7 - вывести список сделок" << std::endl;
		std::cout << "8 - напечатать список сделок в файл" << std::endl;
		std::cout << "9 - вывести 5 самых удачных сделок" << std::endl;
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
			sellMachine_();
			break;
		case 7:
			printDealsInConsole_();
			break;
		case 8:
			printDealsInFile_();
			break;
		case 9:
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

void AgreculturalSystemV2::addMachine_()
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

	if (machines_.find(machine) == machines_.end()) {
		machines_[machine] = 1;
	}
	else {
		machines_[machine] += 1;
	}
}

void AgreculturalSystemV2::printMachinesInConsole_()
{
	if (machines_.size() == 0) {
		std::cout << "Список сельхозмашин на складе пуст" << std::endl;
		return;
	}
	for (std::map<AgriculturalMachinery, int>::iterator it = machines_.begin(); it != machines_.end(); it++) {
		std::cout << it->first << "Количество: " << it->second << std::endl << std::endl;
	}
}

void AgreculturalSystemV2::printMachinesInFile_()
{
	std::string fileName;
	std::cout << "Введите имя файла" << std::endl;
	std::cin >> fileName;

	std::ofstream file(fileName, std::ios::out);

	if (machines_.size() == 0) {
		file << "Список сельхозмашин на складе пуст" << std::endl;
		file.close();
		return;
	}

	for (std::map<AgriculturalMachinery, int>::iterator it = machines_.begin(); it != machines_.end(); it++) {
		file << it->first << "Количество: " << it->second << std::endl << std::endl;
	}

	file.close();
}

void AgreculturalSystemV2::findMachineByModel_()
{
	std::cout << "Введите модель, которую хотите найти" << std::endl;
	std::string model;
	std::cin >> model;

	std::map<AgriculturalMachinery, int>::iterator it = std::find_if(machines_.begin(), machines_.end(), [model](std::pair<AgriculturalMachinery,int> x) {
		return x.first.getModel() == model;
		});

	if (it == machines_.end())
		std::cout << "Искомая сельхозмашина не найдена" << std::endl;
	else
		std::cout << it->first << "Количество: " << it->second << std::endl;;
}

void AgreculturalSystemV2::printMachineInConsoleByType_()
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
	for (std::map<AgriculturalMachinery,int>::iterator it = machines_.begin(); it != machines_.end(); it++) {
		if ((it->first).getType() == type) {
			std::cout << it->first << "Количество: " << it->second << std::endl;;
			isHaveMachine = true;
		}
	}
	if (!isHaveMachine)
		std::cout << "На складе нет сельхозмашин данного типа" << std::endl;

}

void AgreculturalSystemV2::sellMachine_()
{
	std::cout << "Введите модель, которую хотите продать" << std::endl;
	std::string model;
	std::cin >> model;

	std::map<AgriculturalMachinery,int>::iterator it = std::find_if(machines_.begin(), machines_.end(), [model](std::pair<AgriculturalMachinery, int> x) {
		return x.first.getModel() == model;
		});

	if (it == machines_.end()) {
		std::cout << "Данная модель не найдена" << std::endl;
		return;
	}

	std::cout << "Введите стоимость по которой хотите продать" << std::endl;
	int cost;
	std::cin >> cost;


	deals_.insert(Deal(it->first, cost));
	mostProfiDeals_.insert(Deal(it->first, cost));
	it->second--;
	if (!(it->second))
		machines_.erase(it);
	std::cout << "Сельхозмашнина успешно продана" << std::endl;
	std::cout << "Информацию о продаже можете посмотреть в списке продаж" << std::endl;
}

void AgreculturalSystemV2::printDealsInConsole_()
{
	if (deals_.size() == 0) {
		std::cout << "Список сделок пуст" << std::endl;
		return;
	}
	for (std::multiset<Deal>::iterator it = deals_.begin(); it != deals_.end(); it++) {
		std::cout << *it;
	}
}

void AgreculturalSystemV2::printDealsInFile_()
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
	for (std::multiset<Deal>::iterator it = deals_.begin(); it != deals_.end(); it++) {
		file << *it;
	}

	file.close();
}

void AgreculturalSystemV2::printFiveMostProfitDeals_()
{
	if (mostProfiDeals_.size() == 0) {
		std::cout << "Список сделок пуст" << std::endl;
		return;
	}
	for (std::set<Deal>::iterator it = mostProfiDeals_.begin(); it != mostProfiDeals_.end() ; it++) {
		std::cout << *it;
	}
}
