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

std::vector<Line> Circle::getLinesAroundCircle() {
	std::vector<Line> lines;

	int radius = radius * LINES_OFFSET;
	for (int angle = 90; angle < 360; angle += LINES_ANGLE_STEP) {
		Line::Point begin_p, end_p;

		begin_p.x = static_cast<int>(originX + (radius * cos(angle))); //calculate point 1
		begin_p.y = static_cast<int>(originY + (radius * sin(angle)));

		end_p.x = static_cast<int>(originX + (radius * cos(angle + LINES_ANGLE_STEP))); //calculate point 2
		end_p.y = static_cast<int>(originY + (radius * sin(angle + LINES_ANGLE_STEP)));

		if (angle == (360 - LINES_ANGLE_STEP)) {
			end_p.x = lines[LINES_VALUE].getLine().begin_pos.x;
			end_p.y = lines[LINES_VALUE].getLine().begin_pos.y;
		}
		lines.push_back(Line{ begin_p, end_p }); //store line
	}	
	return lines;
}




