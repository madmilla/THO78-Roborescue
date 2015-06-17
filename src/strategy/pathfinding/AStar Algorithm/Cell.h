#ifndef _CELL_H_
#define _CELL_H_
class Cell
{
public:
	Cell();
	Cell(bool isObstacle);
	~Cell();

	bool isObstacle();
	void setObstacle(bool isObstacle);

private:
	bool obstacle;
};
#endif