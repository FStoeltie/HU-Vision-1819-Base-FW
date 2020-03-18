#include "StudentPreProcessing.h"
#include "IntensityImageStudent.h"

IntensityImage * StudentPreProcessing::stepToIntensityImage(const RGBImage &image) const {
	IntensityImageStudent* intensity = new IntensityImageStudent(image.getHeight(), image.getWidth());
	for (int w = 0; w < image.getWidth(); w++) {
		for (int h = 0; h < image.getHeight(); h++) {
			RGB curPixel = image.getPixel(w, h);
			int newPixel = (0.299 * curPixel.r) + (0.587 * curPixel.g) + (0.114 * curPixel.b);
			//newPixel = (0.2126 * curPixel.r) + (0.7152 * curPixel.g) + (0.0722 * curPixel.b);
			intensity->setPixel(w, h, newPixel);
		}
	}
	return intensity;
	// for rgb pixel --> set intensituy pixel
	// return intensity
}

IntensityImage * StudentPreProcessing::stepScaleImage(const IntensityImage &image) const {
	return nullptr;
}

IntensityImage * StudentPreProcessing::stepEdgeDetection(const IntensityImage &image) const {
	return nullptr;
}

IntensityImage * StudentPreProcessing::stepThresholding(const IntensityImage &image) const {
	return nullptr;
}