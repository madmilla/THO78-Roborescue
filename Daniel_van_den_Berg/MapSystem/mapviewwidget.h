#ifndef MAPVIEWWIDGET_H
#define MAPVIEWWIDGET_H

#include <QWidget>
#include <QBrush>
#include "mapeditor.h"
#include <map>


namespace Ui {
class MapViewWidget;
}

class MapViewWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MapViewWidget(QWidget *parent = 0);
    ~MapViewWidget();

private slots:
    void on_MapViewWidget_destroyed();

private:
    Ui::MapViewWidget *ui;
    void MapViewWidget::mousePressEvent(QMouseEvent *) override;
    void paintEvent(QPaintEvent * paintEvent) override;

    std::map<MapEditor::Objects,QBrush> objectBrushes;

    /*QBrush objectBrushes[] = {
        MapEditor::DRONE=QBrush(Qt::green),
        MapEditor::WALL=QBrush(Qt::red)
    };*/
    QBrush backgroundBrush = QBrush(QColor(128,128,128,255));
};

#endif // MAPVIEWWIDGET_H
