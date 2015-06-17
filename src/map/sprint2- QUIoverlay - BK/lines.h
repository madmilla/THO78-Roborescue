/*!
 *  Class defining a line using 4 numerical values indicating the coordinates (X1, Y1, X2, Y2).
 *  Depending on the chosen T, the numerical values can either be of type int or float
 *  \author    Bianca Krieger
 */
#ifndef LINE_H
#define LINE_H

template <typename T>

class Lines
{
//T must be a int or float
public:
    Lines<T>(T x1, T y1, T x2, T y2) :
        x1(x1),
        y1(y1),
        x2(x2),
        y2(y2){}
    T x1, y1, x2, y2;
};

#endif // LINE_H
