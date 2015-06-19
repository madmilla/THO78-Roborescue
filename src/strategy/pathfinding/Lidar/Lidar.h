#ifndef LIDAR_H
#define LIDAR_H


class Lidar
{
public:
	Lidar();
	~Lidar();
	int getRange();
private:
	int range = 7;
};

#endif // LIDAR_H
