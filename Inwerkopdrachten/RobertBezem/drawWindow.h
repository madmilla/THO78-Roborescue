#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
class QGraphicsView;
class QGraphicsScene;
class QPushButton;
class QGraphicsItem;
class drawWindow : public QWidget
{
public:
    explicit drawWindow(int xSize = 800, int ySize = 480,QWidget *parent = 0);
    void addGrid(int distanceBetweenLines = 20);
    void removeGrid();
    void toggleGrid(int distanceBetweenLines = 20);
private:
   QGraphicsView *graphicsview;
   QGraphicsScene *scene;
   QList<QGraphicsItem *> grid;
   QList<QGraphicsItem *> objects;
   int xSize,ySize;
};

#endif // WINDOW_H
