#include "Cell.h"


Cell::Cell()
{
}

Cell::Cell(bool isObstacle)
{
	obstacle = isObstacle;
}

Cell::~Cell()
{
}

bool Cell::isObstacle()
{
	return obstacle;
}

void Cell::setObstacle(bool isObstacle)
{
	obstacle = isObstacle;
}