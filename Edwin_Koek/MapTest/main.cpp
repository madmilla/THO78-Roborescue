#include "window.h"
#include "grid.h"
#include <QApplication>
#include <iostream>
using namespace std;

void printMap(Grid& grid){
    cout << endl;
    for(int y = 0; y < grid.getGridSize().y(); y++){
        for(int x = 0; x < grid.getGridSize().x(); x++){
            switch(grid.getGrid()[(y * grid.getGridSize().x()) + x].getTileType()){
            case TileType::Walkable:
                cout<<"W ";
                break;
            case TileType::Dangerous:
                cout<<"D ";
                break;
            case TileType::Blocked:
                cout<<"B ";
                break;
            case TileType::Object:
                cout<<"O ";
                break;
            case TileType::Undefined:
                cout<<"U ";
                break;
            }
        }
        cout << endl;
    }
    cout << endl;
}

bool testMap(Grid& grid,
             string mapName,
             int expWalkable = 0,
             int expDangerous = 0,
             int expBlocked = 0,
             int expObject = 0,
             int expUndefined = 0)
{
    int walkable = 0,dangerous = 0,blocked = 0,object = 0,undefined = 0;
    for(Tile tile : grid.getGrid()){
        switch(tile.getTileType()){
        case TileType::Walkable:
            walkable++;
            break;
        case TileType::Dangerous:
            dangerous++;
            break;
        case TileType::Blocked:
            blocked++;
            break;
        case TileType::Object:
            object++;
            break;
        case TileType::Undefined:
            undefined++;
            break;
        }
    }
    if((walkable + dangerous + blocked +object + undefined) > 0){
        cout << "Load succes" << endl;
        printMap(grid);
        cout << mapName << " has:" << endl;
        cout << walkable << " walkable tiles " << expWalkable << " expected" << endl;
        cout << dangerous << " dangerous tiles " << expDangerous <<" expected"<< endl;
        cout << blocked << " blocked tiles " << expBlocked << " expected" <<endl;
        cout << object << " objects " << expObject << " expected" <<endl;
        cout << undefined << " undefined tiles " << expUndefined << " expected" << endl;
        if(walkable == expWalkable && dangerous == expDangerous && blocked == expBlocked
                && object == expObject && undefined == expUndefined){
            cout << "All values are expected" << endl;
            return true;
        }
        else{
            cout << "Unexpected values" << endl;
            return false;
        }
    }
    else{
        cout << "Load failed" << endl;
        return false;
    }

}

int main()
{
    Grid grid;
    cout << endl << "STARTING TEST" << endl;

    cout << "Loading good map..." << endl;

    grid.load("maps/goodtestmap.png");
    testMap(grid,"Good map",277,31,88,4,0);

    cout << endl << endl;

    cout << "Loading bad map..." << endl;

    grid.load("maps/badtestmap.png");
    testMap(grid,"Bad map",0,0,10,0,1540);

    cout << endl << endl;

    cout << "Creating clean 20x20 map..." << endl;
    grid.newCleanGrid(QVector2D(20,20));
    testMap(grid,"New 20x20 map",0,0,0,0,400);

    cout << endl;

    cout << "Selecting and editing first 4 tiles to Walkable - Dangerous - Blocked - Object" << endl;
    grid.selectTile(grid.tileAt(QVector2D(grid.getTileSize().x() * 0 ,grid.getTileSize().y() * 0)));
    grid.colorTile(grid.typeToColor(TileType::Walkable));
    grid.selectTile(grid.tileAt(QVector2D(grid.getTileSize().x() * 1 ,grid.getTileSize().y() * 0)));
    grid.colorTile(grid.typeToColor(TileType::Dangerous));
    grid.selectTile(grid.tileAt(QVector2D(grid.getTileSize().x() * 0 ,grid.getTileSize().y() * 1)));
    grid.colorTile(grid.typeToColor(TileType::Blocked));
    grid.selectTile(grid.tileAt(QVector2D(grid.getTileSize().x() * 1 ,grid.getTileSize().y() * 1)));
    grid.colorTile(grid.typeToColor(TileType::Object));



    walkable = 0,dangerous = 0,blocked = 0,object = 0,undefined = 0;
    cout << endl;

    cout << "Saving and loading the clean 20x20 map" << endl;
    cout << "Saving clean 20x20 map..." << endl;
    grid.save("maps/newcleanmap.png");
    cout << "Loading good map (just to be sure the save works properly)..." << endl;
    grid.load("maps/goodtestmap.png");
    cout << "Loading clean 20x20 map..." << endl;

    grid.load("maps/newcleanmap.png");
    testMap(grid,"Edited 20x20 map",1,1,1,1,396);

}

