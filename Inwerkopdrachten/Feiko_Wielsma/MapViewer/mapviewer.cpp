#include "mapviewer.h"


MapViewer::MapViewer(QWidget * parent)
    : QWidget(parent)
{
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
    std::map<ObjectType, QColor> mapData =
    {
        {ObjectType::Empty, QColor(255,255,255)},
        {ObjectType::Wall, QColor(0,0,0)},
        {ObjectType::Tree, QColor(0,255,0)},
        {ObjectType::Quad, QColor(255,0,0)},
        {ObjectType::ATV, QColor(0,0,255)}
    };
    objectColorMap = mapData;
    selectedObject = ObjectType::Empty;
    qDebug() << "Creating Mapviewer";
}


MapViewer::~MapViewer()
{

}

void MapViewer::setMap(Map* newMap)
{
    map = newMap;
}

void MapViewer::setSelectedObject(ObjectType objectType)
{
    selectedObject = objectType;
}

void MapViewer::mousePressEvent(QMouseEvent *event)
{
    if(map != nullptr)
    {
        QPoint mousePosition = event->pos();

        auto xPosition = mousePosition.x() / GRID_SIZE;
        auto yPosition = mousePosition.y() / GRID_SIZE;
        //qDebug() << "x: " << xPosition;
       // qDebug() << "y: " << yPosition;

        map->setType(xPosition, yPosition, selectedObject);

        this->repaint();
    }
}

void MapViewer::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPen pen;
    pen.setWidth(CELL_BORDER_SIZE);
    painter.setPen(pen);
    for (int x = 0; x < GRID_SIZE; x++)
    {
        for (int y = 0; y < GRID_SIZE; y++)
        {
            drawCell(painter, x, y);
        }
    }
}

void MapViewer::drawCell(QPainter& painter, int x, int y)
{
    if (map != nullptr)
    {
        //qDebug() << "Getting map color data";
        painter.fillRect(
            x*(CELL_WIDTH + CELL_PADDING + CELL_BORDER_SIZE),
            y*(CELL_HEIGHT + CELL_PADDING + CELL_BORDER_SIZE),
            CELL_WIDTH,
            CELL_HEIGHT,
            QBrush(objectColorMap[map->getType(x,y)])
            );

        painter.drawRect(
            x*(CELL_WIDTH + CELL_PADDING + CELL_BORDER_SIZE),
            y*(CELL_HEIGHT + CELL_PADDING + CELL_BORDER_SIZE),
            CELL_WIDTH,
            CELL_HEIGHT
            );
    }
    else
    {
        //qDebug() << "Map not set";
    }

}
