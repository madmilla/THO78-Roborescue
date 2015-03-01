#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#define CUBE (480/20)   //480x480 field, 20x20 characters in map file
#define MAX 20
#define GRAVEL "x"
#define DIRT "o"
#define ROCK "d"
#define WATER "-"

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
    void messages(QString type);
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    QString character;  //character from map file
    QString objects[MAX][MAX];
    int cX, cY;         //x & y of character
protected:
    void paintEvent(QPaintEvent *);
};

#endif // MAINWINDOW_H
