#ifndef CHECKPOINT_H
#define CHECKPOINT_H


class checkPoint
{
private:
    int checkPointx = 0;
    int checkPointy = 0;
public:
    checkPoint();
    checkPoint(int x, int y);
    void setX(int x);
    void setCoordinates(int x, int y);
    void setY(int y);
    int getX();
    int getY();
    ~checkPoint();
};

#endif // CHECKPOINT_H
