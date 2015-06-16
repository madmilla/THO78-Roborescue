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

* Use at your own risk!
**/

#ifndef MAPSEARCHNODE_H
#define MAPSEARCHNODE_H

#include "fsa.h"
#include "stlastar.h"
#include <iostream>
#include <stdio.h>
#include <math.h>
#include "Map.h"

class MapSearchNode
{
public:
    int x;	 // the (x,y) positions of the node
    int y;

    MapSearchNode();
    MapSearchNode(Map * map);
    MapSearchNode( int px, int py );
    ~MapSearchNode();

    float GoalDistanceEstimate( MapSearchNode &nodeGoal );
    bool IsGoal( MapSearchNode &nodeGoal );
    bool GetSuccessors( AStarSearch<MapSearchNode> *astarsearch, MapSearchNode *parent_node );
    float GetCost( MapSearchNode &successor );
    bool IsSameState( MapSearchNode &rhs );

    void PrintNodeInfo();
    void Search(int nodeStartX, int nodeStartY, int nodeEndX, int nodeEndY);
    Map * map;



};

#endif // MAPSEARCHNODE_H