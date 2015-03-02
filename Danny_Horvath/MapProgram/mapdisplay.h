#ifndef MAPDISPLAY_H
#define MAPDISPLAY_H

#include <QDialog>
#include <QString>
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QMouseEvent>

namespace Ui {
class MapDisplay;
}

class MapDisplay : public QDialog
{
    Q_OBJECT

public:
    explicit MapDisplay(QWidget *parent = 0);
    ~MapDisplay();
    void setMap(QString content);
    void paintEvent(QPaintEvent *e);
    void draw(QRect &rect);
    void mousePressEvent(QMouseEvent *);

private slots:
    void on_wallButton_clicked();

    void on_grassButton_clicked();

    void on_sandButton_clicked();

    void on_stoneButton_clicked();

    void on_treeButton_clicked();

    void on_waterButton_clicked();

    void on_atvButton_clicked();

    void on_rosbeeButton_clicked();

    void on_quadButton_clicked();

    void on_objectiveButton_clicked();

    void on_saveButton_clicked();

private:
    Ui::MapDisplay *ui;
    QString map;
    enum Tiles{
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
    char selected;
    int objectx;
    int objecty;
    int x;
    int y;
};

#endif // MAPDISPLAY_H
