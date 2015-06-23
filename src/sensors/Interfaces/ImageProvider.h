#include "CImg.h"

class ImageProvider{
public:
	enum class ImageType{
		CIMG,
		OPENCV
	};
	
	template <typename imgType>
	void provideImage(imgType image, ImageType imageType){
		switch (imageType){
			case ImageType::CIMG:
				provideImageCImg(static_cast<cimg_library::CImg<unsigned char>*>(image));
			break;
			case ImageType::OPENCV:
				int zero = 0;
				int a = 1 / zero;
			break;
		}
	}
	
	template <typename imgType>
	imgType requestImage(ImageType imageType){
		switch (imageType){
			case ImageType::CIMG:
				return requestImageCImg();
			break;
			case ImageType::OPENCV:
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
	
	cimg_library::CImg<unsigned char>* requestImageCImg(){
		return cImg;
	}
	
	cimg_library::CImg<unsigned char>* cImg = nullptr;
};