#pragma once

#include <string>

class QRCode
{
private:
	std::string value;
	int x;
	int y;
	int z;
public:
	QRCode() {}
	QRCode(const std::string& value, int x, int y, int z): value(value), x(x), y(y), z(z) {}
	~QRCode() {}
	
	void setValue(const std::string& value) { this->value = value; }
	void setX(int x) { this->x = x; }
	void setY(int y) { this->y = y; }
	void setZ(int z) { this->z = z; }

	std::string getValue() { return value; }
	int getX() { return this->x; }
	int getY() { return this->y; }
	int getZ() { return this->z; }
};