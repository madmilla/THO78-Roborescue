#include "MapSearchNode.h"
MapSearchNode::MapSearchNode(){
    x = 0;
    y = 0;
}

MapSearchNode::MapSearchNode(Map *map, Route *route){
    this->map = map;
    x = 0;
    y = 0;
}
MapSearchNode::MapSearchNode(Route *route){
	x = 0;
	y = 0;
}


MapSearchNode::MapSearchNode(int px, int py){
   x=px; y=py;
}


/**
 * Destructor of Map.
 */

MapSearchNode::~MapSearchNode(){
    // Destructor
}


bool MapSearchNode::IsSameState( MapSearchNode &rhs )
{

    // same state in a maze search is simply when (x,y) are the same
	if ((x == rhs.x) &&
		(y == rhs.y))
	{
		return true;
	}
    else
    {
        return false;
    }

}

void MapSearchNode::PrintNodeInfo()
{
	Container::setRouteTile(x, y);
//	std::cout << "PrintNodeInfo "<< x << y << std::endl;
//	char str[100];
//    sprintf( str, "Node position : (%d,%d)\n", x,y );
//    cout << str;
}

// Here's the heuristic function that estimates the distance from a Node
// to the Goal.

float MapSearchNode::GoalDistanceEstimate( MapSearchNode &nodeGoal )
{
    return fabsf(x - nodeGoal.x) + fabsf(y - nodeGoal.y);
}

bool MapSearchNode::IsGoal( MapSearchNode &nodeGoal )
{
    if( (x == nodeGoal.x) &&
        (y == nodeGoal.y) )
    {
        return true;
    }

    return false;
}

// This generates the successors to the given Node. It uses a helper function called
// AddSuccessor to give the successors to the AStar class. The A* specific initialisation
// is done for each node internally, so here you just set the state information that
// is specific to the application
bool MapSearchNode::GetSuccessors( AStarSearch<MapSearchNode> *astarsearch, MapSearchNode *parent_node )
{

    int parent_x = -1;
    int parent_y = -1;

    if( parent_node )
    {
        parent_x = parent_node->x;
        parent_y = parent_node->y;
    }


    MapSearchNode NewNode;

    // push each possible move except allowing the search to go backwards
    if( (map->GetMap( x-1, y ) < 9)
        && !((parent_x == x-1) && (parent_y == y))
      )
    {
        NewNode = MapSearchNode( x-1, y );
        astarsearch->AddSuccessor( NewNode );
    }
    if( (map->GetMap( x, y-1 ) < 9)
        && !((parent_x == x) && (parent_y == y-1))
      )
    {
        NewNode = MapSearchNode( x, y-1 );
        astarsearch->AddSuccessor( NewNode );
    }

    if( (map->GetMap( x+1, y ) < 9)
        && !((parent_x == x+1) && (parent_y == y))
      )
    {
        NewNode = MapSearchNode( x+1, y );
        astarsearch->AddSuccessor( NewNode );
    }


    if( (map->GetMap( x, y+1 ) < 9)
        && !((parent_x == x) && (parent_y == y+1))
        )
    {
        NewNode = MapSearchNode( x, y+1 );
        astarsearch->AddSuccessor( NewNode );
    }

    return true;
}

// given this node, what does it cost to move to successor. In the case
// of our map the answer is the map terrain value at this node since that is
// conceptually where we're moving

float MapSearchNode::GetCost( MapSearchNode &successor )
{
    return (float) map->GetMap( x, y );

}

void MapSearchNode::Search(int nodeStartX, int nodeStartY, int nodeEndX, int nodeEndY){
    cout << "STL A* Search implementation\n(C)2001 Justin Heyes-Jones\n";

        // Our sample problem defines the world as a 2d array representing a terrain
        // Each element contains an integer from 0 to 5 which indicates the cost
        // of travel across the terrain. Zero means the least possible difficulty
        // in travelling (think ice rink if you can skate) whilst 5 represents the
        // most difficult. 9 indicates that we cannot pass.

        // Create an instance of the search class...

        AStarSearch<MapSearchNode> astarsearch;

        unsigned int SearchCount = 0;

        const unsigned int NumSearches = 1;

        while(SearchCount < NumSearches)
        {

            // Create a start state
            MapSearchNode nodeStart;
            nodeStart.x = nodeStartX;
            nodeStart.y = nodeStartY;

            // Define the goal state
            MapSearchNode nodeEnd;
            nodeEnd.x = nodeEndX;
            nodeEnd.y = nodeEndY;

            // Set Start and goal states

            astarsearch.SetStartAndGoalStates( nodeStart, nodeEnd );

            unsigned int SearchState;
            unsigned int SearchSteps = 0;

            do
            {
                SearchState = astarsearch.SearchStep();

                SearchSteps++;

        #if DEBUG_LISTS

                cout << "Steps:" << SearchSteps << "\n";

                int len = 0;

                cout << "Open:\n";
                MapSearchNode *p = astarsearch.GetOpenListStart();
                while( p )
                {
                    len++;
        #if !DEBUG_LIST_LENGTHS_ONLY
                    ((MapSearchNode *)p)->PrintNodeInfo();
        #endif
                    p = astarsearch.GetOpenListNext();

                }

                cout << "Open list has " << len << " nodes\n";

                len = 0;

                cout << "Closed:\n";
                p = astarsearch.GetClosedListStart();
                while( p )
                {
                    len++;
        #if !DEBUG_LIST_LENGTHS_ONLY
                    p->PrintNodeInfo();
        #endif
                    p = astarsearch.GetClosedListNext();
                }

                cout << "Closed list has " << len << " nodes\n";
        #endif

            }
            while( SearchState == AStarSearch<MapSearchNode>::SEARCH_STATE_SEARCHING );

            if( SearchState == AStarSearch<MapSearchNode>::SEARCH_STATE_SUCCEEDED )
            {
                cout << "Search found goal state\n";

                    MapSearchNode *node = astarsearch.GetSolutionStart();

        #if DISPLAY_SOLUTION
                    cout << "Displaying solution\n";
        #endif
                    int steps = 0;

                    node->PrintNodeInfo();
                    for( ;; )
                    {
                        node = astarsearch.GetSolutionNext();

                        if( !node )
                        {
                            break;
                        }

                        node->PrintNodeInfo();
                        steps ++;

                    };

                    cout << "Solution steps " << steps << endl;

                    // Once you're done with the solution you can free the nodes up
                    astarsearch.FreeSolutionNodes();


            }
            else if( SearchState == AStarSearch<MapSearchNode>::SEARCH_STATE_FAILED )
            {
                cout << "Search terminated. Did not find goal state\n";

            }

            // Display the number of loops the search went through
            cout << "SearchSteps : " << SearchSteps << "\n";

            SearchCount ++;

            astarsearch.EnsureMemoryFreed();
        }
}
