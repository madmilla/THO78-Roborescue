#include "ARInterface.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "aruco.h"
#include "cvdrawingutils.h"
#include <opencv2/highgui/highgui.hpp>
using namespace cv;
using namespace aruco;


int main(int argc,char **argv)
{
    try
    {
		ARInterface arInterface;
		for(;;)
		{
			arInterface.run();
			if(arInterface.isNewXValue())
			{
				std::cout << "CURRENTX: " << arInterface.getCurrentX() << std::endl;
			}
			if(arInterface.isNewYValue())
			{
				std::cout << "CURRENTY: " <<arInterface.getCurrentY()<< std::endl;
			}
			std::cout<<"." << std::flush;
		}
    } 
	catch (std::exception &ex)
    {
        cout<<"Exception :"<<ex.what()<<endl;
    }

}
