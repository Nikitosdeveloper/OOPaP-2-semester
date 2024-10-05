#include "ConverterSystem.h"

void ConverterSystem::convert()
{
	std::cout << "����� ���� �� ������ �� ������ ��������������?" << std::endl;
	std::cout << "1 - jpg � png" << std::endl;
	std::cout << "2 - png � jpg" << std::endl;
	
	std::cout << "���� �����: ";
	int options = 0;

	std::cin >> options;

	if (std::cin.fail()) {
		std::cin.clear();
		std::cout << "�������� ����, ���������� ��� ���" << std::endl;
		std::cin.ignore(32657,'\n');
		convert();
		return;
	}

	switch (options)
	{
	case 1:
		convertJpgToPng();
		break;
	case 2:
		convertPngToJpg();
		break;
	default:
		std::cout << "�������� ����, ���������� ��� ���" << std::endl;
		convert(); break;
	}
	
}

void ConverterSystem::menu()
{
	while (true)
	{
		std::cout << "�������� ��������: " << std::endl;
		std::cout << "1 - �������������� ����" << std::endl;
		std::cout << "2 - �������� ������� �����������" << std::endl;
		std::cout << "3 - ����� �� ���������" << std::endl;

		int choice;
		std::cin >> choice;

		if (std::cin.bad()) {
			std::cout << "����������� ������!";
			exit(1);
		}

		if (!std::cin.good()) {
			std::cin.clear();
			std::cout << "�������� ����, ���������� ��� ���" << std::endl;
			std::cin.ignore(32657, '\n'); 
			if(std::cin.eof()){
				std::cout << "����� �����!"; exit(0);
			}
			
		}
		else
		{
			switch (choice)
			{
			case 1:
				convert();
				break;
			case 2:
				showHistoryOfConverting();
				break;
			case 3:
				std::cout << "������� �� ������������� ���������" << std::endl;
				exit(0);
			default:
				break;
			}
		}
	}
}

void ConverterSystem::convertJpgToPng()
{
	std::cout << "������� ���� ��� jpg �����: " << std::endl;
	std::string path;
	std::cin >> path;

	std::cout << "������� ������ �����: ";
	int height;
	std::cin >> height;
	std::cout << "������� ������ �����: ";
	int weight;
	std::cin >> weight;

	if (!std::cin.good()) {
		std::cin.clear();
		std::cout << std::endl << "�������� ����, ���������� ��� ���" << std::endl;
		std::cin.ignore(32657, '\n'); 
		if(std::cin.eof()){
			std::cout << "����� �����!"; exit(0);
		}
		convertJpgToPng();
		return;
	}

	try
	{
		JpgFile jpg(path, height, weight);

		std::cout << "������������ ��������� jpg ����" << std::endl;

		PngJpgConverter* converter = new PngJpgConverter;

		PngFile png = converter->convertJpgToPng(jpg);

		std::cout << "���� ������� �������������" << std::endl;

		historyOfConvertation_.push_back(Converting(png.getFilePath(), converter->getTimeOfLastConverting()));

		delete converter;
	}
	catch (std::exception&) {}
	catch (RangeException& excpt)
	{
		std::cout << excpt.what() << std::endl;
		convertJpgToPng();
	}
	catch (FormatException& expt) {
		std::cout << "���������� ������� ����" << std::endl;
		convertJpgToPng();
	}
	

	
}

void ConverterSystem::convertPngToJpg()
{
	std::cout << "������� ���� ��� png �����: " << std::endl;
	std::string path;
	std::cin >> path;
	std::cout << "������� ������ �����: ";
	int height;
	std::cin >> height;
	std::cout << "������� ������ �����: ";
	int weight;
	std::cin >> weight;

	if (!std::cin.good()) {
		std::cin.clear();
		std::cout << std::endl << "�������� ����, ���������� ��� ���" << std::endl;
		std::cin.ignore(32657, '\n'); 
		if(std::cin.eof()){
			std::cout << "����� �����!"; exit(0);
		}
		convertPngToJpg();
		return;
	}

	try
	{
		PngFile png(path, height, weight);

		std::cout << "������������ ��������� png ����" << std::endl;

		PngJpgConverter* converter = new PngJpgConverter;

		JpgFile jpg = converter->convertPngToJpg(png);

		std::cout << "���� ������� �������������" << std::endl;

		historyOfConvertation_.push_back(Converting(jpg.getFilePath(), converter->getTimeOfLastConverting()));

		delete converter;
	}
	catch (RangeException& excpt)
	{
		std::cout << excpt.what() << std::endl;
		convertPngToJpg();
	}
	catch (FormatException& expt) {
		std::cout << "���������� ������� ����" << std::endl;
		convertPngToJpg();
	}
}

void ConverterSystem::showHistoryOfConverting()
{
	calculateSizeFileName();
	calculateSizeTimeOfConvertation();

	showBorder();

	std::cout.setf(std::ios::left);

	std::cout << "|";

	std::cout.width(sizeFileName_);

	std::cout << "��� �����";
	std::cout << "|";

	std::cout.width(sizeTimeOfConvertation_);

	std::cout << "����� �����������";
	std::cout << "|" << std::endl;

	showBorder();

	
	for (int i = 0; i < historyOfConvertation_.size(); i++) {

		std::cout.setf(std::ios::left);
		
		std::cout << "|";

		std::cout.width(sizeFileName_);

		std::cout << historyOfConvertation_[i].getFileName();

		std::cout << "|";

		std::cout.width(sizeTimeOfConvertation_);

		std::cout << historyOfConvertation_[i].getConvertationTimeInSecond_();

		std::cout << "|";
		std::cout << std::endl;

		std::cout.unsetf(std::ios::left);

		showBorder();

	}
	

}

void ConverterSystem::showBorder()
{
	std::cout.setf(std::ios::right);
	std::cout.width(sizeFileName_+sizeTimeOfConvertation_+3);
	std::cout.fill('-');

	std::cout << '-';

	std::cout << std::endl;

	std::cout.fill(' ');
	std::cout.unsetf(std::ios::right);
}

int ConverterSystem::calculateLengthFilesName_()
{
	double maxLength = 0;

	for (auto converting : historyOfConvertation_) {
		maxLength = std::max(converting.getConvertationTimeInSecond_(),maxLength);
	}

	return maxLength;

}

void ConverterSystem::calculateSizeFileName()
{
	sizeFileName_ = strlen("��� �����");
	for (int i = 0; i < historyOfConvertation_.size(); i++) {
		sizeFileName_ = std::max(sizeFileName_, int(historyOfConvertation_[i].getFileName().size()));
	}
}

void ConverterSystem::calculateSizeTimeOfConvertation()
{
	sizeTimeOfConvertation_ = strlen("����� �����������");
	for (int i = 0; i < historyOfConvertation_.size(); i++) {
		sizeTimeOfConvertation_ = std::max(sizeTimeOfConvertation_, int(std::to_string(historyOfConvertation_[i].getConvertationTimeInSecond_()).size()));
	}
}
