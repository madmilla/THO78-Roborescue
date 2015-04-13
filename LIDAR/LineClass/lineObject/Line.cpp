#include "Line.h"

Line::Line(const Point & begin_pos, const Point & end_pos)	{
	lineData.begin_pos = begin_pos;
	lineData.end_pos = end_pos;
}

Line::~Line() {
}

void Line::setLine(const Point & begin_pos, const Point & end_pos) {
	lineData.begin_pos = begin_pos;
	lineData.end_pos = end_pos;
}
Line::LineData& Line::getLine() {
	return lineData;
}
