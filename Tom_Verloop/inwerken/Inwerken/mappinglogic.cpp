#include "mappinglogic.h"
#include <QMessageBox>


//-------------------------------------------------------------------------------------------------------
//
//  MappingLogic Class
//
//-------------------------------------------------------------------------------------------------------

MappingLogic::MappingLogic()
{
    load_file();
}

MappingLogic::~MappingLogic()
{
    while(!tiles.empty()) delete tiles.front(), tiles.pop_front();
}

void MappingLogic::load_file()
{
    while(!tiles.empty()) delete tiles.front(), tiles.pop_front();
    std::ifstream input("map.txt",std::ios_base::in);
    if(input.is_open())
    {
        while(input.get() == ' ')
        {
            int temp;
            MapTile * t = new MapTile();
            input >> temp;
            t->setx(temp);
            input >> temp;
            t->sety(temp);
            input >> temp;
            t->setstatus(temp);
            tiles.push_back(t);
        }
        input.close();
    }
}

void MappingLogic::save_file()
{
    std::ofstream output("map.txt");
    for (MapTile * i : tiles )
    {
        if(i->getstatus() != 0)
        {
        output << ' ';
        output << i->getx();
        output << ' ';
        output << i->gety();
        output << ' ';
        output << i->getstatus();
        }
    }
    output.close();
}

void MappingLogic::set_tile(int x,int y,int status)
{

    bool set = false;
    for (MapTile * i : tiles )
    {
        if(i->getx() == x && i->gety() == y)
        {

            i->setstatus(status);
            set = true;
        }
    }
    if(!set)
    {
        MapTile * t = new MapTile();
        t->setx(x);
        t->sety(y);
        t->setstatus(status);
        tiles.push_front(t);
    }
}

int MappingLogic::get_tile(int x, int y)
{
    for (MapTile * i : tiles )
    {
        if(i->getx() == x && i->gety() == y)
        {
            return i->getstatus();
        }
    }
    return 0;
}


QList<MapTile*> MappingLogic::getTiles()
{
    return tiles;
}

//-------------------------------------------------------------------------------------------------------
//
//  MapTile Class
//
//-------------------------------------------------------------------------------------------------------


MapTile::MapTile()
{

}

int MapTile::getx()
{
    return x;
}

int MapTile::gety()
{
    return y;
}

int MapTile::getstatus()
{
    return status;
}

void MapTile::setx(int X)
{
    this->x = X;
}

void MapTile::sety(int Y)
{
    this->y = Y;
}

void MapTile::setstatus(int stat)
{
    status = stat;
}



