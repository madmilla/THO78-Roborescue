#include "tile.h"

Tile::Tile(TileType tileType,QColor tileColor, QVector2D pos, QVector2D size):
    m_tileType(tileType),
    m_pos(pos),
    m_size(size),
    m_tileColor(tileColor)
{}

void Tile::drawTile(QPainter& painter, bool selected, bool startTile){
    painter.fillRect(m_pos.x(),m_pos.y(),m_size.x(),m_size.y(),m_tileColor);

    if(selected) {
        painter.setPen(Qt::yellow);
    }else if(startTile){
        painter.setPen(Qt::red);
    }else{
        painter.setPen(Qt::gray);
    }
    painter.drawRect(m_pos.x(),m_pos.y(),m_size.x(),m_size.y());
}

QVector2D Tile::getPosition()
{
    return m_pos;
}

TileType Tile::getTileType()
{
    return m_tileType;
}

void Tile::setTileType(TileType type)
{
    m_tileType = type;
}

void Tile::setTileColor(QColor color)
{
    m_tileColor = color;
}
