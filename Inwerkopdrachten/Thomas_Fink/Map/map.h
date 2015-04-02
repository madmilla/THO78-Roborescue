#ifndef MAP_H
#define MAP_H

#include <QWidget>
#include <QTableWidget>
#include "maplogic.h"

namespace Ui {
class Map;
}

class Map : public QWidget
{
    Q_OBJECT

public:
    explicit Map(QString filename, QWidget *parent = 0);
    ~Map();
    void updateMap(int y, int x, int newContent);
    int getMapData(int y, int x);

private:
    Ui::Map *ui;
    QTableWidget * table;

    MapLogic* mapLogic;

    void showMap();

    Qt::GlobalColor getColorById(int id);

    const int mapGridSize = 20;

private slots:
   void on_emptyButton_clicked();
   void on_redButton_clicked();
   void on_greenButton_clicked();
   void on_blueButton_clicked();


   void on_saveButton_clicked();

   void fillColor(int id);
};

#endif // MAP_H
