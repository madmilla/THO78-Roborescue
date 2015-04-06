#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <vector>
#include "line.h"

class Algorithms
{
public:  

    static const float MAX_X =  1.0f;
    static const float MIN_X = -1.0f;
    static const float MAX_Y =  1.0f;
    static const float MIN_Y = -1.0f;

    static const float DIF_X = 2.0f; // MAX_X - MIN_X;
    static const float DIF_Y = 2.0f; // MAX_Y - MIN_Y;

    static const float BOTTOM = -1.0f;
    static const float HEIGHT = 0.5f;
    static const float HEIGHT_ISO = 0.2f;

    static const float ZOOM_OUT_Z = -8.0f;
    static const float NEAR_VAL = 5.0f;
    static const float FAR_VAL = 30.0f;

    static const std::vector<Line<float> > normalizeLines(const std::vector<Line<int> > lines);
    static const Line<float> twoDToIso(const Line<float>);
    static const std::vector<Line<float> > twoDToIsoVector(const std::vector<Line<float> > linesNormalized);
};

#endif // ALGORITHMS_H
