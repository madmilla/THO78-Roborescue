#include "CImg.h"
#include <opencv2/highgui/highgui.hpp>

class Image{
public:
	Image(){}
	
	void setImage(cimg_library::CImg<unsigned char>* cImg){
		cImgToMat(cImg);
	}
	
	void setImage(cv::Mat* image){
		this->image = image;
	}
	
	cv::Mat* getImage(){
		return image;
	}
	
	~Image(){
		delete image;
	}
private:
	void cImgToMat(cimg_library::CImg<unsigned char>* cImg);
	cv::Mat *image = nullptr;
};