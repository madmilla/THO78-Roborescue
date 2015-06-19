/**
 * @file Map.cpp
 * @author Coen Andriessen
 * @version 1.8
 */

#include "Map.h"

const int MAP_WIDTH = 20;
const int MAP_HEIGHT = 20;

int world_map[ MAP_WIDTH * MAP_HEIGHT ] =
{

// 0001020304050607080910111213141516171819
    9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,   // 00
    9,1,1,9,9,1,1,1,1,1,1,1,1,1,1,1,1,1,1,9,   // 01
    9,1,1,1,9,1,1,1,1,1,1,1,1,1,1,1,1,1,1,9,   // 02
    9,1,9,1,9,1,1,1,1,1,1,1,1,1,1,1,1,1,1,9,   // 03
    9,1,9,1,9,1,1,1,1,1,1,1,1,1,1,1,1,1,1,9,   // 04
    9,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,9,   // 05
    9,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,9,   // 06
    9,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,9,   // 07
    9,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,9,   // 08
    9,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,9,   // 09
    9,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,9,   // 10
    9,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,9,   // 11
    9,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,9,   // 12
    9,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,9,   // 13
    9,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,9,   // 14
    9,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,9,   // 15
    9,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,9,   // 16
    9,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,9,   // 17
    9,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,9,   // 18
    9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,   // 19

};

// map helper functions



/**
 * Constructor of Map.
 *
 * @param rosbee
 */

Map::Map(Rosbee *rosbee){
    bool_isLoaded = false;
    this->rosbee = rosbee;
}

/**
 * Destructor of Map.
 */

Map::~Map(){
    // Destructor
}

/**
 * Function to set tile in map. X and Y where the tile is on the map,
 * value what kind of tile it is.
 *
 * @param x
 * @param y
 * @param value
 */

void Map::setTile(int x, int y, int * value){
	if (GetMap(x, y) == 9){
		return;
	}
	else{
		world_map[(y*MAP_WIDTH) + x] = *value;
	}
}

void Map::updateMap(){
	int * tmp = new int;
	*tmp = 9;
	setTile(1, 5, tmp);
}

/**
 * Function to get tile in map. X and Y to search which tile must be returned.
 *
 * @param x
 * @param y
 * @return myMap[x][y]
 */

int Map::getTile(int x, int y){
    if(x < 0 || x > 19 || y < 0 || y > 19){
        return 9;
    }else{
        std::cout <<"Debug:" << x<<y;
        //std::cout <<"Debug:" <<myMap[x][y];
        //return *myMap[x][y];
    }

}

/**
 * Function to check if the map is full scanned. For all the tiles in myRoute,
 * will be checked if they are connect to a tile what isnt scanned.
 */

bool Map::isMapFullScanned(){
	for (int iiy = 0; iiy < 20; iiy++){
		for (int iix = 0; iix < 20; iix++){
			if (GetMap(iix, iiy) == 1){
				return false;
			}
		}
	}
	return true;
}

void Map::printMap(){
	for (int iiy = 0; iiy < 20; iiy++){
		for (int iix = 0; iix < 20; iix++){
				std::cout << GetMap(iix, iiy);
				if (iix == 19){
					std::cout << " " << std::endl;
				}
		}
	}
}

bool Map::tileIsAccessible(int x, int y){
	if (GetMap(x, y) < 9){
		return true;
	}
	else{
		return false;
	}
}

void Map::tilesInRangeLidar(){
    int x = rosbee->getRosbeeLocationX()-2;
    int y = rosbee->getRosbeeLocationY()-2;
    int * tmp = new int;
    *tmp=2;
    for(int i = 0; i < 5; i++){
        for(int ii = 0; ii < 5; ii++){
            if((x+i) >= 1 && (x+i) <= 18 && (y+ii) >= 1 && (y+ii) <= 18){
                setTile((x+i), (y+ii), tmp);
            }
        }
    }
}

int * Map::getUnscannedTile(){
    static int tileLocation[1];
    for(int iiy = 0; iiy < 20; iiy++){
        for(int iix = 0; iix < 20; iix++){
            if(GetMap(iix, iiy) == 1){
                std::cout << iix << " " << iiy << std::endl;
                tileLocation[0] = iix;
                tileLocation[1] = iiy;
                return tileLocation;
            }
        }
    }
}

/**
 * Function to check if the location of the rosbee is changed. When the location is changed,
 * the old location will be stored in myRoute.
 */

void Map::rosbeeLocationChanged(){
    // Check if the location of the rosbee is changed.
    if(rosbee->isLocationChanged()){
        // Set tile where to rosbee was on isScanned.
        int * tmp = new int;
        *tmp=1;
        setTile(rosbee->getOldRosbeeLocationX(), rosbee->getOldRosbeeLocationY(), tmp);
        // Create pair temp to store the old rosbee location.
        std::pair <int, int> temp;
        temp.first = rosbee->getOldRosbeeLocationX();
        temp.second = rosbee->getOldRosbeeLocationY();
        // Set the old rosbee location in myRoute.
        myRoute.push_back(temp);
        // Increase steps.
        numberOfSteps++;
    }
}

/**
 * Function get tile that will be needed in the mid area scan algorithm.
 * First will be check if the tile above the rosbee is free, then right to
 * the rosbee, then left to the rosbee and last down to the rosbee. When there
 * is no tile available the last tile out myRoute will be returned.
 * Param x and y to search for tile location.
 *
 * @param x
 * @param y
 * @return tileLocation
 */

int * Map::getTileForMidAlgorithm(int x, int y){
    // Create temp to save tile location.
    static int tileLocation[1];
    // Check tile above to the rosbee.
    if(GetMap(x, y-1) == 0){
        tileLocation[0] = int(x);
        tileLocation[1] = int(y-1);
    }
    // Check tile right to the rosbee.
    else if(GetMap(x+1, y) == 0){
        tileLocation[0] = int(x+1);
        tileLocation[1] = int(y);
    }
    // Check tile left to the rosbee.
    else if(GetMap(x-1, y) == 0){
        tileLocation[0] = int(x-1);
        tileLocation[1] = int(y);
    }
    // Check tile below to the rosbee.
    else if(GetMap(x, y+1) == 0){
        tileLocation[0] = int(x);
        tileLocation[1] = int(y+1);
    }
    // When the rosbee is stuck.
    else{
        // Get size of myRoute.
        int i = myRoute.size()-1;
        // Last tile of myRoute.
        tileLocation[0] = int(myRoute[i-1].first);
        tileLocation[1] = int(myRoute[i-1].second);
        // Remove tile out myRoute.
        myRoute.pop_back();
        myRoute.pop_back();
    }
    return tileLocation;
}

/**
 * Function to check if the tile is connected to a tile what is not scanned.
 * Param x and y to search for tile location.
 *
 * @param x
 * @param y
 */

bool Map::isTileConnectedScanned(int x, int y){
    // Check if tile left to the tile is scanned.
    if(getTile(x-1, y) == 0){
        return false;
    }
    // Check if tile right to the tile is scanned.
    else if(getTile(x+1, y) == 0){
        return false;
    }
    // Check if tile above to the tile is scanned.
    else if(getTile(x, y-1) == 0){
        return false;
    }
    // Check if tile below to the tile is scanned.
    else if(getTile(x, y+1) == 0){
        return false;
    }else{
        return true;
    }
}

/**
 * Function to check if the map is loaded.
 *
 * @return bool_isLoaded
 */

bool Map::isLoaded(){
    return bool_isLoaded;
}

/**
 * Function to get the number of steps.
 *
 * @return numberOfSteps
 */

int Map::getNumberOfSteps(){
    return numberOfSteps;
}

/**
 * Function to choose the map. Random number will be create to
 * choose a map.
 *
 * @return pathMap
 */

const char * Map::chooseMap(){
    srand(static_cast<unsigned int>(time(0)));
    int random = rand() % 5;
    switch(5){
        case 1:
            return pathMap1;
            break;
        case 2:
            return pathMap2;
            break;
        case 3:
            return pathMap3;
            break;
        case 4:
            return pathMap4;
            break;
        default:
            return pathMap5;
            break;
    }

}

/**
 * Function to load the map by filename.
 *
 * @param filename
 */

void Map::loadMap(const char * filename){
    int xLength = 0;
    int yLength = 0;
    ifstream file(filename, ifstream::binary);
    file.seekg(0, file.end);
    // Store length of file.
    int length = file.tellg();
    file.seekg(0, file.beg);
    // Create buffer for file.
    char * buffer = new char[length];
    // Store data of file in buffer.
    file.read(buffer, length);
    file.close();
    // Loop through buffer.
    for(int i = 0; i < int(strlen(buffer)); i++){
        // Store character at i in buffer in character.
        int character = int(buffer[i]);
        // When xLength is 20 set xLength on 0 and increase yLength by 1.
        if(xLength == 20){
            xLength = 0;
            yLength = yLength + 1;
        }
        // Check for correct input.
        //if(character == '0' || character == '3' || character == '2'){
            // Create tile with value of character.

            int * pointer = new int;
            *pointer = character;
            //setTile(xLength, yLength, pointer);
            xLength = xLength + 1;
        //}
        /*
        if(character == 'Q'){
            for(int henk = (i + 1); henk < (i + 6); henk++){
            temp += buffer[henk];
            std::cout << temp << std::endl;
            }*/
       // }
    }
    // Set rosbee location.

    rosbee->setRosbeeLocationX(1);
    rosbee->setRosbeeLocationY(1);
    // Set loaded on true.
    bool_isLoaded = true;
}

int Map::GetMap( int x, int y )
{
    if( x < 0 ||
        x >= MAP_WIDTH ||
         y < 0 ||
         y >= MAP_HEIGHT
      )
    {
        return 9;
    }
    return world_map[(y*MAP_WIDTH)+x];
}
