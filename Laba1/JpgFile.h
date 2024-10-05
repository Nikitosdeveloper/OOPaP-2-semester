#pragma once
#include "ImageFile.h"
#include "Pixel.h"

class JpgFile :
    public ImageFile
{
public:
    JpgFile(std::string filePath, int height, int weight);
    JpgFile(const JpgFile& obj);

    JpgFile();

    ~JpgFile();

    JpgFile operator=(const JpgFile& obj);

private:
    Pixel** image_;

    friend class PngJpgConverter;
};

