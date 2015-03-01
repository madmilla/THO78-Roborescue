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
    const void load(const QString path);
    const void save(const QString path);

    const void placeDrone();

    Tile* tileAt(QVector2D tilePos);
    const Tile* tileAt(QVector2D tilePos) const;



    const QVector2D getTileSize();
    const QVector2D getGridSize();
    Tile* getStartTile();
    void draw(QPainter& painter);
    const void selectTile(Tile *tile);
    const void setStartTile();
    const void colorTile(QColor color);
    const void newCleanGrid(QVector2D gridSize);

    const TileType colorToType(QColor color);
    const QColor typeToColor(TileType type);
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

