#ifndef GRID
#define GRID

#include <vector>
#include <QVector2D>
#include <QImage>
#include "tile.h"

using namespace std;

class Grid{
public:
    Grid();
    void load(const QString path);
    void save(const QString path);

    Tile* tileAt(QVector2D tilePos);
    const Tile* tileAt(QVector2D tilePos) const;



    QVector2D getTileSize();
    QVector2D getGridSize();
    Tile* getStartTile();
    void draw(QPainter& painter);
    void selectTile(Tile *tile);
    void setStartTile();
    void colorTile(QColor color);
    void newCleanGrid(QVector2D gridSize);

    TileType colorToType(QColor color);
    QColor typeToColor(TileType type);
private:
    Tile* m_selectedTile;
    Tile* m_droneStartTile;
    QVector2D m_gridSize;
    QVector2D m_tileSize;
    vector<Tile> m_grid;
    vector<pair<TileType,QColor>> m_colorMap;
    QImage m_image;


};

#endif // GRID

