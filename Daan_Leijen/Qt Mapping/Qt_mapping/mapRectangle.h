#ifndef MAPRECTANGLE_H
#define MAPRECTANGLE_H

#include <QRect>

class mapRectangle
{
public:
    mapRectangle(QRectF rect, char rectType);
    mapRectangle();
    ~mapRectangle();
private:
    QRectF rectangle;
    char type;
};

#endif // MAPRECTANGLE_H
