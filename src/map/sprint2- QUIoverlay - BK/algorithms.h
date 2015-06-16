/*!
 *  Class used for calculating normalized lines, calculating the coordinates
 *  of isometric 2D lines and defining several constants used for displaying
 *  the lines
 *  \author    Bianca Krieger
 */

#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <vector>
#include "line.h"
#include "point.h"

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

    static const float NEAR_VAL = 5.0f;
    static const float FAR_VAL = 30.0f;

    static void test();

    static void getMinMax(const std::vector<Line<int> > lines, int &minX, int &maxX, int &minY, int &maxY);

    /*!
    *   Finds the minimum and maximum x and y for the range of the map and
    *   normalizes the x and y values of the lines between -1.0 and 1.0
    *   @param lines vector of lines that need to be normalized
    *   @return returns a vector of lines between -1.0 and 1.0
    */
    static const std::vector<Line<float> > getNormalizedLinesForPolygons(const std::vector<std::vector<point> >& polygons);

    /*!
    *   Finds the minimum and maximum x and y for the range of the map and
    *   normalizes the x and y values of the lines between -1.0 and 1.0
    *   @param lines vector of lines that need to be normalized
    *   @return returns a vector of lines between -1.0 and 1.0
    */
    static const std::vector<Line<float> > normalizeLines(const std::vector<Line<int> > lines, int &minX, int &maxX, int &minY, int &maxY);

    /*!
    *   Calculate the coordinates were a line should be drawn for an isometric representation
    *   @param line Normalized line to calculate isometric positions for
    *   @return returns Line with coordinates translated to isometric position
    */
    static const Line<float> twoDToIso(const Line<float> line);

    /*!
    *   Calculate the coordinates were the lines should be drawn for an isometric representation
    *   @param linesNormalized Normalized lines to calculate isometric positions for
    *   @return returns Vector of lines with coordinates translated to isometric position
    */
    static const std::vector<Line<float> > twoDToIsoVector(const std::vector<Line<float> > linesNormalized);
};

#endif // ALGORITHMS_H
