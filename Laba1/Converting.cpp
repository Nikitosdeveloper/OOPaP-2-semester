#include "Converting.h"

Converting::Converting(std::string fileName, int convertationTimeInSecond)
{
	fileName_ = fileName;
	convertationTimeInSecond_ = convertationTimeInSecond;
}

std::string Converting::getFileName()
{
	return fileName_;
}

double Converting::getConvertationTimeInSecond_()
{
	return convertationTimeInSecond_;
}
