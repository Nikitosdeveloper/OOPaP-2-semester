#include "ImageFile.h"

ImageFile::ImageFile(std::string filePath, int height, int weight) : File(filePath)
{
	
	if (height < 0)
		throw RangeException(TypeRange::HEIGHT);

	height_ = height;
	weight_ = weight;
	
}

ImageFile::ImageFile() : File()
{
	height_ = weight_ = 0;
}
