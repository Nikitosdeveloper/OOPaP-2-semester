#pragma once
#include <string>
#include <iostream>

enum TypeRange
{
	HEIGHT,
	WEIGHT
};

class RangeException {
public:
	RangeException(TypeRange type);

	std::string what();
private:
	TypeRange type_;
};

class FormatException {
public:

	FormatException(std::string wht);
	std::string what();
private:
	std::string wht_;
};

void myTerminate();