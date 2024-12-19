#include "PngJpgConverter.h"




JpgFile PngJpgConverter::convertPngToJpg(PngFile file)
{
    JpgFile jpg(file.filePath_.erase(file.filePath_.find_first_of(".png")) + ".jpg", file.height_, file.weight_);

    for (int i = 0; i < file.height_; i++) {
        for (int j = 0; j < file.weight_; j++) {
            jpg.image_[i][j] = file.image_[i][j];
        }
    }
    timeOfLastConverting_ = file.height_ * file.weight_ /100;

    return jpg;
}

PngFile PngJpgConverter::convertJpgToPng(JpgFile file)
{
    PngFile png(file.filePath_.erase(file.filePath_.find_first_of(".jpg")) + ".png", file.height_, file.weight_);

    for (int i = 0; i < file.height_; i++) {
        for (int j = 0; j < file.weight_; j++) {
            png.image_[i][j] = file.image_[i][j];
        }
    }
     timeOfLastConverting_ = file.height_ * file.weight_ / 100;

    return png;
}

double PngJpgConverter::getTimeOfLastConverting()
{
    return timeOfLastConverting_;
}
