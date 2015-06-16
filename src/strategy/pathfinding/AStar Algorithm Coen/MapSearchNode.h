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
