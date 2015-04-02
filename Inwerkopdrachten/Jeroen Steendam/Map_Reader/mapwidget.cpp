#include "mapwidget.h"

#include <QPainter>


/**
 * @brief MapWidget::MapWidget
 * @param parent
 *
 * Constructor
 */
MapWidget::MapWidget(QWidget *parent) : QWidget(parent)
{
    colorMap.insert({
        {Map::VALUE_FREE, QColor::fromRgb(255, 255, 255)},
        {Map::VALUE_WALL, QColor::fromRgb(0, 0, 0)},
        {Map::VALUE_QUAD, QColor::fromRgb(255, 0, 0)}
    });
}

/**
 * @brief MapWidget::~MapWidget
 *
 * Destructor
 */
MapWidget::~MapWidget()
{

}

/**
 * @brief MapWidget::setMap
 * @param map
 *
 * Set current map.
 */
void MapWidget::setMap(Map &map)
{
    this->map = &map;
    repaint();
}

/**
 * @brief MapWidget::paintEvent
 *
 * Paints the map.
 */
void MapWidget::paintEvent(QPaintEvent*)
{
    if(map != NULL) {
        QPainter painter(this);
        painter.fillRect(rect(), Qt::transparent);

        int screenWidth = width();
        int screenHeight = height();

        int blockWidth = screenWidth/map->width;
        int blockHeight = screenHeight/map->height;

        if(blockWidth > blockHeight)
            blockWidth = blockHeight;
        if(blockHeight >= blockWidth)
            blockHeight = blockWidth;

        for(int x = 0; x < map->width; x++) {
            for(int y = 0; y < map->height; y++) {
                int value = map->data[x + y * map->width];
                painter.fillRect(x*blockWidth, y*blockHeight, blockWidth, blockHeight, colorMap[value]);
            }
        }
    }
}

/**
 * @brief MapWidget::mousePressEvent
 * @param event
 *
 * If a map region is clicked change it's value.
 */
void MapWidget::mousePressEvent(QMouseEvent * event)
{
    if(map != NULL) {
        int screenWidth = width();
        int screenHeight = height();

        int blockWidth = screenWidth/map->width;
        int blockHeight = screenHeight/map->height;

        if(blockWidth > blockHeight)
            blockWidth = blockHeight;
        if(blockHeight >= blockWidth)
            blockHeight = blockWidth;

        int x = event->x()/blockWidth;
        int y = event->y()/blockWidth;

        if(x >= (map->width) || y >= (map->height))
            return;

        map->data[x + y * map->width] = ((map->data[x + y * map->width] + 1) % 3);
        repaint();
    }
}
