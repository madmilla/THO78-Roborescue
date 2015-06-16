#include "algorithms.h"

#include <stdio.h>
#include <iostream>
#include <limits.h>

void Algorithms::getMinMax(const std::vector<Line<int> > lines, int &minX, int &maxX, int &minY, int &maxY){
    // Set initial values to extremes of the opposites
    minX = INT_MAX;
    maxX = INT_MIN;
    minY = INT_MAX;
    maxY = INT_MIN;

    // Find the minimum and maximum x and y for the range of the map
    for(std::vector<Line<int> >::const_iterator it = lines.begin(); it != lines.end(); ++it) {
        if (minX > it->x1) {
            minX = it->x1;
        }
        if (minX > it->x2) {
            minX = it->x2;
        }
        if (maxX < it->x1) {
            maxX = it->x1;
        }
        if (maxX < it->x2) {
            maxX = it->x2;
        }

        if (minY > it->y1) {
            minY = it->y1;
        }
        if (minY > it->y2) {
            minY = it->y2;
        }
        if (maxY < it->y1) {
            maxY = it->y1;
        }
        if (maxY < it->y2) {
            maxY = it->y2;
        }
    }
}

const std::vector<Line<float> > Algorithms::getNormalizedLinesForPolygons(const std::vector<std::vector<point> >& polygons) {
    std::vector<std::vector<point> >::const_iterator it_polygons;
    std::vector<point>::const_iterator it;

    // Set initial values to extremes of the opposites
    int minX = INT_MAX;
    int maxX = INT_MIN;
    int minY = INT_MAX;
    int maxY = INT_MIN;

    // Find the minimum and maximum x and y for the range of the map
    for(it_polygons = polygons.begin(); it_polygons != polygons.end(); ++it_polygons) {
        for(it = (*it_polygons).begin(); it != (*it_polygons).end(); ++it) {
            if (minX > it->getX()) {
                minX = it->getX();
            }

            if (maxX < it->getX()) {
                maxX = it->getX();
            }

            if (minY > it->getY()) {
                minY = it->getY();
            }
            if (maxY < it->getY()) {
                maxY = it->getY();
            }
        }
    }
    int difX = maxX - minX;
    int difY = maxY - minY;

    std::vector<Line<float> > linesNormalized;
    for(it_polygons = polygons.begin(); it_polygons != polygons.end(); ++it_polygons) {
        point *prev = NULL;
        for(it = (*it_polygons).begin(); it != (*it_polygons).end(); ++it) {
            if (prev != NULL) {
                // Normalize x and y between -1.0 and 1.0
                float x1 = ((float(prev->getX() - minX) / difX) * DIF_X) + MIN_X;
                float y1 = ((float(prev->getY() - minY) / difY) * DIF_Y) + MIN_Y;
                float x2 = ((float(it->getX() - minX) / difX) * DIF_X) + MIN_X;
                float y2 = ((float(it->getY() - minY) / difY) * DIF_Y) + MIN_Y;

                Line<float> lineNormalized(x1, y1, x2, y2);
                linesNormalized.push_back(lineNormalized);
            }
            *prev = *it;
        }
    }

    return linesNormalized;
}

const std::vector<Line<float> > Algorithms::normalizeLines(const std::vector<Line<int> > lines, int &minX, int &maxX, int &minY, int &maxY){
  /*  // Set initial values to extremes of the opposites
    int minX = INT_MAX;
    int maxX = INT_MIN;
    int minY = INT_MAX;
    int maxY = INT_MIN;

    // Find the minimum and maximum x and y for the range of the map
    for(std::vector<Line<int> >::const_iterator it = lines.begin(); it != lines.end(); ++it) {
        if (minX > it->x1) {
            minX = it->x1;
        }
        if (minX > it->x2) {
            minX = it->x2;
        }
        if (maxX < it->x1) {
            maxX = it->x1;
        }
        if (maxX < it->x2) {
            maxX = it->x2;
        }

        if (minY > it->y1) {
            minY = it->y1;
        }
        if (minY > it->y2) {
            minY = it->y2;
        }
        if (maxY < it->y1) {
            maxY = it->y1;
        }
        if (maxY < it->y2) {
            maxY = it->y2;
        }
    }*/
    int difX = maxX - minX;
    int difY = maxY - minY;
  //  return const std::vector<Line> linesNormalized

    std::vector<Line<float> > linesNormalized;
    for(std::vector<Line<int> >::const_iterator it = lines.begin(); it != lines.end(); ++it) {
        // Normalize x and y between -1.0 and 1.0
        float x1 = ((float(it->x1 - minX) / difX) * DIF_X) + MIN_X;
        float y1 = ((float(it->y1 - minY) / difY) * DIF_Y) + MIN_Y;
        float x2 = ((float(it->x2 - minX) / difX) * DIF_X) + MIN_X;
        float y2 = ((float(it->y2 - minY) / difY) * DIF_Y) + MIN_Y;

        Line<float> lineNormalized(x1, y1, x2, y2);
        linesNormalized.push_back(lineNormalized);
    }

    return linesNormalized;
}

const Line<float> Algorithms::twoDToIso(const Line<float> line){
    // change the normalized coordinates to make it isometric
    float newX1 = (line.x1 - line.y1) / 2;
    float newY1 = (line.x1 + line.y1) / 2;
    float newX2 = (line.x2 - line.y2) / 2;
    float newY2 = (line.x2 + line.y2) / 2;
    Line<float> lineIso(newX1, newY1, newX2, newY2);
    return lineIso;
}

const std::vector<Line<float> > Algorithms::twoDToIsoVector(const std::vector<Line<float> > linesNormalized){
    std::vector<Line<float> > linesNormalizedIso;
    for(std::vector<Line<float> >::const_iterator it = linesNormalized.begin(); it != linesNormalized.end(); ++it) {
        Line<float> lineNormalizedIso = twoDToIso(*it);
        linesNormalizedIso.push_back(lineNormalizedIso);
    }
    return linesNormalizedIso;
}
