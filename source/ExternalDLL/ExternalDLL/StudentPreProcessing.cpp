#include "StudentPreProcessing.h"
#include "IntensityImageStudent.h"
#include <thread>
#include <iostream>
IntensityImage * StudentPreProcessing::stepToIntensityImage(const RGBImage &image) const {
	IntensityImageStudent* intensity = new IntensityImageStudent(image.getHeight(), image.getWidth());



	// Pass f and its parameters to thread  
	// object constructor as 
	auto f = [](int startx, int starty, int stopx, int stopy, IntensityImageStudent* intensity, const RGBImage & image) {
		// Do Something 
		for (int w = startx; w < stopx; w++) {
			for (int h = starty; h < stopy; h++) {
				RGB curPixel = image.getPixel(w, h);
				int newPixel = (0.299 * curPixel.r) + (0.587 * curPixel.g) + (0.114 * curPixel.b);
				//newPixel = (0.2126 * curPixel.r) + (0.7152 * curPixel.g) + (0.0722 * curPixel.b);
				intensity->setPixel(w, h, newPixel);
			}
		}
	};
	
	//std::reference_wrapper<const RGBImage>;
	auto thread_object1 = std::thread(f, 0, 0, image.getWidth()/2, image.getHeight()/2, intensity, std::ref(image));
	auto thread_object2 = std::thread(f, image.getWidth()/2, 0, image.getWidth(), image.getHeight() / 2, intensity, std::ref(image) );
	auto thread_object3 = std::thread(f, 0, image.getHeight() / 2, image.getWidth() / 2, image.getHeight(), intensity, std::ref(image));
	auto thread_object4 = std::thread(f, image.getWidth() / 2, image.getHeight() / 2, image.getWidth(), image.getHeight(), intensity, std::ref(image));
	thread_object1.join();
	thread_object2.join();
	thread_object3.join();
	thread_object4.join();
	//std::thread thread_object([](IntensityImageStudent* intensity, std::reference_wrapper<const RGBImage> image) {
	//	// Do Something 
	//	for (int w = 0; w < image.get().getWidth(); w++) {
	//		for (int h = 0; h < image.get().getHeight(); h++) {
	//			RGB curPixel = image.get().getPixel(w, h);
	//			int newPixel = (0.299 * curPixel.r) + (0.587 * curPixel.g) + (0.114 * curPixel.b);
	//			//newPixel = (0.2126 * curPixel.r) + (0.7152 * curPixel.g) + (0.0722 * curPixel.b);
	//			intensity->setPixel(w, h, newPixel);
	//		}
	//	}
	//});

	//std::thread thread_object2([](IntensityImageStudent* intensity, const RGBImage& image) {
	//	// Do Something 
	//	for (int w = image.getWidth()/2; w < image.getWidth(); w++) {
	//		for (int h = image.getHeight()/2; h < image.getHeight(); h++) {
	//			RGB curPixel = image.getPixel(w, h);
	//			int newPixel = (0.299 * curPixel.r) + (0.587 * curPixel.g) + (0.114 * curPixel.b);
	//			//newPixel = (0.2126 * curPixel.r) + (0.7152 * curPixel.g) + (0.0722 * curPixel.b);
	//			intensity->setPixel(w, h, newPixel);
	//		}
	//	}
	//});
	//for (int w = 0; w < image.getWidth(); w++) {
	//	for (int h = 0; h < image.getHeight(); h++) {
	//		RGB curPixel = image.getPixel(w, h);
	//		int newPixel = (0.299 * curPixel.r) + (0.587 * curPixel.g) + (0.114 * curPixel.b);
	//		//newPixel = (0.2126 * curPixel.r) + (0.7152 * curPixel.g) + (0.0722 * curPixel.b);
	//		intensity->setPixel(w, h, newPixel);
	//	}
	//}
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