#ifndef DISPLAY_H
#define DISPLAY_H

#include <QtDesigner/QtDesigner>
#include <QWidget>
#include "pathfinding.h"

/**
* @class   Display
* @author  Wibren Wiersma
* @date    Juni, 2015
* @brief   This class draws the map and the pathFinding results on the screen
*/
class Display : public QWidget
{
   Q_OBJECT
public:
   /**
   *  Construts a display
   *  @param parent use this param if this is a sub window of some QWidget
   */
   explicit Display(QWidget *parent = 0);
   /**
     * Deconstructor for display
     */
   ~Display();

   /**
   *  Set the pathfinding object needed to draw pathfinding results
   *  @param pf the object
   */
   void setPathFinding(PathFinding & pf) { this->pf = &pf; }
   /**
   *  Get the pathfinding object stored in this class
   *  @returns nullptr is not set
   */
   PathFinding * getPathFinding() { return this->pf; }

   /**
   *  Change the startpoint
   *  @param startPoint the new startpoint
   */
   void setStartPoint(QPointF startPoint);
   /**
   *  Change target or stoppoint
   *  @param stopPoint the new stopPoint
   */
   void setStopPoint(QPointF stopPoint);
   /**
   *  Execute pathfinding on a seperate thread, with the given start and stop point.
   */
   void execute();

   /**
   *  Push the current tempMapItem into the map
   */
   void pushMapItem();
   /**
   *  Deletes the current tempMapItem without pushing it in the map
   */
   void cancelMapItem();

   /**
   *  Get the current tempMapItem so adding a mapItem will be show in the gui without it is already in the map
   */
   MapItem & getTempMapItem();

   /**
   *  Check if the algorithm is running
   */
   bool isExecuting() {return executeRunning;}

signals:
   /**
   *  Raises if left mouse released in the display.
   * @param clickedMapPos A map based position of location where clicked.
   */
   void clicked(QPointF clickedMapPos);
   /**
   *  Raises when the executing of the algorithm is done
   */
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
