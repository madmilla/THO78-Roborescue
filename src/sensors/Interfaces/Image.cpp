#include "Image.h"
Image::CImgToMat(cimg_library::CImg<unsigned char>* cImg){
	if (cImg->size()){
		cImg->save("image.BMP");
		image = new cv::Mat(imread("image.BMP",cv::CV_LOAD_IMAGE_COLOR));
	}
}