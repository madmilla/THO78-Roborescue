#include "TempListener.h"
#include <iostream>

TempListener::TempListener()
{
}


TempListener::~TempListener()
{
}

void TempListener::notifyListener(Subject&, StatusText statusText)
{
	if (statusText != StatusText::NONE)
	{
		std::cout << "New message:";
		std::cout << (int)statusText << ':';
		std::string printable = "Unknown";
		for (auto & pair : statusTextMap)
		{
			if (pair.second == statusText)
			{
				printable = pair.first;
				break;
			}
		}
		std::cout << printable;
		std::cout << "\n";
	}
}