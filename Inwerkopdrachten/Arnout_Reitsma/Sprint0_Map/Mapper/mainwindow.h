#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#define CUBE 24
#define MAX 20

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void loadFile(QString filename);
    void messages(QString type);
private slots:
    void on_loadButton_clicked();
    void on_clearButton_clicked();

private:
    bool loadButtonClicked;
    bool clearButtonClicked;
    enum Objects{
        Grass = 3,
        Stone = 2,
        Wall = 1,
        Unknown = 0,
        Water = 5,
        Tree = 4
    };
    Ui::MainWindow *ui;
    QString character;  //character from map file
    QString objects[MAX][MAX];
    int cX, cY;         //x & y of character
protected:
    void paintEvent(QPaintEvent *);
};

#endif // MAINWINDOW_H
