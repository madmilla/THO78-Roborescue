#ifndef VIRTUALLIDAR_H
#define VIRTUALLIDAR_H


class virtualLidar
{
public:
	virtualLidar();
	~virtualLidar();
	int getRange();
private:
	int range = 7;
};

#endif // VIRTUALLIDAR_H
