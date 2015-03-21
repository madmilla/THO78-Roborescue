#include "drawArea.h"

drawArea::drawArea()
{
    rectangles.clear();
    strings.clear();
}

drawArea::drawArea(QWidget *widget):
    QGraphicsView(widget)
{

}


drawArea::~drawArea()
{

}

QVector<mapRectangle> drawArea::getRectangles()
{
    return rectangles;
}

void drawArea::setRectangles(QVector<mapRectangle> rectangles) {
    this->rectangles = rectangles;
}

QVector<QString> drawArea::getStrings()
{
    return strings;
}

void drawArea::setStrings(QVector<QString> strings) {
    this->strings = strings;
}
void drawArea::paintEvent(QPaintEvent * /* event */) {
    QPainter painter(this);

    if (rectangles.isEmpty() && strings.isEmpty()) { //No paintable elements
        qDebug() << "No paintable elements!";
    }
    else if (!rectangles.isEmpty() && !strings.isEmpty()) { //Both rectangles & strings are filled
        qDebug() << "Too many paintable elements!";
    }
    else if (rectangles.isEmpty()) { //Strings is filled, legend needs to be painted
        for (int i = 0; i < strings.length(); i++) {
            if (strings[i].toLower().contains("quad")) {
                painter.setBrush(QBrush(Qt::red));
                painter.drawText(10, 30 * (i+1), strings[i]);
            }
            else if (strings[i].toLower().contains("target")) {
                painter.setBrush(QBrush(Qt::yellow));
                painter.drawText(10, 30 * (i+1), strings[i]);
            }
            else if (strings[i].toLower().contains("rosbee")) {
                painter.setBrush(QBrush(Qt::green));
                painter.drawText(10, 30 * (i+1), strings[i]);
            }
            else if (strings[i].toLower().contains("atv")) {
                painter.setBrush(QBrush(Qt::blue));
                painter.drawText(10, 30 * (i+1), strings[i]);
            }
            else if (strings[i].toLower().contains("obstacle")) {
                painter.setBrush(QBrush(Qt::black));
                painter.drawText(10, 30 * (i+1), strings[i]);
            }
        }
        qDebug() << "Drew the legend!";
    }
    else {
        for (int i = 0; i < rectangles.length(); i++) {
            switch (rectangles[i].getType()) {
            case 'e':
                painter.fillRect(rectangles[i].getRectangle(), QBrush(Qt::cyan, Qt::CrossPattern));
                break;
            case 'q':
                painter.fillRect(rectangles[i].getRectangle(), QBrush(Qt::red));
                break;
            case 't':
                painter.fillRect(rectangles[i].getRectangle(), QBrush(Qt::yellow));
                break;
            case 'r':
                painter.fillRect(rectangles[i].getRectangle(), QBrush(Qt::green));
                break;
            case 'u':
                painter.fillRect(rectangles[i].getRectangle(), QBrush(Qt::blue));
                break;
            case 'o':
                painter.fillRect(rectangles[i].getRectangle(), QBrush(Qt::black));
                break;
            default:
                break;
            }
        }
        qDebug() << "Drew the map!";
    }
}
