#ifndef MAPGRAPHICSVIEW_H
#define MAPGRAPHICSVIEW_H
#include <QGraphicsView>
#include <QGraphicsRectItem>

class MapGraphicsView : public QGraphicsView
{
public:
    MapGraphicsView(QWidget* parent = nullptr);
    void addItem(QGraphicsItem* item);
private:
    QGraphicsScene *scene;
    void wheelEvent(QWheelEvent *event) override;
};
#endif // MAPGRAPHICSVIEW_H
