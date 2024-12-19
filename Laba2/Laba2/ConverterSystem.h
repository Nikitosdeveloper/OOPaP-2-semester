#pragma once
#include "Converting.h"
#include "PngJpgConverter.h"
#include <iostream>
#include<iomanip>
#include <fstream>

class ConverterSystem
{
public:
	void convert();
	void menu();
private:
	void convertJpgToPng();
	void convertPngToJpg();
	void showHistoryOfConverting();

	void showBorder();

	int calculateLengthFilesName_();

	void calculateSizeFileName();
	void calculateSizeTimeOfConvertation();

	bool readHistoryOfConvertationFromFile();

	std::vector<Converting> historyOfConvertation_;

	int sizeFileName_ = 0, sizeTimeOfConvertation_ = 0;
};