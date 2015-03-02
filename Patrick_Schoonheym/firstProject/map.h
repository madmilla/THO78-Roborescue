#ifndef MAP_H
#define MAP_H

#include <QDialog>
#include <vector>
#include <QString>
#include <QPainter>
#include <map>
#include <QtGui>
#include <QtCore>
#include <QDebug>
#include <QPixmap>
#include <QMouseEvent>
#include <QFileDialog>

enum Objects : char { BEKER = '0', DEUR = '1', MUUR = '2', PLANT = '3', TAFEL = '4' };

namespace Ui {
class Map;
}

class Map : public QDialog
{
    Q_OBJECT

public:
    explicit Map(QWidget *parent = 0);
    ~Map();
    void setMap(std::vector<QString> & map);

private slots:

    void on_edit_button_clicked();

    void on_beker_clicked();

    void on_deur_clicked();

    void on_muur_clicked();

    void on_plant_clicked();

    void on_tafel_clicked();

private:
    Ui::Map *ui;
    std::vector<QString> map;
    void paintEvent(QPaintEvent* e);
    void mouseMoveEvent(QMouseEvent *event);
    void addImage(const QString & name);
    std::vector<QPixmap> images;
    Objects selected_object;
    bool edit_mode;
};

#endif // MAP_H
