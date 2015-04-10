#ifndef MAP_H
#define MAP_H

#include <QVector>
#include <QTableWidget>
using namespace std;

class Map
{
public:
    Map(string fileName);
    Map(string fileName, int height, int width);
    vector<vector< int > > getMapContent();
    void setMapContent(vector<vector< int > > newMapLayout);
    void setMapObject(int object,int y, int x);
    int getMapObject(int y, int x);
    void saveMap();
    int width = 0;
    int height = 0;
    string fileName;
    ~Map();

private:
    vector<vector< int > > mapLayout;
    void createNewMap(string fileName);
    void loadMap(string fileName);
};

#endif // MAP_H
