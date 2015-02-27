#ifndef MAPVIEWWIDGET_H
#define MAPVIEWWIDGET_H

#include <QWidget>
#include <QBrush>
#include "mapeditor.h"


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
    void paintEvent(QPaintEvent * paintEvent) override;

    QBrush droneBrush = QBrush(Qt::red);
};

#endif // MAPVIEWWIDGET_H
