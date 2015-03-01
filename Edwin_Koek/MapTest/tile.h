#ifndef TILE
#define TILE
#include <QWidget>
#include <QPainter>
#include <QVector2D>

enum class TileType{
    Walkable,
    Blocked,
    Dangerous,
    Object,
    Undefined
};

class Tile{
public:
    Tile(TileType tileType,QColor tileColor, QVector2D pos, QVector2D size);

    void drawTile(QPainter& painter, bool selected = false, bool startTile = false);
    QVector2D getPosition();
    TileType getTileType();
    const void setSelected();
    void setTileType(TileType type);
    void setTileColor(QColor color);
private:
    TileType m_tileType;
    QColor m_tileColor;
    QVector2D m_pos;
    QVector2D m_size;

};

#endif // TILE

