#pragma once
#include <random>
#include <iostream>



class Pixel
{
public:


	Pixel(unsigned short red, unsigned short green, unsigned short blue);
	Pixel();
	void setPixel(unsigned short red, unsigned short green, unsigned short blue);
	unsigned short getRed();
	unsigned short getGreen();
	unsigned short getBlue();

	void generateRandom();

protected:
	unsigned short red_, green_, blue_;
};