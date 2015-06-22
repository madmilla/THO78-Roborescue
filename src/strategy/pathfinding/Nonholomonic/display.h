#ifndef DISPLAY_H
#define DISPLAY_H

#include <QtDesigner/QtDesigner>
#include <QWidget>
#include "pathfinding.h"

class Display : public QWidget
{
   Q_OBJECT
public:
   explicit Display(QWidget *parent = 0);
   ~Display();

   void setPathFinding(PathFinding & pf) { this->pf = &pf; }
   PathFinding * getPathFinding() { return this->pf; }

   void setStartPoint(QPointF startPoint);
   void setStopPoint(QPointF stopPoint);
   void execute();

   void pushMapItem();
   void cancelMapItem();
   MapItem & getTempMapItem();

   bool isExecuting() {return executeRunning;}

signals:
   void clicked(QPointF clickedMapPos);
   void executeDone();
public slots:

protected:
   void paintEvent(QPaintEvent *);
   void mousePressEvent(QMouseEvent*);
   void mouseReleaseEvent(QMouseEvent*event);
private:
   PathFinding * pf = nullptr;
   Vector<float> translation;
   bool executeRunning;
   QPointF startPoint, endPoint;

   MapItem tempMapItem;

   QTimer * timer;

   QPointF convertToQPointF(const Vector<float> p);
   QPolygonF convertToQPolygonF(const MapItem & mi);
   void drawNode(QPainter & painter, Node * node);
   void executeTask();
};

#endif // DISPLAY_H
