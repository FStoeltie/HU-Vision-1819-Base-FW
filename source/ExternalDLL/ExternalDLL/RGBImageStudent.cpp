#include "RGBImageStudent.h"
#include <iostream>
#include <fstream>

RGBImageStudent::RGBImageStudent() : RGBImage() {
	//TODO: Nothing
}

RGBImageStudent::RGBImageStudent(const RGBImageStudent &other) : RGBImage(other.getWidth(), other.getHeight()) {
	RGB_pixel_data = other.RGB_pixel_data;
	//TODO: Create a copy from the other object
}


RGBImageStudent::RGBImageStudent(const int width, const int height) : RGBImage(width, height) {
	RGB_pixel_data.reserve(width * height);
	//TODO: Initialize pixel storage
}

RGBImageStudent::~RGBImageStudent() {
	//TODO: delete allocated objects
}

void RGBImageStudent::set(const int width, const int height) {
	RGBImage::set(width, height);
	RGB_pixel_data.reserve(width * height);
	//TODO: resize or create a new pixel storage (Don't forget to delete the old storage)
}

void RGBImageStudent::set(const RGBImageStudent &other) {
	RGBImage::set(other.getWidth(), other.getHeight());
	RGB_pixel_data = other.RGB_pixel_data;
	//TODO: resize or create a new pixel storage and copy the object (Don't forget to delete the old storage)
}

void RGBImageStudent::setPixel(int x, int y, RGB pixel) {
	
	RGB_pixel_data[x + (y * getWidth())] = pixel;
	//TODO: no comment needed :)
}

void RGBImageStudent::setPixel(int i, RGB pixel) {
	RGB_pixel_data[i] = pixel;
	/*
	* TODO: set pixel i in "Row-Major Order"
	*
	*
	* Original 2d image (values):
	* 9 1 2
	* 4 3 5
	* 8 7 8
	*
	* 1d representation (i, value):
	* i		value
	* 0		9
	* 1		1
	* 2		2
	* 3		4
	* 4		3
	* 5		5
	* 6		8
	* 7		7
	* 8		8
	*/
}

RGB RGBImageStudent::getPixel(int x, int y) const {
	return RGB_pixel_data[x + (y * getWidth())];
}

RGB RGBImageStudent::getPixel(int i) const {
	return RGB_pixel_data[i];
}