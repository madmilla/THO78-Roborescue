#include "Circle.h"

Circle::Circle(int originX, int originY, int radius) :
originX{ originX },
originY{ originY },
radius{ radius }
{}

Circle::~Circle()
{

}

void Circle::setCircle(int x, int y, int r) {
	originX = x;
	originY = y;
	radius = r;
}

Circle::circleData Circle::getCircle() {
	circleData circleData;
	circleData.originX = originX;
	circleData.originY = originY;
	circleData.radius = radius;
	return circleData;
}

std::vector<Line> Circle::getLinesAroundCircle(const Circle & circle) {
	std::vector<Line> lines;

	const double OFFSET = 1.25;
	const int ANGLE_STEP = 45;
	const int LINES_VALUE = 6;

	int radius = circle.radius * OFFSET; 
	int line_counter = 0;
	for (int angle = 90; angle < 360; angle += ANGLE_STEP) {
		Line::Point begin_p, end_p;

		begin_p.x = static_cast<int>(circle.originX + (radius * cos(angle))); //calculate point 1
		begin_p.y = static_cast<int>(circle.originY + (radius * sin(angle)));

		end_p.x = static_cast<int>(circle.originX + (radius * cos(angle + ANGLE_STEP))); //calculate point 2
		end_p.y = static_cast<int>(circle.originY + (radius * sin(angle + ANGLE_STEP)));

		if (angle == (360 - ANGLE_STEP)) {
			end_p.x = lines[line_counter].getLine().begin_pos.x;
			end_p.y = lines[line_counter].getLine().begin_pos.y;
			line_counter += LINES_VALUE;
		}
		lines.push_back(Line{ begin_p, end_p }); //store line
	}	
	return lines;
}




