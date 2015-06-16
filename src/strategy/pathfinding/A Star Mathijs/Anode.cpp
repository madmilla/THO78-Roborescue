#include "Anode.h"


//Anode::Anode()
//{
//}


//Anode::~Anode()
//{
//}

const int & node::estimate(const int & xDest, const int & yDest) const
{
	static int xd, yd, d;
	xd = xDest - xPos;
	yd = yDest - yPos;

	// Euclidian Distance
	d = static_cast<int>(sqrt(xd*xd + yd*yd));

	// Manhattan distance
	//d=abs(xd)+abs(yd);

	// Chebyshev distance
	//d=max(abs(xd), abs(yd));

	return(d);
}
