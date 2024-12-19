#pragma once
#include <fstream>
#include <string>

class Converting
{
public:

	Converting(std::string fileName, int convertationTimeInSecond);
	Converting();

	std::string getFileName();
	double getConvertationTimeInSecond();

	friend std::ifstream& operator >>(std::ifstream& file, Converting& conv);
	friend std::ofstream& operator <<(std::ofstream& file, Converting& conv);

private:
	std::string fileName_;
	double convertationTimeInSecond_;
};

class ConvertingBin {
public:
	ConvertingBin();
	ConvertingBin(std::string fileName, int convertationTimeInSecond);

	~ConvertingBin();

	const char* getFileName();

	double getConvertationTimeInSecond();


private:

	friend class Converting;

	char* fileName_;
	double convertationTimeInSecond_;
};