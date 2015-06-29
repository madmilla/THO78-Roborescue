
/*
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file PointCloud.cpp
* @date Created: 22-04-15
*
* @version 1.1
* @author Tijmen Bruggeman
* @section LICENSE
* License: newBSD
*
* Copyright © 2015, HU University of Applied Sciences Utrecht.
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
* - Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
* - Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
* - Neither the name of the HU University of Applied Sciences Utrecht nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
* "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
* THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
* ARE DISCLAIMED. IN NO EVENT SHALL THE HU UNIVERSITY OF APPLIED SCIENCES UTRECHT
* BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
* CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
* GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
* LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
* OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
#include "PointCloud.h"
void Pointcloud::setPoint(Point point){
	removePoint(point.X, point.Y);
	pointCloud->push_back(point);
}
void Pointcloud::setPoint(int x, int y){
	removePoint(x, y);
	Point * point = new Point{ x, y };
	pointCloud->push_back(*point);
}
Pointcloud::Point Pointcloud::getOffset(){
	return offset;
}
void Pointcloud::setOffset(Pointcloud::Point newOffset){
	offset = newOffset;
	int xOffset = offset.X;
	int yOffset = offset.Y;
	int newX, newY;
	std::vector<Point> pc = *this->getPoints();
	for (Pointcloud::Point p : pc) {
		int oldX = p.X;
		int oldY = p.Y;
		newX = oldX + xOffset;
		newY = oldY + yOffset;
		this->removePoint(oldX,oldY);
		this->setPoint(newX,newY);
	}
}
std::vector<Pointcloud::Point> *Pointcloud::getPoints(){
	return pointCloud;
}
void Pointcloud::removePoint(int x, int y){
	int i = 0;
	for (Point p : *pointCloud){
		if (p.X == x && p.Y == y){
			pointCloud->erase(pointCloud->begin()+i);
			break;
		}
		++i;
	}
}
void Pointcloud::removePoint(Point point){
	int i = 0;
	for (Point p : *pointCloud){
		if (p.X == point.X && p.Y == point.Y){
			pointCloud->erase(pointCloud->begin() + i);
			break;
		}
		++i;
	}
}
Pointcloud::Pointcloud(){
	pointCloud = new std::vector<Point>();
	offset.X = 0;
	offset.Y = 0;
	orientation = 0;
}
Pointcloud::Point Pointcloud::getMinValues(){
	int minX = 0;
	int minY = 0;
	for (Pointcloud::Point p : *pointCloud){
		if (p.X < minX){
			minX = p.X;
		}
		if (p.Y < minY){
			minY = p.Y;
		}
	}
	return Pointcloud::Point{ minX, minY };
}
int Pointcloud::getCloudHeight(){
	int maxHeight = 0;
	int minHeight = 0;
	for (Point p : *pointCloud){
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
	for (Point p : *pointCloud){
		if (p.X > maxWidth){
			maxWidth = p.X;
		}
		
		if (p.X < minWidth){
			minWidth = p.X;
		}
	}
	return maxWidth - minWidth;
}
void Pointcloud::setOrientation(int degrees){
	orientation = degrees;
	this->rotate((float)orientation);
}
int Pointcloud::getOrientation(){
	return orientation;
}

void Pointcloud::savePointsToFile(std::string filename){
    std::ofstream pCFile;
    pCFile.open(filename + ".pcl");
    if(!pCFile.is_open()) return;
    pCFile << orientation <<'\n' << offset.X << " " << offset.Y << "\n";
    for(Pointcloud::Point point : *pointCloud){
        pCFile << point.X << ":" << point.Y << '\n';
    }
    pCFile.close();
}
void Pointcloud::loadPointsFromFile(std::string filename){
    std::ifstream pCFile;
    pCFile.open(filename);
	if (!pCFile.is_open()){
		std::cout << "could not load pointcloud";
		exit(-1);
	}
    if(!pointCloud->empty()){
        std::cout << "Load on a not empty pointcloud?" << std::endl;
        return;
    }
    std::string line;
    std::string item;
    int result;
    pCFile >> orientation >> offset.X >> offset.Y;
    while(std::getline(pCFile, line)){
        Pointcloud::Point point;
        std::stringstream ss(line);
        std::getline(ss, item, ':');
        std::stringstream convertX(item);
        if ( !(convertX >> result) )continue;
        point.X = result;

        std::getline(ss, item, ':');
        std::stringstream convertY(item);
        if ( !(convertY >> result) )result = 0;
        point.Y = result;
		setPoint(point);
    }
    pCFile.close();
}

void Pointcloud::printPoints(){
	for (Pointcloud::Point p : *this->getPoints()){
		std::cout << p << "\n";
	}
}

Pointcloud* Pointcloud::rotate(float angle){
	const int halfCircle = 180;
	float sn = sin(angle*M_PI/halfCircle);
	float cs = cos(angle*M_PI/halfCircle); 
	std::vector<Point> pc = *this->getPoints();
	for (Pointcloud::Point p : pc) {
		int x = p.X;
		int y = p.Y;
		int nx = x * cs - y * sn; 
		int ny = x * sn + y * cs;
		this->removePoint(x, y);
		this->setPoint(nx,ny);
		nx = 0;
		ny = 0;
	}	
	return this;
}



//OPERATORS
std::ostream & operator<<(std::ostream & output, const Pointcloud::Point & s){
	output << "(" << s.X << "," << s.Y << ")";
	return output;
}
Pointcloud Pointcloud::operator+(Pointcloud & b){
	Pointcloud pt;
	for (Pointcloud::Point p : *b.getPoints()){
		pt.setPoint(p);
	}
	for (Pointcloud::Point p : *pointCloud){
		pt.removePoint(p);
		pt.setPoint(p);
	}
	pt.setOrientation(orientation);
	return pt;
}
Pointcloud Pointcloud::operator+=(Pointcloud & b){
	for (Pointcloud::Point p : *b.getPoints()){
		setPoint(p);
	}
	return *this;
}
