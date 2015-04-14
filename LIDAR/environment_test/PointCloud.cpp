#include "PointCloud.h"
#include <string>
#include <sstream>

void Pointcloud::setPoint(Point point){
	removePoint(point.X, point.Y);
	pointCloud.push_back(point);
}
void Pointcloud::setPoint(int x, int y){
	removePoint(x, y);
	Point * point = new Point{ x, y };
	pointCloud.push_back(*point);
}
std::vector<Pointcloud::Point> Pointcloud::getPoints(){
	return pointCloud;
}
void Pointcloud::removePoint(int x, int y){
	int i = 0;
	for (Point p : pointCloud){
		if (p.X == x && p.Y == y){
			pointCloud.erase(pointCloud.begin()+i);
		}
		i++;
	}
}
Pointcloud::Pointcloud(){}

int Pointcloud::getCloudHeight(){
	int maxHeight = 0;
	int minHeight = 0;
	for (Point p : pointCloud){
		if (p.Y < minHeight){
			minHeight = p.Y;
		}
		if (p.Y > maxHeight){
			maxHeight = p.Y;
		}
	}
	return maxHeight - minHeight;
}
int Pointcloud::getCloudWidth(){
	int maxWidth = 0;
	int minWidth = 0;
	for (Point p : pointCloud){
		if (p.X > maxWidth){
			maxWidth = p.X;
		}
		if (p.X < maxWidth){
			minWidth = p.X;
		}
	}
	return maxWidth - minWidth;
}
std::ostream & operator<<(std::ostream & output, const Pointcloud::Point & s){
	output << "(" << s.X << "," << s.Y << ")";
	return output;
}

void Pointcloud::setOrientation(int degrees){
	orientation = degrees;
}
int Pointcloud::getOrientation(){
	return orientation;
}

void Pointcloud::savePointsToFile(std::string filename){
    std::ofstream pCFile;
    pCFile.open(filename + ".pcl");
    if(!pCFile.is_open()) return;
    for(Pointcloud::Point point : pointCloud){
        pCFile << point.X << ":" << point.Y << '\n';
    }
    pCFile.close();
}
void Pointcloud::loadPointsFromFile(std::string filename){
    std::ifstream pCFile;
    pCFile.open(filename + ".pcl");
    if(!pCFile.is_open()) return;
    if(!pointCloud.empty()){
        std::cout << "Load on a not empty pointcloud?" << std::endl;
        return;
    }
    std::string line;
    std::string item;
    int result;
    while(std::getline(pCFile, line)){
        Pointcloud::Point point;
        std::stringstream ss(line);
        std::getline(ss, item, ':');
        std::stringstream convertX(item);
        if ( !(convertX >> result) )result = 0;
        point.X = result;

        std::getline(ss, item, ':');
        std::stringstream convertY(item);
        if ( !(convertY >> result) )result = 0;
        point.Y = result;
        setPoint(point);
    }
    pCFile.close();
}
