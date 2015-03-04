#ifndef GUI_H
#define GUI_H

#include <QDialog>
#include <QPoint>
#include <QPainter>
#include "map.h"
#include <QMouseEvent>
#include <QFileDialog>
#include <QTextStream>
#include <iostream>

enum Objects : const char { BEKER = '0', DEUR = '1', MUUR = '2', PLANT = '3', TAFEL = '4' };

namespace Ui {
class Gui;
}

class Gui : public QDialog
{
    Q_OBJECT

public:
    explicit Gui(QPoint & SCREEN_SIZE, std::vector<QPixmap> & images, Map* map, QWidget *parent = 0);
    ~Gui();

private slots:
    void on_beker_button_clicked();

    void on_deur_button_clicked();

    void on_muur_button_clicked();

    void on_plant_button_clicked();

    void on_tafel_button_clicked();

    void on_edit_button_clicked();

private:
    Ui::Gui *ui;
    QPoint & SCREEN_SIZE;
    std::vector<QPixmap> & images;
    void paintEvent(QPaintEvent* e);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void changeMap();
    bool edit_mode;
    Objects selected_object;
    QPoint cursorPos;
    Map* map;
};

#endif // GUI_H
