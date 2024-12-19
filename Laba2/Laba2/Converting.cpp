#include "Converting.h"
#include <iostream>



Converting::Converting(std::string fileName, int convertationTimeInSecond)
{
	fileName_ = fileName;
	convertationTimeInSecond_ = convertationTimeInSecond;
}


Converting::Converting()
{
	fileName_ = "";
	convertationTimeInSecond_ = 0;
}

std::string Converting::getFileName()
{
	return fileName_;
}

double Converting::getConvertationTimeInSecond()
{
	return convertationTimeInSecond_;
}

std::ifstream& operator>>(std::ifstream& file, Converting& conv)
{
	int fileNameLength;
	file.read((char*) (&fileNameLength), sizeof(fileNameLength));

	char* fileName = new char[fileNameLength + 1];
	file.read(fileName, fileNameLength);
	fileName[fileNameLength] = '\0';

	double convertationTime;
	file.read((char*)(&convertationTime), sizeof(convertationTime));
	conv = Converting(std::string(fileName), convertationTime);
	delete[] fileName;

	return file;
}

std::ofstream& operator<<(std::ofstream& file, Converting& conv)
{
	int fileNameLength = conv.getFileName().size();

	file.write((const char*)(&fileNameLength), sizeof(fileNameLength));
	file.write((const char*)conv.getFileName().c_str(), fileNameLength);
	double time = conv.getConvertationTimeInSecond();
	file.write((const char*)&time, sizeof(conv.getConvertationTimeInSecond()));



	return file;
}

ConvertingBin::ConvertingBin()
{
	fileName_ = new char[1];
	fileName_[0] = ' ';
	convertationTimeInSecond_ = 0;
}

ConvertingBin::ConvertingBin(std::string fileName, int convertationTimeInSecond)
{
	fileName_ = new char[fileName.size() + 1];
	strcpy_s(fileName_, fileName.size()+1, fileName.c_str());

	convertationTimeInSecond_ = convertationTimeInSecond;
}

ConvertingBin::~ConvertingBin()
{
	delete fileName_;
}

const char* ConvertingBin::getFileName()
{
	return fileName_;
}

double ConvertingBin::getConvertationTimeInSecond()
{
	return convertationTimeInSecond_;
}
