#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#define CUBE (480/20)   //480x480 field, 20x20 characters in map file
#define MAX 20
#define WALL "1"
#define STONE "2"
#define GRASS "3"
#define TREE "4"
#define WATER "5"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void readFile(QString filename);
    void writeFile(QString filename);
    void messages(QString type);
    QString checkType(QString character);
private slots:

    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

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
