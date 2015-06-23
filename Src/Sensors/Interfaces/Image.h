#include "CImg.h"
#include <opencv2/highgui/highgui.hpp>

class Image{
public:
	Image(){}
	
	void setImage(cimg_library::CImg<unsigned char>* cImg){
		CImgToMat(cImg);
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
	void CImgToMat(cimg_library::CImg<unsigned char>* cImg);
	cv::Mat *image = nullptr;
};