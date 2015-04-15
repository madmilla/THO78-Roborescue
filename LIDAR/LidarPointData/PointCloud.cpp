#include "PointCloud.h"

void Pointcloud::setPoint(Point point){
	removePoint(point.X, point.Y);
	pointCloud.push_back(point);
}
void Pointcloud::setPoint(int x, int y){
	removePoint(x, y);
    Point * point = new Point;
    point->X = x;
    point->Y = y;
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
