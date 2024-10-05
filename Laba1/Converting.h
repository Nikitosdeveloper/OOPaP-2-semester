#pragma once
#include <string>

class Converting
{
public:

	Converting(std::string fileName, int convertationTimeInSecond);

	std::string getFileName();
	double getConvertationTimeInSecond_();

private:
	std::string fileName_;
	double convertationTimeInSecond_;
};

