#ifndef MAP_H
#define MAP_H

#include <QWidget>
#include <QFile>
#include <QTableWidget>

namespace Ui {
class Map;
}

class Map : public QWidget
{
    Q_OBJECT

public:
    explicit Map(QString filename, QWidget *parent = 0);
    ~Map();

private:
    Ui::Map *ui;
    QString filename;
    QTableWidget * table;
    QVector< QVector< int > > mapLayout;

    void showMap();
    void loadMap(QString &filename);
    void updateMap(int x, int y, int newContent);

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
