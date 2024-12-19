#pragma once
#include <string>
#include <iostream>
#include <algorithm>
#include "MyExceptions.h"

class File
{
public:

	File(std::string filePath);
	File();

	std::string getFilePath();


protected:
	std::string filePath_;
};