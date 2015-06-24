#include "map.hpp"

int map::getScaledHeuristicLocationValue(int x,int y){
	int tmp = this->getScaledLocationValue(x, y);
	if (tmp == 1){ return 9; }
	else {
		return tmp;
	}


}


map::map() {
	// Initialize Vehicle Positions
	rosbeePosition = nullptr;
	ATVPosition = nullptr;
	quadcopterPosition = nullptr;

	std::cout << "NEW MAP" <<std::endl;
	access.resize(70);
	for (unsigned int i = 0; i < access.size();i++){
		access.at(i).resize(70);
	
	}

	line a(point(0,0), point(0, access.size()));
	line b(point(0,0), point(access.size(),0));

	line c(point(access.size()-1, access.size()-1), point(0, access.size()-1));
	line d(point(access.size()-1, access.size()-1), point(access.size()-1, 0));

	appendLine(a);
	appendLine(b);
	appendLine(c);
	appendLine(d);
	translateToPoints();	
}

void map::setLocationValue(unsigned int x, int y, int value)
{
	if (x < access.size()&& y< access.at(x).size()){
	access.at(x).at(y) = value;
	}

}

void map::addCircle(int xCentre, int yCentre, int radius){
	for (float degrees = 0; degrees < 360; degrees++){
		float x = radius*cos(degrees) + xCentre;
		float y = radius*sin(degrees) + yCentre;
		this->setScaledLocationValue((int)std::round(x), (int)std::round(y), 1);
	}
}

void map::addValuedCircle(int xCentre, int yCentre, int radius,int value){
	for (float degrees = 0; degrees < 360; degrees++){
		float x = radius*cos(degrees) + xCentre;
		float y = radius*sin(degrees) + yCentre;
		if (this->getScaledLocationValue((int)std::round(x), (int)std::round(y)) == 0){
			this->setScaledLocationValue((int)std::round(x), (int)std::round(y), 2);
		}	
	}
}
std::vector<float> map::addHalfValuedCircle(int xCentre, int yCentre, int radius, int value, std::vector<float> skipInts){
	for (float degrees = 0; degrees < 360; degrees++){
		if (std::find(skipInts.begin(), skipInts.end(), degrees) != skipInts.end()) {
			continue;
		}
		float x = radius*cos(degrees) + xCentre;
		float y = radius*sin(degrees) + yCentre;
		if (this->getScaledLocationValue((int)std::round(x), (int)std::round(y)) != float(1)){
			if (this->getScaledLocationValue((int)std::round(x), (int)std::round(y)) == float(0)){
				this->setScaledLocationValue((int)std::round(x), (int)std::round(y), value);
			}
		}
		else{ skipInts.push_back(degrees); }
	}
	return skipInts;
}

void map::setScaledLocationValue(int x, int y, int value)
{
	x = x*scale;
	y = y*scale;
	for (int i = 0; i < scale; i++){
		for (int ii = 0; ii < scale; ii++){
			this->setLocationValue(x + ii, y + i,value);			
		}
	}
}

int map::getLocationValue(unsigned int x, unsigned int y)
{
	if (x < access.size() && y < access.size()){
		return access.at(x).at(y); }
	else return 1;

}

int map::contains(int value)
{
	for (int i = 0; i < getScaledWidth();i++){
		for (int ii = 0; ii < getScaledHeight(); ii++){
			if (this->getScaledLocationValue(i, ii) == value){
				return true;
			}
		}	
	}
	return false;
}

map::map(line & l){
	mapData.push_back(l);
}

map::map(std::vector<line> & l){
	mapData.insert(mapData.begin(), l.begin(), l.end());
}

std::ostream & operator<<(std::ostream & os, const map & m){
	for (const line & l : m.mapData){
		os << l << "\n";
	}
	return os;
}

map::~map(){}

bool map::hasLine(line & l){
	for (const line & lCmp : mapData){
		if (l.equals(lCmp)){
			return true;
		}
	}
	return false;
}

bool map::hasLine(std::vector<line> & l){
	for (line & lCmp : l){
		if (!hasLine(lCmp)){
			return false;
		}
	}
	return true;
}

std::vector<line> map::getPointLines(point & p){
	std::vector<line> rtn;
	for (line & lCmp : mapData)
	{
		point a = lCmp.getPoint(0);
		point b = lCmp.getPoint(1);
		point c = p;

		int crossproduct = (c.getY() - a.getY()) * (b.getX() - a.getX()) - (c.getX() - a.getX()) * (b.getY() - a.getY());
		if (abs(crossproduct) != 0)
			continue;

		int dotproduct = (c.getX() - a.getX()) * (b.getX() - a.getX()) + (c.getY() - a.getY())*(b.getY() - a.getY());
		if (dotproduct < 0)
			continue;

		int squaredlengthba = (b.getX() - a.getX())*(b.getX() - a.getX()) + (b.getY() - a.getY())*(b.getY() - a.getY());
		if (dotproduct > squaredlengthba)
			continue;

		rtn.push_back(lCmp);
	}
	return rtn;
}

void map::appendLine(line l){
	mapData.push_back(l);
}

void map::appendLine(std::vector<line> & l){
	mapData.insert(mapData.begin(), l.begin(), l.end());
}

bool map::removeLine(line & l){
	if (mapData.size() <= 0) return true;
	std::vector<line>::iterator track = mapData.begin();
	while (track != mapData.end()){
		if (track->equals(l)){
			mapData.erase(track);
			break;
		}
		++track;
	}
	return !hasLine(l);
}

bool map::removeLine(std::vector<line> & l){
	for (line & lCmp : l){
		removeLine(lCmp);
	}
	return hasLine(l);
}

bool map::equals(const map & m){
	if (mapData.size() != m.mapData.size())
		return false;

	map a = m;
	for (line & lCmp : mapData)
	{
		if (a.hasLine(lCmp)){
			a.removeLine(lCmp);
		}
		else{
			return false;
		}
	}

	if (a.mapData.size() == 0){
		return true;
	}
	return false;
}

map map::getRegion(int x, int y, unsigned int width, unsigned int height){
	map rtnMap{};
	int xEnd = x + width;
	int yEnd = y + height;
	for (line & lCmp : mapData)
	{
		// Begin point = 0, End point is 1
		// If begin is in region append line and skip end point check
		for (int i = 0; i < 2; i++){
			if (
				(lCmp.getPoint(i).getX() >= x && lCmp.getPoint(i).getX() <= xEnd)
				&& lCmp.getPoint(i).getY() >= y && lCmp.getPoint(i).getY() <= yEnd
				){
				rtnMap.appendLine(lCmp);
				break;
			}
		}
	}
	return rtnMap;
}

map map::getRegion(point & p, unsigned int width, unsigned int height){
	return getRegion(p.getX(), p.getY(), width, height);
}

//add object to position x,y
void map::addObject(polygon object){
	objects.push_back(object);
}

//fill object (circle or polygon) so that middle is not accessible
void fillObjects(std::vector<int> object){

}

//when pathfinding is done, make all cells unseen again. seen = false;	
void makeUnseen(){

}

//translate lines to points in 2d vector
void map::translateToPoints(){
	for(const line & l : mapData)
		addLineToGrid(l);
}

//check if x,y is accessible
bool map::isAccessible(int x, int y){
	if (access.at(x).at(y) == 0){
		return true;
	}
	else if(access.at(x).at(y) = 1){
		return false;
	}
	
}
void map::setScale(int x){ scale = x; }
bool map::isScaledAccessible(int x, int y ){
	x = x*scale;
	y = y*scale;

	for (int i = 0; i < scale; i++){
		for (int ii = 0; ii < scale; ii++){
			if (!this->isAccessible(i+x, ii+y)){
				return false;			
			}
		}
	}
	return true;
}

int map::getScaledWidth(){
	return access.size() / scale;
}

int map::getScaledHeight(){
	return access.size() / scale;
}

void map::print(){
	for (int i = 0; i < getScaledWidth(); i++){
		for (int ii = 0; ii < getScaledHeight(); ii++){
			std::cout << this->getScaledLocationValue(ii, i);
		}
		std::cout << "\n";
	}
}

int map::getScale(){ 
	return scale; 
}

int map::getScaledLocationValue(int x, int y){
	x = x*scale;
	y = y*scale;
	int highestvalue=0;
	for (int i = 0; i < scale; i++){
		for (int ii = 0; ii < scale; ii++){
			if (highestvalue < this->getLocationValue(x + i, y + ii)){
				highestvalue = this->getLocationValue(x + i, y + ii);
			}
			if (highestvalue==1){
			//	std::cout << "Returned solid \n";
				return 1;
			}
		}
	}
	return highestvalue;
}

void map::addvirtuallidarInput(int virtuallidarInputArray[]){
	if (virtuallidarInputArray[0] == 0){
		appendLine(line(point(virtuallidarInputArray[1], virtuallidarInputArray[2]), point(virtuallidarInputArray[3], virtuallidarInputArray[4])));
	}
	if (virtuallidarInputArray[1] == 1){
		addCircle(virtuallidarInputArray[1], virtuallidarInputArray[2], virtuallidarInputArray[3]);
	}
	translateToPoints();
}

bool map::isReachable(int x, int y, int x1, int y1){
	aStar aS = aStar();
	std::vector<std::pair<int, int>> theRoute;
	theRoute = aS.findPath(x, y, x1, y1, *this);

	if (theRoute.size() <= 0){
		setNotReachable(point(x1, y1));
		return false;
	}

	return true;
}

bool map::isReachable(point p, point p1){
	return isReachable(p.getX(), p.getY(), p1.getX(), p1.getY());
}

void map::setNotReachable(point p){
	access.at(p.getX()).at(p.getY()) = 1;
}

void map::addLineToGrid(line l){
	// Breseham's line algorithm
	float aX = l.getPoint(0).getX(), bX = l.getPoint(1).getX();
	float aY = l.getPoint(0).getY(), bY = l.getPoint(1).getY();

	const bool steep = (fabs(bY - aY) > fabs(bX - aX));
	if (steep){
		// swap points for more comfortable calculation
		std::swap(aX, aY);
		std::swap(bX, bY);
	}

	if (aX > bX){
		// swap points for more comfortable calculation
		std::swap(aX, bX);
		std::swap(aY, bY);
	}

	const float dX = bX - aX;		// delta X
	const float dY = fabs(bY - aY); // delta Y

	float error = dX / 2.0f;
	const int yStep = (aY < bY) ? 1 : -1;
	int y = (int)aY;

	const int maxX = (int)bX;

	for (int x = (int)aX; x < maxX; x++){
		if (steep){
			access.at(y).at(x) = 1;
		}
		else{
			access.at(x).at(y) = 1;
		}

		error -= dY;
		if (error < 0){
			y += yStep;
			error += dX;
		}
	}
}

void map::addPolygonToMapData(polygon p){
	std::vector<point> shape = p.getPoints();
	if (shape.size() < 2) return; // this is not a polygon but a single point
	for (unsigned int i = 0; i < shape.size() - 1; i++){
		point p1 = point(shape.at(i));
		point p2 = point(shape.at(i + 1));
		line l = line(p1, p2);
		appendLine(l);
	}
	point p1 = point(shape.at(shape.size()-1));
	point p2 = point(shape.at(0));
	line l = line(p1, p2);
	appendLine(l);
}

void map::addPolygonToGrid(polygon p){
	std::vector<point> shape = p.getPoints();
	if (shape.size() < 2) return; // this is not a polygon but a single point
	for (unsigned int i = 0; i < shape.size() - 1; i++){
		point p1 = point(shape.at(i));
		point p2 = point(shape.at(i + 1));
		line l = line(p1, p2);
		addLineToGrid(l);
	}
	point p1 = point(shape.at(shape.size()-1));
	point p2 = point(shape.at(0));
	line l = line(p1, p2);
	addLineToGrid(l);
}

void map::floodFillLocation(point node, int target, int replacement){
	if (target == replacement) return;	// Nothing to do here
	if (access.at(node.getX()).at(node.getY()) != target) return; // Node != target
	access.at(node.getX()).at(node.getY()) = replacement;

	if (isAccessible(node.getX() + 1, node.getY())) // Go right
		floodFillLocation(point(node.getX() + 1, node.getY()), target, replacement);
	if (isAccessible(node.getX() - 1, node.getY())) // Go left
		floodFillLocation(point(node.getX() - 1, node.getY()), target, replacement);
	if (isAccessible(node.getX(), node.getY() + 1)) // Go up
		floodFillLocation(point(node.getX(), node.getY() + 1), target, replacement);
	if (isAccessible(node.getX(), node.getY() - 1)) // Go down
		floodFillLocation(point(node.getX(), node.getY() - 1), target, replacement);
	return;
}

void map::floodFillLocationQueue(point node, int target, int replacement){
	if (target == replacement) return;	// Nothing to do here
	std::vector<std::pair<int, int>> myQueue;
	myQueue.push_back(std::pair<int, int>(node.getX(), node.getY()));
	while (myQueue.size() > 0){			// While queue not empy
		std::pair<int, int> tmp = myQueue.at(0);
		myQueue.erase(myQueue.begin());	// Pop first element
		if (access.at(tmp.first).at(tmp.second) == target){
			access.at(tmp.first).at(tmp.second) = replacement;

			myQueue.push_back(std::pair<int, int>(tmp.first + 1, tmp.second));
			myQueue.push_back(std::pair<int, int>(tmp.first - 1, tmp.second));
			myQueue.push_back(std::pair<int, int>(tmp.first, tmp.second + 1));
			myQueue.push_back(std::pair<int, int>(tmp.first, tmp.second - 1));
		}
	}
}