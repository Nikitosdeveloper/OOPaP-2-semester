#pragma once
#include "PngFIle.h"
#include "JpgFile.h"

class PngJpgConverter
{
public:

	JpgFile convertPngToJpg(PngFile file);
	PngFile convertJpgToPng(JpgFile file);

	double getTimeOfLastConverting();

private:
	double timeOfLastConverting_;
};