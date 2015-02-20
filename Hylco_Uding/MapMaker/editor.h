#ifndef EDITOR_H
#define EDITOR_H

#include <QDialog>
#include <QtGui>
#include <QtCore>
#include <QJsonArray>
#include "map.h"
#define MAX_MAP_SIZE 50
namespace Ui {
class Editor;
}

class Editor : public QDialog
{
    Q_OBJECT

public:
    explicit Editor(int height, int width, QJsonObject json = QJsonObject(),QWidget *parent = 0 );
    ~Editor();
    void saveFile();
private slots:
    void on_Save_clicked();

private:
    void mousePressEvent(QMouseEvent * event);
    void paintEvent(QPaintEvent * e);
    Ui::Editor *ui;
    Map * map;
};

#endif // EDITOR_H
