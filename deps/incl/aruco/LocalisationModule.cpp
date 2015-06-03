#include <iostream>
#include "ARInterface.h"
#include <thread>

int main()
{
	ARInterface arRecogniser;
	std::thread recogniserThread{ &ARInterface::run, &arRecogniser};
	recogniserThread.detach();
	bool newValue = false;
	while(1)
	{
		if(arRecogniser.isNewXValue())
		{
			newValue = true;
		}
		if(arRecogniser.isNewYValue())
		{
			newValue = true;
		}
		if(newValue)
		{
			std::cout << "Doe server shit" << std::endl;
			newValue = false;
		}
	}
	return 0;
}