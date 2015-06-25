#ifndef MAPSEARCHNODE_H
#define MAPSEARCHNODE_H

#include "fsa.cpp"
#include "stlastar.cpp"
#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../../../Map/MapStructure/Map.hpp"
#include "../../Common/route.h"
#include "Container.h"

class MapSearchNode
{
public:
    int x;	 // the (x,y) positions of the node
    int y;
	bool notFindRoute = false;

    MapSearchNode();
    MapSearchNode(Map * map, Route * route);
	MapSearchNode(Route * route);
    MapSearchNode( int px, int py );
    ~MapSearchNode();

    float GoalDistanceEstimate( MapSearchNode &nodeGoal );
    bool IsGoal( MapSearchNode &nodeGoal );
    bool GetSuccessors( AStarSearch<MapSearchNode> *astarsearch, MapSearchNode *parent_node );
    float GetCost( MapSearchNode &successor );
    bool IsSameState( MapSearchNode &rhs );

    void PrintNodeInfo();
    void Search(int nodeStartX, int nodeStartY, int nodeEndX, int nodeEndY);
    static Map * map;
};

#endif // MAPSEARCHNODE_H
