#include "Line.h"

Line::Line(const Line::Point & begin_pos, const Line::Point & end_pos)	{
	lineData.begin_pos = begin_pos;
	lineData.end_pos = end_pos;
}

Line::~Line() {
}

void Line::setLine(const Line::Point & begin_pos, const Line::Point & end_pos) {
	lineData.begin_pos = begin_pos;
	lineData.end_pos = end_pos;
}
Line::LineData& Line::getLine() {
	return lineData;
}

std::ostream& operator<<(std::ostream & stream, const Line::Point & point) {
	stream << '(' << point.x << ' ' << point.y << ')';
	return stream;
}

std::ostream& operator<<(std::ostream & stream, const Line & line) {
	stream << line.lineData.begin_pos << ' ' << line.lineData.end_pos;
	return stream;
}

bool operator==(const Line::Point & p1, const Line::Point & p2) {
	if (p1.x == p2.x && p1.y == p2.y) {
		return true;
	}
	return false;
}