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

signals:

public slots:

protected:
   void paintEvent(QPaintEvent *);
private:
   PathFinding * pf = nullptr;
   Vector<float> translation;

   QPointF convertToQPointF(const Vector<float> p);
   QPolygonF convertToQPolygonF(const MapItem & mi);
   void drawNode(QPainter & painter, Node * node);
};

#endif // DISPLAY_H
