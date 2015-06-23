#include "ARInterface.h"

ARInterface::ARInterface(bool hasGui, double thres1, double thres2) :
	theMarkerSize { -1},
	hasGui {hasGui},
	thresParam1{thres1},
	thresParam2{thres2}	
{	
	std::cout << "T1: " << thresParam1 << " T2: " << thresParam2 << std::endl;
	if (thePyrDownLevel>0)
	{
		markerDetector.pyrDown(thePyrDownLevel);
	}
	
	markerDetector.setThresholdParams(thresParam1, thresParam2);
	markerDetector.setCornerRefinementMethod(MarkerDetector::SUBPIX);
}

vector<Marker> ARInterface::detectMarkers(Mat inputImage)
{
	vector<Marker> theMarkers;
	markerDetector.detect(inputImage, theMarkers, 
		theCameraParameters, theMarkerSize);
	return theMarkers;
}

int ARInterface::getIdFromImage(Mat* image)
{
	Mat imageCopy;
	vector<Marker> theMarkers;
	markerDetector.detect(*image, theMarkers,
			theCameraParameters, theMarkerSize);
	
	image->copyTo(imageCopy);
	int detectedId = -1;
	for (unsigned int i=0;i<theMarkers.size();i++) 
	{
		std::cout << "ID DETECTED: " << theMarkers[i].id <<std::endl;
		detectedId = theMarkers[i].id;
		if(hasGui)
		{
			theMarkers[i].draw(imageCopy,Scalar(0,0,255),1);
		}
	}	
	
	if(hasGui)
	{
		cv::imshow("PX4",imageCopy);
		cv::imshow("PX4T",markerDetector.getThresholdedImage());			
		char key = cv::waitKey(10);
	}
	
	return detectedId;
}

Mat ARInterface::getThresholdedImage()
{
	return markerDetector.getThresholdedImage();
}