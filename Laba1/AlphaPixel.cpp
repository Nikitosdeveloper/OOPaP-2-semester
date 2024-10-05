#include "AlphaPixel.h"

AlphaPixel::AlphaPixel(unsigned short red, unsigned short green, unsigned short blue, unsigned short alpha) : Pixel(red,green,blue)
{
	alpha_ = alpha;
}

AlphaPixel::AlphaPixel() : Pixel()
{
	alpha_ = 0;
}

AlphaPixel::AlphaPixel(Pixel px)
{
	red_ = px.getRed();
	blue_ = px.getBlue();
	green_ = px.getGreen();
	alpha_ = 255;
}

void AlphaPixel::setPixel(unsigned short red, unsigned short green, unsigned short blue, unsigned short alpha)
{
	Pixel::setPixel(red, green, blue);
	alpha_ = alpha;
}

unsigned short AlphaPixel::getAlpha()
{
	return alpha_;
}

AlphaPixel AlphaPixel::operator=(Pixel px)
{
	red_ = px.getRed();
	blue_ = px.getBlue();
	green_ = px.getGreen();
	alpha_ = 255;
	return *this;
}

void AlphaPixel::generateRandom()
{
	Pixel::generateRandom();
	alpha_ = rand() % 256;
}
