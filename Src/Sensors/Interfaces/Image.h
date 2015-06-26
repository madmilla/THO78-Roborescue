#include "CImg.h"
#include <opencv2/highgui/highgui.hpp>

class Image{
public:
	/**
	* Sets the image in this Image class.
	* Converts from cimg_library::CImg<unsigned char>* to cv::Mat*.
	*
	* @param cImg is of type cimg_library::CImg<unsigned char>*.
	*/
	void setImage(cimg_library::CImg<unsigned char>* cImg){
		cImgToMat(cImg);
	}
	
	/**
	* Sets the image in this Image class.
	*
	* @param image is of type cv::Mat*.
	*/
	void setImage(cv::Mat* image){
		this->image = image;
	}
	
	/**
	* Returns the image contained by this Image class.
	*
	* @return cv::Mat*, a pointer to the openCV image.
	*/
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