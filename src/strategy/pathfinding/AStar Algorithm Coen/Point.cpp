/**
* A* Algorithm Implementation using STL is
* Copyright (C)2001-2005 Justin Heyes-Jones
* Permission is given by the author to freely redistribute and
* include this code in any program as long as this credit is
* given where due.
*
* COVERED CODE IS PROVIDED UNDER THIS LICENSE ON AN "AS IS" BASIS,
* WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESSED OR IMPLIED,
* INCLUDING, WITHOUT LIMITATION, WARRANTIES THAT THE COVERED CODE
* IS FREE OF DEFECTS, MERCHANTABLE, FIT FOR A PARTICULAR PURPOSE
* OR NON-INFRINGING. THE ENTIRE RISK AS TO THE QUALITY AND
* PERFORMANCE OF THE COVERED CODE IS WITH YOU. SHOULD ANY COVERED
* CODE PROVE DEFECTIVE IN ANY RESPECT, YOU (NOT THE INITIAL
* DEVELOPER OR ANY OTHER CONTRIBUTOR) ASSUME THE COST OF ANY
* NECESSARY SERVICING, REPAIR OR CORRECTION. THIS DISCLAIMER OF
* WARRANTY CONSTITUTES AN ESSENTIAL PART OF THIS LICENSE. NO USE
* OF ANY COVERED CODE IS AUTHORIZED HEREUNDER EXCEPT UNDER
* THIS DISCLAIMER.
*
* Use at your own risk!
**/

#include "Point.h"

struct Tile
{
    Tile *parent;
    bool busy;
    bool opened;
    bool closed;
    unsigned int f, g, h;
    int x, y;
}

Point::Point(){
    Tile *tile;
    tile->parent = NULL;
    tile->closed = false;
    tile->opened = false;

    x = y = f = g = h = 0;
}

Point::Point(int x, int y, bool w)
{
    Point();

    this->walkable = w;
    this->x = x;
    this->y = y;
}

Position* Point::getPosition()
{
    return new Position((float)(x * 64), (float)(y * 64));
}

Point* Point::getParent()
{
    return parent;
}

void Point::setParent(Point *p)
{
    parent = p;
}

int Point::getX()
{
    return x;
}

int Point::getY()
{
    return y;
}

float Point::getXf()
{
    return (float)x;
}

float Point::getYf()
{
    return (float)y;
}

int Point::getGScore(Point *p)
{
    return p->g + ((x == p->x || y == p->y) ? 10 : 14);
}

int Point::getHScore(Point *p)
{
    return (abs(p->x - x) + abs(p->y - y)) * 10;
}

int Point::getGScore()
{
    return g;
}

int Point::getHScore()
{
    return h;
}

int Point::getFScore()
{
    return f;
}

void Point::computeScores(Point *end)
{
    g = getGScore(parent);
    h = getHScore(end);
    f = g + h;
}

bool Point::hasParent()
{
    return parent != NULL;
}

