#pragma once
class mapImplementation
{
public:
	//! Virtual isAccessible to check if indices are accesible in grid
	//! @param The x index of the grid
	//! @param The y index of the grid
	//! @return The result of the accessible check
	virtual bool isAccessible(int x, int y) = 0;
};