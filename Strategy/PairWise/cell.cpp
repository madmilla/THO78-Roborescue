#include "cell.h"

Cell::Cell()
{

}

Cell::~Cell()
{

}
bool Cell::contains(Tile *t){
    for(Tile* tt :tiles){
        if(tt==t){return true;}
    }
    return false;


}

