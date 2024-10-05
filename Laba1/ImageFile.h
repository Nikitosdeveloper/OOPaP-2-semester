#pragma once
#include "File.h"
class ImageFile :
    public File
{
public:

    ImageFile(std::string filePath, int height, int weight);
    ImageFile();

protected:
    int height_, weight_;
};

