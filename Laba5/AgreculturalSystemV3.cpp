#include "AgreculturalSystemV3.h"

void AgreculturalSystemV3::menu()
{
	while (true)
	{
		std::cout << "�������� ��������" << std::endl;
		std::cout << "1 - �������� �������������" << std::endl;
		std::cout << "2 - ������� ������ �������" << std::endl;
		std::cout << "3 - ���������� ������ ������� � ����" << std::endl;
		std::cout << "4 - �������� �������� �� �����" << std::endl;
		std::cout << "5 - ���������� �� ������� ������" << std::endl;
		std::cout << "6 - ������������� ������ ��������" << std::endl;
		std::cout << "7 - ������� ������ �����" << std::endl;
		std::cout << "8 - ������� ������ �����" << std::endl;
		std::cout << "9 - ������� ������ �������" << std::endl;
		std::cout << "��� �����: " << std::endl;
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

	orders_.push(machine);
	std::cout << "��� ����� ��������" << std::endl;
}

void AgreculturalSystemV3::addSpaersSets_()
{
	std::string version;
	std::cout << "������� ������ ���������: ";
	std::cin >> version;

	SparesSets spares(version);

	spaersSetsList_.push_front(spares);

	std::cout << "�������� ������� ��������� �� �����" << std::endl;
}

void AgreculturalSystemV3::makeOrder_()
{
	std::cout << "������ �����: " << std::endl;
	std::cout << orders_.front() << std::endl;

	char choise;
	std::cout << "��������� ���� �����? " << std::endl;
	std::cout << "����� ������������ �������� ������ �� ������(y/n):" << std::endl;
	std::cin >> choise;
	if (choise == 'y') {
		if (spaersSetsList_.empty()) {
			std::cout << "�� ������ ��� �������" << std::endl;
		}
		else {
			std::cout << "����� ������������ ������ ������: ";
			std::cout << spaersSetsList_.front().getVersion() << std::endl;
			spaersSetsList_.pop_front();
			std::cout << "����� ������� ��������" << std::endl;
		}
	}

}

void AgreculturalSystemV3::pritnOrdersInConsole_()
{
	std::cout << "������ �������: " << std::endl;
	std::queue<AgriculturalMachinery> queueList(orders_);

	if (queueList.empty()) {
		std::cout << "����" << std::endl;
	}

	while (!queueList.empty())
	{
		std::cout << queueList.front() << std::endl;
		queueList.pop();
	}
}

void AgreculturalSystemV3::pritnSparesSetsInConsole_()
{
	std::cout << "������ �������: " << std::endl;
	std::deque<SparesSets> dequeList(spaersSetsList_);

	if (dequeList.empty()) {
		std::cout << "����" << std::endl;
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
	std::cout << "������� ��� �����" << std::endl;
	std::cin >> fileName;

	std::ofstream file(fileName, std::ios::out);

	std::queue<AgriculturalMachinery> queueList(orders_);
	file << "������ �������: " << std::endl;

	if (queueList.empty()) {
		std::cout << "����" << std::endl;
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
	std::cout << "������ �����: " << std::endl;
	std::cout << orders_.front() << std::endl;
	char choise;
	std::cout << "����������� ����� �� ������ (y/n):" << std::endl;
	
	std::cin >> choise;
	if (choise == 'y') {
		orders_.pop();
		std::cout << "��������� ����� �� ������" << std::endl;
	}

}

void AgreculturalSystemV3::utilizeSparesSets_()
{
	std::cout << "����� ������ ������: ";
	std::cout << spaersSetsList_.back().getVersion() << std::endl;
	char choise;
	std::cout << "������������� ��� �������� �� ������ (y/n):" << std::endl;

	std::cin >> choise;
	if (choise == 'y') {
		spaersSetsList_.pop_back();
		std::cout << "�������� ������� �������������" << std::endl;
	}
}

void AgreculturalSystemV3::printFirstOrder_()
{
	std::cout << "������ �����: ";
	std::cout << orders_.front();
}
