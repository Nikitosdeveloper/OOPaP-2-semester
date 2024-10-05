#include "PngFile.h"

PngFile::PngFile(std::string filePath, int height, int weight) : ImageFile(filePath,height,weight)
{
	

	try
	{
		std::reverse(filePath.begin(), filePath.end());
		if (!(filePath[0] == 'g' && filePath[1] == 'n' && filePath[2] == 'p' && filePath[3] == '.')) {
			throw FormatException("Неверный формат файла");
		}
	}
	catch (FormatException& excpt)
	{
		std::cout << excpt.what() << std::endl;
		throw FormatException(excpt.what());
	}

	image_ = new AlphaPixel * [height_];
	for (int i = 0; i < height_; i++) {

		try
		{
			image_[i] = new AlphaPixel[weight_];
		}
		catch (std::bad_alloc& exp)
		{
			std::cout << exp.what() << std::endl;
			throw "BadAlloc";
		}

		for (int j = 0; j < weight_; j++) {
			image_[i][j].generateRandom();
		}
	}
}

PngFile::PngFile(const PngFile& obj)
{
	height_ = obj.height_;
	weight_ = obj.weight_;

	filePath_ = obj.filePath_;

	image_ = new AlphaPixel * [height_];
	for (int i = 0; i < height_; i++) {
		image_[i] = new AlphaPixel[weight_];
		for (int j = 0; j < weight_; j++) {
			image_[i][j] = obj.image_[i][j];
		}
	}
}

PngFile::PngFile() : ImageFile()
{
	image_ = nullptr;
}

PngFile::~PngFile()
{
	for (int i = 0; i < height_; i++) {
		delete[] image_[i];
	}
	delete image_;
}

PngFile PngFile::operator=(const PngFile& obj)
{
	height_ = obj.height_;
	weight_ = obj.weight_;

	image_ = new AlphaPixel * [height_];
	for (int i = 0; i < height_; i++) {
		image_[i] = new AlphaPixel[weight_];
		for (int j = 0; j < weight_; j++) {
			image_[i][j] = obj.image_[i][j];
		}
	}

	return *this;
}
