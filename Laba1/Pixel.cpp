#include "Pixel.h"

Pixel::Pixel(unsigned short red, unsigned short green, unsigned short blue)
{
	red_ = red;
	green_ = green;
	blue_ = blue;
}

Pixel::Pixel()
{
	red_ = 0;
	green_ = 0;
	blue_ = 0;
}

void Pixel::setPixel(unsigned short red, unsigned short green, unsigned short blue)
{
	red_ = red;
	green_ = green;
	blue_ = blue;
}

unsigned short Pixel::getRed()
{
	return red_;
}

unsigned short Pixel::getGreen()
{
	return green_;
}

unsigned short Pixel::getBlue()
{
	return blue_;
}

void Pixel::generateRandom()
{
	red_ = rand() % 256;
	green_ = rand() % 256;
	blue_ = rand() % 256;
}
