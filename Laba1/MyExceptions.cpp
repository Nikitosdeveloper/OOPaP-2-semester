#include "MyExceptions.h"

RangeException::RangeException(TypeRange type)
{
	type_ = type;
}

std::string RangeException::what()
{
	switch (type_)
	{
	case HEIGHT:
		return "Неверная высота";
	case WEIGHT:
		return "Неверная ширина";
		break;
	}
}

FormatException::FormatException(std::string wht)
{
	wht_ = wht;
}

std::string FormatException::what()
{
	return wht_;
}

void myTerminate()
{
	std::cout << "Вызвалась пользовательская функция terminate";
	exit(-1);
}
