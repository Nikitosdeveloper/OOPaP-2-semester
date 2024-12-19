#pragma once
#include "ImageFile.h"
#include "AlphaPixel.h"

class PngFile :
    public ImageFile
{
public:

    PngFile(std::string filePath, int height, int weight);

    PngFile(const PngFile& obj);

    PngFile();

    ~PngFile();

    PngFile operator=(const PngFile& obj);

private:
    AlphaPixel** image_;

    friend class PngJpgConverter;
};