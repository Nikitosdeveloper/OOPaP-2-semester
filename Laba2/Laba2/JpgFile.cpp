#include "JpgFile.h"




JpgFile::JpgFile(std::string filePath, int height, int weight) : ImageFile(filePath, height, weight)
{

	try
	{
		std::reverse(filePath.begin(), filePath.end());
		if (!(filePath[0] == 'g' && filePath[1] == 'p' && filePath[2] == 'j' && filePath[3] == '.')) {
			throw FormatException("Неверный формат файла");
		}
	}
	catch (FormatException& excpt)
	{
		std::cout << excpt.what() << std::endl;
		throw FormatException(excpt.what());
	}

	image_ = new Pixel * [height_];
	for (int i = 0; i < height_; i++) {

		try
		{
			image_[i] = new Pixel[weight_];
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

JpgFile::JpgFile(const JpgFile& obj)
{
	height_ = obj.height_;
	weight_ = obj.weight_;

	filePath_ = obj.filePath_;

	image_ = new Pixel * [height_];
	for (int i = 0; i < height_; i++) {
		image_[i] = new Pixel[weight_];
		for (int j = 0; j < weight_; j++) {
			image_[i][j] = obj.image_[i][j];
		}
	}
}

JpgFile::JpgFile() : ImageFile()
{

	image_ = nullptr;
}

JpgFile::~JpgFile()
{
	for (int i = 0; i < height_; i++) {
		delete[] image_[i];
	}
	delete image_;
}

JpgFile JpgFile::operator=(const JpgFile& obj)
{
	height_ = obj.height_;
	weight_ = obj.weight_;

	image_ = new Pixel * [height_];
	for (int i = 0; i < height_; i++) {
		image_[i] = new Pixel[weight_];
		for (int j = 0; j < weight_; j++) {
			image_[i][j] = obj.image_[i][j];
		}
	}

	return *this;
}
