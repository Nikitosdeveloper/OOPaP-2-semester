#include "File.h"




File::File(std::string filePath)
{
	filePath_ = filePath;
}

File::File()
{
	filePath_ = "";
}

std::string File::getFilePath()
{
	return filePath_;
}
