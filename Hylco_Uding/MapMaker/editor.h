#ifndef EDITOR_H
#define EDITOR_H

#include <QDialog>
#include <QtGui>
#include <QtCore>
#include "map.h"
#define MAX_MAP_SIZE 50
namespace Ui {
class Editor;
}

class Editor : public QDialog
{
    Q_OBJECT

public:
    explicit Editor(QString filename,int height = 0, int width = 0,QWidget *parent = 0 );
    ~Editor();
private slots:
    void on_Save_clicked();

private:
    void mousePressEvent(QMouseEvent * event);
    void paintEvent(QPaintEvent * e);
    Ui::Editor *ui;
    Map * map;
};

#endif // EDITOR_H
