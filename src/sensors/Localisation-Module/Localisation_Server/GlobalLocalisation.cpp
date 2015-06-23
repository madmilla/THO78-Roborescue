#include "GlobalLocalisation.h"

bool GlobalLocalisation::initializeDrivers()
{
	if(geteuid() != 0)
	{			
		error += "Program requires root (sudo) to reset video drivers with different parameters!";
		errorOnInit = true;
		return false;
	}
	std::cout << "Disabling video driver" << std::endl;
	std::system("sudo rmmod uvcvideo");
	std::cout << "Enabling video driver with timeout parameter" << std::endl;
	std::system("sudo modprobe uvcvideo nodrop=1 timeout=2000");
	return true;
}

GlobalLocalisation::GlobalLocalisation(bool hasGui, double thres1, double thres2) :
	newCoordinate {false},
	errorOnInit { false},
	error {""},
	hasGui {hasGui},
	ARDetectorX{hasGui, thres1, thres2},
	ARDetectorY{hasGui, thres1, thres2}
{
	//If the drivers failed to initialize, return;
	if(!initializeDrivers())
	{
		return;
	}
	
	//Open the camera's
	theVideoCapturerX.open(VIDEO_DEVICE_X);
	theVideoCapturerX.set(CV_CAP_PROP_FRAME_WIDTH, 1280);
	theVideoCapturerX.set(CV_CAP_PROP_FRAME_HEIGHT, 720);
	
	theVideoCapturerY.open(VIDEO_DEVICE_Y);		
	theVideoCapturerY.set(CV_CAP_PROP_FRAME_WIDTH, 1280);
	theVideoCapturerY.set(CV_CAP_PROP_FRAME_HEIGHT, 720);
	

	//Check video is open
	if (!theVideoCapturerX.isOpened())
	{
		errorOnInit = true;
		error += " Could not open video device X";
		return;
	}
	if (!theVideoCapturerY.isOpened())
	{
		error += " Could not open video device Y";
		errorOnInit = true;
		return;
	}
	//Read first image to get the dimensions of the image
	theVideoCapturerX >> theInputImageX;
	theVideoCapturerY >> theInputImageY;

	//Get the half of the width of the images
	cv::Size sizeX = theInputImageX.size();
	halfWidthCameraX = sizeX.width / 2;
	
	cv::Size sizeY = theInputImageY.size();
	halfWidthCameraY = sizeY.width / 2;
	
	if(hasGui)
	{			
		cv::namedWindow("X",1);		
		cv::namedWindow("Y",1);
		cv::namedWindow("XT",1);		
		cv::namedWindow("YT",1);
	}
		
	std::cout << "Ending constructor" << std::endl;
	
}

void GlobalLocalisation::run()
{
	while (1)
	{
		//Grabs the X and Y images (otherwise .retrieve() will always 
		// return the same image)
		if(!theVideoCapturerX.grab())
		{
			error += " Cannot grab image from X camera";
			errorInRun = true;
		}
		if(!theVideoCapturerY.grab())
		{
			error += " Cannot grab image from Y camera";
			errorInRun = true;
		}
		
		//Retrieves the images and puts them in theInputImages
		if(!theVideoCapturerX.retrieve(theInputImageX))
		{
			error += " Cannot retrieve image from X camera";
			errorInRun = true;
		}
		if(!theVideoCapturerY.retrieve(theInputImageY))
		{
			error += " Cannot retrieve image from Y camera";
			errorInRun = true;
		}

		//Detects markers in the images, and puts them in theMarkers
		theMarkersX = ARDetectorX.detectMarkers(theInputImageX);
		theMarkersY = ARDetectorY.detectMarkers(theInputImageY);
		
		cout << ".";
		cout.flush();

		//Gets the closest marker to the center of the image
		//getClosestId can return -1 if it didn't find anything,
		//so we need to test if it isn't -1, and after that check if 
		//the new coordinate isn't the same as it already is
		int closestIdX = getClosestId(theMarkersX, halfWidthCameraX);
		if (closestIdX != -1)
		{
			if (currentCoordinate.getX() != closestIdX)
			{
				currentCoordinate.setX(closestIdX);
				newCoordinate = true;
			}
		}

		int closestIdY = getClosestId(theMarkersY, halfWidthCameraY);
		if (closestIdY != -1)
		{
			if (currentCoordinate.getY() != closestIdY)
			{
				currentCoordinate.setY(closestIdY);
				newCoordinate = true;
			}
		}
		
		//GUI CODE
		if(hasGui)
			{
			theInputImageX.copyTo(theInputImageCopyX);
			theInputImageY.copyTo(theInputImageCopyY);
			for (unsigned int i=0;i<theMarkersX.size();i++) 
			{
				theMarkersX[i].draw(theInputImageCopyX,Scalar(0,0,255),1);
			}
		
			for (unsigned int i=0;i<theMarkersY.size();i++) 
			{
				theMarkersY[i].draw(theInputImageCopyY,Scalar(0,0,255),1);
			}
		
			cv::imshow("X",theInputImageCopyX);
			cv::imshow("XT",ARDetectorX.getThresholdedImage());
			
			cv::imshow("Y",theInputImageCopyY);
			cv::imshow("YT",ARDetectorY.getThresholdedImage());
			char key = cv::waitKey(10);
		}
	}
}

int GlobalLocalisation::getClosestId(vector<Marker> &theMarkers, int halfWidthCamera)
{
	if (theMarkers.size()>0)
	{
		int currentClosestId = -1;
		float currentClosestX = 1000;

		for (unsigned int i = 0; i<theMarkers.size(); i++)
		{
			float xValueTotal = 0;
			//Add all the x values of the 4 points
			for (int j = 0; j < 4; j++)
			{
				xValueTotal += theMarkers[i][j].x;
			}	
			//Divide the values by 4 to get the average, and substract
			//That from the middle point of the image; this way we get
			//The distance from the middle
			int distance = abs(halfWidthCameraX - (int)(xValueTotal / 4));
			
			//Get the closest distance from all the markers
			if (distance < currentClosestX)
			{
				currentClosestId = theMarkers[i].id;
				currentClosestX = distance;
			}
		}			
		return currentClosestId;
	}
	return -1;
}

Coordinate<int> GlobalLocalisation::getCoordinate()
{
	newCoordinate = false;
	return currentCoordinate;
}

bool GlobalLocalisation::isNewCoordinate()
{
	return newCoordinate;
}

bool GlobalLocalisation::isErrorOnInit()
{
	return errorOnInit;
}

bool GlobalLocalisation::isErrorInRun()
{
	return errorInRun;
}

std::string GlobalLocalisation::getErrorString()
{
	return error;
}