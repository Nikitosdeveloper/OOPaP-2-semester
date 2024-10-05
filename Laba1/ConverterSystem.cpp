#include "ConverterSystem.h"

void ConverterSystem::convert()
{
	std::cout << "Какой файл из какого вы будете конвертировать?" << std::endl;
	std::cout << "1 - jpg в png" << std::endl;
	std::cout << "2 - png в jpg" << std::endl;
	
	std::cout << "Ваши выбор: ";
	int options = 0;

	std::cin >> options;

	if (std::cin.fail()) {
		std::cin.clear();
		std::cout << "Неверный ввод, попробуйте ещё раз" << std::endl;
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
		std::cout << "Неверный ввод, попробуйте ещё раз" << std::endl;
		convert(); break;
	}
	
}

void ConverterSystem::menu()
{
	while (true)
	{
		std::cout << "Выберете действие: " << std::endl;
		std::cout << "1 - Конвертировать файл" << std::endl;
		std::cout << "2 - Показать историю конвертаций" << std::endl;
		std::cout << "3 - Выйти из программы" << std::endl;

		int choice;
		std::cin >> choice;

		if (std::cin.bad()) {
			std::cout << "Критическая ошибка!";
			exit(1);
		}

		if (!std::cin.good()) {
			std::cin.clear();
			std::cout << "Неверный ввод, попробуйте ещё раз" << std::endl;
			std::cin.ignore(32657, '\n'); 
			if(std::cin.eof()){
				std::cout << "Конец файла!"; exit(0);
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
				std::cout << "Спасибо за использование программы" << std::endl;
				exit(0);
			default:
				break;
			}
		}
	}
}

void ConverterSystem::convertJpgToPng()
{
	std::cout << "Введите путь для jpg файла: " << std::endl;
	std::string path;
	std::cin >> path;

	std::cout << "Введите высоту файла: ";
	int height;
	std::cin >> height;
	std::cout << "Введите ширину файла: ";
	int weight;
	std::cin >> weight;

	if (!std::cin.good()) {
		std::cin.clear();
		std::cout << std::endl << "Неверный ввод, попробуйте ещё раз" << std::endl;
		std::cin.ignore(32657, '\n'); 
		if(std::cin.eof()){
			std::cout << "Конец файла!"; exit(0);
		}
		convertJpgToPng();
		return;
	}

	try
	{
		JpgFile jpg(path, height, weight);

		std::cout << "Сгенерирован рандомный jpg файл" << std::endl;

		PngJpgConverter* converter = new PngJpgConverter;

		PngFile png = converter->convertJpgToPng(jpg);

		std::cout << "Файл успешно конвертирован" << std::endl;

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
		std::cout << "Невозможно создать файл" << std::endl;
		convertJpgToPng();
	}
	

	
}

void ConverterSystem::convertPngToJpg()
{
	std::cout << "Введите путь для png файла: " << std::endl;
	std::string path;
	std::cin >> path;
	std::cout << "Введите высоту файла: ";
	int height;
	std::cin >> height;
	std::cout << "Введите ширину файла: ";
	int weight;
	std::cin >> weight;

	if (!std::cin.good()) {
		std::cin.clear();
		std::cout << std::endl << "Неверный ввод, попробуйте ещё раз" << std::endl;
		std::cin.ignore(32657, '\n'); 
		if(std::cin.eof()){
			std::cout << "Конец файла!"; exit(0);
		}
		convertPngToJpg();
		return;
	}

	try
	{
		PngFile png(path, height, weight);

		std::cout << "Сгенерирован рандомный png файл" << std::endl;

		PngJpgConverter* converter = new PngJpgConverter;

		JpgFile jpg = converter->convertPngToJpg(png);

		std::cout << "Файл успешно конвертирован" << std::endl;

		historyOfConvertation_.push_back(Converting(jpg.getFilePath(), converter->getTimeOfLastConverting()));

		delete converter;
	}
	catch (RangeException& excpt)
	{
		std::cout << excpt.what() << std::endl;
		convertPngToJpg();
	}
	catch (FormatException& expt) {
		std::cout << "Невозможно создать файл" << std::endl;
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

	std::cout << "Имя файла";
	std::cout << "|";

	std::cout.width(sizeTimeOfConvertation_);

	std::cout << "Время конвертации";
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
	sizeFileName_ = strlen("Имя файла");
	for (int i = 0; i < historyOfConvertation_.size(); i++) {
		sizeFileName_ = std::max(sizeFileName_, int(historyOfConvertation_[i].getFileName().size()));
	}
}

void ConverterSystem::calculateSizeTimeOfConvertation()
{
	sizeTimeOfConvertation_ = strlen("Время конвертации");
	for (int i = 0; i < historyOfConvertation_.size(); i++) {
		sizeTimeOfConvertation_ = std::max(sizeTimeOfConvertation_, int(std::to_string(historyOfConvertation_[i].getConvertationTimeInSecond_()).size()));
	}
}
