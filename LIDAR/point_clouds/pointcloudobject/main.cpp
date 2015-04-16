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
		pt.removePoint(p);
	}
	pt.setPoint(10, 2330);
	std::cout << "points: \n";
	for (Pointcloud::Point p : pt.getPoints()){
		std::cout << p << "\n";
	}
	pt.removePoint(10, 2330);

	pt.setPoint(20, 20);
	pt.setPoint(20, 30);
	pt.setPoint(20, 40);
	Pointcloud b;
	b.setPoint(20, 20);
	b.setPoint(32, 34);
	b.setPoint(2033, 200);
	Pointcloud c = b + pt;
	std::cout << "c: \n";
	for (Pointcloud::Point p : c.getPoints()){
		std::cout<< p << "\n";
	}

	Pointcloud a;
	a.setPoint(1, 1);
	a.setPoint(2, 2);
	Pointcloud e;
	e.setPoint(2, 2);
	e.setPoint(4, 4);
	Pointcloud d = a + e;
	std::cout << "a: \n";
	for (Pointcloud::Point p : a.getPoints()){
		std::cout << p << "\n";
		a.removePoint(p);
	}
	std::cout << "e: \n";
	for (Pointcloud::Point p : e.getPoints()){
		std::cout << p << "\n";
	}
	std::cout << "d: a + e \n";
	for (Pointcloud::Point p : d.getPoints()){
		std::cout << p << "\n";
		d.removePoint(p);
	}
	d.setPoint(10, 200);
	d.setPoint(12, 112);
	d.setPoint(23, 323);
	a.setPoint(102, 2200);
	a.setPoint(1023, 2300);
	a.setPoint(10, 200);
	a.setPoint(2102, 2003);
	a.setPoint(101, 2001);
	a.setPoint(103, 2002);
	a += d;
	std::cout << "a += d \n";
	for (Pointcloud::Point p : a.getPoints()){
		std::cout << p << "\n";
	}
	printf("pause\n");
	for (Pointcloud::Point p : d.getPoints()){
		std::cout << p << "\n";
	}
	system("pause");
	return 0;
}