#ifndef MAPGRAPHICSVIEW_H
#define MAPGRAPHICSVIEW_H
#include <QGraphicsView>
#include <QGraphicsRectItem>

const double SCALE_FACTOR(1.15);

class MapGraphicsView : public QGraphicsView
{
public:
    MapGraphicsView(QWidget* parent = nullptr);

private:

    /*!
     * \brief Override of the mousewheel event.
     *
     * Catches the mousewheel events registered inside this QGraphicsView
     * and zooms in/out accordingly and doesn't pass it further down to refrain
     * from activating the normal mousewheel handling.
     *
     * \param event The registered mousewheel event
     */
    void wheelEvent(QWheelEvent *event) override;
};
#endif // MAPGRAPHICSVIEW_H
