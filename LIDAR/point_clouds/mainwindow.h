#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void readFile(QString fileOne, QString fileTwo);
    void combine(QString cloud1, QString cloud2, int pos1, int pos2);

private slots:
    void on_pushButton_clicked();

    void on_writeButton_clicked();

private:
    Ui::MainWindow *ui;
    int posi1, posi2;
};

#endif // MAINWINDOW_H
