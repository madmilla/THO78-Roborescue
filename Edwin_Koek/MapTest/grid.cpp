#include "grid.h"
#include <iostream>

Grid::Grid():
    m_selectedTile(nullptr),
    m_colorMap({{TileType::Walkable,Qt::green},
               {TileType::Blocked,Qt::black},
               {TileType::Dangerous,Qt::darkRed},
               {TileType::Object,Qt::blue},
               {TileType::Undefined,Qt::white}})
{}

void Grid::load(const QString path){
    if(!path.isNull()){
        m_image = QImage(path);
        m_gridSize = {static_cast<float>(m_image.size().width()),static_cast<float>(m_image.size().height())};
        m_tileSize = {800/static_cast<float>(m_image.size().width()),600/static_cast<float>(m_image.size().height())};
        m_grid.clear();
        for(int y = 0; y < m_gridSize.y(); y++){
            for(int x = 0; x < m_gridSize.x();x++){
                m_grid.push_back({colorToType(QColor(m_image.pixel(x,y))),
                                  typeToColor(colorToType(QColor(m_image.pixel(x,y)))),
                                  {x * m_tileSize.x(),y * m_tileSize.y()},
                                  m_tileSize});
             }
        }
    }
}

void Grid::save(const QString path){
    if(!path.isNull()){
        m_image.save(path);
    }
}

Tile *Grid::tileAt(QVector2D tilePos){
    if(0 > tilePos.y() || tilePos.y() > m_gridSize.y() * m_tileSize.y()
            || 0 > tilePos.x() || tilePos.x() > m_gridSize.x() * m_tileSize.x()){
        cout << "tileAt: Tile position out of bounds" << endl;
        return nullptr;
    }
    else{
        int x = floor(tilePos.x() / m_tileSize.x());
        int y = floor(tilePos.y() / m_tileSize.y());
        return &m_grid.at((m_gridSize.x() * y) + x);
    }
}


const Tile* Grid::tileAt(QVector2D tilePos) const{
    if(0 > tilePos.y() || tilePos.y() > m_gridSize.y() * m_tileSize.y()
            || 0 > tilePos.x() || tilePos.x() > m_gridSize.x() * m_tileSize.x()){
        cout << "tileAt: Tile position out of bounds" << endl;
        return nullptr;
    }
    else{
        int x = floor(tilePos.x() / m_tileSize.x());
        int y = floor(tilePos.y() / m_tileSize.y());
        return &m_grid.at((m_gridSize.x() * y) + x);
    }
}

QVector2D Grid::getTileSize()
{
    return m_tileSize;
}

QVector2D Grid::getGridSize()
{
    return m_gridSize;
}

Tile *Grid::getStartTile()
{
    return m_droneStartTile;
}

void Grid::draw(QPainter& painter){
    for(Tile& tile: m_grid){
        tile.drawTile(painter,false);
    }
    if(m_selectedTile){
        m_selectedTile->drawTile(painter,true);
    }
    if(m_droneStartTile){
        m_droneStartTile->drawTile(painter,false,true);
    }
}

void Grid::selectTile(Tile* tile){
    m_selectedTile = tile;
}

void Grid::setStartTile(){
    if(m_selectedTile->getTileType() == TileType::Walkable){
        m_droneStartTile = m_selectedTile;
    }
}

void Grid::colorTile(QColor color){
    if(m_selectedTile != nullptr){
        m_selectedTile->setTileColor(color);
        m_selectedTile->setTileType(colorToType(color));
        int x = floor(m_selectedTile->getPosition().x() / m_tileSize.x());
        int y = floor(m_selectedTile->getPosition().y() / m_tileSize.y());
        m_image.setPixel(x,y,color.rgb());
        if(m_selectedTile == m_droneStartTile && m_droneStartTile->getTileType() != TileType::Walkable){
            m_droneStartTile = nullptr;
        }
    }
}

void Grid::newCleanGrid(QVector2D gridSize){
    m_image = QImage(int(gridSize.x()),int(gridSize.y()),QImage::Format_ARGB32);
    m_image.fill(Qt::white);
    m_gridSize = gridSize;
    m_tileSize = {800/static_cast<float>(gridSize.x()),600/static_cast<float>(gridSize.y())};
    m_grid.clear();
    for(int y = 0; y < m_gridSize.y(); y++){
        for(int x = 0; x < m_gridSize.x();x++){
            m_grid.push_back({TileType::Undefined,
                              typeToColor(TileType::Undefined),
                              {x * m_tileSize.x(),y * m_tileSize.y()},
                              m_tileSize});
         }
    }
}

TileType Grid::colorToType(QColor color){
    for(auto p : m_colorMap){
        if(p.second == color){
            return p.first;
        }
    }
    return TileType::Undefined;
}

QColor Grid::typeToColor(TileType type){
    for(auto p : m_colorMap){
        if(p.first == type){
            return p.second;
        }
    }
    return Qt::white;
}


