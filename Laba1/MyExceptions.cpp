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
		return "�������� ������";
	case WEIGHT:
		return "�������� ������";
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
	std::cout << "��������� ���������������� ������� terminate";
	exit(-1);
}
