#pragma once
#include "Pixel.h"

class AlphaPixel :
    public Pixel
{
public:

    AlphaPixel(unsigned short red, unsigned short green, unsigned short blue, unsigned short alpha = 0);
    AlphaPixel();
    AlphaPixel(Pixel px);

    void setPixel(unsigned short red, unsigned short green, unsigned short blue, unsigned short alpha = 0);

    unsigned short getAlpha();

    AlphaPixel operator=(Pixel px);

    void generateRandom();

private:
    unsigned short alpha_;
};

