#include "AgreculturalSystemV3.h"

void AgreculturalSystemV3::menu()
{
	while (true)
	{
		std::cout << "Выберете действие" << std::endl;
		std::cout << "1 - заказать сельхозмашину" << std::endl;
		std::cout << "2 - вывести список заказов" << std::endl;
		std::cout << "3 - напечатать список заказов в файл" << std::endl;
		std::cout << "4 - добавить запчасть на склад" << std::endl;
		std::cout << "5 - отказаться от первого заказа" << std::endl;
		std::cout << "6 - утилизировать старые запчасти" << std::endl;
		std::cout << "7 - вывести первый заказ" << std::endl;
		std::cout << "8 - сделать первый заказ" << std::endl;
		std::cout << "9 - вывести список деталей" << std::endl;
		std::cout << "Ваш выбор: " << std::endl;
		int choice;
		std::cin >> choice;

		switch (choice)
		{
		case 1:
			addOrders_();
			break;
		case 2:
			pritnOrdersInConsole_();
			break;
		case 3:
			printOrdersInFile_();
			break;
		case 4:
			addSpaersSets_();
			break;
		case 5:
			refuseOrders_();
			break;
		case 6:
			utilizeSparesSets_();
			break;
		case 7:
			printFirstOrder_();
			break;
		case 8:
			makeOrder_();
			break;
		case 9:
			pritnSparesSetsInConsole_();
			break;
		case 0:
			exit(0);
			break;
		default:
			break;
		}
	}
}

void AgreculturalSystemV3::addOrders_()
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

	orders_.push(machine);
	std::cout << "Ваш заказ добавлен" << std::endl;
}

void AgreculturalSystemV3::addSpaersSets_()
{
	std::string version;
	std::cout << "Введите версию запчастей: ";
	std::cin >> version;

	SparesSets spares(version);

	spaersSetsList_.push_front(spares);

	std::cout << "Запчасти успешно добавлены на склад" << std::endl;
}

void AgreculturalSystemV3::makeOrder_()
{
	std::cout << "Первый заказ: " << std::endl;
	std::cout << orders_.front() << std::endl;

	char choise;
	std::cout << "Выполнить этот заказ? " << std::endl;
	std::cout << "Будут использованы новейшие детали на складе(y/n):" << std::endl;
	std::cin >> choise;
	if (choise == 'y') {
		if (spaersSetsList_.empty()) {
			std::cout << "На складе нет деталей" << std::endl;
		}
		else {
			std::cout << "Будут использованы детали версии: ";
			std::cout << spaersSetsList_.front().getVersion() << std::endl;
			spaersSetsList_.pop_front();
			std::cout << "Заказ успешно выполнен" << std::endl;
		}
	}

}

void AgreculturalSystemV3::pritnOrdersInConsole_()
{
	std::cout << "Список заказов: " << std::endl;
	std::queue<AgriculturalMachinery> queueList(orders_);

	if (queueList.empty()) {
		std::cout << "Пуст" << std::endl;
	}

	while (!queueList.empty())
	{
		std::cout << queueList.front() << std::endl;
		queueList.pop();
	}
}

void AgreculturalSystemV3::pritnSparesSetsInConsole_()
{
	std::cout << "Список деталей: " << std::endl;
	std::deque<SparesSets> dequeList(spaersSetsList_);

	if (dequeList.empty()) {
		std::cout << "Пуст" << std::endl;
	}

	while (!dequeList.empty())
	{
		std::cout << dequeList.front() << std::endl;
		dequeList.pop_front();
	}
}

void AgreculturalSystemV3::printOrdersInFile_()
{
	std::string fileName;
	std::cout << "Введите имя файла" << std::endl;
	std::cin >> fileName;

	std::ofstream file(fileName, std::ios::out);

	std::queue<AgriculturalMachinery> queueList(orders_);
	file << "Список заказов: " << std::endl;

	if (queueList.empty()) {
		std::cout << "Пуст" << std::endl;
	}

	while (!queueList.empty())
	{
		file << queueList.front() << std::endl;
		queueList.pop();
	}

	file.close();
}

void AgreculturalSystemV3::refuseOrders_()
{
	std::cout << "Первый заказ: " << std::endl;
	std::cout << orders_.front() << std::endl;
	char choise;
	std::cout << "Подтвердите отказ от заказа (y/n):" << std::endl;
	
	std::cin >> choise;
	if (choise == 'y') {
		orders_.pop();
		std::cout << "Произошёл отказ от заказа" << std::endl;
	}

}

void AgreculturalSystemV3::utilizeSparesSets_()
{
	std::cout << "Самая старая версия: ";
	std::cout << spaersSetsList_.back().getVersion() << std::endl;
	char choise;
	std::cout << "Утилизировать эти запчасти со склада (y/n):" << std::endl;

	std::cin >> choise;
	if (choise == 'y') {
		spaersSetsList_.pop_back();
		std::cout << "Запчасти успешно утилизированы" << std::endl;
	}
}

void AgreculturalSystemV3::printFirstOrder_()
{
	std::cout << "Первый заказ: ";
	std::cout << orders_.front();
}
