#include "PointCloud.h"
#include <iostream>
///TEST		TEST	TEST	TEST	TEST	TEST	TEST	TEST

int main(){
	int maxWidth = 3000;
	int maxHeight = 3454;
	int minHeight = -200;
	int minWidth = -2342;
	int orientation = 180;
	Pointcloud::Point point{ 300, 23 };
	Pointcloud pt;
	std::cout << point << std::endl;
	pt.setPoint(point);
	pt.setPoint(2, maxHeight);
	pt.setPoint(maxWidth, 100);
	pt.setPoint(200, 3);
	pt.setPoint(minHeight, minHeight);
	pt.setPoint(minWidth, 3);

	pt.setOrientation(orientation);
	if (pt.getOrientation() != orientation){
		exit(1);
	}
	if (pt.getCloudHeight() != maxHeight - minHeight || pt.getCloudWidth() != maxWidth - minWidth){
		std::cout << "de size of the cloud is not correct\n";
		std::cout << "maxWidth: " << pt.getCloudWidth() << "\nMaxHeight: " << pt.getCloudHeight() << std::endl;
		exit(1);
	}
	for (Pointcloud::Point p : pt.getPoints()){
		std::cout << p << "\n";
	}
	system("pause");
	return 0;
}