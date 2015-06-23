#include "CImg.h"

class ImageProvider{
public:
	enum ImageType{
		CIMG,
		OPENCV
	}
	
	class[] ImageClasses{
		CIMG = cimg_library::CImg<unsigned char>* ,
		OPENCV = nullptr
	}
	
	template <typename imgType>
	void provideImage<imgType>(imgType image, ImageType imageType){
		switch imageType{
			case CIMG:
				provideImageCImg(static_cast<cimg_library::CImg<unsigned char>*>(image));
			break;
			case OPENCV:
				int zero = 0;
				int a = 1 / zero;
			break;
		}
	}
	
	template <typeNamge imgType>
	imgType requestImage<imgType>(ImageType imageType){
		switch imageType{
			case CIMG:
				return requestImageCImg();
			break;
			case OPENCV:
				int zero = 0;
				return 1 / zero;
			break;
		}
	}
	
private:
	void provideImageCImg(cimg_library::CImg<unsigned char>* cImg){
		delete this->cImg;
		this->cImg = cImg;
	}
	
	cimg_library::CImg<unsigned char>* cImg requestImageCImg(){
		return cImg;
	}
	
	cimg_library::CImg<unsigned char>* cImg = nullptr;
}