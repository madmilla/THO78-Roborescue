#ifndef EDITOR_H
#define EDITOR_H

#include <QDialog>
#include <QtGui>
#include <QtCore>
#include <QJsonArray>
#define MAX_MAP_SIZE 50
namespace Ui {
class Editor;
}

class Editor : public QDialog
{
    Q_OBJECT

public:
    explicit Editor(QWidget *parent = 0);
    ~Editor();
    void setMap(QJsonObject json);
    void setSize(int height, int width);

private slots:
    void on_Save_clicked();

private:
    int width=20,height=20;

    void mousePressEvent(QMouseEvent * event);
    void paintEvent(QPaintEvent * e);
    QJsonArray array[MAX_MAP_SIZE][MAX_MAP_SIZE];
    std::map<QString,QBrush> Types;
    Ui::Editor *ui;
};

#endif // EDITOR_H
