class Point
{

public:
	Point(double x = 0.0,double y = 0.0):_x(x),_y(y){}
	double getX(){return _x;}
	double getY(){return _y;}
	void setX(double x){_x = x;}
	void setY(double y){_y = y;}
private:
	double _x,_y;
}

class Line
{
public:
	Line(Point & tail, Point & head):_tail(tail),_head(head){}
	Line(double x1 = 0.0,double y1 = 0.0,double x2 = 0.0,double y2 = 0.0):_tail(x1,y1),_head(x2,y2){}
	const Point & getTail(){return _tail;}
	const Point & getHead(){return _head;}
	void setTail(const Point & tail){_tail = tail;}
	void setHead(const Point & head){_head = head;}
private:
	Point _tail;
	Point _head;
}

class enum RobotType
{
	Quad = 1,
	ATV = 2,
	Rosbee = 3;
}