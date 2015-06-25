#include "Image.h"
#include <opencv2/core/core.hpp>
#include <iostream>
void Image::cImgToMat(cimg_library::CImg<unsigned char>* cImg){
	if (cImg->size()){
		cImg->save("image.BMP");
		image = new cv::Mat(cv::imread("image.BMP",CV_LOAD_IMAGE_COLOR));
	}
}