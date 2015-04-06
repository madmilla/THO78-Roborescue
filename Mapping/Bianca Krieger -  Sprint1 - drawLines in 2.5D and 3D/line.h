#ifndef LINE_H
#define LINE_H

template <typename T>

class Line
{
public:
    Line<T>(T x1, T y1, T x2, T y2) :
        x1(x1),
        y1(y1),
        x2(x2),
        y2(y2){}
    T x1, y1, x2, y2;
};

#endif // LINE_H
