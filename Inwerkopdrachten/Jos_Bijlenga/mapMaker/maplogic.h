#ifndef MAPLOGIC_H
#define MAPLOGIC_H

#include <iostream>
#include <QString>
#include <QFileDialog>
#include <QStandardPaths>
#include <QObject>
#include <QMainWindow>
#include <QtGui>
#include <QWidget>
#include <vector>
#include <string>
#include <QPoint>

const int EMPTY = 0;
const int OBJECT = 1;
const int COPTER = 2;
const int WIDTH = 20;
const int HEIGHT = 20;
const int OFFSET = 21;

class mapLogic
{
public:
    mapLogic();
    mapLogic(QWidget * parent);
    ~mapLogic();
    void newFile();
    void openFile();
    void saveFile();
    void mouseClicked(QPoint pos, Qt::MouseButtons button);
    void readFile(QString filename);
    QVector2D getCell(QPoint point);
    int getCelltype(QVector2D point);
    int ** getMap();
    int ** create2DArray(unsigned height, unsigned width);

    QString toString();
private:
    QWidget * inst;
    QString curFile;
    int ** map;
    int screenWidth;
    int screenHeight;
};

#endif // MAPLOGIC_H
