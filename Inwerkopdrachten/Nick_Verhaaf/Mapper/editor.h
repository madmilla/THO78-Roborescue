#ifndef EDITOR_H
#define EDITOR_H

#include <QDialog>
#include <QString>
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QMouseEvent>

namespace Ui {
class Editor;
}

class Editor : public QDialog
{
    Q_OBJECT

public:
    explicit Editor(QWidget *parent = 0);
    ~Editor();
    void setMap(QString content);
    void paintEvent(QPaintEvent *e);
    void draw(QRect &rect);
    void mousePressEvent(QMouseEvent *);

private slots:
    void on_Wall_clicked();

    void on_Rock_clicked();

    void on_Grass_clicked();

    void on_Tree_clicked();

    void on_Water_clicked();

    void on_Sand_clicked();

    void on_ATV_clicked();

    void on_Quadcopter_clicked();

    void on_ROSBEE_clicked();

    void on_Objective_clicked();

    void on_SaveMap_clicked();

private:
    Ui::Editor *ui;
    QString map;
    enum Objects
    {
        Wall = '1',
        Rock = '2',
        Grass = '3',
        Tree = '4',
        Water = '5',
        Sand = '6',
        ATV = '7',
        Quadcopter = '8',
        ROSBEE = '9',
        Objective = '0',
        Unknown = 'U'
    };
    char selectedObject;
    int objectX;
    int objectY;
    int x;
    int y;
};

#endif // EDITOR_H
