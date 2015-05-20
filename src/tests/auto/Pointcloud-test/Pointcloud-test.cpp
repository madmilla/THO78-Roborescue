#include "PointCloud.h"
#include <iostream>
#include <fstream>

int main(){
	std::ofstream output("PointCloud-test-results.txt");
	bool SUCCES = true;
	int maxWidth = 3000;
	int maxHeight = 3454;
	int minHeight = -200;
	int minWidth = -2342;
	int orientation = 180;
	Pointcloud::Point point{ 300, 23 };
	Pointcloud pt;
	Pointcloud::Point offset{ 23, 234 };
	pt.setPoint(point);
	if (pt.getPoints().front().X == point.X && pt.getPoints().front().Y == point.Y){
		std::cout << "Add single Point SUCCES\nGet Points SUCCES\n";
		output << "Add single Point SUCCES\nGet Points SUCCES\n";
	}
	else{
		std::cout << "Add single Point SUCCES\nGet Points FAILED\n";
		output << "Add single Point SUCCES\nGet Points FAILED\n";
		SUCCES = false;
	}
	pt.setPoint(2, maxHeight);
	pt.setPoint(maxWidth, 100);
	if (pt.getCloudHeight() != maxHeight + (abs(minHeight))){
		std::cout << "GetCloudHeight = FAILED\n";
		output << "GetCloudHeight = FAILED\n";
		SUCCES = false;
	}
	else{
		std::cout << "GetCloudHeight = SUCCES\n";
		output << "GetCloudHeight = SUCCES\n";
	}
	if (pt.getCloudWidth() != maxWidth + (abs(minWidth))){
		std::cout << "getCloudWidth = SUCCES\n";
		output << "getCloudWidth = SUCCES\n";
	}
	else{
		std::cout << "getCloudWidth = FAILED\n";
		output << "getCloudWidth = FAILED\n";
		SUCCES = false;
	}
	for (Pointcloud::Point p : pt.getPoints()){
		pt.removePoint(p);
	}
	if (pt.getPoints().size() > 0){
		std::cout << "RemovePoint = FAILED\n";
		output << "RemovePoint = FAILED\n";
		SUCCES = false;
	}
	else{
		std::cout << "RemovePoint = SUCCES\n";
		output << "RemovePoint = SUCCES\n";
	}

	pt.setOrientation(orientation);
	if (pt.getOrientation() != orientation){
		std::cout << "SetOrientation = FAILED\n";
		output << "SetOrientation = FAILED\n";
		SUCCES = false;
	}
	else{
		std::cout << "SetOrientation = SUCCES\n";
		output << "SetOrientation = SUCCES\n";
	}
	pt.setOffset(offset);
	if (pt.getOffset().X != offset.X || pt.getOffset().Y != offset.Y){
		std::cout << "SetOffset = FAILED\n";
		output << "SetOffset = FAILED\n";
		SUCCES = false;
	} 
	else{
		std::cout << "SetOffset = SUCCES\n";
		output << "SetOffset = SUCCES\n";
	}
	pt.setPoint(2, 4);
	pt.setPoint(2, 42);
	pt.savePointsToFile("test");
	Pointcloud pt2;
	pt2.loadPointsFromFile("test");
	int i = 0;
	bool loadSave = true;
	if (pt.getPoints().size() != pt2.getPoints().size() ||
		pt.getOrientation() != pt2.getOrientation() ||
		pt.getOffset().X != pt2.getOffset().X ||
		pt.getOffset().Y != pt2.getOffset().Y){
		loadSave = false;
	}
	for (Pointcloud::Point point2 : pt.getPoints()){
		if (pt2.getPoints().at(i).X != point2.X || pt2.getPoints().at(i).Y != point2.Y ){
			loadSave = false;
		}
		i++;
	}
	if (loadSave){
		std::cout << "Load and Save functions  = SUCCES\n";
		output << "Load and Save functions  = SUCCES\n";
	}
	else{
		std::cout << "Load and Save functions  = FAILED\n";
		output << "Load and Save functions  = FAILED\n";
		SUCCES = false;
	}
	output.close();
	system("pause");
	return SUCCES -1;
}